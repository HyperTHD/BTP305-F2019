// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 09/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		reservation = nullptr;
		size = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& response)
	{
		this->reservation = nullptr;
		*this = response;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& response)
	{
		if (this != &response)
		{
			this->size = response.size;
			delete[] this->reservation;

			this->reservation = new Reservation const *[this->size];

			for (int i = 0; i < this->size; i++)
			{
				this->reservation[i] = response.reservation[i];
			}
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] this->reservation;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& response)
	{
		reservation = nullptr;
		*this = std::move(response);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& response)
	{
		if (this != &response)
		{
			this->size = response.size;
			delete[] reservation;
			this->reservation = response.reservation;

			response.size = 0;
			response.reservation = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
			bool found = true;

			if (this->size != 0)
			{
				for (int i = 0; i < size; i++)
				{
					if (reservation[i] == &res)
					{
						found = false;
					}
				}
			}
			if (found)
			{
				ConfirmationSender temp = *this;
				if (this->size != 0)
				{
					delete[] this->reservation;
				}

				reservation = new const Reservation*[temp.size + 1];

				for (int j = 0; j < size; j++)
				{
					this->reservation[j] = temp.reservation[j];
				}
				this->reservation[size] = &res;
				this->size++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->reservation[i] == &res)
			{
				this->reservation[i] = nullptr;
				this->size--;
				break;
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& response)
	{
		if (response.reservation == nullptr)
			os << "--------------------------" << std::endl
			<< "Confirmations to Send" << std::endl
			<< "--------------------------" << std::endl
			<< "The object is empty!" << std::endl
			<< "--------------------------" << std::endl;
		else
		{
			os << "--------------------------" << std::endl
				<< "Confirmations to Send" << std::endl
				<< "--------------------------" << std::endl;

			for (size_t i = 0; i < response.size; i++)
			{
				os << *response.reservation[i];
			}

			os << "--------------------------" << std::endl;
		}
		return os;
	}

}