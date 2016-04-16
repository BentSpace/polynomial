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

// Default Constructor
Polynomial::Polynomial()
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        coefficents[i] = 0;
    }
}

Polynomial::Polynomial(long long fifthDegreeCoefficient,
                       long long forthDegreeCoefficient,
                       long long thirdDegreeCoefficient,
                       long long secondDegreeCoefficient,
                       long long firstDegreeCoefficient,
                       long long zeroDegreeCoefficient)
{
    coefficents[0] = fifthDegreeCoefficient;
    coefficents[1] = forthDegreeCoefficient;
    coefficents[2] = thirdDegreeCoefficient;
    coefficents[3] = secondDegreeCoefficient;
    coefficents[4] = firstDegreeCoefficient;
    coefficents[5] = zeroDegreeCoefficient;
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
    std::string superScripts = "5432";
    std::string temp;
    for (int i = 0; i < NUM_COEFFICIENTS; i++)
    {
        if (obj.coefficents[i])
        {
            //std::string superTemp = superScripts[i];
            if (firstTerm)
            {
                temp += std::to_string(obj.coefficents[i]);
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
                temp += std::to_string(std::abs(obj.coefficents[i]));
            }
            if (i < 4)
            {
                temp += "x^";
                temp += superScripts[i];
            }
            else if (i == 4)
            {
                temp += "x";
            }
        }
        
    }
    strm << temp;
    // strm << obj.feet << " feet, " << obj.inches << " inches";
    return strm;
}
