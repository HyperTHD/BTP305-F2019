#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 30/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator+=(Vehicle*);
		void display(std::ostream&) const;
	};
}

#endif 
