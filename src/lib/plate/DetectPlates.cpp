
#include "DetectPlates.h"
namespace za {
std::vector<za::PossiblePlate> detectPlatesInScene(cv::Mat &imgOriginalScene, bool SHOW_STEPS) 
{
    // Return value
    std::vector<za::PossiblePlate> vectorOfPossiblePlates;			

    cv::Mat imgGrayscaleScene;
    cv::Mat imgThreshScene;
    cv::Mat imgContours(imgOriginalScene.size(), CV_8UC3, za::SCALAR_BLACK);

    cv::RNG rng;

    cv::destroyAllWindows();

if (SHOW_STEPS)
{
    std::cout << "step 0 - Display of the original image\n";        
    cv::imshow("0", imgOriginalScene);
}
    // Preprocess to get grayscale and threshold images
za::preprocess(imgOriginalScene, imgGrayscaleScene, imgThreshScene);        

if(SHOW_STEPS)
{
    std::cout << "step 1 - Display of (a) 8-bits gray scale image (b) 1-bit gray scale image\n";        
    cv::imshow("1. (a)", imgGrayscaleScene);
    cv::imshow("1. (b)", imgThreshScene);
}
    // Find all possible chars in the scene
    // This function first finds all contours
    // Then only includes contours that could be chars (without comparison to other chars yet)
    std::vector<za::PossibleChar> vectorOfPossibleCharsInScene = 
                                findPossibleCharsInScene(imgThreshScene,SHOW_STEPS);

if (SHOW_STEPS)
{
    // 131 with MCLRNF1 image
    std::cout << "step 2 - vectorOfPossibleCharsInScene.Count = " 
              << vectorOfPossibleCharsInScene.size() << "\n";       

    imgContours = cv::Mat(imgOriginalScene.size(), CV_8UC3, za::SCALAR_BLACK);
    std::vector<std::vector<cv::Point> > contours;

    for (auto &possibleChar : vectorOfPossibleCharsInScene) 
    {
        contours.push_back(possibleChar.contour);
    }
    cv::drawContours(imgContours, contours, -1, za::SCALAR_WHITE);
    cv::imshow("2", imgContours);

}
    // Given a vector of all possible chars
    // Find groups of matching chars
    // In the next steps each group of matching chars will attempt 
    // To be recognized as a plate
    std::vector<std::vector<za::PossibleChar> > vectorOfVectorsOfMatchingCharsInScene = 
                za::findVectorOfVectorsOfMatchingChars(vectorOfPossibleCharsInScene);

if (SHOW_STEPS)
{
    // 13 with MCLRNF1 image
    std::cout << "step 3 - vectorOfVectorsOfMatchingCharsInScene.size() = " 
              << vectorOfVectorsOfMatchingCharsInScene.size() <<"\n";        

    imgContours = cv::Mat(imgOriginalScene.size(), CV_8UC3, za::SCALAR_BLACK);

    for (auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingCharsInScene) 
    {
        int intRandomBlue = rng.uniform(0, 256);
        int intRandomGreen = rng.uniform(0, 256);
        int intRandomRed = rng.uniform(0, 256);

        std::vector<std::vector<cv::Point> > contours;

        for (auto &matchingChar : vectorOfMatchingChars) 
        {
            contours.push_back(matchingChar.contour);
        }
        cv::drawContours(imgContours, contours, -1, 
                        cv::Scalar((double)intRandomBlue, 
                        (double)intRandomGreen, 
                        (double)intRandomRed));
    }
    cv::imshow("3", imgContours);
}

    for (auto &vectorOfMatchingChars : vectorOfVectorsOfMatchingCharsInScene) 
    {   // For each group of matching chars attempt to extract plate
	    za::PossiblePlate possiblePlate = extractPlate(imgOriginalScene, vectorOfMatchingChars);    

        if (possiblePlate.imgPlate.empty() == false) 
        {   // If plate was found
            // Add to vector of possible plates
            vectorOfPossiblePlates.push_back(possiblePlate);                                        
        }
    }
     // 13 with MCLRNF1 image
    std::cout <<"\n"<< vectorOfPossiblePlates.size() << " possible plates found\n";      

if (SHOW_STEPS)
{
    std::cout << "Step 4 - \n";
    cv::imshow("4a", imgContours);

    for (unsigned int i = 0; i < vectorOfPossiblePlates.size(); i++) 
    {
        cv::Point2f p2fRectPoints[4];

        vectorOfPossiblePlates[i].rrLocationOfPlateInScene.points(p2fRectPoints);

        for (int j = 0; j < 4; j++) 
        {
            cv::line(imgContours, p2fRectPoints[j], p2fRectPoints[(j + 1) % 4], za::SCALAR_RED, 2);
        }
        cv::imshow("4a", imgContours);

        std::cout << "possible plate " << i << ", click on any image and press a key to continue . . .\n";

        cv::imshow("4b", vectorOfPossiblePlates[i].imgPlate);
        cv::waitKey(0);
    }
    std::cout  << "\nplate detection complete, click on any image and press a key "
               <<"to begin char recognition . . .\n\n";
               
    cv::waitKey(0);

}
    return vectorOfPossiblePlates;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<za::PossibleChar> findPossibleCharsInScene(cv::Mat &imgThresh, bool SHOW_STEPS) 
{
    // Return value
    std::vector<za::PossibleChar> vectorOfPossibleChars;            

    cv::Mat imgContours(imgThresh.size(), CV_8UC3, za::SCALAR_BLACK);
    int intCountOfPossibleChars = 0;

    cv::Mat imgThreshCopy = imgThresh.clone();

    std::vector<std::vector<cv::Point> > contours;

    // find all contours
    cv::findContours(imgThreshCopy, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);        

    for (unsigned int i = 0; i < contours.size(); i++) 
    {    // for each contour        
        if (SHOW_STEPS)
        {
            cv::drawContours(imgContours, contours, i, za::SCALAR_WHITE);
        }
 
	za::PossibleChar possibleChar(contours[i]);

        // if contour is a possible char, note this does not compare to other chars (yet) . . .
        // increment count of possible chars
        // and add to vector of possible chars
        if (checkIfPossibleChar(possibleChar)) 
        {                
            intCountOfPossibleChars++;                          
            vectorOfPossibleChars.push_back(possibleChar);      
        }
    }

if (SHOW_STEPS)
{
    // 2362 with MCLRNF1 image
    std::cout << "\ncontours.size() = " << contours.size() << "\n"; 
    // 2362 with MCLRNF1 image
    std::cout << "\nstep 2 - intCountOfValidPossibleChars = " << intCountOfPossibleChars << "\n";
    // 131 with MCLRNF1 image
    cv::imshow("2a", imgContours);
}
                            

    return vectorOfPossibleChars;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
za::PossiblePlate extractPlate(cv::Mat &imgOriginal, std::vector<za::PossibleChar> &vectorOfMatchingChars) {
	za::PossiblePlate possiblePlate;            // this will be the return value

                                            // sort chars from left to right based on x position
    std::sort(vectorOfMatchingChars.begin(), vectorOfMatchingChars.end(), za::PossibleChar::sortCharsLeftToRight);

    // calculate the center point of the plate
    double dblPlateCenterX = (double)(vectorOfMatchingChars[0].intCenterX + 
                vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterX) / 2.0;
    double dblPlateCenterY = (double)(vectorOfMatchingChars[0].intCenterY + 
                vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterY) / 2.0;
    cv::Point2d p2dPlateCenter(dblPlateCenterX, dblPlateCenterY);

    // calculate plate width and height
    int intPlateWidth = (int)((vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].boundingRect.x + 
    vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].boundingRect.width - 
    vectorOfMatchingChars[0].boundingRect.x) * za::PLATE_WIDTH_PADDING_FACTOR);

    double intTotalOfCharHeights = 0;

    for (auto &matchingChar : vectorOfMatchingChars) 
    {
        intTotalOfCharHeights = intTotalOfCharHeights + matchingChar.boundingRect.height;
    }

    double dblAverageCharHeight = (double)intTotalOfCharHeights / vectorOfMatchingChars.size();

    int intPlateHeight = (int)(dblAverageCharHeight * za::PLATE_HEIGHT_PADDING_FACTOR);

    // calculate correction angle of plate region
    double dblOpposite = vectorOfMatchingChars[vectorOfMatchingChars.size() - 1].intCenterY - 
    vectorOfMatchingChars[0].intCenterY;

    double dblHypotenuse = distanceBetweenChars(vectorOfMatchingChars[0], 
    vectorOfMatchingChars[vectorOfMatchingChars.size() - 1]);

    double dblCorrectionAngleInRad = asin(dblOpposite / dblHypotenuse);
    double dblCorrectionAngleInDeg = dblCorrectionAngleInRad * (180.0 / CV_PI);

    // assign rotated rect member variable of possible plate
    possiblePlate.rrLocationOfPlateInScene = cv::RotatedRect(p2dPlateCenter, 
    cv::Size2f((float)intPlateWidth, (float)intPlateHeight), (float)dblCorrectionAngleInDeg);

    // final steps are to perform the actual rotation
    cv::Mat rotationMatrix;             
    cv::Mat imgRotated;
    cv::Mat imgCropped;

    // get the rotation matrix for our calculated correction angle
    rotationMatrix = cv::getRotationMatrix2D(p2dPlateCenter, dblCorrectionAngleInDeg, 1.0);         

    // rotate the entire image
    cv::warpAffine(imgOriginal, imgRotated, rotationMatrix, imgOriginal.size());            

     // crop out the actual plate portion of the rotated image
    cv::getRectSubPix(imgRotated, possiblePlate.rrLocationOfPlateInScene.size, possiblePlate.rrLocationOfPlateInScene.center, imgCropped);

    // copy the cropped plate image into the applicable member variable of the possible plate
    possiblePlate.imgPlate = imgCropped;            

    return possiblePlate;
}
}
