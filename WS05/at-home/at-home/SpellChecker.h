#pragma once

#include <iostream>
#include <string>
#include <iomanip>

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 20/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5];
		std::string m_goodWords[5];

	public:
		SpellChecker(const char*);
		void operator() (std::string&) const;
		std::string trim(std::string);
	};

}