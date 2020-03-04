#pragma once

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;

	public:
		Movie();
		Movie(const std::string&);
		const std::string& title() const;
		std::string trim(std::string);
		friend std::ostream& operator<<(std::ostream&, const Movie&);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}