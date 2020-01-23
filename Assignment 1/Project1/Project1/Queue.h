#pragma once
using namespace std;

class Queue
{
public:
	Queue(void);
	~Queue(void);
	void Enqueue(int i, int priority = 0);
	int Dequeue(void);
protected:
	Node* back;
	Node* front;
private:
	virtual Node* NodeDequeue(void);
};
