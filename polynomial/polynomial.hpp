/* -----------------------------------------------------------------------------
 
 FILE NAME:         polynomial.hpp
 
 DESCRIPTION:       Describe the this file ...
 
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
 Programmer      mm-dd-yyyy     Version number
 
 ----------------------------------------------------------------------------- */

#ifndef polynomial_hpp
#define polynomial_hpp

#include <iostream>

using std::cout;
using std::endl;

class Polynomial
{
public:// Everything following this is visible from the outside
    static const int NUM_COEFFICIENTS = 6;
    
    // Constructor(s)
        // Default constructor
    Polynomial();
    Polynomial(long long, long long, long long, long long, long long, long long);
        // Copy constructor
    Polynomial(const Polynomial &);
    
    // Destructor
    ~Polynomial ();
    
    // Overloaded = operator
    void operator=(const Polynomial &);

private:

    long long coefficents[NUM_COEFFICIENTS];
};
#endif /* polynomial_hpp */
