// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#include "Book.h"

namespace sdds
{
	std::string Book::trim(std::string str)
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

	Book::Book()
	{
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.0;
		m_description = "";
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const 
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}


	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;

		m_author = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);
		
		m_title = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_country = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_price = stod(trim(temp.substr(0, strBook.find(","))));
		temp.erase(0, temp.find_first_of(",") + 1);

		m_year = stoi(trim(temp.substr(0, strBook.find(","))));
		temp.erase(0, temp.find_first_of(",") + 1);
		
		m_description = trim(temp);	
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		return os << std::setw(20) << book.m_author << " | "
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | "
			<< book.m_description << std::endl;
	}
}
