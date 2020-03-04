#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;

	public:
		Book();
		std::string trim(std::string);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string&);

		friend std::ostream& operator<<(std::ostream&, const Book&);
	};
}

#endif