/* -----------------------------------------------------------------------------
 
 FILE NAME:         polynomial.cpp
 
 DESCRIPTION:       Implementation file for the Polynomial class
 
 PURPOSE:           member functions of the Polynomial class implemented here

 EXIT CODES:        0 = Success
 Otherwise = Error
 
 COMPILATION:       Built in Xcode, complied on Ubuntu with GNU g++
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Nathan Bertram   04-15-2016     7.0
 
 ----------------------------------------------------------------------------- */

#include "polynomial.hpp"
#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;


/* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Default Constructor
 RETURNS:           A Polynomial object
 NOTES:
 ----------------------------------------------------------------------------- */
Polynomial::Polynomial()
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = 0;
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Overloaded Constructor
 RETURNS:           A Polynomial object
 NOTES:
 ----------------------------------------------------------------------------- */
Polynomial::Polynomial(long long fifthDegreeCoefficient,
                       long long fourthDegreeCoefficient,
                       long long thirdDegreeCoefficient,
                       long long secondDegreeCoefficient,
                       long long firstDegreeCoefficient,
                       long long zeroDegreeCoefficient)
{
    coefficents[0] = zeroDegreeCoefficient;
    coefficents[1] = firstDegreeCoefficient;
    coefficents[2] = secondDegreeCoefficient;
    coefficents[3] = thirdDegreeCoefficient;
    coefficents[4] = fourthDegreeCoefficient;
    coefficents[5] = fifthDegreeCoefficient;
    for (int i = 6; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = 0;
    }
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Copy Constructor
 RETURNS:           A Polynomial object
 NOTES:             For assigning another Polynomial object to a new Polynomial
 ----------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial &obj)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = obj.coefficents[i];
    }
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Polynomial()
 DESCRIPTION:       Destructor
 RETURNS:
 NOTES:             Not much to destroy since nothing dynamically allocated
 ----------------------------------------------------------------------------- */
Polynomial::~Polynomial()
{
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded = operator()
 DESCRIPTION:       Assigns values from Polynomial on right of = Polynomial on left
 RETURNS:           Void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Polynomial::operator=(const Polynomial &right)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = right.coefficents[i];
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded << operator()
 DESCRIPTION:       Provides prettifying of object for print to screen with cout
 RETURNS:           stream object
 NOTES:
 ----------------------------------------------------------------------------- */
std::ostream &operator << (std::ostream &strm, const Polynomial &obj)
{
    bool firstTerm = true;
    //std::string superScripts = "⁵⁴³²";
    //std::string superScripts = "5432";
    //std::string superScripts [] = {"", "", "²", "³", "⁴", "⁵"};
    std::string temp;
    for (int i = NUM_COEFFICIENTS - 1; i >= 0; i--)
    {
        if (obj.coefficents[i])
        {
            //std::string superTemp = superScripts[i];
            if (firstTerm)
            {
                if (obj.coefficents[i] > 1)
                {
                    temp += std::to_string(obj.coefficents[i]);
                }
                firstTerm = false;
            }
            else
            {
                temp += " ";
                if (obj.coefficents[i] > 0)
                {
                    temp += "+";
                }
                else
                {
                    temp += "-";
                }
                temp += " ";
                if (i == 0)
                {
                    temp += std::to_string(std::abs(obj.coefficents[i]));
                }
                else if (std::abs(obj.coefficents[i]) != 1)
                {
                    temp += std::to_string(std::abs(obj.coefficents[i]));
                }
            }
            if (i > 1)
            {
                temp += "x^";
                temp += std::to_string(i);
                //temp += superScripts[i];
            }
            else if (i == 1)
            {
                temp += "x";
            }
        }
        
    }
    if (temp == "")
        temp = "0";
    strm << temp;
    return strm;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded >> operator()
 DESCRIPTION:       Used to with to get values for a new Polynomial object from 
                    the user
 RETURNS:           stream object
 ----------------------------------------------------------------------------- */
std::istream &operator >> (std::istream &strm, Polynomial &obj)
{
    std::string degrees [] = {"zeroth", "first", "second", "third", "fourth", "fifth"};
    for (int i = 5; i >= 0; i--)
    {
        cout << "Please enter the coefficient of the " << degrees[i] << " degree term: ";
        strm >> obj.coefficents[i];
    }
    return strm;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded + operator()
 DESCRIPTION:       Used to add two Polynomial object
 RETURNS:           A Polynomial object that is result of the addition
 ----------------------------------------------------------------------------- */
Polynomial Polynomial::operator + (const Polynomial &right)
{
    Polynomial temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        temp.coefficents[i] = coefficents[i] + right.coefficents[i];
    }
    return temp;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded - operator()
 DESCRIPTION:       Used to subtract two Polynomial object
 RETURNS:           A Polynomial object that is result of the subtration
 ----------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial &right)
{
    Polynomial temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        temp.coefficents[i] = coefficents[i] - right.coefficents[i];
    }
    return temp;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded * operator()
 DESCRIPTION:       Used to multiply two Polynomial object
 RETURNS:           A Polynomial object that is result of the multiplication
 ----------------------------------------------------------------------------- */
Polynomial Polynomial::operator * (const Polynomial &right)
{
    Polynomial temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        for (int j = 0; j < NUM_COEFFICIENTS; j++)
        {
            temp.coefficents[i + j] += coefficents[i] * right.coefficents[j];
        }
    }
    return temp;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Overloaded == operator()
 DESCRIPTION:       Used to test equally of two Polynomial object
 RETURNS:           A true of false bool
 ----------------------------------------------------------------------------- */
bool Polynomial::operator == (const Polynomial &right)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        if (coefficents[i] != right.coefficents[i])
        {
            return false;
        }
    }
    return true;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          evaluatePolynomialFor()
 DESCRIPTION:       Evaluates the Polynomial for when x is equal to the passed 
                    in parameter
 RETURNS:           A long long int that is the result of the evaluation
 ----------------------------------------------------------------------------- */
long long Polynomial::evaluatePolynomialFor(long long x)
{
    long long accumulator = coefficents[0]; // Start accumulator at the zero degree term
    for (int i = 1; i < NUM_COEFFICIENTS; i++)
    {
        accumulator += coefficents[i] * pow (x, i);
    }
    return accumulator;
}