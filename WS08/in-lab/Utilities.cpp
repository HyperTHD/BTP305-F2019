// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 13/11/2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers


		for (auto i = 0u; i < desc.size(); ++i)
		{
			for (auto x = 0u; x < price.size(); ++x)
			{
				if (price[x].code == desc[i].code)
				{
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;					
					break;
				}
			}
		}		

		return priceList;
	}
}
