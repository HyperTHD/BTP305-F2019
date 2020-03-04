#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_speed;

	public:
		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
		std::string trim(std::string);
	};
}

#endif 
