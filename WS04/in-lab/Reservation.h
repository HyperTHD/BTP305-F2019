#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 02/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
	class Reservation
	{
		std::string m_reserve_id;
		std::string m_name;
		std::string m_email;
		int m_numOfPeople;
		int m_day;
		int m_hour;

	public: 
		Reservation();
		Reservation(const std::string&);

		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

#endif