
/*
	Name: Abdulbasid Guled
	Student Number: 156024184
	Email: aguled5@myseneca.ca
	Due Date: 29/09/2019
*/

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

namespace sdds
{

template <typename T, int N>
class List
{
	T list[N];
	int m_maxSize = 0;

public:
	// return the size of the list

	size_t size() const
	{
		return m_maxSize;
	}

	// Return an element at the specified index

	const T &operator[](size_t i) const
	{
		return list[i];
	}

	// Either do nothing or add a copy of the parameter to the array
	// Check if it's higher than the maximum size
	void operator+=(const T &tt)
	{
		if (m_maxSize < N)
		{
			list[m_maxSize] = tt;
			m_maxSize++;
		}
	}
};

template <typename L, typename V, typename T, unsigned int N>
class LVList : public List<T, N>
{

public:
	V accumulate(const L &label) const
	{
		V currentInstance = T::getInitialValue();

		for (size_t i = 0; i < this->size(); i++)
		{
			currentInstance = (*this)[i].sum(label, currentInstance);
		}
		return currentInstance;
	}
};

} // namespace sdds
#endif