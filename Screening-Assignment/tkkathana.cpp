// tkkathana@gmail.com
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

string randlines[5];

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
	int charcount=0,typedcount=0,linelen=0,t0,t1;
	string line,temp;
	t0 = time(NULL);
	for(int i=0;i<5;i++){
		cout << randlines[i]+'\n';
		charcount += randlines[i].size(); 
		getline(cin,line); 
		typedcount += line.size();
		cout << endl;
	}
	t1 = time(NULL);
	cout << "Characters entered: " << charcount << endl;
	cout << "Characters per minute: " << (charcount*60)/(t1-t0) << endl;
}

int main(){
	get_rand_lines();
	test_speed();
}
