/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  conVerRepS.h
 *
 *   This file contains the header definition of conVerRepS
 * - prototype
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 * -prototype
 */

#ifndef conVerRepS_h
#define conVerRepS_h

#include "repS.h"
#include "conVerter.h"

#include <stdio.h>
class conVerRepS: public repS, public conVerter
{
public:
    conVerRepS(string);
    ~conVerRepS(){};
    void reset();
    int query(int);
    string whoAmI();
    string getOutPutMessage();
};

#endif /* conVerRepS_h */
