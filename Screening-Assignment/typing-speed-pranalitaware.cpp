//pranalitaware@gmail.com

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
string line,messageVar;
int random_number[10];
float cpm;
    vector<string> lines;
    srand(time(0));
    ifstream file("shakespeare.txt");
    int total_lines=0;
    while(getline(file,line))
    {
       total_lines++;
       lines.push_back(line);
    }
    int random_number1=rand()%total_lines;
    int random_number2=rand()%total_lines;
    int random_number3=rand()%total_lines;
    int random_number4=rand()%total_lines;
    int random_number5=rand()%total_lines;

    cout<<"line 1:"<<lines[random_number1]<<endl;
    cout<<"line 2:"<<lines[random_number2]<<endl;
    cout<<"line 3:"<<lines[random_number3]<<endl;
    cout<<"line 4:"<<lines[random_number4]<<endl;
    cout<<"line 5:"<<lines[random_number5]<<endl;

    cout<<endl<<"Type the above 5 lines here:\n";

    auto begin = std::chrono::high_resolution_clock::now();
    getline(cin, messageVar);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

    cout<<endl<<"The number of characters in the string are: " << messageVar.size()<<endl;
    cout<<"Time measured is: "<<elapsed.count()<<" seconds"<<endl;
    cout<<"Your typing speed is "<<(messageVar.size()*60/elapsed.count())<< " characters per minute. \n \n";

    return 0;
}
