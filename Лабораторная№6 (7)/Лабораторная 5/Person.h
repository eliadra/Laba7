#pragma once
#include <iostream>
using namespace std;

class Person
{
	char *name=0;
	int size=0;
public:
	Person(void) { name = new char[0]; }
	
	Person(const char*name)
	{
		setname(name);
	}
	
	void setname(const char *name)
	{
		delete[]this->name;
		size = strlen(name);
		this->name = new char[strlen(name)];
		for (int i = 0; i < strlen(name); i++)
		{
			this->name[i] = name[i];
		}
	}
	
	void getname()
	{ 
		cout << "имя персоны: " << endl;
	for (int i = 0; i < size; i++)
		{
		cout << name[i];
			}
	cout << endl;
	}

	friend istream& operator >> (istream& input, Person& x) { return input>>x.name; }
	
	~Person(void) { delete[]name; };
};