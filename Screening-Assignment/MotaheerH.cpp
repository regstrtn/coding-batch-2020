//motaheerhassan@gmail.com

#include<bits/stdc++.h>
#include<fstream>
#include<time.h>

using namespace std;

int main()
{
	int noOfChars=0, totalTime=0, size=0;

	ifstream myFile;
	myFile.open("shakespeare.txt");
	if(myFile.is_open())
	{
		//reading file into an array
		string lines[1396];
		for(int i=0; i<1396; i++)
		{
			getline(myFile, lines[i]);
		}
		
			
		string inputLine;
		cout<<"Typing test started. Start typing the sentences one by one as they appear"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		srand(time(0));
		for(int i=0; i<5; i++)
		{
			int elapsed=0;
			int rndIndex= rand()%1396;
			cout<<lines[rndIndex]<<endl;
			time_t start, end;
			time(&start);
			getline(cin, inputLine);
			time(&end);
			elapsed= end-start;
			totalTime+=elapsed;
			size+=inputLine.size();
		}
		
		
		myFile.close();
	
	cout<<"Your Result................"<<endl;
	cout<<"No. of character typed= "<<size<<endl;
	cout<<"Total time taken= "<<totalTime<<" seconds"<<endl;
	cout<<"Typing speed (characters per minutes)= "<<(size*60)/totalTime<<endl;	
	}
	
	else
	{
		cout<<"Failed to open the file. Try again"<<endl;
	}


}

