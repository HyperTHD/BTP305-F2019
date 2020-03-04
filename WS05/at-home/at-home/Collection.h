#pragma once

#include <iostream>
#include <string>
#include <iomanip>

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 20/10/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


namespace sdds 
{
	template<typename T>
	class Collection
	{
		std::string m_name;
		T* m_items;
		size_t m_size;
		void (*func)(const Collection<T>&, const T&);
	public:
		
		Collection(std::string name) : m_name(name), m_items(nullptr), m_size(0), func(nullptr){}
		
		Collection(const Collection&) = delete;
		
		Collection& operator=(const Collection&) = delete;
		
		~Collection() 
		{
			delete[] m_items;
		}
		
		const std::string& name() const
		{
			return m_name;
		}
		
		size_t size() const {
			return m_size;
		}
		
		void setObserver(void (*observer) (const Collection<T>&, const T&))
		{
			func = observer;
		};
		
		Collection<T>& operator+=(const T& item)
		{
			bool found = true;

			if (m_size != 0)
			{
				for (size_t i = 0; i < m_size; i++)
				{
					if (m_items[i].title() == item.title())
					{
						found = false;
					}
				}
			}
			if (found)
			{
				if (m_size != 0)
				{
					T* temp = new T[m_size];
					for (size_t j = 0; j < m_size; j++)
					{
						temp[j] = m_items[j];
					}
					delete[] m_items;
					m_items = new T[m_size + 1];

					for (size_t j = 0; j < m_size; j++)
					{
						m_items[j] = temp[j];
					}

					m_items[m_size] = item;
					m_size++;

				}

				else
				{
					m_size++;
					m_items = new T[m_size];
					m_items[0] = item;
				}
				if (func != nullptr)
				{
					func(*this, item);
				}
			}
			return *this;
		}
		
		T& operator[](size_t idx) const
		{
			std::string errorMsg = ("EXCEPTION: Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");

			if (idx >= m_size || idx < 0)
				throw std::out_of_range(errorMsg);
				
			else 
				return m_items[idx];
		}
		
		T* operator[](std::string title) const
		{
			T* found = nullptr;
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_items[i].title() == title)
				{
					found = &m_items[i];
				}
			}
			return found;
		}
		
		
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& col)
	{
		for (size_t i = 0; i < col.size(); i++)
		{
			os << col[i];
		}
		return os;
	}
}