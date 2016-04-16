/* -----------------------------------------------------------------------------
 
 FILE NAME:         driver.cpp
 
 DESCRIPTION:       Driver program for the polynomial class
 
 PURPOSE:           Describe the purpose for this file ...
 
 USAGE:             Give instructions for running the program from the command
 line ...
 
 EXAMPLES:          Give examples of how to run the program ...
 
 PARAMETERS:        List all command line parameters here and their purpose ...
 
 EXIT CODES:        0 = Success
 Otherwise = Error
 
 COMPILATION:       Tell another programmer what tools development you used to
 build the .EXE
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Nathan Bertram   04-15-2016     4.0
 
 ----------------------------------------------------------------------------- */

#include <iostream>

#include "general.hpp"
#include "polynomial.hpp"


int main() {
    
    Polynomial myPolynomial(-1,0,0,4,-5,6);
    Polynomial myPolynomial2;
    myPolynomial2 = myPolynomial;
    //cout << "⁵⁴³²";
    cout << myPolynomial2;
    return 0;
}
