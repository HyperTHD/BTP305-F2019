// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 30/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& is)
	{
		Vehicle* newCar = nullptr;
		char tag;

		is >> tag;

		if (tag == 'c' || tag == 'C')
			newCar = new Car(is);

		return newCar;
	}
}