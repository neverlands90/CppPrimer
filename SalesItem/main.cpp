// CppPrimer.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include <fstream>
#include "Sales_item.h"
#include "Sales_data.h"
#include "..\CppPrimer.h"

std::ifstream file;
void book_sales_data() {
	file.open((std::string)PROJECT_SOURCE_DIR + "/SalesItem/book_sales");
	std::cin.rdbuf(file.rdbuf());
}


int sales_item_function() 
{
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cerr << "No Data?!" << std::endl;
		return -1;
	}
}

int sales_data_function() 
{
	Sales_data total;
	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin,trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(std::cout, total);
				total = trans;
			}
		}
		print(std::cout, total);
	}
	else
	{
		std::cerr << "No Data?!" << std::endl;
		return -1;
	}

}
int main()
{
	book_sales_data(); //cin重定向到文件
	//sales_item_function();
	sales_data_function();
}
