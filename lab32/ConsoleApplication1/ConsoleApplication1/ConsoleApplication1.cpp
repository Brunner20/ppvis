
#include "pch.h"
#include <iostream>
#include "bank.h"
#include <fstream>
using namespace std;



int main(int argc, char *argv[])
{
	setlocale(SEEK_SET, "rus");
	string str1 = (string)argv[1];
	string str2 = (string)argv[2];
	read r;
	vector<cart> carte=r.read_cart(str1);
	vector<base> bas = r.read_base(str2);
	session s1(carte, bas);
    s1.beg();
    s1.end(str1);

}