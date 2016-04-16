/* -----------------------------------------------------------------------------
 
 FILE NAME:         polynomial.hpp
 
 DESCRIPTION:       Header file for the Polynomial class
 
 PURPOSE:           Polynomial class defined here
 
 EXIT CODES:        0 = Success
 Otherwise = Error
 
 COMPILATION:       Built in Xcode, complied on Ubuntu with GNU g++
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Nathan Bertram   04-15-2016     7.0
 
 ----------------------------------------------------------------------------- */

#ifndef polynomial_hpp
#define polynomial_hpp

#include <iostream>

using std::cout;
using std::endl;

class Polynomial;

// Overloaded << operator
std::ostream &operator << (std::ostream &, const Polynomial &);
std::istream &operator >> (std::istream &, Polynomial &);

static const int NUM_COEFFICIENTS = 11;

class Polynomial
{
public:// Everything following this is visible from the outside
    
    // Constructor(s)
        // Default constructor
    Polynomial();
        // Overloaded constructor
    Polynomial(long long, long long, long long, long long, long long, long long);
        // Copy constructor
    Polynomial(const Polynomial &);
    
    // Destructor
    ~Polynomial ();
    
    // Overloaded operator functions
    void operator=(const Polynomial &);
    Polynomial operator + (const Polynomial &); // Overloaded +
    Polynomial operator - (const Polynomial &); // Overloaded −
    Polynomial operator * (const Polynomial &); // Overloaded *
    bool operator == (const Polynomial &); // Overloaded ==
    
    // Friends
    friend std::ostream &operator << (std::ostream &, const Polynomial &);
    friend std::istream &operator >> (std::istream &, Polynomial &);
    
    // Evalute polynomial at x
    long long evaluatePolynomialFor(long long);
    
private:

    long long coefficents[NUM_COEFFICIENTS];
};
#endif /* polynomial_hpp */
