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
 * @file Main.h
 *
 * @brief Identify a plate number from image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */

#ifndef IDENTIFY_PLATE_H         
#define IDENTIFY_PLATE_H

#include<opencv2/imgproc/imgproc_c.h>
#include "DetectPlates.h"
#include "ShowLicensePlateArgs.h"
#include <iostream>
         

/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Show a detected plate on an image.
 *
 * \details The input image is processed, then if a plate is detected a rectangle is drawn around it. 
 *
 * \param showLicensePlateArgs [in] argument of the function, type is ShowLicensePlateArgs
 *
 * \return #error code, type is int
 * 
 * \see ShowLicensePlateArgs
 * 
 */
int showLicensePlate(ShowLicensePlateArgs<cv::String, bool> &showLicensePlateArgs);
/**
 * \brief Draw rectangle around a plate.
 *
 * \details Get 4 vertices of a plate, then the rectangle with specified color. 
 *
 * \param imgOriginalScene [in][out] original image, type is opencv Mat.
 * \param licPlate [in] license plate, type is PossiblePlate.
 * \param color [in] rectangle lines color, type is opencv Scalar.
 *
 * \return #void
 * 
 * \attention licPlate has 4 vertices
 * 
 */
void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate, cv::Scalar color);

/**
 * \brief Draw rectangle around a plate.
 *
 * \details Get 4 vertices of a plate, then the rectangle with specified color. 
 *
 * \param imgOriginalScene [in][out] original image, type is opencv Mat.
 * \param licPlate [in] license plate, type is PossiblePlate.
 *
 * \return #void
 * 
 * \attention licPlate has 4 vertices
 * 
 */
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate);

/**
 * \brief Identify license plate from an image, show it on the original image.
 *
 * \details Identify license plate from an image, show it on the original image.
 *          Save the new image with license plate upon user requests.
 *
 * \param imgOriginalScene [in][out] original image, type is opencv Mat.
 * \param licPlate [in] license plate, type is PossiblePlate.
 *
 * \return #void
 * 
 * \attention licPlate has 4 vertices
 * 
 */
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate);



void getCurrentTime(char *now);

# endif	// IDENTIFY_PLATE_H

