// Лабораторная 5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Massiv.h"
#include "Person.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	Massiv <int> A(6);
	A.input();
	A.print();

	Massiv <int> B(2);
	B.input();
	B.print();

	Massiv <int> C((Massiv <int>)(A + B));
	C.print();


	cout << C[2] << endl;
	C.getSize();

	cout << "Proverka na vhogdenie:" << endl;
	cout << (A > C);
	cout << endl;
	cout << (A > B);
	cout << endl;


	cout << "Proverka na neravenstvo:" << endl;
	cout << (A != B);
	cout << endl;
	cout << (B != C);
	cout << endl;


	Person Sergei;
	Sergei.setname("Сергей");

	Person Roman;
	Roman.setname("Роман");

	Person Mihail;
	Mihail.setname("Михаил");

	Massiv<Person>K(3); //массив указателей на персоны
	K[0] = Sergei;
	K[1] = Roman;
	K[2] = Mihail;
	K.print();

	exit (0);
}

