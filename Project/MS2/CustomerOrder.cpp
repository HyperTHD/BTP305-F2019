#include "CustomerOrder.h"

	// static variable declaration

	size_t CustomerOrder::m_widthField = 1;

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}

	CustomerOrder::CustomerOrder(std::string& str) : CustomerOrder()
	{

		Utilities util;

		std::string temp = str;

		bool isFound = true;

		size_t next_pos = 0;

		// Collect the tokens

		m_name = util.extractToken(temp, next_pos, isFound);

		m_product = util.extractToken(temp, next_pos, isFound);

		m_cntItem = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;

		m_lstItem = new ItemInfo * [m_cntItem];

		for (auto i = 0u; i < m_cntItem; i++)
		{
			std::string data = util.extractToken(temp, next_pos, isFound);
			m_lstItem[i] = new ItemInfo(data);
		}

		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();
	}
	

		// Move Semantics (Constructor and Operator=)

		CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
		{
			m_lstItem = nullptr;
			*this = std::move(src);
		}

		CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) 
		{
			if (this != &src)
			{
				m_name = src.m_name;
				m_product = src.m_product;
			
				for (auto i = 0u; i < m_cntItem; ++i)
					delete m_lstItem[i];
				delete[] m_lstItem;

				m_cntItem = src.m_cntItem;
				m_lstItem = src.m_lstItem;

				src.m_lstItem = nullptr;
				src.m_name = "";
				src.m_product = "";
				src.m_cntItem = 0;
			}
			return *this;
		}
		
		CustomerOrder::CustomerOrder(const CustomerOrder& src)
		{
			throw "Error! Copy Operations are not allowed!";
		}

		CustomerOrder::~CustomerOrder()
		{
			for (auto i = 0u; i < m_cntItem; ++i)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}

		bool CustomerOrder::getItemFillState(std::string str) const
		{
			bool confirm = true; // Assume that the item is filled

			for (size_t i = 0; i < m_cntItem; i++)
			{
				if (m_lstItem[i]->m_itemName == str) // If the item exists in the list
				{
					if (!m_lstItem[i]->m_fillState) // If the item's filled state is not full
					{
						confirm = false; 
					}
				}
			}
			return confirm;
		}

		bool CustomerOrder::getOrderFillState() const
		{
			bool confirm = true; // Assume that all items are filled

			for (size_t i = 0; i < m_cntItem; i++)
			{
				if (!m_lstItem[i]->m_fillState)
				{
					confirm = false;
				}
			}
			return confirm;
		}

		void CustomerOrder::fillItem(Item& item, std::ostream& os)
		{
				bool found = false; // Assume it's not found
				size_t cnt = 0; // to get the customer order needed. Have to get the right index
				for (size_t i = 0; i < m_cntItem; i++)
				{
					if (m_lstItem[i]->m_itemName == item.getName())
					{
						found = true;
						cnt = i;
					}	
				}

				if (found)
				{
					item.updateQuantity();
					m_lstItem[cnt]->m_serialNumber = item.getSerialNumber();
					m_lstItem[cnt]->m_fillState = true;
					os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
				}
			
				if (item.getQuantity() < 0)
				{
					os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
				}
		}
		
		void CustomerOrder::display(std::ostream& os) const
		{
			os << m_name << " - " << m_product << std::endl;

			for (auto i = 0u; i < m_cntItem; ++i)
			{
				os << "[" << std::setw(6) << std::setfill('0') << std::left << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";

				(m_lstItem[i]->m_fillState == false) ? os << "MISSING" : os << "FILLED";

				os << std::endl;
			}
		}

