/*
 *Hankel Haldin
 *Data Structures Lab 3: Stack Class
 *Due: 2/17/2021
 * This project is a basic implementation of a stack data structure. The client software allows the user to perform operations on the stack.
 */

#include "Stack.h"
#include "ItemType.h"

#include <iostream>

using namespace std;

void ProcessSelection(char selection, Stack &StackObj);
//Pre: Stack object exists and user has provided valid input.
//Post: The appropriate operation is performed on the stack.

void PushCase(Stack &StackObj);
//Pre: A stack object exists and is passed to the function.
//Post: An element is pushed on to the stack.

int main()
{
	Stack StackObj;

	char selection;
	cout << "This program allows you to perform operations on a stack ADT implemented as a linked list.\n";
	do
	{
		cout << "Enter the operation you would like to perform from the menu below:\n";
		cout << "1 - Push an item on to the stack.\n";
		cout << "2 - Pop and item from the top of the stack.\n";
		cout << "3 - Return a copy of the element at the top of the stack.\n";
		cout << "Q - Quit.\n";
		cout << "Selection: ";

		cin >> selection;

		ProcessSelection(selection, StackObj);

	} while (toupper(selection) != 'Q');

	cout << "Goodbye...\n";

	return 0;
}

void ProcessSelection(char selection, Stack &StackObj)
{
	system("cls");
	switch (toupper(selection))
	{
	case '1':
		PushCase(StackObj);
		break;

	case '2':
		StackObj.Pop();
		break;
	
	case '3':
		StackObj.Top();
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
}

