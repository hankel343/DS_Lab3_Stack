#include "Stack.h"
#include "ItemType.h"
#include <new>

Stack::Stack() {};

bool Stack::IsEmpty()
{
	return (iTop == nullptr);
}

bool Stack::IsFull()
{
	try
	{
		//Allocating mem. for test 
		Node* test = new Node; //If out of memory, throw bad_alloc exception.
		delete test; //If this statement is reached, memory was successfully allocated.
		return false;
	} catch (std::bad_alloc) {
		return true;
	}
}

void Stack::Push(ItemType iNewItem)
{
	Node* iTemp = new Node;
	iTemp->iData = iNewItem;

	if (iTop == nullptr) { //If list was empty.
		iTemp->iNext = nullptr;
		iTop = iTemp; //Making top point to first node.
	} else {
		iTemp->iNext = iTop; //Making link to previous top node.
		iTop = iTemp; //Moving top to most recently inserted item.
	}
}

void Stack::Pop()
{
	Node* iTemp = iTop;
	iTop = iTop->iNext; //Moves top to next item in the list.
	delete iTemp; //Deallocates memory for node to be deleted.
}

ItemType Stack::Top()
{
	//Client is reponsible for calling IsEmpty() before this function
	//to prevent stack underflow.
	return iTop->iData;
}

Stack::~Stack()
{
	if (iTop != NULL) //If stack still has nodes with dynamically allocated memory.
	{
		Node* iTemp = iTop;
		Node* iTempTrailer = NULL;

		while (iTemp != NULL)
		{
			iTempTrailer = iTop;
			iTop = iTop->iNext;
			delete iTempTrailer; //Deallocate memory from nodes in the list.
		}
	}
}