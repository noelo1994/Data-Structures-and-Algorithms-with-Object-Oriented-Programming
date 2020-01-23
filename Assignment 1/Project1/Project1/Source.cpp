#include <iostream>
#include <chrono>
#include <thread>

#include "Node.h";
#include "Stack.h";
#include "Queue.h";
#include "Scheduler.h";
using namespace std;



Node::Node(int value, Node * nextptr, Node * prevptr, int currentpriority)//constructor
{
	this->value = value;
	next = nextptr;
	prev = prevptr;
	priority = currentpriority;
}

int Node::getVal(void)
{
	return value;
}

Node * Node::getNext(void)
{
	return next;
}

Node * Node::getPrev(void)
{
	return prev;
}

void Node::setVal(int value)
{
	this->value = value;
}

void Node::setPrev(Node * prevptr)
{
	prev = prevptr;
}

void Node::setNext(Node * nextptr)
{
	next = nextptr;
}

 int Node::getPriority(void)
{
	return priority;
}

 void Node::setPriority(int priority)
{
	this->priority = priority;
}



Stack::Stack(void)
{
	top = 0;
}

Stack::~Stack(void)
{
	while (top != nullptr)//loop untill no pointers remain
	{
		delete NodePop();//delete
	}
}

void Stack::Push(int value)//function to push numbers into the top/front of the stack
{
	cout << value << " ";//display numbers as they are being entered into the stack
	Node* tmp = new Node(value, top);//creates new node to add to the stack passing in value from main and top
	top = tmp;//updates top to new value entered
}

Node* Stack::NodePop(void)//function to re-aim the pointers when node is popped
{
	Node* temp = top;//saving current top value in stack
	top = top->getNext();//setting the new top to the next value of the stack using the get next function
	return temp;//return temp pointer to be deleted
}

int Stack::Pop(void)
{
	
	int returnValue = top->getVal();//setting return value to top to be shown to user

	Node* temp = NodePop();//recieve the pointer to the popped node to delte

	delete temp;//delete the current temp
	return returnValue;//return returnValue back to main to output onto screen
}


Queue::Queue(void)
{
	back = nullptr;//setting back to nullptr when queue is empty
	front = nullptr;//setting front to nullptr when queue is empty
}

Queue::~Queue(void)
{
	while (NodeDequeue() != nullptr);
}

void Queue::Enqueue(int i, int priority)
{
	cout << i << " ";//output the queue as its being entered
	Node* temp = new Node(i, back, nullptr, priority);//creating new node to be added to the queue
	back = temp;//last entry in the queue is the new node temp
	if (front == nullptr) front = back;//if front pointer is null then front = back and queue is empty
	else
	{
		temp = back->getNext();
		temp->setPrev(back);
	}
}

int Queue::Dequeue(void)
{
	Node* temp = NodeDequeue();
	int returnValue = 0;
	if (temp != nullptr)
	{
		returnValue = temp->getVal();
	}
	
	else
	{
		cout << "Queue empty.";
		return -1;
	}
	cout << returnValue << " ";

	if (front == nullptr) back = front;

	delete temp;//delete temp
	return returnValue;
}

Node * Queue::NodeDequeue(void)
{
	Node* temp = front;//setting the temp value to the front of the queue
	if (front != nullptr)//if front is null
	{
		front = front->getPrev();//front set to previous number in the queue
		if (front != nullptr) front->setNext(nullptr);
	}
	return temp;//return tmp value which is the front of the queue
}
Node * Scheduler::NodeDequeue(void)
{
	Node* tmp = front;//sets temp to the front of the queue. This is the node that will point to the number with the highest priority
	Node* seek = tmp->getPrev();//setting seek to the 2nd in the queue

	while (seek != nullptr)//while loop to loop though the whole queue
	{
		if (seek->getPriority() > tmp->getPriority())//compares priority of seek and temp and of seel os bigger
		{
			tmp = seek;//temp is now seek
		}
		seek = seek->getPrev();//seek moves 1 back in the queue to compare the next node
	}

	Node* prevtmp = tmp->getPrev();//setting previous node
	Node* nexttmp = tmp->getNext();//setting next node

	if (prevtmp != nullptr)
	{
		prevtmp->setNext(nexttmp);
	}
	else
		back = nexttmp;

	if (nexttmp != nullptr)
	{
		nexttmp->setPrev(prevtmp);
	}
	else
		front = prevtmp;

	return tmp;
}

int main()
{
	using namespace this_thread;     // sleep_for, sleep_until
	using namespace chrono_literals; // ns, us, ms, s, h, etc.
	using chrono::system_clock;

	//Stack s;
	//cout << "<---------Pushing numbers onto the stack ---------->" << endl;
	//for (int i = 0; i < 21; i++)
	//{
	//	s.Push(i);
	//	sleep_for(0.25s);
	//	
	//}
	//cout << endl << endl << "<---------Popping numbers off the stack ---------->" << endl;
	//for (int j = 0; j < 21; j++)
	//{
	//	cout << s.Pop() << " ";
	//	sleep_for(0.25s);
	//}
	//cout << endl << endl;

	Queue q;
	cout << "<---------Enqueue numbers onto the queue ---------->" << endl;
	for (int i = 0; i < 10; i++)
	{
		q.Enqueue(i);
		sleep_for(0.25s);
	}
	cout << endl << endl << "<---------Dequeueing numbers off the queue ---------->" << endl;
	for (int j = 0; j < 11; j++)
	{
		q.Dequeue();
		sleep_for(0.25s);
	}
	cout << endl << endl;

	//Scheduler SC;
	//cout << "<---------Enqueue numbers onto priority queue ---------->" << endl;
	//int priority = 10;
	//for (int i = 0; i < 11; i++)
	//{
	//	SC.Enqueue(i, priority);
	//	priority--;
	//}
	//cout << endl;
	//


	//for (int j = 0; j < 15; j++)
	//{
	//	cout << SC.Dequeue() << " ";

	//	sleep_for(0.25s);
	//}



	system("pause");
}

