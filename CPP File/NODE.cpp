#include "NODE.h"

	Node::Node()
	{
		link = NULL;
		/*prev = NULL;*/
	}
	string Node::get_data()
	{
		return data;
	}

	void Node::set_data(string x)
	{
		data = x;

	}
	Node* Node::get_link()
	{
		return link;

	}
	/*Node* Node::pget()
	{
		return prev;

	}*/
	void Node::set_link(Node* linkNode)
	{
		link = linkNode;
	}
	/*void Node::pset(Node* prevNode)
	{
		prev = prevNode;
	}*/

