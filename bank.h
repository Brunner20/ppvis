#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class cart
{
public:
	string id;
	string name;
	string pin;
	double cash;
	string date;
};
class base {
public:
	string id_base;
};
class read {
	public:
	vector<cart>read_cart(string);
	vector<base>read_base(string);
	
};
class main_windows
{   
public:

	main_windows(vector<cart>,vector<base>);
	int print();
    void card_choose();
    bool continu();

	int value;
	vector<cart> carte;
	vector<base> bas;
};


class check :public main_windows {

public:
	check(main_windows );
	double check_the_balance();
};
class check_pin :public main_windows {
public:
	check_pin(main_windows);
	bool checkpin();
};
class pull :public main_windows {
public:
	pull(main_windows);
	double pull_cash();
};
class put :public main_windows {
public:
	put(main_windows );
	void put_money_in_the_account();
};
class trans :public main_windows {
public:
	trans(main_windows);
	void transfer();
};
class change :public main_windows {
public:
	change(main_windows);
	void change_pin();
};
class info:public main_windows
{
public:
	info(main_windows);
	void out();
};
class session
{
public:
	session(vector<cart>,vector<base>);
	void beg();
	void end(string);

private:
	vector<cart> car;
	vector<base> bas;
	
};

