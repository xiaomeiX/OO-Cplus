/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  conVerGarS.cpp
 * This file contains the implementation of the conVerGarS class.
 *  which is-a conVerter and is-a garbledS.
 * -A conVerGarS object encapsulates string from both parents and will have different output
 *      based on an internal state
 * -Class invariants: encapsulates both an string,
 *      inheritance the both parents functionality.
 *      object will age out after a certain number of pings,
 *      will only return -1,which means this object need reset(),
 *      and call iSlogan::reset() directlly.
 *
 * -Certain members are virtual or protected in anticipation of future inheritance
 *
 * -Interface invariants: object can only becomes
 *      irretrievably inactive, object can be queried to return -1 if it's
 *      been reset();
 */

#include "conVerGarS.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
//Default constructor that uses both parent constructors for initialization
conVerGarS::conVerGarS(string message):garbledS(message), conVerter(message)
{
    
}
////Function that resets the active states from garbledS parent.
void conVerGarS::reset()
{
    garbledS::reset();
}

// Function is get function as interface for external class.
// function combined the output message from both parents.
string conVerGarS::getOutPutMessage(){
    
    return conVerter::getOutPutMessage()+ garbledS::getOutPutMessage();
    
}
////Function that update out put message from conVerter and RepS both parents;
//returns integer represent state
int conVerGarS::query(int val)
{
    conVerter::query(val);
    int r = garbledS::query(val);
    if (r ==-1) reset();
    return r;
}

//ID function
string conVerGarS::whoAmI()
{
    return  conVerter::myId + garbledS::myId ;
}

