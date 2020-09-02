//Mohd Ammad Rehman : marehman0211@gmail.com (Github : rehman0211)

#include<bits/stdc++.h>
#include<fstream>
#include<time.h>
using namespace std;

int main(){
	/*reading the input file*/
	string data[2000];
	ifstream inFile;
	inFile.open("shakespeare.txt");
	string tp;
	int size=0;
	while(getline(inFile, tp)){
		data[size++] = tp;
	}
	/*file read and stored*/
	srand(time(NULL));
	cout<<"Ready to check your typing speed, press any key to start.";
	getline(cin, tp);//random input just giving time to start.
	int turn=5;
	long charCount=0;
	/*calling random strings from file and taking input, for 5 times*/
	time_t begin, end;
	time(&begin);
	while(turn--){
		string inString;
		int index = rand()%size;
		cout<<data[turn]<<endl;
		getline(cin, inString);
		charCount += inString.length();
	}
	time(&end);
	time_t elapsedTime = end-begin;
	cout<<"No of characters typed : "<<charCount<<endl;
	cout<<"Time taken : "<<elapsedTime<<" seconds"<<endl;
	cout<<"Typing speed : "<<charCount*60/elapsedTime<<"characters/min"<<endl;
	inFile.close();
}
