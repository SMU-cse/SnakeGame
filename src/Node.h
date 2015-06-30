//this version of the snake game created by N. Chase Squires, June 2015
//------
//you may not use the code here verbatim for your lab. Sorry, i'm not
//here to let you outsource your grades to me.
//this code is posted as a guideline only.
#pragma once
class Node
{
private:
	int PosX;
	int PosY;
	Node *next;
public:
	Node();
	Node(int x, int y);
	void setPosX(int PosX);
	void setPosY(int PosY);
	int getPosX();
	int getPosY();

	void setNext(Node *node);
	Node* getNext();
	~Node();
};
