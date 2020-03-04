#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds
{
	
	class Restaurant
	{
		Reservation* reservation;
		size_t length;

	public:
		Restaurant(Reservation* reservation[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		~Restaurant();
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		size_t size() const;

		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};

}

#endif