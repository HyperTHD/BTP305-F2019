#pragma once

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