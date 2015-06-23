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
	~LinkedList();
	int getX_at(int index);
	int getY_at(int index);
};