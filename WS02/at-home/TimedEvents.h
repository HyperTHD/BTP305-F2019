// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 22/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>

namespace sdds
{
const int max_records = 7;

class TimedEvents
{
    int counter;
    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;

    struct
    {
        std::string m_eventName;
        std::string m_unitsOfTime;
        std::chrono::steady_clock::duration m_duration;
    } records[max_records];

public:
    TimedEvents();
    void startClock();
    void stopClock();
    void recordEvent(const char *);
    friend std::ostream &operator<<(std::ostream &, TimedEvents &);
};
} // namespace sdds

#endif