/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  iSlogan.h
 *
 *  This file contains the header definition of iSlogan
 *    -several members are virtual or protected for future inheritance
 *    -virtual destructor defined here
 */

#ifndef iSlogan_h
#define iSlogan_h
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
class iSlogan
{
    
protected:
    int q;
    string message;
    int index;
    int p;
    int numOnOff;
    bool on;
    string myId;

public:
    iSlogan(string);
    virtual ~iSlogan(){};
    //Puts the obj in active state
    virtual void reset();
    //Gets output from obj
    //POSTCONDITION: object may be inactive
    
    virtual int query(int qVal);
    virtual string getOutPutMessage();
    virtual string whoAmI();
};
#endif /* iSlogan_H_*/
