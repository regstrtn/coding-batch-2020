//arsalansaad.iitkgp@gmail.com

#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<int> random_nos(int no_of_lines)
{
	vector<int> rand_indices;
	
	srand(time(0));
	for(int i = 0; i<5; i++)
		rand_indices.push_back(rand()%no_of_lines);
	
	return rand_indices;
}

vector<string> random_lines(string filepath)
{
	ifstream infiles(filepath);
	
	int no_of_lines = 0;
	string line;
	
	while(getline(infiles,line))
		++no_of_lines;
	
	vector<int> indices = random_nos(no_of_lines);	
	vector<string> rand_lines;
	int i = 0;
	
	ifstream infile(filepath);	
	while (getline(infile,line))
	{
		if(find(indices.begin(), indices.end(), i) != indices.end())
			rand_lines.push_back(line);
		i++;
	}
	
	return rand_lines;
}

int main()
{
	vector<string> lines;
	int total_char = 0;
	int total_time = 0;
	string filepath = "shakespeare.txt";
	
	lines = random_lines(filepath);
	
	cout << "!!!Welcome to Typing Speed Calculator!!!!\n" << endl;
	
	for(int i = 0;i < lines.size();i++)
	{	
		string text;
		cout << lines[i] << endl;
		cout << "Please type in the above line:" << endl;
		auto begin = chrono::high_resolution_clock::now();
    	
    	getline(cin, text);
    	
    	auto end = chrono::high_resolution_clock::now();
    	auto elapsed = chrono::duration_cast<chrono::seconds>(end - begin);
    	
    	int interval = int(elapsed.count());
    	
    	if(text.length() == 0)
    	{
    		cout << "\nYou didn't type anything." << endl;
    		continue;
		}
    	else
    	{
    		
    		cout << "\n" << i+1 << ". " << "Characters typed: " << text.size() << endl;
    		cout << "Time taken: " << interval << " seconds." << endl;
    		cout << "Typing speed: " << float(text.length()*60)/interval << " characters per minute.\n" << endl;
    		total_char += text.length();
    		total_time += interval;
		} 
	}
	
	cout << "\nAverage typing speed: " << float(total_char*60)/total_time << " characters per minute." << endl;	
	
	return 0;
}
