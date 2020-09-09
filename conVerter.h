/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/3/18.
 *  P4
 *  version 1
 *  conVerter.h
 *  This file contains the header definition of conVerter
 *    -several members are virtual or protected for future inheritance
 *    -virtual destructor defined here
 */

#ifndef conVerter_h
#define conVerter_h

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <sstream>

using namespace std;
class conVerter
{
protected:
    string message;
    string myId;
    int r;
private:
    string updateMessage;
    string tempMessage;
public:
    conVerter(string);
    virtual ~conVerter(){};
    //Puts the obj in active state
    virtual int query(int rVal);
    virtual string getOutPutMessage();
    virtual string whoAmI();
};
#endif /* conVerter_hpp */
