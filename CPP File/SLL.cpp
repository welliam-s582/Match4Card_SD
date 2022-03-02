#include "SLL.h"

	Link::Link()
	{
		head = NULL;
		tail = NULL;
		cnt = 0;
	}
	void Link::input_data(string data)
	{
		Node* baru;
		baru = new Node;
		baru->set_data(data);
		if (head == NULL)
		{
			head = baru;
			tail = head;
		}
		else
		{
			tail->set_link(baru);
			tail = baru;
		}
		cnt++;
	}


	void Link::delete_by_index(int index)
	{
		Node* temp, * temp2;
		int idx = 0;

		temp = head;
		temp2 = NULL;

		if (temp != NULL && index == 0)
		{
			head = temp->get_link(); 
			delete temp; 
			return;
		}
		
		else if (temp != NULL && index > 0)
		{
			while (temp != NULL && idx != index)
			{
				temp2 = temp;
				temp = temp->get_link();
				idx++;
			}
		}

		else if (temp == NULL)
		{
			return;
		}

		temp2->set_link(temp->get_link()); 
		if (temp->get_link()==NULL)
		{
			tail = temp2;
		}
		
		delete temp;
		
	}

	void Link::reset()
	{
		head = NULL;
		tail = NULL;
	}

	void Link::print()
	{
		Node* tmp=head;
		while (tmp != NULL)
		{
			cout << " " << tmp->get_data() << " ";
			tmp = tmp->get_link();
		}

		cout << endl;

	}

	string Link::get_data_by_index(int index)
	{
		int pos=0;
		Node* tmp = head;
		while (pos!=index)
		{
			tmp = tmp->get_link();
			pos++;
		}

		return tmp->get_data();

	}

	int Link::get_ttl()
	{
		return cnt;
	}

