#include "IdentifyPlate.h"

int main(int argc, char const *argv[]) 
{
   cv::String keys =
        "{i image |<none>           | input image path}"         
        "{c classifier |../ressource/xml/classifications.xml   | input classifier path}"         
        "{t train |../ressource/xml/images.xml                 | input trained images path}"         
        "{p path |../result/image/                 | save image detected with detected plate path}"                 
        "{p name |image                 | save image detected with detected plate name}"                 
        "{n ext |png                | save image detected with detected plate extension}"                 
        "{s show |false                 | show detection steps}"         
        "{v save |false                 | save image with detected plate}"         
        "{help h usage ?    |      | show help message}";      
  
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Car license plate detection");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }
    bool hasImagePath = parser.has("image");
    cv::String imagePath = parser.get<cv::String>("image"); 
    cv::String classifierPath = parser.get<cv::String>("classifier"); 
    cv::String trainImagePath = parser.get<cv::String>("train"); 
    cv::String savePath = parser.get<cv::String>("path"); 
    cv::String saveName = parser.get<cv::String>("name"); 
    cv::String saveExt = parser.get<cv::String>("ext"); 
    bool showDetectionSteps = parser.get<bool>("show"); 
    bool saveImgWithDetectedPlate = parser.get<bool>("save"); 
      

    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }


    ShowLicensePlateArgs<cv::String, bool> showLicensePlateArgs(imagePath, classifierPath, 
                            trainImagePath,  savePath,saveName,saveExt, 
                            showDetectionSteps, saveImgWithDetectedPlate);

    showLicensePlate(showLicensePlateArgs);

    return 0;
}


