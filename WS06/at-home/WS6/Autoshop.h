#pragma once
// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 03/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		~Autoshop();
		Autoshop& operator+=(Vehicle*);
		void display(std::ostream&) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
			{
				if (test(*i) == true)
					vehicles.push_back(*i);
			}
		}
	};
}

#endif 
