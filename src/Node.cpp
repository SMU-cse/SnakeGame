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