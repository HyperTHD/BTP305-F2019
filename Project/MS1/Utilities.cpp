
// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 10/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

	// variable definition

	Utilities::Utilities() : m_widthField(1) {}

	char Utilities::m_delimiter = '\0';

	// Queries and Modifier functions

	void Utilities::setFieldWidth(size_t width)
	{
		m_widthField = width;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	void Utilities::setDelimiter(const char next)
	{
		m_delimiter = next;
	}

	const char Utilities::getDelimiter() const
	{
		return m_delimiter;
	}


	/*
	Name: extractFunction	
	Params: const string reference, size_t reference, boolean reference
	Return: const string with the tokens extracted
	*/

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string temp;	// Returning temp

		size_t new_pos = str.find(m_delimiter, next_pos + 1);

		size_t length = (new_pos - next_pos);
		
		temp = str.substr(next_pos, length);
		
		next_pos = new_pos + 1;

		if (m_widthField < temp.length()) 			
			m_widthField = temp.length();

		if (temp == "")
		{
			more = false;
			throw "Error! No tokens can be found!";
		}
		else
		{
			more = true;
			return temp;
		}
	}

