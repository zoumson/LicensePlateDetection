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
* \see <http://www.lsstcorp.org/LegalNotices/>.
*/

/**
 * @file Preprocess.h
 *
 * @brief Identify a plate number from image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */


#ifndef PREPROCESS_H
#define PREPROCESS_H

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include "ConstantsPreprocess.h"
namespace za {
/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Preprocess an image to get its 8-bits gray scale and 1-bit gray scale image.
 *
 * \details Get the 8-bits gray scale image first through HSV tranformation, 
 *          then use thresholding to get the 1-bit (white-black) gray scale image.
 *
 * \param imgOriginal [in] original image, type is opencv Mat
 * \param imgGrayscale [out] 8-bits gray scale image, type is opencv Mat
 * \param imgThresh [out] threshold or 1-bit gray scale image, type is opencv Mat
 *
 * \return type is void
 * 
 * \see extractImgGrayscale()
 * \see maximizeContrast()
 * \see opencv convertTo()
 * \see opencv GaussianBlur()
 * \see opencv adaptiveThreshold()
 * 
 * \attention For enhancing the image contrast used to get the 1-bit gray scale image 
 *            either opencv convertTo() or the custom function convertTo() can be used.
 */
void preprocess(cv::Mat &imgOriginal, cv::Mat &imgGrayscale, cv::Mat &imgThresh);

/**
 * \brief Extract 8-bits single channel 2D grayscale image from an 8-bits 3 channels BGR 2D image.
 *
 * \details Fist, the image is converted from BGR to HSV. 
 *          Then the 3 channels HSV image is splitted in 3 single channel image, H, S, and V.
 *          The last, third[0, 1, ->2], single channel image V is the gray scale image.
 *
 * \param imgOriginal [in] original image, type is opencv Mat
 *
 * \return grayscale image, type is opencv Mat.
 * 
 * \see opencv cvtColor()
 * \see opencv split()
 * 
 * \attention The opencv split() can either accepts either array or vector as argument. 
 * 
 */
cv::Mat extractImgGrayscale(cv::Mat &imgOriginal);

/**
 * \brief Maximize the contrast of an image.
 *
 * \details Maximize the contrast of an image by adding top hat and removing black from it.
 * 
 * \param imgGrayscale [in]original image, type is opencv Mat.
 *
 * \return image with higher contrast, type is opencv Mat
 * 
 * \see opencv convertTo()
 * 
 * \attention opencv convertTo() also adjusts an image contrast.
 * 
 */
cv::Mat maximizeContrast(cv::Mat &imgGrayscale);
}

#endif	// PREPROCESS_H

