// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 30/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <algorithm>
#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* veh)
	{
		m_vehicles.push_back(veh);		
		return *this;
	}

	void Autoshop::display(std::ostream& os) const
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << "| Cars in the autoshop!        |" << std::endl;
		std::cout << "--------------------------------" << std::endl;


		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
		}

		std::cout << "--------------------------------" << std::endl;
	}
}