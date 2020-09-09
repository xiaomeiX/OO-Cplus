/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/5/18.
 *  P4
 *  version 1
 *  repS.cpp
 *
 * * This file contains the class definition of repS.
 *    A repS acts like a iSlogan, except that
 *     @@ it repeats some characters of its message
 *     @@ q or p times for output
 *     @@ cannot cycle through on/off states more than k times.
 *
 *      CLASS INVARIANTS
 *      The repS object will deactivate after a certain number of
 *      queries but can be reactivated with reset or terminated.
 *
 *      k value related with P value, but varies from object to object.
 *
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new
 *      arithmetic sequence, but there is no way to restart a gen obj
 *      to retrieve the beginning of the sequence.
 *       @@ the q value is pass by the parameter of guery method
 *       @@ guery() function have return value, know as relVal
 *        So driver can get result for query:
 *         -- relVal = -1 // means obj is off and reset()
 *         -- relVal = 1 // means obj is on and process the message successfully
 *         -- relVal = -2 // means obj is terminated.
 *         -- relVal = 0 // as initial
 *       @@ can't cycle through on/off states more than k times.
 *
 *     Using s override whoAmI() function to detect the type of class.
 *     override function: reSet(), getMessage(),
 *                       getOutputMessage()
 *                       whoAmI() // type identified.
 *
 *    IMPLEMENTATION INVARIANTS
 *     @@ code reuse, override parent function ,
 *        base class using virtual funtion, once virtual always virtual.
 *     @@ less code replication: child own function not responsible for parent.
 *     @@ Inheritance relationship, is is-a relationship, fixed 1 by 2 cardinary.
 *     @@ Efficiency.
 *
 *      Provide utility and flexibility function, and data hide,
 *      Designed by Open Close principle
 *       and LISKOV substitutability principle:
 *        child class object can stand in for a parent class object.
 *      @@ type extension.
 *
 *     Open close principly, data hidden.
 *     provide public method to be accessed by client.
 *      The functions query and reset are virtual for extension in
 *          descendant classes.
 */

#include "repS.h"

const int DEFAULT_FACTOR = 2;

repS::repS(string inputMessage) : iSlogan(inputMessage)
{
    newMessage = "";
    k = (p *DEFAULT_FACTOR)% 10 + 1;
    isTerminated = false;
    countK = 0;
    myId="repS";
    
}
//Function to reset object. Overrides gen's function
void repS::reset()
{
    if (countK == (k-1))
        isTerminated = true;
    else
    {
        iSlogan::reset();
        countK++;
    }
}
string repS::getOutPutMessage()
{
    return newMessage;
}

bool repS::terminated()
{
    return isTerminated;
}


//Overridden parent function to retrieve output.
//Function to return integer represent the state
//PRECONDITION: no output will happen if object is inactive
//POSTCONDITION: object may become inactive
int repS::query(int qVal){
    int relVal;
    // q is 1-digit Value
    q = qVal % 10;
    numOnOff++;
    int len = (int)message.length();
    if (isTerminated)
    {
        return -2;
    }
    else
    {
        if (numOnOff % p == 0)
        {
            on = !on;
            if (on)
                relVal = 0;
            else
            {
                relVal = -1;
                reset();
                return relVal;
                
            }
            
        }
        else if (on && p != q)
        {
            if ( len > 2)
                subString = message.substr(3, 3);
            else
                subString = message;
            
            newMessage = getRepeats(subString);
            
            // printMessage();
            relVal = 1;
        }
        else if (on && p == q)
        {
            relVal = 99;
        }
        
        else if (!on)
        {
            relVal = -1;
            reset();
        }
    }
    return relVal;
    
}

// private utility function to get repeate string
string repS::getRepeats(string subString)
{
    if (subString.length() == 0) return NULL;
    int pOrq = rand()%3+1;
    string temp = "";
    
    if (pOrq % 2==0)
    {
        if (p>0)
        {
            for (int i = 0; i < p;i++)
            {
                temp += subString;
            }
            
        }
        else
            temp = subString;
        
    }
    else
    {
        if (q>1)
        {
            for (int j = 0; j < q-1; j++)
            {
                temp += subString;
            }
        }
        
        else
            temp= subString;
    }
    return temp;
}

// Id function
string repS::whoAmI(){
    return myId;
}


