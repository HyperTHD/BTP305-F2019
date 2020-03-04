#pragma once
// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;

	public:
		Racecar();
		Racecar(std::istream&);
		void display(std::ostream&) const;
		double topSpeed() const;
	};
}

#endif