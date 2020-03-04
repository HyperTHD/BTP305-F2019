#include "CustomerOrder.h"

	size_t CustomerOrder::m_widthField = 1;

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}

	void CustomerOrder::Deallocate()
	{
		for (auto i = 0u; i < m_cntItem; ++i)
			delete m_lstItem[i];

		delete[] m_lstItem;
	
		m_lstItem = nullptr;
	}
	
	CustomerOrder::CustomerOrder(std::string& str) : CustomerOrder()
	{
		Utilities util;

		std::string temp = str;

		bool isFound = true;

		size_t next_pos = 0;

		m_name = util.extractToken(temp, next_pos, isFound);

		m_product = util.extractToken(temp, next_pos, isFound);

		m_cntItem = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;

		m_lstItem = new ItemInfo * [m_cntItem];

			for (auto i = 0u; i < m_cntItem; ++i)
			{
				std::string data = util.extractToken(temp, next_pos, isFound);
				m_lstItem[i] = new ItemInfo(data);
			}
		
			if (m_widthField < util.getFieldWidth())
				m_widthField = util.getFieldWidth();
	}
	
		CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : CustomerOrder::CustomerOrder()
		{	
			*this = std::move(src);
		}

		CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) 
		{
			if (this != &src)
			{
				m_name = src.m_name;
				m_product = src.m_product;
				if(m_cntItem > 0)
				this->Deallocate();
				delete[] m_lstItem;
				m_cntItem = src.m_cntItem;
				m_lstItem = src.m_lstItem;

				src.m_lstItem = { nullptr };
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
			Deallocate();
		}

		bool CustomerOrder::getItemFillState(std::string str) const
		{
			bool confirm = true; 

			for (size_t i = 0; i < m_cntItem; i++)
			{
				if (m_lstItem[i]->m_itemName == str) 
				{
					if (!m_lstItem[i]->m_fillState) 
					{
						confirm = false; 
					}
				}
			}
			return confirm;
		}

		bool CustomerOrder::getOrderFillState() const
		{
			bool confirm = true; 

			for (size_t i = 0; i < m_cntItem; i++)
			{
				if (!m_lstItem[i]->m_fillState)
				{
					confirm = false;
					break;
				}
			}
			return confirm;
		}

		void CustomerOrder::fillItem(Item& item, std::ostream& os)
		{

			for (auto i = 0u; i < m_cntItem; ++i) {

				if (m_lstItem[i]->m_itemName == item.getName()) {

					if (item.getQuantity() > 0) { 

						item.updateQuantity();
						m_lstItem[i]->m_serialNumber = item.getSerialNumber();
						m_lstItem[i]->m_fillState = true;

						os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;

					}
					else {
						os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
					}
				}
			}
		}
		
		void CustomerOrder::display(std::ostream& os) const
		{
			os << m_name << " - " << m_product << std::endl;

			for (auto i = 0u; i < m_cntItem; ++i)
			{
				os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ') << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";

				(m_lstItem[i]->m_fillState == false) ? os << "MISSING" : os << "FILLED";

				os << std::endl;
			}
		}

