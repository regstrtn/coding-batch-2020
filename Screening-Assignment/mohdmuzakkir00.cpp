// mohdmuzakkir00@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main(){
    string line[2000];
    ifstream file("shakespeare.txt");
    int i=0;
    while (getline(file, line[i])){
        i++;
    }
    file.close();

    int csum =0;
    time_t tsum=0;
    string str_var;
    cout<<"Type the lines as displayed: "<<endl;
    for (int j=0; j<5; j++){
        time_t begin, end;
        cout<<line[rand()%1200]<<endl;
        time(&begin);
        getline(cin, str_var);
        time(&end);
        tsum+=(end-begin);
		csum+=str_var.length();
    }

    cout<<"\nNumber of characters you typed: "<<csum<<endl;
    cout<<"Time taken to type those characters are: "<<tsum<<endl;
    cout<<"Your typing speed is "<<(csum*60/tsum)<<" characters per minute.";

    return 0;
}