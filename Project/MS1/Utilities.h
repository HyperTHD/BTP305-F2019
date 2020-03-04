#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 10/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H


#include <iostream>
#include <string>

	class Utilities
	{
		size_t m_widthField;
		static char m_delimiter;

	public:
		Utilities();
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
		static void setDelimiter(const char);
		const char getDelimiter() const;
		const std::string extractToken(const std::string&, size_t&, bool&);
	};

#endif