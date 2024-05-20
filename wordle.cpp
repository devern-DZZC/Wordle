#include<iostream>
#include<string>

using namespace std;


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"


void drawBoard(string guess[], string key)
{
	guess[5];
	string word;
	int c=0;
	for(int x=0;x<6;x++)
	{
		word = guess[x];
		bool isPresent = false;
		bool isRight = false;
		cout << "---------------------\n";
		cout << "| ";
		for (int y=0;y<5;y++)
		{
			for(int j=0;j<5;j++)
			{
				if(word[y] == key[y])
					isRight = true;
				if(word[y] == key[j] && isRight==false)
					isPresent = true;
			}
			
			if(isRight==true){
				cout <<GREEN<< word[y]<<RESET<<" | ";
				isRight = false;
			}
			else if (isPresent==true){
				cout <<YELLOW<< word[y]<<RESET<<" | ";
				isPresent=false;
			}
			else
				cout << word[y] << " | ";
		}
		cout<<endl;
	}
	cout << "---------------------\n";
	
}

void printAlpha(char alpha[], char arr[], int size)
{
	alpha[26];
	arr[size];
	
	bool previous, current, satisfied;
	cout << "Letters available: ";
	
	for(int i=0;i<26;i++)
	{
		bool found=false;
		for(int j=0;j<=size;j++)
		{
			if (alpha[i] != arr[j])
				found = false;
			if (alpha[i] == arr[j])
			{
				found = true;
				break;
			}	
		}

		if(!found){
			cout << alpha[i]<<", ";
		}
	}
	
}

int main()
{
	string key;
	string guess[6];
	int a=0, keySize;
	char word[5], arr[26];
	bool found=true;
	char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	cout << "Enter secret keyword: ";
	getline(cin, key);
	keySize = key.length();
	while(keySize>5 || keySize<5)
	{
		cout << "Incorrect word length. Please enter 5 letter word\n";
		cout << "\nEnter secret keyword: ";
		getline(cin, key);
		keySize = key.length();
	}

	system("cls");
	for(int x=0;x<6;x++)
	{
		for(int y=0;y<5;y++)
			word[y] = ' ';
		
		guess[x] = word;
	}
	drawBoard(guess, key);

	for (int x=0;x<6;x++)
	{
		int c=0, size, alphaSize;
		string letter;
		printAlpha(alpha, arr, a);
		cout << "\n\nEnter guess: ";
		getline(cin, guess[x]);
		letter = guess[x];
		size = letter.length();
		while(size>5 || size<5)
		{
			cout << "Incorrect word length. Please enter 5 letter word\n";
			cout << "\nEnter guess: ";
			getline(cin, guess[x]);
			letter = guess[x];
			size = letter.length();
		}
		
		for(int y=0;y<5;y++)
		{
			for(int z=0;z<5;z++)
			{
				if(letter[y] != key[z])
					found = false;
				if(letter[y] == key[z]){
					found = true;
					break;
				}
			}
			if (found==false){
				arr[a] = letter[y];	
				a++;
			}	
		}
		
		
		system("cls");
		drawBoard(guess, key);
		if(guess[x]==key)
		{
			cout << "\nYou Win!";
			exit(0);
		}
		
	}
	cout << "\nYou Lose!\n";
	cout << "Correct word: "<<key;
return 0;
}
