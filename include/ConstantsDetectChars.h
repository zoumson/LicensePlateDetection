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
 * @file ConstantsDetectChars.h
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */



#ifndef CONSTANTS_DETECT_CHARS_H
#define CONSTANTS_DETECT_CHARS_H
#include <opencv2/ml.hpp>
namespace za {
/* ============================================================================
 * Global Constants
 * ============================================================================
 */

// Constants for checkIfPossibleChar, this checks one possible char 
// Only (does not compare to another char)
inline constexpr int MIN_PIXEL_WIDTH = 2;
inline constexpr int MIN_PIXEL_HEIGHT = 8;

inline constexpr double MIN_ASPECT_RATIO = 0.25;
inline constexpr double MAX_ASPECT_RATIO = 1.0;

inline constexpr int MIN_PIXEL_AREA = 80;

// Constants for comparing two chars
inline constexpr double MIN_DIAG_SIZE_MULTIPLE_AWAY = 0.3;
inline constexpr double MAX_DIAG_SIZE_MULTIPLE_AWAY = 5.0;

inline constexpr double MAX_CHANGE_IN_AREA = 0.5;

inline constexpr double MAX_CHANGE_IN_WIDTH = 0.8;
inline constexpr double MAX_CHANGE_IN_HEIGHT = 0.2;

inline constexpr double MAX_ANGLE_BETWEEN_CHARS = 12.0;

// Other constants
inline constexpr int MIN_NUMBER_OF_MATCHING_CHARS = 3;

inline constexpr int RESIZED_CHAR_IMAGE_WIDTH = 20;
inline constexpr int RESIZED_CHAR_IMAGE_HEIGHT = 30;

inline constexpr int MIN_CONTOUR_AREA = 100;

extern cv::Ptr<cv::ml::KNearest>  kNearest;
}
#endif	// CONSTANTS_DETECT_CHARS_H

