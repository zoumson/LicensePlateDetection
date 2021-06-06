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
 * @file DetectPlates.h
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */

#ifndef DETECT_PLATES_H
#define DETECT_PLATES_H

#include "ConstantsDetectPlates.h"
#include "DetectChars.h"
namespace za {

/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Detect plates in a image.
 *
 * \details Scan all the possible plates in a image
 *
 * \param imgOriginalScene [in][out] original image, type is opencv Mat.
 * \param SHOW_STEPS [in] show detection steps, type is bool.
 *
 * \return #Vector of possible plates detected in input image, type is vector of PossiblePlate.
 * 
 * \attention default SHOW_STEPS is false.
 * 
 */
std::vector<za::PossiblePlate> detectPlatesInScene(cv::Mat &imgOriginalScene, bool SHOW_STEPS); 

/**
 * \brief Find possible characters in a image.
 *
 * \details Scan all the possible characters in a image based on the analyse of small sections. 
 *
 * \param imgThresh [in] original threshold, type is opencv Mat.
 * \param SHOW_STEPS [in] show detection steps, type is bool.
 *
 * \return #Vector os possible characters detected in input image.
 * 
 * \attention default SHOW_STEPS is false.
 * 
 */
std::vector<za::PossibleChar> findPossibleCharsInScene(cv::Mat &imgThresh, bool SHOW_STEPS);

/**
 * \brief Extract plate from a image.
 *
 * \details Use a matching character to extract plate.
 *
 * \param imgOriginal[in] original image, type is opencv Mat.
 * \param vectorOfMatchingChars [in] contains a matching characters, type is vector of PosssibleChar.
 * 
 * \return #type is PossiblePlate.
 * 
 * \attention 
 * 
 */
za::PossiblePlate extractPlate(cv::Mat &imgOriginal, std::vector<za::PossibleChar> &vectorOfMatchingChars);

}
# endif	// DETECT_PLATES_H

