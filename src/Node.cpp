//this version of the snake game created by N. Chase Squires, June 2015
//------
//you may not use the code here verbatim for your lab. Sorry, i'm not
//here to let you outsource your grades to me.
//this code is posted as a guideline only.
#include<iostream>
#include "Node.h"

using namespace std;


	Node::Node()
	{
		PosX = 0;
		PosY = 0;
		next = NULL;
	}
	Node::Node(int x, int y)
	{
		this->PosX = x;
		this->PosY = y;
		next = NULL;
	}
	/*--------------------------------------------//
	P.S: nullptr is the new standard (C++ 11)
	null pointer value. In old standard null
	pointer value is just NULL or you can
	simply write 0.
	//--------------------------------------------*/
	void Node::setPosX(int PosX)
	{
		this->PosX = PosX;
	}
	void Node::setPosY(int PosY)
	{
		this->PosY = PosY;
	}

	int Node::getPosX()
	{
		return PosX;
	}
	int Node::getPosY()
	{
		return PosY;
	}

	void Node::setNext(Node *node)
	{
		this->next = node;
	}
	Node *Node::getNext()
	{
		return next;
	}
	Node::~Node()
	{
		delete next;
		next = nullptr;
		/*
		For testing destructor, you can add:
		cout << "Destructor of Node" << endl;
		*/
	}