
// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 10/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"

	size_t Item::m_widthField = 1;

	Item::Item(const std::string& str)
	{
		Utilities util; // Utility object
		
		std::string temp = str; 

		bool isFound = true; // Assume that it exists

		size_t next_pos = 0; // Start at the first position

		// Collect the tokens

		m_name = util.extractToken(temp, next_pos, isFound);
		m_serialNumber = std::stoul(util.extractToken(temp, next_pos, isFound));
		m_quantity = std::stoi(util.extractToken(temp, next_pos, isFound));

		// Check the field width after the first 3 since description has no formatting option
		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();

		m_description = util.extractToken(temp, next_pos, isFound);

		// Update the field width

		if (m_widthField > util.getFieldWidth())
			m_widthField = util.getFieldWidth();
	}

	const std::string& Item::getName() const
	{
		return m_name;
	}

	const unsigned int Item::getSerialNumber()
	{
		return m_serialNumber++;
	}

	const unsigned int Item::getQuantity()
	{
		return m_quantity;
	}

	void Item::updateQuantity()
	{
		if (m_quantity >= 0)
			m_quantity--;
	}

	void Item::display(std::ostream& os, bool full) const
	{
		if (!full)
		{
			os << std::setw(m_widthField) << std::left << m_name 
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ') << std::endl;
		}
		else
		{
			os  << std::setw(m_widthField) << std::left << m_name
				<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ')
				<< " Quantity: " << std::setw(m_widthField) << std::left << m_quantity
				<< " Description: " << m_description << std::endl;
		}	
	}
