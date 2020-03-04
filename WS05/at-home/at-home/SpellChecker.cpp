#include <fstream>
#include "SpellChecker.h"

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 20/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		std::string line;
		
		if (!file)
		{
			throw "Bad file name!";
		} 
		else
		{
			for (auto i = 0u; i < 5; i++)
			{
				std::getline(file, line);
				m_badWords[i] = line.substr(0, line.find(" "));
				m_badWords[i] = trim(m_badWords[i]);
				m_goodWords[i] = line.substr(line.find_last_of(" "), line.length());
				m_goodWords[i] = trim(m_goodWords[i]);
			}
			file.close();
		}

	}

	void SpellChecker::operator()(std::string& text) const
	{
		for (auto i = 0u; i < 5; i++)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
	std::string SpellChecker::trim(std::string str)
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

}
