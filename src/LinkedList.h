#pragma once
#include "Node.h"
class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	bool empty();
	void push_back(int PosX, int PosY);
	int size();
	void output();
	void clear();
	void change_at(int index, int x, int y);
	~LinkedList();
	int getX_at(int index);
	int getY_at(int index);
	int getLastX();
	int getLastY();
};