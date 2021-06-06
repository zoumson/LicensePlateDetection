// PossibleChar.cpp
#include "PossibleChar.h"

namespace za {
///////////////////////////////////////////////////////////////////////////////////////////////////
PossibleChar::PossibleChar(std::vector<cv::Point> _contour) 
{
    contour = _contour;

    boundingRect = cv::boundingRect(contour);
    
    intCenterX = (boundingRect.x + boundingRect.x + boundingRect.width) / 2;
    intCenterY = (boundingRect.y + boundingRect.y + boundingRect.height) / 2;
    

    dblDiagonalSize = sqrt(pow(boundingRect.width, 2) + pow(boundingRect.height, 2));

    dblAspectRatio = (float)boundingRect.width / (float)boundingRect.height;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool PossibleChar::sortCharsLeftToRight(const PossibleChar &pcLeft, const PossibleChar & pcRight) 
{
    return(pcLeft.intCenterX < pcRight.intCenterX);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool PossibleChar::operator == (const PossibleChar& otherPossibleChar) const 
{
    return (this->contour == otherPossibleChar.contour); 
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool PossibleChar::operator != (const PossibleChar& otherPossibleChar) const 
{
    return (this->contour != otherPossibleChar.contour); 
}
}
