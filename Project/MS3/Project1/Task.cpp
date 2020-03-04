#include "Task.h"

Task::Task(const std::string& line) : Item(line), m_pNextTask(nullptr) {}

void Task::runProcess(std::ostream& os)
{
	if (!m_orders.empty())
	{
		if (m_orders.back().getItemFillState(Item::getName()) == false)
		{
			m_orders.back().fillItem(*this, os);
		}
	}
}

bool Task::moveTask()
{
	bool pushed = false; 

	if (!m_orders.empty()) 
		{
			if (m_orders.back().getItemFillState(Item::getName()) == true)
			{
				if (m_pNextTask != nullptr)
				{
					m_pNextTask->m_orders.push_front(std::move(this->m_orders.back()));
					m_orders.pop_back();
					pushed = true;
				}
			}
		}
	return pushed;
}

void Task::setNextTask(Task& task)
{
	m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& order)
{
	bool pushed = false; 

	if (!m_orders.empty() && m_orders.back().getOrderFillState()) 
	{
		order = std::move(m_orders.back()); 
		m_orders.pop_back();
		pushed = true;
	}

	return pushed;
}

void Task::validate(std::ostream& os)
{
	if (m_pNextTask == nullptr)
		os << Item::getName() << " --> " << "END OF LINE" << std::endl;
	else
		os << Item::getName() << " --> " << m_pNextTask->Item::getName() << std::endl;
	
}

Task& Task::operator+=(CustomerOrder&& order)
{
	m_orders.push_front(std::move(order));
	return *this;
}


