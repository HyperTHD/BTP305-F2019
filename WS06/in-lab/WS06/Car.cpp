// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 30/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <algorithm>
#include "Car.h"

namespace sdds
{
	// Trim function to trim out spaces

	std::string Car::trim(std::string str)
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

	double Car::topSpeed() const
	{
		return m_speed;
	}

	std::string Car::condition() const
	{
		std::string con;

		if (m_condition[0] == 'n')
			con = "new";
		else if (m_condition[0] == 'u')
			con = "used";
		else if (m_condition[0] == 'b')
			con = "broken";

		return con;
	}

	Car::Car() : m_maker(""), m_condition(""), m_speed(0.0) {}

	Car::Car(std::istream& is)
	{
		std::string temp;
	
		std::getline(is, temp);
		
		temp.erase(0, temp.find_first_of(", ") + 2);

		m_maker = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_condition = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_speed = stod(trim(temp));
		
	}

	void Car::display(std::ostream& os) const
	{
		os << "| " << std::setw(10) << std::right << m_maker << " | "
		   << std::setw(6) << std::left << condition() << " | "
		   << std::fixed << std::setprecision(2) << std::right << std::setw(6) << m_speed << " | " << std::endl;
	}

	


}