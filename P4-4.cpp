
/*
 * Author: xiaomei Xie
 * Created on: 11/4, 2018
 * P4
 * version 1
 * 
 * * This file contains the driver for P4
 * -It is intended for testing the classes created in P3 as well
 *      as the new multiple inherited classes created in P4.
 *
 * -It uses heterogeneous collections that are initialized via
 *      isolated getObj functions to show that the objects multiply
 *      inheriting can stand in for either of its parents
 * -Random generators are used to generate random ints and random strings
 *  @@ alphanumeric characters(no punctuation)
 *
 * - Each object, will be tested by constantly call its query() function,
 *   passed by a random interger.
 *
 *   Driver can test each object and get result from virtual function query(int):
 *         -- relVal = -1 // means obj is off, and reset().
 *         -- relVal = 1 // means obj is on and process the message successfully
 *         -- relVal = 99 // means obj is on, but q = p, no output needed.
 *         -- relVal = -2 // Object was terminted.
 *
 * - Before end of program, will deallocate the heap memory.
 *
 *  Design use Open close principle and subtype Polymorphism,
 *    heterogenous collection, Open extentitional and closs modificationed.
 *   keep code efficency and code reuse, transfer responsiblity to class design.
 *   reduce test time;
 *   Efficiency: replaceable subobject.
 * - Code reuse and consistance.
 * - Function decomposition 
 * - Mutiple inheritance
 * - Maintainance.
 *
 */
#include<iostream>
#include<cctype>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "iSlogan.h"
#include "garbledS.h"
#include "repS.h"
#include "conVerter.h"
#include "iSloganConVert.h"
#include "conVerGarS.h"
#include "conVerRepS.h"


const int MAXRAND = 99;
const int NUMOBJS = 20;
const int NUMTESTS = 15;
const int MAXSTRINGLENGH=10;

using namespace std;

static string randString();
iSlogan* getiSloganObj(int x);
conVerter* getconVerterObj(int x);
template <typename T> void testHeterogeneousArray(T & testItem);


int main() {
    
  srand( static_cast<unsigned int>(time(NULL)));

    int key;
    //HETEROGENEOUS ARRAYS
    iSlogan* iSloganArray[NUMOBJS];
    conVerter* conVerterArray[NUMOBJS];
    
    cout<<"Generating random heterogeneous collection objects"<<endl;
    
    for(int i = 0; i < NUMOBJS; i++)
    {
        key= rand()% MAXRAND+1;
        iSloganArray[i] = getiSloganObj(key);
        conVerterArray[i] = getconVerterObj(key);

    }
    
    cout<<"\nQuerying each obj ";
    cout<<NUMTESTS;
    cout<<" times"<<endl;
    
    // TEST HETEROGENEOUS ARRAYS
    for(int l = 0; l < NUMOBJS; l++)
    {
       //Test iSlogan Array
        testHeterogeneousArray(iSloganArray[l]);
        cout << endl << endl;
        
       // Test ConVerter Array
        testHeterogeneousArray(conVerterArray[l]);
        
    }
    
    // Deallocate the heap memory.
    for(int i = 0; i < NUMOBJS; i++)
    {
       delete iSloganArray[i];
       delete conVerterArray[i];
    }
    
    return 1;
}

 iSlogan* getiSloganObj(int x)
{
      iSlogan* retObj;
      int y = (x%4);
      string newS;
      if (y==0)
       {
            newS= randString();
            retObj = new garbledS(newS);
       }
        else if (y==1)
        {
            newS= randString();
            retObj = new repS(newS);
            
        }
        else if (y==2)
        {
            newS= randString();
            retObj = new iSloganConVert(newS);
            
        }
      else
        {
            string newS= randString();
            retObj = new iSlogan(newS);
           
        }
    
    return retObj;
}
conVerter* getconVerterObj(int x)
{
    conVerter* conObj;
    int y = (x%4);
    string newS;
    if (y==0)
    {
        newS= randString();
        conObj = new iSloganConVert(newS);
    }
    else if (y==1)
    {
        newS= randString();
        conObj = new conVerGarS(newS);
    }
    else if (y==2)
    {
        newS= randString();
        conObj = new conVerRepS(newS);
    }
    else
    {
        newS= randString();
        conObj = new conVerter(newS);
        
    }
    
    return conObj;
}

//Function to generate a random string of random length
string randString()
{
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string newstr;
    int pos;
    while(newstr.size() != MAXSTRINGLENGH) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos,1);
    }
    return newstr;
     
}

template <typename T>void testHeterogeneousArray(T & testItem){
    string who = testItem->whoAmI();
    cout << "\n************************************************ "<< endl;
    cout << "**##       Type ID is:  " << who <<" " << endl;
    cout << "************************************************ "<< endl;
    
    for(int j = 0; j < NUMTESTS; j++)
    {
        cout<<"\ncase # "<<j<<":"<<endl;
        int key = rand()% MAXRAND+1;
        int result = testItem->query(key);
        if (result == -1)
        {
            cout<<"Object reset."<<endl;
        }
        
        else if (result == 1)
        {
            string outPut;
            outPut =testItem->getOutPutMessage();
            cout<<"Print out message is: "<<outPut<<endl;
            
        }
        else if (result == 99)
        {
            cout<<"p=q, no message need be print out "<<endl;
        }
        else if (result == -2)
        {
            cout<<"Object was terminted."<<endl;
            break;
        }
    }
    
}



