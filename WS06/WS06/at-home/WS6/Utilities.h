#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream&);
}

#endif 
