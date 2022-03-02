#pragma once
#include <iostream>
#include <string>
using namespace std;
class Node
{
private:
	string data;
	Node* link;
	/*Node* prev; */
public:
	Node();
	
	string get_data();

	void set_data(string x);
	
	Node* get_link();
	
	/*Node* pget();*/
	
	void set_link(Node* nextNode);
	
	/*void pset(Node* prevNode);*/

};