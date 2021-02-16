/*
 *Hankel Haldin
 *Data Structures Lab 3: Stack Class
 *Due: 2/17/2021
 * This project is a basic implementation of a stack data structure. The client software allows the user to perform operations on the stack.
 */

#include "Stack.h"
#include <iostream>

using namespace std;

void ProcessSelection(char cSelection, Stack &StackObj);
//Pre: Stack object exists and user has provided valid input.
//Post: The appropriate operation is performed on the stack.

void PushCase(Stack &StackObj);
//Pre: A stack object exists and is passed to the function.
//Post: An element is pushed on to the stack.

int main()
{
	Stack StackObj;

	char cSelection;
	cout << "This program allows you to perform operations on a stack ADT implemented as a linked list.\n";
	do
	{
		cout << "Enter the operation you would like to perform from the menu below:\n";
		cout << "1 - Push an item on to the stack.\n";
		cout << "2 - Pop and item from the top of the stack.\n";
		cout << "3 - Return a copy of the element at the top of the stack.\n";
		cout << "Q - Quit.\n";
		cout << "cSelection: ";

		cin >> cSelection;

		ProcessSelection(cSelection, StackObj);

	} while (toupper(cSelection) != 'Q');

	cout << "Goodbye...\n";

	return 0;
}

void ProcessSelection(char cSelection, Stack &StackObj)
{
	system("cls");
	switch (toupper(cSelection))
	{
	case '1':
		try 
		{
			PushCase(StackObj);
		} 
		catch (FullStack overflow) 
		{
			std::cerr << "===============================================================\n";
			std::cerr << "Exception: Bad memory allocation caught - the stack is full!\n";
			std::cerr << "===============================================================\n\n";
		}
		break;

	case '2':
		try
		{
			StackObj.Pop();
			cout << "The top most element has been removed from the stack.\n\n";
		}
		catch (EmptyStack underflow) 
		{
			std::cerr << "===============================================\n";
			std::cerr << "Exception thrown: The stack is currently empty.\n";
			std::cerr << "===============================================\n\n";
		}
		break;
	
	case '3':
		try
		{
			cout << StackObj.Top().Get() << " is the element at the top of the list\n\n";
		}
		catch (EmptyStack underflow) 
		{
			std::cerr << "===============================================\n";
			std::cerr << "Exception thrown: The stack is currently empty.\n";
			std::cerr << "===============================================\n\n";
		}
		break;

	case 'Q':
		break;

	default:
		cout << "Unrecognized input - Please try again.\n";
		break;
	}
}

void PushCase(Stack &StackObj)
{
	int nNewData;
	ItemType iNewItem;
	cout << "Enter the item you would like to push on to the stack.\n";
	cout << "Item: ";
	while (!(cin >> nNewData))
	{
		cout << "\aYou have entered invalid input - new items should be integers.\n"; 
		cin.ignore(100, '\n');
		cin.clear();
	}
	iNewItem.Set(nNewData);

	StackObj.Push(iNewItem);
	system("cls");
	cout << "There is a new top most element on the stack.\n\n";
}

