/*
*  Fall_CS3200_P4
*  Created by Xiaomei Xie
*  on 11/5/18.
*  P4
*  version 1
*  conVerRepS.cpp
*
** This file contains the implementation of the conVerRepS class.
*  which is-a conVerter and is-a RepS.
* -A conVerRepS object encapsulates string from both parents and will have different output
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

#include "conVerRepS.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
//Default constructor that uses both parent constructors for initialization
conVerRepS::conVerRepS(string message):repS(message), conVerter(message)
{
    
}
//Function that resets the active states from repS
void conVerRepS::reset()
{
    repS::reset();
}

// Function is get function as interface for external class.
// function combined the output message from both parents.
string conVerRepS::getOutPutMessage(){
    
    return conVerter::getOutPutMessage()+ repS::getOutPutMessage();
    
}
//Function that update out put message from conVerter and RepS both parents;
//returns integer represent state
int conVerRepS::query(int val)
{
    conVerter::query(val);
    int r = repS::query(val);
    if (r ==-1) reset();
    return r;
}

//ID function
string conVerRepS::whoAmI()
{
    return  conVerter::myId + repS::myId ;
}

