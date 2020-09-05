// iamanullahmahmood@gmail.com

/*
  Program Name: Typing Speed Calculator
  Author: Amanullah Mahmood
  Date: Sat, 5 September 2020
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <limits>

using namespace std;

int main() {

  string lines[1396];
  int totalCharactersTyped = 0;
  time_t totalTypingTime = 0;

  // Read from the text file if exists.
  ifstream sampleTextFile("shakespeare.txt");
	if(!sampleTextFile)
	{
		cout<<"Couldn't open the file"<<endl;
		exit(1);
	}

  // Reading lines of the file into array of strings.
  for (int i = 0; i < 1396; i++)
  {
    getline (sampleTextFile, lines[i]);
  }

  //Greeting message to user.
  cout << "=================================================================\n";
  cout << "Welcome to Typing Speed Calculator!\n";
  cout << "_________________________________________________________________\n";
  cout << "You'll get 5 random English sentences to write (one by one).\n";
  cout << "Get Ready and Press Enter to Continue.\n";
  cout << "=================================================================\n";
  cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

  // Showing random sentences to a user
  // Reading user input
  // Calculating time and character
  for (int i = 0; i < 5; i++)
  {
    srand(time(0));
    int line = rand() % 1396;
    cout<<lines[line]<<'\n';
    string userTypedLine;
    time_t begin, end;
    time(&begin);
    getline(cin, userTypedLine);
    time(&end);
    time_t elapsed = end - begin;
    totalCharactersTyped += userTypedLine.size();
    totalTypingTime += elapsed;
  }

  // Showing result to user
  cout << "=====================================================\n";
  cout << "RESULT:\n";
  cout << "Number of character typed: " << totalCharactersTyped << " charaters.\n";
  cout << "Time taken: " <<totalTypingTime << " seconds.\n";
  cout << "Typing speed: " << static_cast<int>((static_cast<double>(totalCharactersTyped)/totalTypingTime)*60) << " characters/min.\n";
  cout << "=====================================================\n";

  // Close the file
  sampleTextFile.close();
}

/*
CREDIT
LINE 23 - Reading from text:
https://stackoverflow.com/questions/11546177/how-to-read-lines-of-text-from-file-and-put-them-into-an-array
LINE 43 - Skip Enter:
https://stackoverflow.com/questions/903221/press-enter-to-continue
LINE 51 - Generating Random Number
http://www.cplusplus.com/reference/cstdlib/rand/
LINE 55 - Calculating Time
https://github.com/regstrtn/cool-codes/blob/master/measure-time-cpp.cpp
LINE 57 - Reading from console
https://stackoverflow.com/questions/18786575/using-getline-in-c
*/

/*
ASSUMPTION
User will write sentences without any error.
*/
