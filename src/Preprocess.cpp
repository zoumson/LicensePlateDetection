// Preprocess.cpp

#include "Preprocess.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void preprocess(cv::Mat &imgOriginal, cv::Mat &imgGrayscale, cv::Mat &imgThresh) 
{
    // Extract value channel only from original image to get imgGrayscale
    imgGrayscale = extractImgGrayscale(imgOriginal);   

    // Maximize contrast with top hat and black hat
    // Try different method to maximize contrast
    
    double alpha = 1; /*< Simple contrast control [1.0-3.0] */ 
    int beta = 0;       /*< Simple brightness control [0-100] */
    cv::Mat imgMaxContrastGrayscale;      
    imgGrayscale.convertTo(imgMaxContrastGrayscale, -1, alpha, beta); 
    //cv::Mat imgMaxContrastGrayscale = maximizeContrast(imgGrayscale);       

    cv::Mat imgBlurred;

    // Gaussian blur
    cv::GaussianBlur(imgMaxContrastGrayscale, imgBlurred, GAUSSIAN_SMOOTH_FILTER_SIZE, 0);          

    // Call adaptive threshold to get imgThresh, 8 bits transfomed to 1 bit                                                                                         
    cv::adaptiveThreshold(imgBlurred, imgThresh, 255.0, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY_INV, ADAPTIVE_THRESH_BLOCK_SIZE, ADAPTIVE_THRESH_WEIGHT);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
cv::Mat extractImgGrayscale(cv::Mat &imgOriginal) 
{
    cv::Mat imgHSV;
    std::vector<cv::Mat> vectorOfHSVImages;
    cv::Mat imgValue;

    //Convert an original image the an image in the HSV color space.
    cv::cvtColor(imgOriginal, imgHSV, CV_BGR2HSV);

    //Split 3 channels image into 3 images of single channel
    cv::split(imgHSV, vectorOfHSVImages);
    /*
    HSV = Hue-Saturation-Value

    What Is Hue?
    Hues are the three primary colors (red, blue, and yellow) and 
    the three secondary colors (orange, green, and violet) that 
    appear in the color wheel or color circle. 
    When you refer to hue, you are referring to pure color, or 
    the visible spectrum of basic colors that can be seen in a rainbow.

    Range: normal[0-360], opencv[0-180] => using 8bits only offer 0-255 
    Ex: vectorOfHSVImages[0];

    What Is Saturation?
    Color saturation is the purity and intensity of a color as displayed 
    in an image. The higher the saturation of a color, the more vivid and 
    intense it is. The lower a color’s saturation, or chroma, the closer 
    it is to pure gray on the grayscale. 

    Range: [0-255]
    Ex: vectorOfHSVImages[1];

    What Is Color Value?
    Color value refers to the relative lightness or darkness of a color. 
    We perceive color value based on the quantity of light reflected off 
    of a surface and absorbed by the human eye. We refer to the intensity 
    of the light that reaches the eye as “luminance.”

    Range: [0-255]
    Ex: vectorOfHSVImages[2];
    */
    imgValue = vectorOfHSVImages[2];

    return imgValue;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
cv::Mat maximizeContrast(cv::Mat &imgGrayscale) 
{
    cv::Mat imgTopHat;
    cv::Mat imgBlackHat;
    cv::Mat imgGrayscalePlusTopHat;
    cv::Mat imgGrayscalePlusTopHatMinusBlackHat;

    cv::Mat structuringElement = cv::getStructuringElement(CV_SHAPE_RECT, cv::Size(3, 3));

    cv::morphologyEx(imgGrayscale, imgTopHat, CV_MOP_TOPHAT, structuringElement);
    cv::morphologyEx(imgGrayscale, imgBlackHat, CV_MOP_BLACKHAT, structuringElement);

    imgGrayscalePlusTopHat = imgGrayscale + imgTopHat;
    imgGrayscalePlusTopHatMinusBlackHat = imgGrayscalePlusTopHat - imgBlackHat;

    return imgGrayscalePlusTopHatMinusBlackHat;
}


