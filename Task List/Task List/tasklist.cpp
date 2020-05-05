// Task List project.cpp 
//
//ofstream: Stream class to write on files
//ifstream: Stream class to read from files
//fstream: Stream class to both read and write from/to files
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> _items;

void DisplayMainMenu()
{
	cout << "1. List items" << endl;
	cout << "2. Add item" << endl;
	cout << "3. Remove item" << endl;
	cout << "0. Quit" << endl;
}

void ListItems()
{
	int numItems = _items.size();

	if (numItems > 0)
	{
		for (int i = 0; i < _items.size(); i++)
		{
			cout << endl;
			cout << i + 1 << ". " << _items[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "\nThere is nothing on your to do list.\n";
		cout << endl;
	}
}

void AddItem()
{
	//open and write to txt file/save tasks
	cout << "Enter a to do item:" << endl;
	string itemText;
	getline(cin, itemText);

	_items.push_back(itemText);

	cout << "You have added an item!" << endl;
	cout << endl;
}

void RemoveItem()
{
	//Rewrite txt file after it is removed
	cout << "Enter the number of the item you wish to remove:" << endl;

	int choice;
	cin >> choice;

	_items.erase(_items.begin() + (choice - 1));

	cout << "Item removed!" << endl;
}

int main()
{
	cout << "Welcome to the to do app!" << endl << endl;


	int choice;

	do
	{
		DisplayMainMenu();

		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			break;
		case 1:
			ListItems();
			break;
		case 2:
			AddItem();
			break;
		case 3:
			RemoveItem();
			break;
		default:
			cout << endl;
			cout << "Invalid Selection. Please try again." << endl;
			cout << endl;
			break;
		}
	} while (choice != 0);

	cout << "Goodbye";
	cout << endl;
}