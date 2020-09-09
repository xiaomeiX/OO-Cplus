/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/3/18.
 *  P4
 *  version 1
 *  garbledS.cpp
 *
 * This file contains the class definition of garbledS.
 *      garbledS inherits from iSlogan class. It retains public
 *      functionality such as
 *      setting the arithmetic sequence
 *      and inherits the protected data fields q,
 *      message, p, threshold, and active.
 *
 *      CLASS INVARIANTS
 *      -- garbledS is child of iSlogan, inheritance the function of its parent class
 *      -- object will deactivate after a certain number of
 *        but can be reactivated with public reset().
 *      -- query(), swap pth char with qth charqueries of message
 *         and arbitrarily mixes case.
 *
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new
 *      arithmetic sequence, but there is no way to restart a iSlogan obj
 *      to retrieve the beginning of the sequence.
 *
 *     @@ the q value is pass by the parameter of guery method
 *     @@ guery() function is override function.
 *        So driver can get result for query:
 *         -- relVal = -1 // means obj is off
 *         -- relVal = 1 // means obj is on and process the message successfully
 *      Using s override whoAmI() function to detect the type of class.
 *      override function: reSet(), getMessage(),
 *                       getOutputMessage()
 *                       whoAmI()
 *      The functions query and reset are virtual for extension in
 *          descendant classes.
 *
 *     IMPLEMENTATION INVARIANTS
 *     @@ code reuse, override parent function ,
 *        base class using virtual funtion, once virtual always virtual.
 *     @@ less code replication: child own function not responsible for parent.
 *     @@ Inheritance relationship, is is-a relationship, fixed 1 by 2 cardinary.
 *     @@ Efficiency.
 *      The functions query and reset are virtual for extension in
 *          descendant classes.
 *      Provide utility and flexibility function, and data hide,
 *      Designed by Open Close principle
 *       and LISKOV substitutability principle:
 *        child class object can stand in for a parent class object.
 *      @@ type extension.
 *
 * 
 */

#include "garbledS.h"
//repS(string inputMessage) : iSlogan(inputMessage)
garbledS::garbledS(string inputMessage) : iSlogan(inputMessage)
{
    updateMessage = "";
    myId="garbledS";
    on = true;
    
}
//Function to reset object. Overrides iSlogan's function
void garbledS::reset()
{
    iSlogan::reset();
}

// Function is get function as interface for external class.
// function send output message to client.
string garbledS::getOutPutMessage()
{
    return updateMessage;
}

//Function to return integer represent the control state.
//Overridden parent function to retrieve output.
//PRECONDITION: if object is on
//POSTCONDITION: object may update the outputmessage
//               and return value depend on the state.
int garbledS::query(int qVal){
    int relVal=0;
    // q is 1-digit Value
    q = qVal % 10;
   
    numOnOff++;
    if ((numOnOff) % p == 0)
    {
        on = !on;
        
        if (on == false)
        {
            relVal = -1;
            reset();
            return relVal;
        }
    }
    if (on)
    {
        updateMessage = message;
         //swap the pth char with qth char
        swap(updateMessage[p], updateMessage[q]);
     
        // arbitrarily mixes case.
        for (int i = 0; i < updateMessage.length(); i++)
        {
            if (i % 3 == 0 && (q % 3==0 || q% 3 == 2))
                updateMessage[i] = toupper(updateMessage.at(i));
            else if (i % 3 == 0 && q % 3 ==1)
                updateMessage[i] = tolower(updateMessage.at(q));
            else if (i >= (updateMessage.length()-3))
                updateMessage[i] = toupper(updateMessage.at(i));
            else
                updateMessage[i] = tolower(updateMessage.at(i));
        }        
        relVal = 1;
        
    }
    
    // if off,a garbledS acts like a iSlogan with be turn off.    
    else
    {
        relVal = -1;
        reset();
    }
    return relVal;
    
}
string garbledS::whoAmI(){
    return myId;
}

