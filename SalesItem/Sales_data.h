#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;
struct Sales_data
{
friend istream& read(istream&, Sales_data&);
friend ostream& print(ostream&, const Sales_data&);
public:
	Sales_data() = default;
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

};

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0.0;
};
Sales_data& Sales_data::combine(const Sales_data& rhs) 
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
};

istream& read(istream& is, Sales_data& item) 
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
};

ostream& print(ostream& os, const Sales_data& item) 
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price() << std::endl;
	return os;
};

//Sales_data add(const Sales_data&, const Sales_data&);


#endif // !SALES_DATA_H