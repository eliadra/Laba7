#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

void prints(int x) { cout << " " << x; }
void prints(Person x) { x.getname(); }

template <class T>
class Massiv
{
	T *chislo;
	int size; // размер массива 
public:
	Massiv()// конструктор по умолчанию, без параметров
	{
			size = 5;
			chislo = new T[size]; // выделить место в памяти для массива
			for (int ix = 0; ix < size; ix++) // обнуляем массив
				chislo[ix] = (rand() % 13 - 2);
		}

	Massiv(int size)
	{
		this->size = size;
		chislo = new T[size]; // выделить место в памяти для массива
	}

	Massiv(Massiv&a)  
	{
		chislo = new T[a.size];
		size = a.size;
		for (int i = 0; i<size; i++)
			chislo[i] = a.chislo[i]; 
	}
	
	void input() 
	{
		for (int ix = 0; ix < size; ix++) // обнуляем массив
		{
			cout << "Vvedidete znachenie ";
			cin >> chislo[ix];
		}
	}
	
	~Massiv(){ delete[] chislo; }// освободить память, удалив массив
	
	int getSize() const { return size; }
	
	void print()  
	{
		for (int i = 0; i < size; i++)
		{
			prints(chislo[i]);
		}
		cout << endl;
	}

	friend Massiv operator+ (const Massiv &a, const Massiv &b) 
	{
		Massiv A(a.size + b.size);
		for (int i = 0; i < a.size; i++)
		{
			A.chislo[i] = a.chislo[i];
		}

		for (int j = 0; j < b.size; j++)
		{
			A.chislo[j + a.size] = b.chislo[j];
		}

		return A;
	}

	friend bool operator != (const Massiv&a, const Massiv&b)
	{
		if (a.size != b.size)
		return 1;
			else
				for (int i = 0; i < a.size; i++)
			{
				if (a.chislo[i] != b.chislo[i])
					return 1;
		}
		return 0;
	}

	T &operator[](int subscript) {
		if (subscript < 0 || subscript >= size)
		{
			cout << "\n Ошибка индекса: " << subscript << endl;
			exit(1); // завершить работу программы, неправильный индекс
		}
		return chislo[subscript]; // возврат ссылки на элемент массива
	}

	friend bool operator >(const Massiv &a, const Massiv&b) 
	{
		for (int i = 0; i < a.size; i++)
		{
			bool y = 0;
			for (int n = 0; n < b.size; n++)
			{
				if (b.chislo[i] == a.chislo[n])
				{
					y = 1;
					break;
				}

			}
			if (y == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	
	static int getCount() { return size; }
};