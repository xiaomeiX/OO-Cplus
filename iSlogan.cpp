/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/3/18.
 *  P4
 *  version 1
 *  iSlogan.cpp
 * This file contains the class definition of iSlogan.
 * -A iSlogan object outputs its message;
 *      upon query with 1-digit value. It defines the public interface
 *      of a iSlogan object that can reset and query, also change
 *      the sequence definition.
 *
 *      CLASS INVARIANTS
 *      1)If ‘on’, an iSlogan object outputs its message,
 *        unless p = = q, where p is a stable 1-digit value that varies from object to object;
 *        its on/off state is toggled with every pth request
 *
 *      INTERFACE INVARIANTS
 *     @@ the q value is pass by the parameter of guery method
 *     @@ guery() function have return value, know as relVal
 *        So driver can get result for query:
 *         -- relVal = -1 // means obj is off, and reset()
 *         -- relVal = 1 // means obj is on and process the message successfully
 *         -- relVal = 99 // means obj is on, but q = p, no output needed.
 *         -- relVal = 0 // as initial
 *
 *     Using virtual query() function,
 *     so the its child class can override this function,
 *        to process heterogenerous collection
 *     virtual function: reSet()
 *                       query()
 *                       getOutputMessage()
 *                       whoAmI()
 *       for extension in descendant classes.
 *
 *    IMPLEMENTATION INVARIANTS
 *     @@ code reuse, base class using virtual funtion, once virtual always virtual.
 *     @@ less code replication: child own function not responsible for parent.
 *     @@ Efficiency.
 *
 *  Provide utility and flexibility function, and data hide,
 *      Designed by Open Close principle
 *      and LISKOV substitutability principle:
 *      child class object can stand in for a parent class object.
 *
 *
 */

#include "iSlogan.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

iSlogan::iSlogan( string inputMessage )
    {
        
        /* initialize random seed: */
        /* generate secret number between 1 and 9: */
        p = rand() % 8+2;
        message = inputMessage;
        numOnOff = 0;
        on = true;
        myId = "iSlogan";
        
    }

//Puts the obj in on/active state
void iSlogan::reset()
    {
        on = true;
        numOnOff =0;
    }
string iSlogan::getOutPutMessage()
{
    return message;
}

//Function to return integer represent the state
//PRECONDITION: no output will happen if object is inactive
//POSTCONDITION: object may become inactive
int iSlogan::query(int qVal)
    {
        int relVal=0;
        // q is 1-digit Value
        q = qVal % 10;
        numOnOff++;
        if ((numOnOff) % p == 0)
        {
            on = !on;
            
            if (!on)
            {
                
                relVal = -1;
                reset();
                return relVal;
            }
            
        }
        if (on)
        {
            
            if (p != q)
            {
                //printMessage();
                relVal = 1;
            }
            else if (p == q)
            {
                // p==q, no message pring out
                relVal = 99;
            }
        }
        
        else
        {
            relVal = -1; // off state
            reset();
        }
    
        return relVal;
}

//ID fundtion
string iSlogan::whoAmI(){
    
    return myId;
}



