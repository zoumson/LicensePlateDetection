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
 * @file DetectChars.h
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */



#ifndef DETECT_CHARS_H
#define DETECT_CHARS_H

#include "ConstantsDetectChars.h"
#include "ConstantsIdentifyPlate.h"
#include "PossibleChar.h"
#include "PossiblePlate.h"
#include "Preprocess.h"

/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Load KNN data and train.
 *
 * \details Get KNN data from xml files and train KNN.
 *
 * \param classifierPath [in] classifier path, type is opencv String.
 * \param imageClassifiedPath [in] image classified path, type is String.
 *
 * \return #void
 * 
 * \attention add default values 
 * 
 */
bool loadKNNDataAndTrainKNN(cv::String classifierPath,
                            cv::String imageClassifiedPath);

/**
 * \brief Detect possible plate from a set of  possible plate.
 *
 * \details Detect possible plate from a set of  possible plate.
 *
 * \param cvectorOfPossiblePlates [in] classifier path, type is opencv String
 * \param SHOW_STEPS [in] show steps, type is obool
 *
 * \return #Possible plate, type is vector of PossiblePlate
 * 
 * \attention add default values 
 * 
 */
std::vector<PossiblePlate> detectCharsInPlates(std::vector<PossiblePlate> &vectorOfPossiblePlates, bool SHOW_STEPS);


/**
 * \brief Find possible characters in fa image.
 *
 * \details Find possible characters in fa image.
 *
 * \param imgGrayscale [in] gray scale image, type is opencv Mat.
 * \param imgThresh [in] threhold image, type is opencv Mat.
 *
 * \return #Possible character, type is vector of PossibleChar.
 * 
 * \attention add default values 
 * 
 */
std::vector<PossibleChar> findPossibleCharsInPlate(cv::Mat &imgGrayscale, cv::Mat &imgThresh);


/**
 * \brief Check if a detected element is character.
 *
 * \details Check if a detected element is character.
 *
 * \param possibleChar [in] a possible character, type is PossibleChar.
 *
 * \return #true if it is a character, false otherwise, type is vector of bool.
 * 
 * \attention add default values 
 * 
 */
bool checkIfPossibleChar(PossibleChar &possibleChar);

/**
 * \brief find vector of vectors of matching characters.
 *
 * \details find vector of vectors of matching characters.
 *
 * \param vectorOfPossibleChars [in] a possible character, type is vector of PossibleChar.
 *
 * \return #type is vector of vector of PossibleChar
 * 
 * \attention add default values 
 * 
 */
std::vector<std::vector<PossibleChar> > findVectorOfVectorsOfMatchingChars(const std::vector<PossibleChar> &vectorOfPossibleChars);

/**
 * \brief Find a group  of matching characters.
 *
 * \details Find all chars in the big vector that are a match for the single possible char.
 *
 * \param possibleChar [in] a possible character, type is PossibleChar.
 * \param vectorOfChars [in] set of possible characters, type is vector of PossibleChar.
 *
 * \return #type is vector of PossibleChar.
 * 
 * \attention 
 * 
 */
std::vector<PossibleChar> findVectorOfMatchingChars(const PossibleChar &possibleChar, const std::vector<PossibleChar> &vectorOfChars);

/**
 * \brief compute distance between characters.
 *
 * \details compute distance between characters.
 *
 * \param firstChar [in] a possible character, type is PossibleChar.
 * \param secondChar [in] a possible character, type is PossibleChar.
 *
 * \return #type is double.
 * 
 * \attention 
 * 
 */
double distanceBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);

/**
 * \brief compute angle between characters.
 *
 * \details compute angle between characters.
 *
 * \param firstChar [in] a possible character, type is PossibleChar.
 * \param secondChar [in] a possible character, type is PossibleChar.
 *
 * \return #type is vector of double.
 * 
 * \attention 
 * 
 */
double angleBetweenChars(const PossibleChar &firstChar, const PossibleChar &secondChar);

/**
 * \brief remove inner overlapping characters.
 *
 * \details Check if a detected element is character.
 *
 * \param vectorOfMatchingChars [in] a possible character, type is vector of PossibleChar.
 *
 * \return #type is vector of PossibleChar.
 * 
 * \attention  
 * 
 */
std::vector<PossibleChar> removeInnerOverlappingChars(std::vector<PossibleChar> &vectorOfMatchingChars);

/**
 * \brief recognize a character in a plate.
 *
 * \details recognize a character in a plate.
 *
 * \param imgThresh [in] an image threshold, type is opencv Mat
 * \param vectorOfMatchingChars [in] a matching characters, type is vector of PossibleChar
 * \param SHOW_STEPS [in] show steps, type is bool
 *
 * \return #type is string.
 * 
 * \attention 
 * 
 */
std::string recognizeCharsInPlate(cv::Mat &imgThresh, std::vector<PossibleChar> &vectorOfMatchingChars, bool SHOW_STEPS);


#endif	// DETECT_CHARS_H

