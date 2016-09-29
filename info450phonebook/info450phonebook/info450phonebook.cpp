#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//static integer so it set to default 0
static int NewEntry = 0;
char phoneBook[10][2][100];
void showMenu() {
	cout << "---------------------" << endl;
	cout << "What do you want to do:" << endl;
	cout << "---------------------" << endl;
	cout << "[A]dd new person -- enter A" << endl;
	cout << "[D]isplay persons in book -- enter D" << endl;
	cout << "[Q]uit to exit program -- enter Q" << endl;
}
//funtion to make sure phone book does not exceede 10 entries
void addPhoneBook() {
	if (NewEntry >= 10) {
		cout << "Phone book is full." << endl;
		return;

	}
	cout << "Entry: ";
	int entry;
	cin >> entry;

	if (entry != NewEntry + 1) {
		cout << "Invalid entry number." << endl;
		entry = 0;
		return;
// function to enter your name
	}
	char name[50];
	cout << NewEntry << " Please enter name: ";
	cin >> name;
	for (int i = 0; i <= NewEntry; i++) {
		if (strcmp(phoneBook[i][0], name) == 0) {
			cout << name << " Already exists in the phonebook!" << endl;
			return;
		}
//function to enter phone number 
	}
	cout << "Please enter phone number:";
	char phone[30];
	cin >> phone;
	strcpy_s(phoneBook[NewEntry][0], name);
	strcpy_s(phoneBook[NewEntry][1], phone);
	NewEntry++;
	return;
}
void display() {
	for (int i = 0; i < NewEntry; i++) {
		cout << "Entry " << i + 1 << " Name: " << phoneBook[i][0] << " Number: " << phoneBook[i][1] << endl;
		
	}

}
int main() {
	char option = ' ';
	while (option != 'Q') {
		showMenu();
		cin >> option;
		switch (option)
		{
		case 'A':
			addPhoneBook();
			break;
		case 'D':
			display();
			break;
		case 'Q':
			break;
		default:
			break;
		}
		cout << endl;
	}

	return 0;
}
