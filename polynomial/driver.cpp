/* -----------------------------------------------------------------------------
 
 FILE NAME:         driver.cpp
 
 DESCRIPTION:       Driver program for testing the Polynomial class
 
 PURPOSE:           To test functionality of Polynomial class
 
 USAGE:             type ./polynomial on the command line
 
 EXAMPLES:
 
 PARAMETERS:        none
 
 EXIT CODES:        0 = Success
 Otherwise = Error
 
 COMPILATION:       Built in Xcode, complied on Ubuntu with GNU g++
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Nathan Bertram   04-15-2016     7.0
 
 ----------------------------------------------------------------------------- */

#include <iostream>

#include "polynomial.hpp"

using std::cin;

int main() {
    
    cout << "default constructor test" << endl;
    Polynomial myPolynomial;
    cout << "myPolynomial = " << myPolynomial << endl << endl;
    
    cout << "Overloaded constructor test" << endl;
    Polynomial myPolynomial2(7,-5,2,0,1,1);
    cout << "myPolynomial2 = " << myPolynomial2 << endl << endl;
    
    cout << "Copy constructor test" << endl;
    Polynomial myPolynomial3 = myPolynomial2;
    cout << "myPolynomial3 = " << myPolynomial3 << endl << endl;
    
    cout << "Overloaded = test" << endl;
    myPolynomial = myPolynomial3;
    cout << "myPolynomial = " << myPolynomial << endl << endl;
    
    cout << "Overloaded >> test" << endl;
    Polynomial myPolynomial4;
    cin >> myPolynomial4;
    cout << "myPolynomial4 = " << myPolynomial4 << endl << endl;
    
    cout << "Overloaded + test" << endl;
    myPolynomial = myPolynomial2 + myPolynomial3;
    cout << "(" << myPolynomial2 <<  ") + (" << myPolynomial3 << ") = " << myPolynomial << endl << endl;
    
    cout << "Overloaded - test" << endl;
    myPolynomial = myPolynomial2 - myPolynomial4;
    cout << "(" << myPolynomial2 <<  ") - (" << myPolynomial4 << ") = " << myPolynomial << endl << endl;
    
    cout << "Overloaded * test" << endl;
    myPolynomial = myPolynomial2 * myPolynomial4;
    cout << "(" << myPolynomial2 <<  ") * (" << myPolynomial4 << ") = " << myPolynomial << endl << endl;
    
    cout << "Overloaded == test" << endl;
    bool equal = myPolynomial2 == myPolynomial3;
    cout << "(" << myPolynomial2 <<  ") is equal to (" << myPolynomial3 << ")? " << (equal ? "true" : "false") << endl << endl;
    
    cout << "Evaluation test" << endl;
    long long ans = myPolynomial2.evaluatePolynomialFor(7);
    cout << "(" << myPolynomial2 <<  ") when x = 7 is equal to : " << ans << endl << endl;
    
    return 0;
}
