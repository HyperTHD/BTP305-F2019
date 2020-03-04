// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <ctype.h>
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
		std::string temp("");
		std::string copy[3]{};

		// Grab the first 2 values and store them in a temp array so that I can confirm if m_condition is valid
		
		for (int i = 0; i < 2; i++)
		{
			std::getline(is, temp, ',');
			temp.erase(0, temp.find_first_not_of(' '));
			copy[i] = temp;
		}

		m_maker = trim(copy[0]); // Removes space at the end


		/*
			With regards to the error handling, getline is used to extract the next line if any of the error checks fail
			at any point for m_condition or m_speed
			The exception is then thrown. 
		*/

		// Checks for m_condition

		if (copy[1].empty())
			copy[1] = 'n';
		if (copy[1].at(0) == 'n' || copy[1].at(0) == 'u' || copy[1].at(0) == 'b')
			m_condition = copy[1].at(0);
		else
		{
			std::getline(is, temp);
			throw std::string("Invalid record!");
		}

		// Here, the speed is checked using isDigit() function from ctype.h library

		is >> copy[2];

		if (!isdigit(copy[2].at(0)))
		{
			std::getline(is, temp);
			throw std::string("Invalid record!");
		}
		else
			m_speed = stod(copy[2]);
	}

	void Car::display(std::ostream& os) const
	{
		// Calling the topSpeed() function here because dynamic binding means the right speed will be displayed at run-time

		os << "| " << std::setw(10) << std::right << m_maker << " | "
			<< std::setw(6) << std::left << condition() << " | "
			<< std::fixed << std::setprecision(2) << std::right << std::setw(6) << topSpeed() << " |";

	}

	


}