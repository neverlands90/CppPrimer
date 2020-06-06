// CppPrimer.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include <fstream>
#include "Sales_item.h"
#include "..\CppPrimer.h"

std::ifstream file;
void book_sales_data() {
	file.open((std::string)PROJECT_SOURCE_DIR + "/SalesItem/book_sales");
	std::cin.rdbuf(file.rdbuf());
}


int main()
{
	book_sales_data(); //cin重定向到文件
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
	return 0;
}
