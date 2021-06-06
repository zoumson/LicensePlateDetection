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
 * @file PossibleChar.h
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */

// PossibleChar.h

#ifndef POSSIBLE_CHAR_H
#define POSSIBLE_CHAR_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace za {
/**
 * Implementation of a Possible character for retrieving character
 *
 * A character is delimited by a rectangular area
 * the area itself has a center defined by a coordinate (x,y)
 * the rectangle diagonal length and aspect ratio are used to 
 * check whether the possible character is a real character or not
 *
 */
class PossibleChar 
{
public:
    /* ============================================================================
    * Data Memeber Declaration
    * ============================================================================
    */

    std::vector<cv::Point> contour;

    cv::Rect boundingRect;

    int intCenterX;
    int intCenterY;

    double dblDiagonalSize;
    double dblAspectRatio;

    /* ============================================================================
    * Member Function Declaration
    * ============================================================================
    */
   
    /**
     * \brief Custom constructor.
     *
     * \details Custom constructor.
     *
     * \param _contour [in] contour of an area, type is vector of opencv Point.
     *      *
     * \return #void
     * 
     * \attention 
     * 
     */
    PossibleChar(std::vector<cv::Point> _contour);

    /**
     * \brief sort characters from left to right.
     *
     * \details Get 4 vertices of a plate, then the rectangle with specified color. 
     *
     * \param pcLeft first compared possible characters, type is PossibleChar.
     * \param pcRight second compared possible characters, type is PossibleChar.
     *
     * \return #void
     * 
     * \attention 
     * 
     */
    static bool sortCharsLeftToRight(const PossibleChar &pcLeft, const PossibleChar & pcRight); 

    /**
     * \brief Check if two Possible characters are equal.
     *
     * \details Check if two Possible characters are equal.
     *
     * \param otherPossibleChar [in] compared possible characters, type is PossibleChar.
     *
     * \return # type is bool.
     * 
     * \attention 
     * 
     */
    bool operator == (const PossibleChar& otherPossibleChar) const; 
  

    /**
     * \brief Check if two Possible characters are different.
     *
     * \details Check if two Possible characters are different.
     *
     * \param otherPossibleChar [in] compared possible characters, type is PossibleChar.
     *
     * \return # type is bool.
     * 
     * \attention 
     * 
     */
    bool operator != (const PossibleChar& otherPossibleChar) const;

};
}
#endif  // POSSIBLE_CHAR_H

