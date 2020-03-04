// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds
{

	size_t Restaurant::size() const 
	{
		return this->length;
	}

	Restaurant::Restaurant(Reservation* reservation[], size_t cnt)
	{
		this->length = cnt;
		this->reservation = new Reservation[this->length];

		for (int i = 0; i < cnt; i++)
		{
			this->reservation[i] = *reservation[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& order)
	{
		this->reservation = nullptr;
		*this = order;
	}

	Restaurant& Restaurant::operator=(const Restaurant& order)
	{
		if (this != &order)
		{
			this->length = order.length;
			delete[] this->reservation;
			
			this->reservation = new Reservation[order.length];

			for (int i = 0; i < this->length; i++)
			{
				this->reservation[i] = order.reservation[i];
			}
		}
		return *this;
	}

	Restaurant::~Restaurant()
	{
		delete[] this->reservation;
	}

	Restaurant::Restaurant(Restaurant&& order)
	{
		reservation = nullptr;
		*this = std::move(order);
	}

	Restaurant& Restaurant::operator=(Restaurant&& order)
	{
		if (this != &order)
		{
			delete[] this->reservation;
			this->reservation = order.reservation;
			this->length = order.length;

			order.length = 0;
			order.reservation = nullptr;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& order)
	{
		if (order.reservation == nullptr)
			os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl
			<< "The object is empty!" << std::endl
			<< "--------------------------" << std::endl;
		else
		{
			os << "--------------------------" << std::endl
				<< "Fancy Restaurant" << std::endl
				<< "--------------------------" << std::endl;

			for (size_t i = 0; i < order.length; i++)
			{
				os << order.reservation[i];
			}

			os << "--------------------------" << std::endl;
		}
		return os;
		
	}
}