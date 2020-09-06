// nabsarkar@gmail.com
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
	vector<string> lines;
       	string line;
	ifstream infile("shakespeare.txt");
	if(infile.is_open()) {
		while(!infile.eof()){
			getline(infile, line);
			lines.push_back(line);
		}
		infile.close();
	} else 	cout << "Unable to open file.";

	int t = 5, mxL = lines.size(), count=0;
	srand (time(NULL));
	struct timespec begin, end; 
	clock_gettime(CLOCK_REALTIME, &begin);	
	
	cout << "Hi there ! Welcome to typing practice session.\n" << "Kindly start typing when prompted. There will be total 5 sentences tot test you. \n" << "\n";
	while(t--){
		int idx = rand() % mxL;
		cout << (5-t) << ". "<< lines[idx] << "\n\n";
		string messageVar;
		cout << "Type here: ";
		cin.ignore();
		getline(cin, messageVar);
		cout << "\n";
		count += messageVar.size();
	}
	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
    	long nanoseconds = end.tv_nsec - begin.tv_nsec;
   	double elapsed = seconds + nanoseconds*1e-9;
	printf("You have type %d characters in %.3f seconds with speed of %.3f characters per minute.\n", count, elapsed, (count*60/elapsed));


	return 0;

}
