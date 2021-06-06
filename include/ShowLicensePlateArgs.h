
/*
* License plate detection
* See COPYRIGHT file at the top of the source tree.
*
* This product includes software developed by the
* STARGUE Project (http://www.stargue.org/).
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the STARGUE License Statement and
* the GNU General Public License along with this program. If not,
* see <http://www.lsstcorp.org/LegalNotices/>.
*/

/**
 * @file ShowLicensePlateArgs.h
 *
 * @brief All the arguments used to detect an image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */



#ifndef SHOW_LICENSE_PLATE_ARGS_H
#define SHOW_LICENSE_PLATE_ARGS_H
namespace za {

/**
 * Implementation of a all arguemts used to detect an image.
 * All arguemts passed through the cmmand line are grouped in a single 
 * arguemt then passed to the function showLicensePlate
 */
template <typename ...> class ShowLicensePlateArgs;
template <typename A, typename B>
class ShowLicensePlateArgs<A, B>
{
protected:
    A imagePath_;
    A classifierPath_;
    A imageClassifiedPath_;
    A savePath_; 
    A saveName_;
    A saveExt_;
    B showDetectionSteps_;
    B saveImgWithDetectedPlate_;
public:

// Default Constructors
ShowLicensePlateArgs()
                        : imagePath_(), 
                        classifierPath_(),
                        imageClassifiedPath_(),
                        savePath_(),
                        saveName_(),
                        saveExt_(),                       
                        showDetectionSteps_(),
                        saveImgWithDetectedPlate_(){}

// Custom Constructor
ShowLicensePlateArgs(A _imagePath_, A _classifierPath_, 
                        A _imageClassifiedPath_, A _savePath_,
                        A _saveName_, A _saveExt_,B _showDetectionSteps_, 
                        B _saveImgWithDetectedPlate_)
                        : imagePath_(_imagePath_), 
                        classifierPath_(_classifierPath_),
                        imageClassifiedPath_(_imageClassifiedPath_),
                        savePath_(_savePath_),
                        saveName_(_saveName_),
                        saveExt_(_saveExt_),
                        showDetectionSteps_(_showDetectionSteps_),
                        saveImgWithDetectedPlate_(_saveImgWithDetectedPlate_){}



bool operator == (const ShowLicensePlateArgs<A, B>& obj) const 
{
 return (isASame(this->imagePath_, obj.imagePath_) &&
            isASame(this->classifierPath_, obj.classifierPath_)&&
                isASame(this->imageClassifiedPath_, obj.imageClassifiedPath_)&&
                  isASame(this->savePath_, obj.savePath_) &&
                    isASame(this->saveName_, obj.saveName_)&&
                isASame(this->saveExt_, obj.saveExt_)&&
                isBSame(this->showDetectionSteps_, obj.showDetectionSteps_)&&
        isBSame(this->saveImgWithDetectedPlate_, obj.saveImgWithDetectedPlate_));  
}



bool operator != (const ShowLicensePlateArgs<A, B>& obj) const 
{
 return !(isASame(this->imagePath_, obj.imagePath_) &&
            isASame(this->classifierPath_, obj.classifierPath_)&&
                isASame(this->imageClassifiedPath_, obj.imageClassifiedPath_)&&
                  isASame(this->savePath_, obj.savePath_) &&
                    isASame(this->saveName_, obj.saveName_)&&
                isASame(this->saveExt_, obj.saveExt_)&&
                isBSame(this->showDetectionSteps_, obj.showDetectionSteps_)&&
        isBSame(this->saveImgWithDetectedPlate_, obj.saveImgWithDetectedPlate_)); 
}


bool isASame (A compared1, A compared2) const
                            {
                                return (compared1 == compared2);
                            }


bool isBSame(B compared1, B compared2) const
                            {
                                return (compared1 == compared2);
                            }

// Setter and Getter imagePath

auto imagePath() const& -> const A& { return imagePath_; }

auto imagePath() &      -> A&       { return imagePath_; }

auto imagePath() &&     -> A&&      { return std::move(imagePath_); }

// Setter and Getter classifierPath
auto classifierPath() const& -> const A& 
                            { 
                                return classifierPath_; 
                            }
auto classifierPath() & -> A&       
                            { 
                                return classifierPath_; 
                            }
auto classifierPath() && -> A&&      
                            { 
                                return std::move(classifierPath_); 
                            }
// Setter and Getter imageClassifiedPath
auto imageClassifiedPath() const& -> const A& 
                            { 
                                return imageClassifiedPath_; 
                            }
auto imageClassifiedPath() & -> A&       
                            { 
                                return imageClassifiedPath_; 
                            }

auto imageClassifiedPath() && -> A&&      
                            { 
                                return std::move(imageClassifiedPath_); 
                            }
// Setter and Getter savePath

auto savePath() const& -> const A& { return savePath_; }

auto savePath() &      -> A&       { return savePath_; }

auto savePath() &&     -> A&&      { return std::move(savePath_); }

// Setter and Getter saveName
auto saveName() const& -> const A& 
                            { 
                                return saveName_; 
                            }
auto saveName() & -> A&       
                            { 
                                return saveName_; 
                            }
auto saveName() && -> A&&      
                            { 
                                return std::move(saveName_); 
                            }
// Setter and Getter saveExt
auto saveExt() const& -> const A& 
                            { 
                                return saveExt_; 
                            }
auto saveExt() & -> A&       
                            { 
                                return saveExt_; 
                            }

auto saveExt() && -> A&&      
                            { 
                                return std::move(saveExt_); 
                            }

// Setter and Getter showDetectionSteps
auto showDetectionSteps() const& -> const B& 
                            { 
                                return showDetectionSteps_; 
                            }

auto showDetectionSteps() & -> B&       
                            { 
                                return showDetectionSteps_; 
                            }

auto showDetectionSteps() && -> B&&      
                            { 
                                return std::move(showDetectionSteps_); 
                            }
// Setter and Getter saveImgWithDetectedPlate
auto saveImgWithDetectedPlate() const& -> const B& 
                            { 
                                return saveImgWithDetectedPlate_; 
                            }
auto saveImgWithDetectedPlate() & -> B&       
                            { 
                                return saveImgWithDetectedPlate_; 
                            }

auto saveImgWithDetectedPlate() && -> B&&      
                            { 
                                return std::move(saveImgWithDetectedPlate_); 
                            }
    
   
};
}
#endif  // SHOW_LICENSE_PLATE_ARGS_H
