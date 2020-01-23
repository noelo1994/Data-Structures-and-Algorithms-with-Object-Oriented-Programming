#pragma once
using namespace std;

class Stack
{
public:
	Stack(void);
	~Stack(void);
	void Push(int value);
	Node* NodePop(void);
	int Pop(void);
private:
	Node* top;
};
