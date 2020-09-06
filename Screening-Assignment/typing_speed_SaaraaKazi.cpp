//saaraakazi@gmail.com

#include <string.h>
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 

using namespace std;

void single_line() {
   //load the text file and put it into a single string:
  ifstream in("/Users/saaraa/projects/typing_calculator/shakespeare.txt");
  stringstream buffer;
  buffer << in.rdbuf();
  string test = buffer.str();
  //cout << test << endl << endl;

  //create variables that will act as "cursors". we'll take everything between them.
   size_t pos1 = 0;
   size_t pos2;
   
   string str[500];
   int r = 0;


   for (int x=0; x<=500; x++){
      pos2 = test.find("\n", pos1); //search for the bar "\n". pos2 will be where the bar was found.
      str[x] = test.substr(pos1, (pos2-pos1)); //make a substring, wich is nothing more than a copy of a fragment of the big string.
      pos1 = pos2+1; // sets pos1 to the next character after pos2. so, it can start searching the next \n line.
    }
   
   r = rand() % 500 + 1; 
   //cout << "   \n" << r;
   cout<< "\nType the following sentence. : " << "\n";
   cout << "\n" << str[r] << endl;
} 

int type(int lent) {
   string typing;
   getline(cin, typing);
   lent += typing.length();
   return lent;
}

int main()
{
   int len = 0;
   float words_per_min, sec;
   
   single_line();

   clock_t time_req;
   time_req = clock();
   len = type(len);

   cout << "-----------" << "\n";
   single_line();
   time_req = clock();
   len = type(len);

   cout << "-----------" << "\n";
   single_line();
   time_req = clock();
   len = type(len);

   cout << "-----------" << "\n";
   single_line();
   time_req = clock();
   len = type(len);

   cout << "-----------" << "\n";
   single_line();
   time_req = clock();
   len = type(len);

   cout << "\n The number of characters you typed are : "<<len<<"\n";
	time_req = clock() - time_req;
   sec = (float)time_req/CLOCKS_PER_SEC;
   words_per_min = (sec/6)*60;
   cout << "\n It took you " << sec << " seconds" <<endl;
   cout << "\n Word per minute speed is : " << words_per_min << "\n" <<endl;

   


   return 0;
   
}