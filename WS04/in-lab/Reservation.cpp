// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 02/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <cstring>
#include "Reservation.h"


using namespace std;

namespace sdds
{
Reservation::Reservation()
{
	m_reserve_id = "";
	m_name = "";
	m_email = "";
	m_numOfPeople = 0;
	m_day = 0;
	m_hour = 0;
}

Reservation::Reservation(const std::string &m_res)
{
	string props[6];
	string temp = m_res;

	for (int i = 0; i < props.length(); i++)
	{
		temp.erase(0, temp.find_first_not_of(" ,:"));
		props[i] = temp.substr(0, temp.find_first_of(" ,:"));
		temp.erase(0, temp.find_first_of(" ,:") + 1);
	}
	m_reserve_id = props[0];
	m_name = props[1];
	m_email = props[2];
	m_numOfPeople = stoi(props[3]);
	m_day = stol(props[4]);
	m_hour = stol(props[5]);
}

std::ostream &operator<<(std::ostream &os, const Reservation &res)
{
	if (res.m_hour >= 6 && res.m_hour <= 9)
	{
		return os << res.m_reserve_id << ": " << res.m_name << res.m_email << " Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPeople << " people." << std::endl;
	}
}

} // namespace sdds