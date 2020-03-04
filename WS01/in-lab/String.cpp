// Name: Abdulbasid Gueld
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 11/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace sdds {

    unsigned int g_maxSize = 3;

    String::String() 
    {
        word[0] = '\0';
    }

    String::String(const char* Word)
    {
       if (Word == nullptr)
       {
           *this = String();
       }
       else 
       {
           strncpy(word, Word, 3);
           word[strlen(word)] = '\0';
       }
    }

    void String::display(ostream& os) const 
    {
        os << word;
    }

    ostream& operator<<(ostream& os, const String& Word)
    {
        static int counter = 0;
        counter++;
        cout << counter << ": ";
        Word.display(os);
        return os;
    }

}
