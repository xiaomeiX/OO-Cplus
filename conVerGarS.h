/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  conVerRepS.h
 *
 *   This file contains the header definition of conVerGarS
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 * - prototype
 */

#ifndef conVerGarS_h
#define conVerGarS_h
#include "garbledS.h"
#include "conVerter.h"

#include <stdio.h>
class conVerGarS: public garbledS, public conVerter
{
public:
    conVerGarS(string);
    ~conVerGarS(){};
    void reset();
    int query(int);
    string whoAmI();
    string getOutPutMessage();
};

#endif /* iSloganConVert_h */
