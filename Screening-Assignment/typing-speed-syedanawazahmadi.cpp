//syedanawazahmadi@gmail.com
//Syeda Nawaz Ahmadi

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){

    int r;
    std::ifstream infile("shakespeare.txt");
    std::string line;
    string lines[2000];

if (infile.is_open()){   //checking whether the file is open

      int i=0;
      while(getline(infile,line)){ //read data from file object and put it into string.

            lines[i]=line;
            //cout<<lines[i]<< "\n"; //print the data of the string
            i++;
        }
      }

      infile.close(); //close the file object.

    //Displaying time and read 5 random lines
    cout<<"Please type the lines given below , All the Best!"<<endl<<endl;
    std:string msg;
    int count;
    time_t begin, end;
    time(&begin);
    for(int j=0;j<2;j++)
    {
          cout<<endl<<lines[rand()%2000]<<endl;
          getline(cin,msg);
          count=msg.size();
    }

    time(&end);



    float elapsed = end - begin;
    float elapsedMin = elapsed/60.0;
    float speed = (count/5)/elapsedMin;


    cout<<endl<<endl<<"Result :"<<endl;
    cout<<"You typed "<<count<<" characters in "<<elapsedMin<<" min   "<<elapsed<<" sec"<<endl<<endl;
    cout<<"Your typing speed is "<<speed<<" WPM."<<endl;


   }



