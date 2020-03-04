#pragma once
/*
	Name: Abdulbasid Guled
	Student Number: 156024184
	Email: aguled5@myseneca.ca
	Due Date: 29/09/2019
*/

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>
#include <string>

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
		m_label = {};
		m_value = {};
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

	virtual void display(std::ostream &os) const
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

template <typename L, typename V>
class SummableLVPair : public LVPair<L, V>
{

	static V init_val;
	static size_t m_width;

public:
	static const V &getInitialValue()
	{
		return init_val;
	}

	SummableLVPair()
	{
		init_val = V{};
	}

	SummableLVPair(const L &lbl, const V &val) : LVPair<L, V>(lbl, val)
	{
		if (m_width < lbl.size())
		{
			m_width = lbl.size();
		}
	}

	V sum(const L &lbl, const V &val) const
	{
		if (this->key() == lbl)
		{
			return this->value() + val;
		}
		else
		{
			return val;
		}
	}
	void display(std::ostream &os) const
	{
		os << std::setw(m_width) << std::left;
		LVPair<L, V>::display(os);
		os << std::right;
	}
};

template <class L, class V>
size_t SummableLVPair<L, V>::m_width = 0;

template <class L, class V>
V SummableLVPair<L, V>::init_val = V{};

template <>
SummableLVPair<std::string, std::string>::SummableLVPair() : LVPair<std::string, std::string>(std::string{}, "")
{
	this->init_val = "";
}

template <>
SummableLVPair<std::string, int>::SummableLVPair() : LVPair<std::string, int>(std::string{}, 0)
{
	this->init_val = 0;
}
template <>
std::string SummableLVPair<std::string, std::string>::sum(const std::string &label, const std::string &value) const
{
	if (this->key() == label)
	{
		if (value == "")
		{
			return this->value();
		}
		else
		{
			return value + ", " + this->value();
		}
	}
	else
	{
		return value;
	}
}

} // namespace sdds
#endif