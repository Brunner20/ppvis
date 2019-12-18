#include"pch.h"
#include "bank.h"
#include <string>
#include <vector>
#include <fstream>

vector<cart>read::read_cart(string file) { 

	vector<cart> carte;
	int i = 0;
	ifstream fin(file);
	if (fin.is_open())
		while (!fin.eof()) {
			carte.resize(i + 1);
			fin >> carte[i].id;
			fin >> carte[i].name;
			fin >> carte[i].pin;
			fin >> carte[i].cash;
			fin >> carte[i].date;
			i++;
		}
	return carte;
}
vector<base>read::read_base(string file) {
	vector<base> bas;
	int i = 0;
	ifstream fin(file);
	while (!fin.eof())
	{
		bas.resize(i + 1);
		fin >> bas[i].id_base;
		i++;
	}
	return bas;
}

main_windows::main_windows(vector<cart> cart = {}, vector<base>bas = {}) {
	carte = cart;
	this->bas = bas;
}
int main_windows::print() {
	double i;
	cout << "Выберете операцию:"<<endl;
	cout << "1-Проверка счета\t\t2-Снятие наличных\n3-Положить деньги на счет\t4-Перевод с карты на карту\n5-Изменение PIN\t\t\t6-Информация о счете\n";
	cout << "7-поменять рабочую карту\t8-выход\n";
	cin >> i;
	return i;
}
void main_windows::card_choose() {
	double card_number;
	do {
		cout << "выберите карту для работы:" << endl;
		for (int i = 0; i < bas.size(); i++) {
			cout << i + 1 << ") " << bas[i].id_base << endl;
		}
		cin >> card_number;
	} while (card_number > bas.size() || card_number <= 0);

	system("cls");
	value= card_number - 1;
}
bool main_windows::continu() {
	double k;
	cout << "Желаете продолжить?\n1-да\t2-нет\n";
	cin >> k;
	if (k == 2) {
		return false;
	}
	system("cls");
	return true;
}

bool check_pin::checkpin() {
	string pas; int i = 0;
	cout << "Введите PIN:";
	cin >> pas;
	do {
		if (pas == carte[value].pin)
			return true;
		i++;
		cout << "Повторите ввод:";
		cin >> pas;
	} while (i < 2);
	return false;
}
check_pin::check_pin(main_windows wind ) {
	this->carte = wind.carte;
	value = wind.value;
}

check::check(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
double  check::check_the_balance() {
		return carte[value].cash;
}

pull::pull(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
double pull::pull_cash() {
	double amo;
		cout << endl << "Введите сумму:";
		cin >> amo;
		if (amo <= carte[value].cash) {
			carte[value].cash -= amo;
			return amo;
		}
		else cout << "Недостаточно средств" << endl;

	return 0;
}

put::put(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
void put::put_money_in_the_account() {
	cout << "Введите сумму:" << endl;
	double money;
	cin >> money;
	carte[value].cash += money;
	cout << "Завершено успешно"<<endl;
}

trans::trans(main_windows wind) {
	this->carte = wind.carte;
	this->bas = wind.bas;
	value = wind.value;
}
void trans::transfer() {
	cout << "Доступные карты:" << endl;
	for (int i = 0; i < carte.size(); i++) {
		cout << carte[i].id << endl;
	}
	string id_new;
	cout << "Введите номер карты получателя: ";
	cin >> id_new;
	double number;
	for (int i = 0; i < bas.size(); i++) {
		if (bas[i].id_base == id_new && id_new!=bas[value].id_base)
		{
			number = i;
			break;
		}
		if (i == bas.size() - 1) {
			cout << "Неверный ввод" << endl;
		}
	}
	double sum;
		cout << endl << "введите сумму:";
		cin >> sum;
		if (sum <= carte[value].cash) {
			carte[number].cash += sum;
			carte[value].cash-= sum;
			cout << "успешно завершено"<<endl;
			
		}
		else cout << "недостаточно средств" << endl;
		

}

change::change(main_windows wind) {
	this->carte = wind.carte;
	this->bas = wind.bas;
	value = wind.value;
}
void change::change_pin() 
{
	string pin_old, pin_new;
	cout << "Введите старый пароль:";
	cin >> pin_old;
	if (pin_old == carte[value].pin)
	{
		cout << endl << "Введите новый паоль:";
		cin >> pin_new;
		carte[value].pin = pin_new;
		cout << "завершено" << endl;
		

	}
	else cout << "неверный пароль" << endl;

}

info::info(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
void info::out(){
	cout << "Владелец карты: " <<carte[value].name<<endl;
	cout << "Срок действия карты: " << carte[value].date << endl;

}

session::session(vector<cart>c, vector<base>b) {
	car = c;
	bas = b;
}
void session::beg() {
	int i = 0;
	double k;
	main_windows win(car,bas);
	win.card_choose();
	check_pin pin(win);
		i = 0;
		if (!pin.checkpin()) i = 1;
		system("cls");
		while (!i)
		{	
			switch (win.print())
			{
			case 1: {
				check ch(win);
				cout << "На вашем счете: " << ch.check_the_balance() << endl;
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 2: { 
				pull p(win);
				p.pull_cash();
				win = p;
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 3: {
				put pt(win);
				pt.put_money_in_the_account();
				win = pt;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 4: {
				trans tr(win);
				tr.transfer();
				win = tr;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 5: {
				change ch(win);
				ch.change_pin();
				win = ch;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break;
			}
			case 6: {
				info inf(win);
				inf.out();
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 7: {
				win.card_choose();
				system("cls");
				break; }
			case 8: 
			{
				i = 1; 
				break;
			}
			default:
			{
				cout << "повторите ввод" << endl; break; }
			}
		}
		car = win.carte;
	}


void session::end(string file) {
	ofstream fout(file);
	for (int i = 0; i < car.size(); i++)
	{
		fout << car[i].id<<"\n";
		fout << car[i].name << "\n";
		fout << car[i].pin << "\n";
		fout << car[i].cash << "\n";
		if (i == car.size() - 1)fout << car[i].date;
		else fout << car[i].date << "\n";
	}


}
/*1234567854784568
ivanov
1111
9000
12.20
1234567854780000
petrov
2222
5500
08.20
9876543219876543
sidorov
3333
11000
10.21*/