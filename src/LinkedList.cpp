#include "LinkedList.h"
#include <iostream>

using namespace std;
/*---------------------------------------------//
LinkedList
//---------------------------------------------*/
LinkedList::LinkedList()
{
	head = NULL;
}
bool LinkedList::empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
void LinkedList::push_back(int PosX, int PosY)//add new Node to the end of list
{
	if (empty())
		head = new Node(PosX, PosY);
	else
	{
		Node *p = head;

		while (p->getNext() != NULL)
			p = p->getNext();
		p->setNext(new Node(PosX, PosY));
		p = nullptr;//avoid dangling pointer
	}
}
int LinkedList::size()//get the size of the list
{
	if (empty())
		return 0;
	else
	{
		int i = 1;
		//int i{ 1 }//new standard writing style;
		Node *p = head;
		//Node *p{ head };//new standard writing style;
		while (p->getNext() != NULL)
		{
			p = p->getNext();
			i++;
		}
		p = NULL;//avoid dangling pointer
		//p=nullptr;//new standard NULL value
		return i;
	}
}
void LinkedList::output()//output all stored values of the list
{
	if (empty())
		cout << "List is empty!" << endl;
	else
	{
		int i = 1;
		Node *p = head;
		//Node *p{ head };//new standard writing style
		while (p->getNext() != NULL)
		{
			cout << "Index " << i - 1 << ", Node " << i << ": X=" << p->getPosX() << "; Y=" << p->getPosY() << "; " << endl;
			p = p->getNext();
			i++;
		}
		cout << "Index " << i - 1 << ", Node " << i << ": X=" << p->getPosX() << "; Y=" << p->getPosY() << "; " << endl;
		p = NULL;//avoid dangling pointer
		//p=nullptr;//new standard NULL value
	}
}
void LinkedList::clear()//clear all nodes in the list
{
	delete head;
	head = NULL;
	//head=nullptr;//new standard NULL value
}
LinkedList::~LinkedList()
{
	delete head;
	head = NULL;
	//head=nullptr;//new standard NULL value
	/*
	For testing destructor, you can add:
	cout << "Destructor of Linkedlist" << endl;
	*/
}

int LinkedList::getX_at(int index) {
	Node *p = head;
	if (index >= size() || index<0){
		cout << "Error: Out of bounds." << endl;
		return -1;
	}
	else if (empty()){
		cout << "Error: Empty List" << endl;
		return -1;
	}
	else{
		int i = 0;
		while (i < index){
			p = p->getNext();
			i++;
		}
		//cout << "Data at " << index << ": " << p->getData() << endl;
		int PosX = p->getPosX();
		p = nullptr;
		return PosX;
	}
}
int LinkedList::getY_at(int index) {
	Node *p = head;
	if (index >= size() || index < 0){
		cout << "Error: Out of bounds." << endl;
		return -1;
	}
	else if (empty()){
		cout << "Error: Empty List" << endl;
		return -1;
	}
	else{
		int i = 0;
		while (i < index){
			p = p->getNext();
			i++;
		}
		//cout << "Data at " << index << ": " << p->getData() << endl;
		int PosY = p->getPosY();
		p = nullptr;
		return PosY;
	}
}
	void LinkedList::change_at(int index, int x, int y){
		Node *p = head;
		if (index >= size() || index < 0){
			cout << "Error: Out of bounds." << endl;
		}
		else if (empty()){
			cout << "Error: Empty List" << endl;
		}
		else{
			int i = 0;
			while (i < index){
				p = p->getNext();
				i++;
			}
			p->setPosX(x);
			p->setPosY(y);
		}
		p = nullptr;
	}
/*
void delete_at(int index){
if (empty() || index <= 0 || index >= size()) {
cout << "Error: Out of bounds, or the list might be empty." << endl;
}
else {
Node *p = head;
Node *q = head;
for (int i = 0; i < index; i++){
p = p->getNext();
}
for (int i = 0; i < index - 1; i++){
q = q->getNext();
}
q->setNext(p->getNext());
p = nullptr;
q = nullptr;
}
}
*/