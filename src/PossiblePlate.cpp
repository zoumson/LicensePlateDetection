// PossiblePlate.cpp

#include "PossiblePlate.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
bool PossiblePlate::sortDescendingByNumberOfChars(const PossiblePlate &ppLeft, 
const PossiblePlate &ppRight) 
{
    return(ppLeft.strChars.length() > ppRight.strChars.length());
}
