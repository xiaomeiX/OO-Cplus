/*
 *  Fall_CS3200_P4
 *  Created by Xiaomei Xie
 *  on 11/3/18.
 *  P4
 *  version 1
 *  conVerter.cpp
 * * This file contains the class definition of iSlogan.
 * -A conVerter object take string as input and outputs a sequence of ASCII;
 *      values corresponding to the first r(which is 1-digit value)[1 to 9]
 *      alphanumeric characters(no punctuation) of the input string
 *
 *      It defines the public interface
 *
 *
 *      CLASS INVARIANTS
 *      1)take string as input and outputs a sequence of ASCII,
 *        values corresponding to the first r, where r is a stable 1-digit value
 *        that varies from object to object;
 *
 *
 *      INTERFACE INVARIANTS
 *     @@ the r value is pass by the parameter of query method,
 *         with 1-digit value
 *     @@ guery() function have return value, know as relVal
 *        So driver can get result for query:
 *         -- relVal = 1 // means obj is on and process the message successfully
 *
 *     Using virtual query() function,
 *     so the its child class can override this function,
 *        to process heterogenerous collection
 *     virtual function:
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
 */

#include "conVerter.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

conVerter::conVerter( string inputMessage )
{
    /* generate secret number between 1 and 9: */
    message = inputMessage;
    tempMessage = inputMessage;
    updateMessage = "";
    myId = "conVerter";
}

// Function is get function as interface for external class.
// function send output message to client.
string conVerter::getOutPutMessage()
{
    return updateMessage;
}


//Function to return integer represent process success.
//PRECONDITION: N/A
//POSTCONDITION: object may update the outputmessage
int conVerter::query(int rVal)
{
    // r is 1-digit Value
    r = rVal % 9+1;
    int i=0;
    updateMessage="";
    while (isalnum(tempMessage[i]) && i<r)
    {
       if (i<r)
       {
        ostringstream temp;  //temp as in temporary
        temp<<(int)tempMessage[i];
        updateMessage +=temp.str();
        i++;

       }
    }
    return 1;
}
string conVerter::whoAmI(){
    return myId;
}



