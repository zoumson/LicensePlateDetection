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
 * @file ConstantsPreprocess.h
 *
 * @brief Identify a plate number from image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */

#ifndef CONSTANTS_PREPROCESS_H
#define CONSTANTS_PREPROCESS_H
#include<opencv2/core/types.hpp>
namespace za {
/* ============================================================================
 * Global Constants
 * ============================================================================
 */

const cv::Size GAUSSIAN_SMOOTH_FILTER_SIZE = cv::Size(5, 5);
inline constexpr int ADAPTIVE_THRESH_BLOCK_SIZE = 19;
inline constexpr int ADAPTIVE_THRESH_WEIGHT = 9;
}
#endif	// CONSTANTS_PREPROCESS_H

