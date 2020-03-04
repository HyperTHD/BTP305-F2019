// Name: Abdulbasid Gueld
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 11/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <iostream>

namespace sdds {

extern unsigned int g_maxSize;

class String {

    char* word;

    public:
        String();
        String(const char*);
        String(const String&);
        String& operator=(const String&);
        ~String();
        void display(std::ostream&) const;
    };
    std::ostream& operator<<(std::ostream& os, const String& word);
}
#endif