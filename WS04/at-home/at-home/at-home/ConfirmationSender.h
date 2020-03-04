#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** reservation;
		unsigned int size;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);

		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}

#endif 