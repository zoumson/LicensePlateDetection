// DetectChars.cpp

#include "DetectChars.h"
///usr/local/include/opencv4/opencv2/imgproc/types_c.h
// global variables ///////////////////////////////////////////////////////////////////////////////
//cv::Ptr<cv::ml::KNearest> kNearest = cv::ml::KNearest::create();
cv::Ptr<cv::ml::KNearest> kNearest = cv::ml::KNearest::create();

///////////////////////////////////////////////////////////////////////////////////////////////////
bool loadKNNDataAndTrainKNN(cv::String classifierPath,
cv::String imageClassifiedPath
)
{

    // read in training classifications ///////////////////////////////////////////////////
    // we will read the classification numbers into this variable as though it is a vector
    // open the classifications file
    cv::Mat matClassificationInts; 
    cv::FileStorage fsClassifications(classifierPath, cv::FileStorage::READ); 

    if (fsClassifications.isOpened() == false)
    {  
        std::cout << "error, unable to open training classifications file, exiting program\n\n";
        return (false);                                                                          
    }
    // read classifications section into Mat classifications variable
    fsClassifications["classifications"] >> matClassificationInts; 
    // close the classifications file
    fsClassifications.release();                                   

    // read in training images ////////////////////////////////////////////////////////////
    // we will read multiple images into this single image variable as though it is a vector
    cv::Mat matTrainingImagesAsFlattenedFloats; 

    // open the training images file
    cv::FileStorage fsTrainingImages(imageClassifiedPath, cv::FileStorage::READ); 
    if (fsTrainingImages.isOpened() == false)
    {                                                                                   
        std::cout << "error, unable to open training images file, exiting program\n\n"; 
        return (false);                                                                 
    }
    // read images section into Mat training images variable
    fsTrainingImages["images"] >> matTrainingImagesAsFlattenedFloats; 
    fsTrainingImages.release();                                       

    // train //////////////////////////////////////////////////////////////////////////////

    // finally we get to the call to train, note that both parameters have to be of type Mat 
    //(a single Mat)
    // even though in reality they are multiple images / numbers
    kNearest->setDefaultK(1);

    kNearest->train(matTrainingImagesAsFlattenedFloats, cv::ml::ROW_SAMPLE, matClassificationInts);

    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<PossiblePlate> detectCharsInPlates(std::vector<PossiblePlate> &vectorOfPossiblePlates, bool SHOW_STEPS)
{
    int intPlateCounter = 0; // this is only for showing steps
    cv::Mat imgContours;
    std::vector<std::vector<cv::Point>> contours;
    cv::RNG rng;

    if (vectorOfPossiblePlates.empty())
    {   // if vector of possible plates is empty
        return vectorOfPossiblePlates; // return
    }
    // at this point we can be sure vector of possible plates has at least one plate

    for (auto &possiblePlate : vectorOfPossiblePlates)
    {   // for each possible plate, this is a big for loop that takes up most of the function
        // preprocess to get grayscale and threshold images
        preprocess(possiblePlate.imgPlate, possiblePlate.imgGrayscale, possiblePlate.imgThresh); 

    if (SHOW_STEPS)
    {
        cv::imshow("5a", possiblePlate.imgPlate);
        cv::imshow("5b", possiblePlate.imgGrayscale);
        cv::imshow("5c", possiblePlate.imgThresh);    
    }


        // upscale size by 60% for better viewing and character recognition
        cv::resize(possiblePlate.imgThresh, possiblePlate.imgThresh, cv::Size(), 1.6, 1.6);

        // threshold again to eliminate any gray areas
        cv::threshold(possiblePlate.imgThresh, possiblePlate.imgThresh, 0.0, 255.0, CV_THRESH_BINARY | CV_THRESH_OTSU);

    if (SHOW_STEPS)
    {
        cv::imshow("5d", possiblePlate.imgThresh);
    }

        // find all possible chars in the plate,
        // this function first finds all contours, 
        // then only includes contours that could be chars (without comparison to other chars yet)
        std::vector<PossibleChar> vectorOfPossibleCharsInPlate = findPossibleCharsInPlate(possiblePlate.imgGrayscale, possiblePlate.imgThresh);

    if (SHOW_STEPS)
    {
        imgContours = cv::Mat(possiblePlate.imgThresh.size(), CV_8UC3, SCALAR_BLACK);
        contours.clear();

        for (auto &possibleChar : vectorOfPossibleCharsInPlate)
        {
            contours.push_back(possibleChar.contour);
        }

        cv::drawContours(imgContours, contours, -1, SCALAR_WHITE);

        cv::imshow("6", imgContours);
    }

        // given a vector of all possible chars, find groups of matching chars within the plate
        std::vector<std::vector<PossibleChar>> vectorOfVectorsOfMatchingCharsInPlate = 
                        findVectorOfVectorsOfMatchingChars(vectorOfPossibleCharsInPlate);

    if (SHOW_STEPS)
    {
        imgContours = cv::Mat(possiblePlate.imgThresh.size(), CV_8UC3, SCALAR_BLACK);

        contours.clear();

        for (auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingCharsInPlate)
        {
            int intRandomBlue = rng.uniform(0, 256);
            int intRandomGreen = rng.uniform(0, 256);
            int intRandomRed = rng.uniform(0, 256);

            for (auto &matchingChar : vectorOfMatchingChars)
            {
                contours.push_back(matchingChar.contour);
            }
            cv::drawContours(imgContours, contours, -1, cv::Scalar((double)intRandomBlue, 
                                    (double)intRandomGreen, (double)intRandomRed));
        }
        cv::imshow("7", imgContours);
    }

        if (vectorOfVectorsOfMatchingCharsInPlate.size() == 0)
        { // if no groups of matching chars were found in the plate
    if (SHOW_STEPS)
    {
            std::cout << "chars found in plate number " << intPlateCounter << " = (none), click on any image and press a key to continue . . ." << std::endl;
            intPlateCounter++;
            cv::destroyWindow("8");
            cv::destroyWindow("9");
            cv::destroyWindow("10");
            cv::waitKey(0);
    }                           
            // set plate string member variable to empty string      
            possiblePlate.strChars = ""; 
            // go back to top of for loop
            continue;                    
        }

        for (auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingCharsInPlate)
        {                              
            // sort the chars left to right                                                                                // for each vector of matching chars in the current plate
            std::sort(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), 
                            PossibleChar::sortCharsLeftToRight); 
            vectorOfMatchingChars = removeInnerOverlappingChars(vectorOfMatchingChars);                                // and eliminate any overlapping chars
        }

    if (SHOW_STEPS)
    {
        imgContours = cv::Mat(possiblePlate.imgThresh.size(), CV_8UC3, SCALAR_BLACK);

        for (auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingCharsInPlate)
        {
            int intRandomBlue = rng.uniform(0, 256);
            int intRandomGreen = rng.uniform(0, 256);
            int intRandomRed = rng.uniform(0, 256);

            contours.clear();

            for (auto &matchingChar : vectorOfMatchingChars)
            {
                contours.push_back(matchingChar.contour);
            }
            cv::drawContours(imgContours, contours, -1, cv::Scalar((double)intRandomBlue, 
                                        (double)intRandomGreen, (double)intRandomRed));
        }
        cv::imshow("8", imgContours);
}

        // within each possible plate, suppose the longest vector of 
        // potential matching chars is the actual vector of chars
        unsigned int intLenOfLongestVectorOfChars = 0;
        unsigned int intIndexOfLongestVectorOfChars = 0;
        // loop through all the vectors of matching chars, get the index of the one with the most chars
        for (unsigned int i = 0; i < vectorOfVectorsOfMatchingCharsInPlate.size(); i++)
        {
            if (vectorOfVectorsOfMatchingCharsInPlate[i].size() > intLenOfLongestVectorOfChars)
            {
                intLenOfLongestVectorOfChars = vectorOfVectorsOfMatchingCharsInPlate[i].size();
                intIndexOfLongestVectorOfChars = i;
            }
        }
        // suppose that the longest vector of matching chars within 
        // the plate is the actual vector of chars
        std::vector<PossibleChar> longestVectorOfMatchingCharsInPlate = 
                        vectorOfVectorsOfMatchingCharsInPlate[intIndexOfLongestVectorOfChars];

    if (SHOW_STEPS)
    {
        imgContours = cv::Mat(possiblePlate.imgThresh.size(), CV_8UC3, SCALAR_BLACK);

        contours.clear();

        for (auto &matchingChar : longestVectorOfMatchingCharsInPlate)
        {
            contours.push_back(matchingChar.contour);
        }
        cv::drawContours(imgContours, contours, -1, SCALAR_WHITE);

        cv::imshow("9", imgContours);
    }

        // perform char recognition on the longest vector of matching chars in the plate
        possiblePlate.strChars = recognizeCharsInPlate(possiblePlate.imgThresh, 
                            longestVectorOfMatchingCharsInPlate, SHOW_STEPS);

    if (SHOW_STEPS)
    {
        std::cout << "chars found in plate number " << intPlateCounter 
                << " = " << possiblePlate.strChars 
                << ", click on any image and press a key to continue . . .\n" ;
        intPlateCounter++;
        cv::waitKey(0);
    }

    } // end for each possible plate big for loop that takes up most of the function

    if (SHOW_STEPS)
    {
    std::cout << "\nchar detection complete, click on any image and press a key to continue . . .\n"; 
    cv::waitKey(0);
    }

    return (vectorOfPossiblePlates);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<PossibleChar> findPossibleCharsInPlate(cv::Mat &imgGrayscale, cv::Mat &imgThresh)
{
    // this will be the return value
    std::vector<PossibleChar> vectorOfPossibleChars; 

    cv::Mat imgThreshCopy;

    std::vector<std::vector<cv::Point>> contours;

    // make a copy of the thresh image, this in necessary b/c findContours modifies the image
    imgThreshCopy = imgThresh.clone(); 

    // find all contours in plate
    cv::findContours(imgThreshCopy, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE); 

    for (auto &contour : contours)
    { // for each contour
        PossibleChar possibleChar(contour);

        if (checkIfPossibleChar(possibleChar))
        {   
            // if contour is a possible char, note this does not compare to other chars (yet) . . .
            // add to vector of possible chars
            vectorOfPossibleChars.push_back(possibleChar); 
        }
    }

    return vectorOfPossibleChars;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool checkIfPossibleChar(PossibleChar &possibleChar)
{
    // this function is a 'first pass' that does a rough check 
    // on a contour to see if it could be a char,
    // note that we are not (yet) comparing the char to other chars to look for a group
    if (possibleChar.boundingRect.area() > MIN_PIXEL_AREA &&
        possibleChar.boundingRect.width > MIN_PIXEL_WIDTH && 
        possibleChar.boundingRect.height > MIN_PIXEL_HEIGHT &&
        MIN_ASPECT_RATIO < possibleChar.dblAspectRatio && 
        possibleChar.dblAspectRatio < MAX_ASPECT_RATIO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::vector<PossibleChar>> findVectorOfVectorsOfMatchingChars(const std::vector<PossibleChar> &vectorOfPossibleChars)
{
    // with this function, we start off with all the possible chars in one big vector
    // the purpose of this function is to re-arrange the one big vector of chars into a 
    //vector of vectors of matching chars,
    // note that chars that are not found to be in a group of matches do not need to be 
    //considered further
    //Return value
    std::vector<std::vector<PossibleChar>> vectorOfVectorsOfMatchingChars;
    for (auto &possibleChar : vectorOfPossibleChars)
    { // for each possible char in the one big vector of chars

        // find all chars in the big vector that match the current char
        std::vector<PossibleChar> vectorOfMatchingChars = findVectorOfMatchingChars(possibleChar, 
                                                                    vectorOfPossibleChars);

        // also add the current char to current possible vector of matching chars
        vectorOfMatchingChars.push_back(possibleChar); 
        
        // if current possible vector of matching chars is not long enough to constitute a possible plate
        if (vectorOfMatchingChars.size() < MIN_NUMBER_OF_MATCHING_CHARS)
        {
            // jump back to the top of the for loop and try again with next char, 
            // note that it's not necessary to save the vector in any way 
            // since it did not have enough chars to be a possible plate
            continue; 
        }
        // if we get here, the current vector passed test as a "group" or "cluster" of matching chars
        // so add to our vector of vectors of matching chars
        vectorOfVectorsOfMatchingChars.push_back(vectorOfMatchingChars); 
        // remove the current vector of matching chars from the big vector 
        // so we don't use those same chars twice,
        // make sure to make a new big vector for this since 
        // we don't want to change the original big vector
        std::vector<PossibleChar> vectorOfPossibleCharsWithCurrentMatchesRemoved;

        for (auto &possChar : vectorOfPossibleChars)
        {
            if (std::find(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), possChar) == vectorOfMatchingChars.end())
            {
                vectorOfPossibleCharsWithCurrentMatchesRemoved.push_back(possChar);
            }
        }
        // declare new vector of vectors of chars to get result from recursive call
        std::vector<std::vector<PossibleChar>> recursiveVectorOfVectorsOfMatchingChars;

        // recursive call
        recursiveVectorOfVectorsOfMatchingChars = findVectorOfVectorsOfMatchingChars(vectorOfPossibleCharsWithCurrentMatchesRemoved); // recursive call !!

        for (auto &recursiveVectorOfMatchingChars : recursiveVectorOfVectorsOfMatchingChars)
        {   
            // for each vector of matching chars found by recursive call
            // add to our original vector of vectors of matching chars
            vectorOfVectorsOfMatchingChars.push_back(recursiveVectorOfMatchingChars); 
        }
        // exit for loop
        break; 
    }

    return vectorOfVectorsOfMatchingChars;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<PossibleChar> findVectorOfMatchingChars(const PossibleChar &possibleChar, 
                                    const std::vector<PossibleChar> &vectorOfChars)
{
    // the purpose of this function is, given a possible char and a big vector of possible chars,
    // find all chars in the big vector that are a match for the single possible char, 
    //and return those matching chars as a vector
    // this will be the return value
    std::vector<PossibleChar> vectorOfMatchingChars; 

    for (auto &possibleMatchingChar : vectorOfChars)
    { // for each char in big vector

        // if the char we attempting to find matches for is the exact same char as 
        // the char in the big vector we are currently checking
        if (possibleMatchingChar == possibleChar)
        {
            // then we should not include it in the vector of matches 
            //b/c that would end up double including the current char
            continue; 
            // so do not add to vector of matches and jump back to top of for loop
        }
        // compute stuff to see if chars are a match
        double dblDistanceBetweenChars = distanceBetweenChars(possibleChar, possibleMatchingChar);
        double dblAngleBetweenChars = angleBetweenChars(possibleChar, possibleMatchingChar);
        double dblChangeInArea = (double)abs(possibleMatchingChar.boundingRect.area() - 
                        possibleChar.boundingRect.area()) / (double)possibleChar.boundingRect.area();
        double dblChangeInWidth = (double)abs(possibleMatchingChar.boundingRect.width - 
                            possibleChar.boundingRect.width) / (double)possibleChar.boundingRect.width;
        double dblChangeInHeight = (double)abs(possibleMatchingChar.boundingRect.height - 
                            possibleChar.boundingRect.height) / (double)possibleChar.boundingRect.height;

        // check if chars match
        if (dblDistanceBetweenChars < (possibleChar.dblDiagonalSize * MAX_DIAG_SIZE_MULTIPLE_AWAY) &&
            dblAngleBetweenChars < MAX_ANGLE_BETWEEN_CHARS &&
            dblChangeInArea < MAX_CHANGE_IN_AREA &&
            dblChangeInWidth < MAX_CHANGE_IN_WIDTH &&
            dblChangeInHeight < MAX_CHANGE_IN_HEIGHT)
        {
            // if the chars are a match, add the current char to vector of matching chars
            vectorOfMatchingChars.push_back(possibleMatchingChar); 
        }
    }

    return vectorOfMatchingChars;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// use Pythagorean theorem to calculate distance between two chars
double distanceBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar)
{
    int intX = abs(firstChar.intCenterX - secondChar.intCenterX);
    int intY = abs(firstChar.intCenterY - secondChar.intCenterY);

    return (sqrt(pow(intX, 2) + pow(intY, 2)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// use basic trigonometry(SOH CAH TOA) to calculate angle between chars
double angleBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar)
{
    double dblAdj = abs(firstChar.intCenterX - secondChar.intCenterX);
    double dblOpp = abs(firstChar.intCenterY - secondChar.intCenterY);

    double dblAngleInRad = atan(dblOpp / dblAdj);

    double dblAngleInDeg = dblAngleInRad * (180.0 / CV_PI);

    return (dblAngleInDeg);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// if we have two chars overlapping or to close to each other to possibly be separate chars,
//  remove the inner (smaller) char,
// this is to prevent including the same char twice if two contours are found for the same char,
// for example for the letter 'O' both the inner ring and the outer ring may be found as contours, 
// but we should only include the char once
std::vector<PossibleChar> removeInnerOverlappingChars(std::vector<PossibleChar> &vectorOfMatchingChars)
{
    std::vector<PossibleChar> vectorOfMatchingCharsWithInnerCharRemoved(vectorOfMatchingChars);

    for (auto &currentChar : vectorOfMatchingChars)
    {
        for (auto &otherChar : vectorOfMatchingChars)
        {
            if (currentChar != otherChar)
            {   // if current char and other char are not the same char . . .
                // if current char and other char have center points at almost the same location . . .
                if (distanceBetweenChars(currentChar, otherChar) < 
                (currentChar.dblDiagonalSize * MIN_DIAG_SIZE_MULTIPLE_AWAY))
                {
                    // if we get in here we have found overlapping chars
                    // next we identify which char is smaller, then if 
                    // that char was not already removed on a previous pass, remove it

                    // if current char is smaller than other char
                    if (currentChar.boundingRect.area() < otherChar.boundingRect.area())
                    {
                        // look for char in vector with an iterator
                        std::vector<PossibleChar>::iterator currentCharIterator = 
                        std::find(vectorOfMatchingCharsWithInnerCharRemoved.begin(), 
                        vectorOfMatchingCharsWithInnerCharRemoved.end(), currentChar);
                        
                        // if iterator did not get to end, then the char was found in the vector
                        if (currentCharIterator != vectorOfMatchingCharsWithInnerCharRemoved.end())
                        {
                            // so remove the char
                            vectorOfMatchingCharsWithInnerCharRemoved.erase(currentCharIterator); 
                        }
                    }
                    else
                    {   // else if other char is smaller than current char
                        // look for char in vector with an iterator
                        std::vector<PossibleChar>::iterator otherCharIterator = std::find(vectorOfMatchingCharsWithInnerCharRemoved.begin(), vectorOfMatchingCharsWithInnerCharRemoved.end(), otherChar);
                        // if iterator did not get to end, then the char was found in the vector
                        if (otherCharIterator != vectorOfMatchingCharsWithInnerCharRemoved.end())
                        {
                            // so remove the char
                            vectorOfMatchingCharsWithInnerCharRemoved.erase(otherCharIterator); 
                        }
                    }
                }
            }
        }
    }

    return (vectorOfMatchingCharsWithInnerCharRemoved);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// this is where we apply the actual char recognition
std::string recognizeCharsInPlate(cv::Mat &imgThresh, std::vector<PossibleChar> &vectorOfMatchingChars, 
                                                                bool SHOW_STEPS)
{
    // this will be the return value, the chars in the lic plate
    std::string strChars; 
    cv::Mat imgThreshColor;

    // sort chars from left to right
    std::sort(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), 
                                    PossibleChar::sortCharsLeftToRight);

    // make color version of threshold image so we can draw contours in color on it
    cv::cvtColor(imgThresh, imgThreshColor, CV_GRAY2BGR); 

    for (auto &currentChar : vectorOfMatchingChars)
    {   
        // for each char in plate
        // draw green box around the char
        cv::rectangle(imgThreshColor, currentChar.boundingRect, SCALAR_GREEN, 2); 

        // get ROI image of bounding rect
        cv::Mat imgROItoBeCloned = imgThresh(currentChar.boundingRect); 

        // clone ROI image so we don't change original when we resize
        cv::Mat imgROI = imgROItoBeCloned.clone(); 

        cv::Mat imgROIResized;
        // resize image, this is necessary for char recognition
        cv::resize(imgROI, imgROIResized, cv::Size(RESIZED_CHAR_IMAGE_WIDTH, RESIZED_CHAR_IMAGE_HEIGHT));

        cv::Mat matROIFloat;

        // convert Mat to float, necessary for call to findNearest
        imgROIResized.convertTo(matROIFloat, CV_32FC1); 

        // flatten Matrix into one row
        cv::Mat matROIFlattenedFloat = matROIFloat.reshape(1, 1); 

        // declare Mat to read current char into, this is necessary b/c findNearest requires a Mat
        cv::Mat matCurrentChar(0, 0, CV_32F); 

        // finally we can call find_nearest !!!
        kNearest->findNearest(matROIFlattenedFloat, 1, matCurrentChar); 

        // convert current char from Mat to float
        float fltCurrentChar = (float)matCurrentChar.at<float>(0, 0); 

        // append current char to full string
        strChars = strChars + char(int(fltCurrentChar)); 
    }

    if (SHOW_STEPS)
    {
        cv::imshow("10", imgThreshColor);
    }

    // return result
    return strChars; 
}
