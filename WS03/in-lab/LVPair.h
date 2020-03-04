#pragma once
/*
	Name: Abdulbasid Guled
	Student Number: 156024184
	Email: aguled5@myseneca.ca
	Due Date: 25/09/2019
*/

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>

namespace sdds
{
template <typename L, typename V>
class LVPair
{
	L m_label;
	V m_value;

public:
	LVPair()
	{
		m_label = L{};
		m_value = V{};
	}

	LVPair(const L &aa, const V &bb) : LVPair()
	{
		m_label = aa;
		m_value = bb;
	}

	const L &key() const
	{
		return m_label;
	}

	const V &value() const
	{
		return m_value;
	}

	void display(std::ostream &os) const
	{
		os << m_label << " : " << m_value << std::endl;
	}
};

template <typename L, typename V>
std::ostream &operator<<(std::ostream &os, const sdds::LVPair<L, V> &pair)
{
	pair.display(os);
	return os;
}

} // namespace sdds
#endif