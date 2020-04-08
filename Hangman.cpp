#include<iostream>
#include<ctime>
#include<iomanip>
#include<list>
#include<string>
#include<sstream>
#include<process.h>
#include<fstream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Hangman
{
	char letter;
	int num;//index number of word
	bool guessed = false;//tells whether word is guessed or not
	bool correct = false;//tells if guessed letter is present in the word to guess
	string word, data;//word to guess
	char blanks[100];//array to store blank spaces
	int length_of_word;//size of word to guess
	string incorrect;//string to hold all the wrongly guessed letters
	
	public:
		bool software() //function to get the word to guess
		{
			srand(time(0));
			int count = 0;
			ifstream fin;
			fin.open("Software Companies.txt");
			int random = 1 + (rand()%9);
			while(!fin.eof())
			{
				getline(fin, data);
				count += 1;
				if(count == random)
				{
					word = data;
					break;
				}
			}
			
			return guess(word);
		}
		
		bool hollywood()
		{
			srand(time(0));
			int count = 0;
			ifstream fin;
			fin.open("Hollywood Celebrities.txt");
			int random = 1 + (rand()%12);
			while(!fin.eof())
			{
				getline(fin, data);
				count += 1;
				if(count == random)
				{
					word = data;
					break;
				}
			}
			
			return guess(word);
		}
		
		bool cars()
		{
			srand(time(0));
			int count = 0;
			ifstream fin;
			fin.open("Car Manufacturers.txt");
			int random = 1 + (rand()%11);
			while(!fin.eof())
			{
				getline(fin, data);
				count += 1;
				if(count == random)
				{
					word = data;
					break;
				}
			}
			
			return guess(word);
		}
		
		bool phones()
		{
			srand(time(0));
			int count = 0;
			ifstream fin;
			fin.open("Phone Manufacturers.txt");
			int random = 1 + (rand()%14);
			while(!fin.eof())
			{
				getline(fin, data);
				count += 1;
				if(count == random)
				{
					word = data;
					break;
				}
			}
			
			return guess(word);
		}
		
		bool rock()
		{
			srand(time(0));
			int count = 0;
			ifstream fin;
			fin.open("Rock Bands.txt");
			int random = 1 + (rand()%17);
			while(!fin.eof())
			{
				getline(fin, data);
				count += 1;
				if(count == random)
				{
					word = data;
					break;
				}
			}
			
			return guess(word);
		}
		
		bool guess(string word)
		{
			int positions[100];
			system("cls");
			cout << "Enter all letters in upper case!\n";
			int i = 0;
			char temp;
			int pos_of_letter = 0;
			incorrect = "";
			int no_of_blanks = word.length();
			int lives = 0;
			string :: iterator iter = word.begin();
			length_of_word = word.length();
			for(; iter != word.end(); ++iter)
			{
				if(*iter == ' ')
				{
					blanks[i] = ' ';
					cout << "  ";
				}
				
				else
				{
					blanks[i] = '_';
					cout << "_" << " ";
				}
				i +=  1;
			}
			cout << endl;
			
			while((lives <= 6) && (no_of_blanks > 0))
			{
				pos_of_letter = 0;
				string :: iterator it = word.begin();
				cout << "Enter a letter: ";
				cin >> letter;
				for(; it != word.end(); ++it)
				{
					if(letter == *it)
					{
						correct = true;
						no_of_blanks -= 1;
						blanks[pos_of_letter] = letter;
					}
					pos_of_letter += 1;
				}
				if(correct == true)
					display(blanks, length_of_word, incorrect);
				
				if(correct == false)
				{
					incorrect += letter;
					lives += 1;
					hangman(lives, word);
					display(blanks, length_of_word, incorrect);
				}
				correct = false;
			}
			if(no_of_blanks == 0)
				guessed = true;
			return guessed;
		}
		
		void hangman(int n, string word)
		{
			int count = 1;
			while(count <= n)
			{
				switch(count)
				{
					case 1:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
						
					case 2:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|        | " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
						
					case 3:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|       /| " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
						
					case 4:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|       /|\\" << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
					
					case 5:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|       /|\\" << endl;
						cout << "|       / " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
						
					case 6:
						system("cls");
						cout << "----------" << endl; 
						cout << "|        |" << endl;
						cout << "|        O" << endl;
						cout << "|       /|\\" << endl;
						cout << "|       / \\" << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						cout << "|         " << endl;
						break;
						
					default:
						cout << "Game over! The word was " << word << endl;
						break;
				}
				count += 1;
				for(int i = 0; i<123456789; i++)
				{}
			}
			system("pause");
		}
		
		void display(char blanks[], int l, string incorrect)
		{
			system("cls");
			for(int i = 0; i<l; i++)
				cout << blanks[i] << " ";
			string :: iterator iter = incorrect.begin();
			cout << endl << endl;
			while(iter != incorrect.end())
			{
				cout << *iter << " ";
				++iter;
			}
			cout << "\n";
			//system("pause");
		}
};

int main()
{
	srand(time(0));
	string congrats, data;
	ifstream fin;
	fin.open("Congratulations.txt");
	bool guessed_correctly;
	Hangman H;//declaring object of type Hangman
	int topic;//holds the topic of choice
	char another;//tells whether user wants to try again
	do
	{
		int count = 0;
		cout << "\t\t\t\t\tWelcome to Hangman\n";
		cout << "Choose the topic: \n";
		cout << "1.Software Companies\n";
		cout << "2.Hollywood Celebrities\n";
		cout << "3.Car Manufacturers\n";
		cout << "4.Phone Manufacturers\n";
		cout << "5.Rock Bands\n";
		cout << "Enter topic[1-5]: ";
		cin >> topic;//getting topic of choice
		int val = 1 + (rand()%5);
		for(int i = 1; i<=5; i++)
		{
			count += 1;
			getline(fin, data);
			if(count == val)
			{
				congrats = data;
				break;
			}
		}	
		switch(topic)
		{
			case 1:
				guessed_correctly = H.software();
				if(guessed_correctly == true)
					cout << congrats << endl;
				break;
			case 2:
				guessed_correctly = H.hollywood();
				if(guessed_correctly == true)
					cout << congrats << endl;
				break;
			case 3:
				guessed_correctly = H.cars();
				if(guessed_correctly == true)
					cout << congrats << endl;
				break;
			case 4:
				guessed_correctly = H.phones();
				if(guessed_correctly == true)
					cout << congrats << endl;
				break;
			case 5:
				guessed_correctly = H.rock();
				if(guessed_correctly == true)
					cout << congrats << endl;
				break;
			default:
				cout << "Invalid input!\n";
				break;
		}
	
		cout << "Do you want to have another go?(y/n): ";
		cin >> another;
		system("cls");
	}while(another == 'y' || another == 'Y');
	return 0;
}

