// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 18/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream>
#include "Text.h"

namespace sdds
{

    Text::Text()
    {
        m_collections = nullptr;
        counter = 0;
    }

    Text::Text(const char* Book)
    {
        std::string buffer = {};
        std::ifstream file;
        file.open(Book);

        if(file.is_open())
        {
            while(std::getline(file, buffer, ' '))
                counter++;
        }

        m_collections = new std::string[counter];

        int i = 0;
        std::string line = {};

        while (std::getline(file, m_collections[i], ' '))
        {
            m_collections[i] = line;
            i++;
        }
        counter--;
    }

    Text::Text(const Text& other)
    {
        m_collections = nullptr;
        *this = other;
    }

    Text& Text::operator=(const Text& other)
    {
        if (this != &other)
        {
            counter = other.counter;
            delete[] m_collections;
            m_collections = new std::string[counter];
            
            for (int i = 0; i < size_t(counter); i++)
                m_collections[i] = other.m_collections[i];
        }
        return *this;
    }

    Text::~Text()
    {
        delete[] m_collections;
    }

    size_t Text::size() const
    {
        return counter;
    }

}
