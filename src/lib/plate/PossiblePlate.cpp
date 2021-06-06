// PossiblePlate.cpp

#include "PossiblePlate.h"
namespace za {
///////////////////////////////////////////////////////////////////////////////////////////////////
bool PossiblePlate::sortDescendingByNumberOfChars(const PossiblePlate &ppLeft, 
const PossiblePlate &ppRight) 
{
    return(ppLeft.strChars.length() > ppRight.strChars.length());
}
}
