#include "LineManager.h"

LineManager::LineManager(const std::string& file, std::vector<Task*>& tasks, std::vector<CustomerOrder>& done) : m_cntCustomerOrder(0)
{
	std::ifstream m_file(file);
	
	std::string temp, task1, task2;

	if (!m_file)
		std::cerr << "File does not exist!";
	else
	{
		std::move(done.begin(), done.end(), std::back_inserter(ToBeFilled)); 

		std::reverse(ToBeFilled.begin(), ToBeFilled.end()); 

		std::copy(tasks.begin(), tasks.end(), std::back_inserter(AssemblyLine)); 

		m_cntCustomerOrder = ToBeFilled.size();

		while (std::getline(m_file, temp))
		{	
			task1 = temp.substr(0, temp.find_first_of('|')); 

			if (temp.find('|') != std::string::npos)
				task2 = temp.substr(temp.find_first_of('|') + 1, temp.length());
			else
				task2 = "";

			Task* ptr1 = nullptr;
			Task* ptr2 = nullptr;

	
			for (auto i = 0u; i < tasks.size(); ++i)
			{
				if (tasks[i]->getName() == task1) 
				{
					ptr1 = tasks[i]; 
					break;
				}
			}

			for (auto j = 0u; j < tasks.size(); ++j)
			{
				if (tasks[j]->getName() == task2)
				{
					ptr2 = tasks[j];
					break;
				}
			}
		
			if (ptr2 != nullptr)
			{
				ptr1->setNextTask(*ptr2);
			}

			if (ptr2 == nullptr)
				break;
		
		}
		task1.clear();
		task2.clear();
	}
}

bool LineManager::run(std::ostream& os)
{
	bool completed = false; 

	if (!ToBeFilled.empty()) 
	{
		Task* first_spot = AssemblyLine.at(4); // Power Supply has the correct order so make a pointer to that task and then add the order. Safer method would be a member variable that holds the address of the first task in case the location of the file changes
		*first_spot += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	
	for (auto i = 0u; i < AssemblyLine.size(); ++i)
	{
		AssemblyLine[i]->runProcess(os);
	}
	for (auto i = 0u; i < AssemblyLine.size(); ++i)
	{
		AssemblyLine[i]->moveTask();  
	}

	for (auto i = 0u; i < m_cntCustomerOrder; ++i)
	{
		if (AssemblyLine[i] != nullptr)
		{
			CustomerOrder tmp;
			if (AssemblyLine[i]->getCompleted(tmp))
			{
				Completed.push_back(std::move(tmp));	
			}
		}
	}

	if (m_cntCustomerOrder == Completed.size())
		completed = true;

	return completed;
}

void LineManager::displayCompleted(std::ostream& os) const
{
	for (const auto& i : Completed)
		i.display(os);
}

void LineManager::validateTasks() const
{
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [](Task* task) {
		task->validate(std::cout);
	});
}
