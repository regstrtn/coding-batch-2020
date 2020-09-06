/* ksakir486@gmail.com */
#include<bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
	string lines[2000];
    ifstream inFile;
    // open the file stream
    inFile.open("./shakespeare.txt");
    // check if opening a file failed
    if (inFile.fail()) {
        cerr << "Error opeing a file" << endl;
        inFile.close();
        exit(1);
    }
    
    string line;
    int i=0;
    while (getline(inFile, line))
    {
    	lines[i]=line;
        i++;
    }
    inFile.close();


srand(time(NULL));
int v1 = rand() % 1300;   // random number

for(int i=v1;i<v1+5;i++){
	cout<<lines[i]<<endl;
}

   
cout << "\n\n\nHey !!: \nYou need to type the above mentioned lines [press Enter after typing of each line]\n\n";

auto start = chrono::high_resolution_clock::now();

string messageVar;
   int totalChars = 0;
   cin.ignore();

for(int i =0 ;i<5;i++){ 
		getline(cin, messageVar);
		totalChars+=messageVar.size();
      }

auto finish = chrono::high_resolution_clock::now();
chrono::duration<double> elapsed = finish - start;
int totalTimeInSeconds = elapsed.count();


double speed = ((totalChars / totalTimeInSeconds) * 60);


cout<<"\n\n\n You have typed total characters are :"<<totalChars<<endl;

cout <<"\n \n Your speed is : "<<speed<<"  characters per minutes"<<endl;


return 0;    
}