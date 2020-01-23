#pragma once
using namespace std;
class Node
{
public:
	Node(int value, Node* nextptr = NULL, Node* prevptr = NULL, int currentpriority=0);
	int getVal(void);
	Node* getNext(void);
	Node* getPrev(void);
	void setVal(int value);
	void setPrev(Node* prevptr);
	void setNext(Node* nextptr);
	int getPriority(void);
	void setPriority(int priority);
private:
	Node* next;
	Node* prev;
	int priority;
	int value;
};