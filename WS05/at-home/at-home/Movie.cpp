#include "Movie.h"

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 20/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


namespace sdds
{
	Movie::Movie()
	{
		m_title = "";
		m_year = 0;
		m_description = "";
	}

	std::string Movie::trim(std::string str)
	{
		char space = ' ';

		while (str.front() == space) {
			str = str.substr(1, str.length() - 1);
		}

		while (str.back() == space) {
			str = str.substr(0, str.length() - 1);
		}

		return str;
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}
	
	Movie::Movie(const std::string& strMovie)
	{
		std::string temp = strMovie;

		m_title = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_year = stoi(trim(temp.substr(0, temp.find(","))));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_description = trim(temp);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		return os << std::setw(40) << movie.m_title << " | "
			<< std::setw(4) << movie.m_year << " | "
			<< movie.m_description << std::endl;
	}
}