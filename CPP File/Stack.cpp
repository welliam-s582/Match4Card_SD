#include "Stack.h"


cstack::cstack()
{
	top = -1;
}
cstack::~cstack()
{
	
}

int cstack::is_empty()
{
	return top < 0;
}
 
bool cstack::is_full()
{
	if (top + 1 == max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cstack::push(string isi)
{
	if (!is_full())
	{
		top++;
		data[top] = isi;
	}
}
string cstack::pop()
{
	if (!is_empty())
	{
		top--;
		return data[top + 1];
	}
}
void cstack::print()
{
	for (int i = 0; i <= top; i++)
	{
		cout << data[i];
	}

}

string cstack::print_data()
{
	return data[top];
}
