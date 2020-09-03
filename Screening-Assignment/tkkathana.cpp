// tkkathana@gmail.com
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

string randlines[5];

/*
 * Assumptions:
 * 1. The lines entered by the user are the same as printed, without any errors.
 * 2. Penalty of 1 sec for each character missed
 */

void get_rand_lines(){
	string lines[2000];
	int randnum,no_of_lines;
	ifstream infile;

	// Reading the entire file and storing in lines
	infile.open("shakespeare.txt",ios::in);
	for(no_of_lines=0;getline(infile, lines[no_of_lines]);no_of_lines++);
	infile.close();

	// Generating 5 random numbers for random lines
	srand(time(NULL));
	cout << "Type the following lines for the test.\n" << endl;
	for(int i=0;i<5;i++){
		randlines[i]=lines[rand()%no_of_lines];
	}
}

void test_speed(){
	int charcount=0,typedcount=0,linelen=0,t0,t1,penalty=0;
	string line,temp;

	// Printing out lines and recording characters typed and time taken by the user
	t0 = time(NULL);
	for(int i=0;i<5;i++){
		cout << randlines[i]+'\n';
		linelen = randlines[i].size(); 
		charcount += linelen;
		getline(cin,line); 
		typedcount += line.size();
		cout << endl;
		if(linelen > line.size()) penalty += linelen-line.size();
	}
	t1 = time(NULL);

	// Printing out characters entered and characters per minute
	cout << "Characters entered: " << charcount << endl;
	cout << "Characters per minute: " << (charcount*60)/(t1-t0+penalty) << endl;
}

int main(){
	get_rand_lines();
	test_speed();
}
