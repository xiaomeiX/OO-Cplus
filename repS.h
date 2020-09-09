/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  repS.h
 *  This file contains the header definition of repS
 *    -several members are virtual or protected for future inheritance
 *    -virtual destructor defined here
 */

#ifndef repS_h
#define repS_h

#include "iSlogan.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
#include <algorithm>/* time */
#include <string.h>

using namespace std;
class repS: public iSlogan
{
    
private:
    int k;
    string subString;
    string newMessage;
    bool isTerminated;
    int countK;
    string getRepeats(string subString);

public:
    repS(string);
    virtual ~repS(){};
    //Puts the obj in on/active state
    void reset();
    int query(int qVal);
     string getOutPutMessage();
    bool terminated();
    string whoAmI();
    
};
#endif /* repS_H_*/
