//this version of the snake game created by N. Chase Squires, June 2015
//------
//you may not use the code here verbatim for your lab. Sorry, i'm not
//here to let you outsource your grades to me.
//this code is posted as a guideline only.
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