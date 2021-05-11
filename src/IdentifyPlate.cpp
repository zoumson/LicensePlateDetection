#include "IdentifyPlate.h"

int showLicensePlate(ShowLicensePlateArgs<cv::String, bool>  &showLicensePlateArgs)
{
 
    cv::String imagePath = showLicensePlateArgs.imagePath();
    cv::String classifierPath = showLicensePlateArgs.classifierPath();
    cv::String trainImagePath = showLicensePlateArgs.imageClassifiedPath();

    const char *savePath = showLicensePlateArgs.savePath().c_str();
    const char *saveName = showLicensePlateArgs.saveName().c_str();
    const char *ext = showLicensePlateArgs.saveExt().c_str();

    bool showDetectionSteps =  showLicensePlateArgs.showDetectionSteps();
    bool saveImgWithDetectedPlate = showLicensePlateArgs.saveImgWithDetectedPlate();

    // attempt KNN training
    bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN(classifierPath,
    trainImagePath) ;          
    
    // KNN training fail
   
    if (!blnKNNTrainingSuccessful) 
    {                                                                                                                                      // show error message
        std::cout << "\n\nerror: error: KNN traning was not successful\n\n";
        return 1;                                                      
    }
    
    // Input image
    cv::Mat imgOriginalScene;

    // Open image
    imgOriginalScene = cv::imread(imagePath);       

    // Unable to open image
    if (imgOriginalScene.empty()) 
    {                                                          
        std::cout << "error: image not read from file\n\n";                                                    
        return 2;                                              
    }

    // Array of possible plates

    std::vector<PossiblePlate> vectorOfPossiblePlates;   

    // Detect plates
    vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene, showDetectionSteps);          
    
    // Detect characters in plates
    vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates, showDetectionSteps);
            
    // Show scene image
    // cv::imshow("imgOriginalScene", imgOriginalScene);           

    //No plates found
    if (vectorOfPossiblePlates.empty()) 
    {                                               
        std::cout << "\nno license plates were detected\n";
        return 3;      
    }
     // At leat one plate found
    else 
    {                                                                                        
        // sort the vector of possible plates in DESCENDING order 
        // (most number of chars to least number of chars)
        std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), 
                    PossiblePlate::sortDescendingByNumberOfChars);

        // suppose the plate with the most recognized chars 
        // (the first plate in sorted by string length descending order) is the actual plate
        PossiblePlate licPlate = vectorOfPossiblePlates.front();
        // show crop of plate and threshold of plate
        //cv::imshow("imgPlate", licPlate.imgPlate);            
        //cv::imshow("imgThresh", licPlate.imgThresh);

        // No characters found in the plate
        if (licPlate.strChars.length() == 0) 
        {                                                      
            std::cout << "\nno characters were detected\n\n";     
            return 4;                                                                              
        }

        // Define rectangle color around plate
        cv::Scalar drawRedRectangleAroundPlateColor;

        // Set rectanle around plate color
        drawRedRectangleAroundPlateColor =  SCALAR_RED;

        // Draw rectangle around plate
        drawRedRectangleAroundPlate(imgOriginalScene, licPlate, drawRedRectangleAroundPlateColor);                // draw red rectangle around plate
        
        // write license plate text to std out
        std::cout << "\n-----------------------------------------\n";
        std::cout << "\nlicense plate read from image = " << licPlate.strChars << "\n";     
        std::cout << "\n-----------------------------------------\n";

        // write license plate text on the image
        writeLicensePlateCharsOnImage(imgOriginalScene, licPlate);              

        // Re-show scene image
        cv::imshow("Plate Identified", imgOriginalScene);
        
        // Write image out to file
        if(saveImgWithDetectedPlate) 
        {
            char *now = new char[32];
            //char savePath[32] = "../result/image";
            //char saveName[32] = "image";
            //char ext[6] = "png";
            char filename[1024];
            getCurrentTime(now);
            sprintf(filename, "%s/%s_%s.%s", savePath, saveName, now, ext);
            //std::cout<< filename;
            cv::imwrite(filename, imgOriginalScene);  
        } 
        
                       
    }

    // hold windows open until user presses a key
    cv::waitKey(0);
    return 0;       
}


void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate, cv::Scalar color) 
{
    cv::Point2f p2fRectPoints[4];
    // get 4 vertices of rotated rect
    licPlate.rrLocationOfPlateInScene.points(p2fRectPoints);
    /*    Line1:    0----->1     0 and (0 + 1)%4 = 1
          Line2:           1     1 and (1 + 1)%2 = 2         
                           |         
                           |         
                           v
                           2
          Line3:    3<-----2     2 and (2 + 1)%4 = 3 
          Line4:    0            3 and (3 + 1)%4 = 0         
                    ^         
                    |         
                    |         
                    3                
    */
    // draw 4 red lines
    for (int i = 0; i < 4; i++) 
    {                                       
        cv::line(imgOriginalScene, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], color, 2);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) 
{
    // this will be the center of the area the text will be written to
    cv::Point ptCenterOfTextArea;                  
    
    // this will be the bottom left of the area that the text will be written to
    cv::Point ptLowerLeftTextOrigin;                

    // choose a plain jane font
    int intFontFace = CV_FONT_HERSHEY_SIMPLEX;                              

    // base font scale on height of plate area
    double dblFontScale = (double)licPlate.imgPlate.rows / 30.0;   

    // base font thickness on font scale        
    int intFontThickness = (int)std::round(dblFontScale * 1.5);             
    int intBaseline = 0;

    // call getTextSize
    cv::Size textSize = cv::getTextSize(licPlate.strChars, intFontFace, dblFontScale, 
                intFontThickness, &intBaseline);      

    // the horizontal location of the text area is the same as the plate
    ptCenterOfTextArea.x = (int)licPlate.rrLocationOfPlateInScene.center.x;  

    // if the license plate is in the upper 3/4 of the image
     // write the chars in below the plate
    if (licPlate.rrLocationOfPlateInScene.center.y < (imgOriginalScene.rows * 0.75)) 
    {      
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) + 
                                    (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }
    else 
    {   // else if the license plate is in the lower 1/4 of the image
         // write the chars in above the plate
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) - 
                                    (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }

    // calculate the lower left origin of the text area
    ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2)); 

    // based on the text area center, width, and height          
    ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y + (textSize.height / 2));          

     // write the text on the image
    cv::putText(imgOriginalScene, licPlate.strChars, ptLowerLeftTextOrigin, intFontFace, dblFontScale,
                 SCALAR_YELLOW, intFontThickness);
}

void getCurrentTime(char *response)
{
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%d_%m_%Y_%H_%M_%S", ptm); 
    strcpy(response, buffer);
}
