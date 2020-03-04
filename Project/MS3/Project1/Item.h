#pragma once

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "Utilities.h"
#include <iomanip>

	class Item
	{
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
		static size_t m_widthField;

	public:
		Item(const std::string&);
		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity();
		void updateQuantity();
		void display(std::ostream&, bool) const;
	};


#endif