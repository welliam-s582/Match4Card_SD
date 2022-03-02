#pragma once
#include "NODE.h"

class Link
{
private:
	Node* head, * tail;
	int cnt;
public:

	Link();
	
	void input_data(string data);
	void delete_by_index(int index);
	void reset();
	void print();
	string get_data_by_index(int index);
	int get_ttl();

};