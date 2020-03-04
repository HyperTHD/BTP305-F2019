// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 22/09/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{

TimedEvents::TimedEvents()
{
    for (int i = 0; i < max_records; i++)
    {
        records[i].m_eventName = "";
        records[i].m_unitsOfTime = "";
    }
}

void TimedEvents::startClock()
{
    m_start = std::chrono::steady_clock::now();
}

void TimedEvents::stopClock()
{
    m_end = std::chrono::steady_clock::now();
}

void TimedEvents::recordEvent(const char *eventName)
{
    if (counter < max_records)
    {
        records[counter].m_eventName = eventName;
        records[counter].m_unitsOfTime = "Nanoseconds";
        records[counter].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);
        counter++;
    }
}

std::ostream &operator<<(std::ostream &os, TimedEvents &e)
{
    os << "Execution Times:\n";
    os << "--------------------------\n";

    for (int i = 0; i < e.counter; i++)
    {
        os << std::setw(20) << std::left << e.records[i].m_eventName << std::setw(12) << std::right << e.records[i].m_duration.count() << " "
           << e.records[i].m_unitsOfTime << std::endl;
    }
    os << "--------------------------\n";

    return os;
}
} // namespace sdds