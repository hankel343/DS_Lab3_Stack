#include "Stack.h"
#include "ItemType.h"
#include <iostream>
#include <new> //This library is included to use bad_alloc exception.

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
	try
	{
		if (this->IsFull()) //If IsFull is called on current object and the method returns true
			throw FullStack();

		Node* iTemp = new Node;
		iTemp->iData = iNewItem;

		if (iTop == nullptr) { //If list was empty.
			iTemp->iNext = nullptr;
			iTop = iTemp; //Making top point to first node.
		}
		else {
			iTemp->iNext = iTop; //Making link to previous top node.
			iTop = iTemp; //Moving top to most recently inserted item.
		}

		std::cout << iTemp->iData.Get() << " was added to the stack.\n\n";
	} catch (FullStack overflow) {
		std::cerr << "===============================================================\n";
		std::cerr << "Exception: Bad memory allocation caught - the stack is full!\n";
		std::cerr << "===============================================================\n\n";
	}
	
}

void Stack::Pop()
{
	try
	{
		if (IsEmpty())
			throw EmptyStack();
		else
		{
			Node* iTemp = iTop;
			iTop = iTop->iNext; //Moves top to next item in the list.
			delete iTemp; //Deallocates memory for node to be deleted.
			std::cout << "The top element has been removed from the stack.\n\n";
		}
	} catch (EmptyStack underflow) {
		std::cerr << "===============================================\n";
		std::cerr << "Exception thrown: The stack is currently empty.\n";
		std::cerr << "===============================================\n\n";
	}
	

	
}

void Stack::Top()
{
	try
	{
		if (this->IsEmpty())
			throw EmptyStack();

		std::cout << iTop->iData.Get() << " is at the top of the stack.\n\n";
	} catch (EmptyStack underflow) {
		std::cerr << "===============================================\n";
		std::cerr << "Exception thrown: The stack is currently empty.\n";
		std::cerr << "===============================================\n\n";
		
	}
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