/* -----------------------------------------------------------------------------
 
 FILE NAME:         XXX.CPP
 
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

#include "polynomial.hpp"
#include "general.hpp"
#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;

// Default Constructor
Polynomial::Polynomial()
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = 0;
    }
}

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

// Copy Constructor
Polynomial::Polynomial(const Polynomial &obj)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = obj.coefficents[i];
    }
}

// Destructor
Polynomial::~Polynomial()
{
}

// Overloaded = operator
void Polynomial::operator=(const Polynomial &right)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = right.coefficents[i];
    }
}

// Overloaded << operator
std::ostream &operator << (std::ostream &strm, const Polynomial &obj)
{
    bool firstTerm = true;
    //std::string superScripts = "⁵⁴³²";
    //std::string superScripts = "5432";
    std::string temp;
    for (int i = NUM_COEFFICIENTS; i >= 0; i--)
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
            }
            else if (i == 1)
            {
                temp += "x";
            }
        }
        
    }
    strm << temp;
    return strm;
}

// Overloaded >> operator
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

Polynomial Polynomial::operator + (const Polynomial &right)
{
    Polynomial temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        temp.coefficents[i] = coefficents[i] + right.coefficents[i];
    }
    return temp;
}

Polynomial Polynomial::operator - (const Polynomial &right)
{
    Polynomial temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        temp.coefficents[i] = coefficents[i] - right.coefficents[i];
    }
    return temp;
}

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

long long Polynomial::evaluatePolynomialFor(long long x)
{
    long long accumulator = coefficents[0]; // Start accumulator at the zero degree term
    for (int i = 1; i < NUM_COEFFICIENTS; i++)
    {
        accumulator += coefficents[i] * pow (x, i);
    }
    return accumulator;
}