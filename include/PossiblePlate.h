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
 * @file PossiblePlate.h
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */


#ifndef POSSIBLE_PLATE_H
#define POSSIBLE_PLATE_H

#include <string>
#include<opencv2/imgproc.hpp>

/**
 * Implementation of a Possible Plate for sorting
 *
 * A character is delimited by a rectangular area
 * the area itself has a center defined by a coordinate (x,y)
 * the rectangle diagonal length and aspect ratio are used to 
 * check whether the possible character is a real character or not
 *
 */
class PossiblePlate 
{
    public:

    /* ============================================================================
    * Data Memeber Declaration
    * ============================================================================
    */
    cv::Mat imgPlate;
    cv::Mat imgGrayscale;
    cv::Mat imgThresh;

    cv::RotatedRect rrLocationOfPlateInScene;

    std::string strChars;

    /* ============================================================================
    * Member Function Declaration
    * ============================================================================
    */       

    /**
     * \brief Sort two possible plates descending.
     *
     * \details Get each possible plate characters length, then compare
     *
     * \param ppLeft [in] first compared possible character, type is PossiblePlate.
     * \param ppRight [in] second compared possible character, type is PossiblePlate.
     *
     * \return #bool
     * 
     * \attention sort by string length
     * 
     */
    static bool sortDescendingByNumberOfChars(const PossiblePlate &ppLeft, const PossiblePlate &ppRight); 

};


#endif// POSSIBLE_PLATE_H

