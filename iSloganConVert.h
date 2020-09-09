/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/4/18.
 *  P4
 *  version 1
 *  iSloganConVert.h
  * -inherits multiply from iSlogan and conVerter
 */

#ifndef iSloganConVert_h
#define iSloganConVert_h
#include "iSlogan.h"
#include "conVerter.h"

#include <stdio.h>
class iSloganConVert: public iSlogan, public conVerter
{
public:
    iSloganConVert(string);
    ~iSloganConVert(){};
    void reset();
    int query(int);
    string whoAmI();
    string getOutPutMessage();
};

#endif /* iSloganConVert_h */
