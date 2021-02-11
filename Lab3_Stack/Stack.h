#ifndef STACK_H
#define STACK_H

#include "ItemType.h"

struct Node
{
	ItemType iData;
	Node *iNext;
};

//FullStack and EmptyStack are used for exception handling.
class FullStack {};
class EmptyStack {};

class Stack
{
private:
	Node *iTop = nullptr; //Pointer to top of stack
	const int nMAX_ITEMS = 5;

public:
	//Constructor:
	Stack();

	//Getters:
	bool IsEmpty();
	//Pre: Stack object exists
	//Post: Returns true or false based on whether the stack is empty.

	bool IsFull();
	//Pre: Stack object exists
	//Post: Returns true or false based on whether the stack is contains the maximum number of elements.

	//Setters:
	void Push(ItemType iNewItem);
	//Pre: Stack object exists and the stack is not full.
	//Post: A new item is pushed on to the stack

	void Pop();
	//Pre: Stack object exists and the stack is not empty.
	//Post: The top most item is removed from the stack (and not returned).

	void Top();
	//Pre: A stack object exists and client has verified stack is not empty.
	//Post: A copy of the item on the top of the stack is returned (and not removed).

	//Destructor:
	~Stack();
	//Pre: A stack object exists.
	//Post all memory allocated for the stack object will be deallocated.
};

#endif STACK_H