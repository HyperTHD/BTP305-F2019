// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar() : Car(), m_booster(0.0) {}


	Racecar::Racecar(std::istream& in) : Car(in)
	{
		// Extraction operator is used here because of how I extracted the car in Car.cpp
		// Could've also used seekg to reset the position to m_booster before extracting it
		// Tried getline but it did not work because it grabbed the next line ignoring the booster

		in >> m_booster;
	}

	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() * m_booster) + Car::topSpeed();
	}

	void Racecar::display(std::ostream& os) const 
	{
		Car::display(std::cout);
		os << "*";
	}
}