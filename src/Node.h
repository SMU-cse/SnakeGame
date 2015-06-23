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
