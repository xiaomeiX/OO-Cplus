//
/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/3/18.
 *  P4
 *  version 1
 *  garbledS.h
 *
 * This file contains the header definition of garbledS
 *  -several members are virtual or protected for future inheritance
 *  -virtual destructor defined here
 */

#ifndef garbledS_h
#define garbledS_h
#include "iSlogan.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
#include <algorithm>/* time */

using namespace std;
class garbledS: public iSlogan
{
    
private:
    string updateMessage;
    
public:
    garbledS(string);
    virtual ~garbledS(){};
    //Puts the obj in on/active state
    void reset();
    int query(int qVal);
    string getOutPutMessage();
    string whoAmI();
};
#endif /* garbledS_H_*/
