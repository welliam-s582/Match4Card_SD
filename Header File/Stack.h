#pragma once
#include <iostream>
#include <string>
using namespace std;
#define max 4

class cstack
{
public:
	cstack();
	~cstack();


	int is_empty();
	bool is_full();
	void push(string isi);
	string pop();
	void print();
	string print_data();

private:
	string data[max];
	int top;

};


