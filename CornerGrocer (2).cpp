//Quinton Hesse
//Programming Languages
//Project 3
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std; 
ifstream inFS; //initialize variables
string searchWord;
string tempWord;
string mapWord;
string mapWord2;
int number;
int wordCount;
int wordCount1;
int wordCount2;

void displaymenu() { //menu for main loop
	cout << "1 - Search for specific item frequency" << endl;
	cout << "2 - List all Items and frequency" << endl;
	cout << "3 - List all Items with histogram" << endl;
	cout << "4 - Exit Program" << endl;
	cout << "Note when selecting options 2 or 3 the program will add right the first time but keep doubling on subsequent use " << endl;
}
void countSpecific() { //specific word function, not used because it wont interact with filestream unless directly in main
	wordCount = 0;
	cout << "Enter search word: ";
	cin >> searchWord;
	while (!inFS.fail()) {
		inFS >> tempWord;
		if (tempWord == searchWord)
			wordCount = wordCount + 1;
	}
	cout << searchWord << ": " << wordCount << endl;

}
template <class A, class B> 
void printMap(map <A, B> map) //print map with numbers
{
	typedef std::map<A, B>::iterator iterator;
	for (iterator i = map.begin(); i != map.end(); i++)
		cout << i->first << ": " << i->second << endl;
}
template <class X, class Y>
void printMapH(map <X, Y> map) //print map with asterisks
{
	typedef std::map<X, Y>::iterator iterator;
	for (iterator i = map.begin(); i != map.end(); i++)
		cout << std::left << std::setw(15) << i->first << ": " << std::right << std::setw(35) << std::string(i->second, '*') << std::endl;
}



int main() {
	ifstream inFS; //main variables
	int userChoice;
	bool quit = false;

	map<string, unsigned int> wordCount, wordCount2; //initialize map
	{
		while (quit != true) { //while loop with exit condition
			inFS.open("C:\\Users\\quind\\source\\repos\\Project3\\ProjectThreeInput.txt"); //initialize input stream
			if (!inFS.is_open()) {
				cout << "Could not open file" << endl; //error code
				return 1;
			}
			displaymenu();
			cin >> userChoice; //menu input
			switch (userChoice) { //switch case for menu input
				case 1:
					wordCount1 = 0; //function call would not interact with file stream so is directly in main
					cout << "Enter search word: ";
					cin >> searchWord;
					while (!inFS.fail()) {
						inFS >> tempWord;
						if (tempWord == searchWord)
							wordCount1= wordCount1 +1;
						
					}
					inFS.close();
					cout << searchWord << ": " << wordCount1 << endl;
					break;
				case 2:

					while (!inFS.fail()) 
					{
						inFS >> mapWord; //map word with numbers
						wordCount[mapWord]++;
					}
					printMap(wordCount);
					inFS.close();
					cout << " Now exiting" << endl;
					break;
				case 3:
					while (!inFS.fail())
					{
						inFS >> mapWord2; //map word with asterisks
						wordCount2[mapWord2]++;
					}
					printMapH(wordCount2);
					inFS.close();
					cout << "Now exiting" << endl;
				
					break;
				case 4:
					quit = true; //exit option
					break;
				default:
					cout << "invalid Input" << endl; //input validation
					break;
				}

			}

		}
	}