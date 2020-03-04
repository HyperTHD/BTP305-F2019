// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& is)
	{
		Vehicle* newCar = nullptr;
		char tag = 'a', comma = ',';

		std::string temp = "";

		is >> std::skipws >> tag; // Skips whitelines before the tag

		bool check = tag == 'c' || tag == 'C' || tag == 'r' || tag == 'R'; // Check for grab, could've been a huge if statement as well

		if (!check) // If the tag is none of these 4 characters, throw away the tag, go to the next line, and throw the exception
		{
			is.unget();
			std::getline(is, temp);
			throw tag; 
		}
		else // Otherwise, check the tag, skip the whitespace, grab the comma to remove it from the input stream, then pass to appropriate constructor
		{
			if (tag == 'c' || tag == 'C') {
				is >> std::skipws >> comma;
				newCar = new Car(is);
			}
			else if (tag == 'r' || tag == 'R')
			{
				is >> std::skipws >> comma;
				newCar = new Racecar(is);
			}
		}
		return newCar;
	}
}