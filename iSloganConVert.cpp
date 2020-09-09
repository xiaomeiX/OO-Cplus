/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/4/18.
 *  P4
 *  version 1
 *  iSloganConVert.cpp
 *
 * * This file contains the implementation of the iSloganConVert class.
 *   which is-a conVerter and is-a iSlogan.
 * -A iSloganConVert object combines the functionality of the iSlogan class
 *      and conVerter class
 * -Class invariants: encapsulates both an string with iSlogan and ConVerter functionality
 *      and a string available for output.
 *      @@ object will age out after a certain number of pings,
 *      will only return -1,which means this object need reset(),
 *      and call iSlogan::reset() directlly.
 * -Interface invariants: subordinates conVerter query() function which only returns
 *      1 if output a sequence of ASCII depend on the first r alphanumeric char,
 *       in favor of supporting iSlogan query() function which gets output message depend on
 *      the control state.
 */

#include "iSloganConVert.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
//Default constructor that uses both parent constructors for initialization
iSloganConVert::iSloganConVert(string message):iSlogan(message), conVerter(message)
{
    
}
//Function that resets the active states for iSlogan parent.
void iSloganConVert::reset()
{
    iSlogan::reset();
}

// Function is get function as interface for external class.
// function combined the output message from both parents.
string iSloganConVert::getOutPutMessage(){
    
    return conVerter::getOutPutMessage()+ iSlogan::getOutPutMessage();
    
}

//Function that update out put message from conVerter and RepS both parents;
//returns integer represent state
int iSloganConVert::query(int val)
{
    conVerter::query(val);
    int r = iSlogan::query(val);
    if (r ==-1) reset();
    return r;
}

//ID function
string iSloganConVert::whoAmI()
{
    return iSlogan::myId + conVerter::myId;
}


