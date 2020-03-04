// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 22/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>
#include <string>

namespace sdds
{
class Text
{
    std::string *m_collections;
    int counter;

public:
    Text();
    Text(const char *);
    Text(const Text &);
    Text &operator=(const Text &);
    Text(Text &&);
    Text &operator=(Text &&);
    ~Text();
    size_t size() const;
};
} // namespace sdds

#endif