//warsiarshad384@gmail.com

#include <stdio.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main() {
    
    string text_source="C:\\Users\\Arshad\\Desktop\\calc.txt";
    //getline(cin, text_source);

    //time_t begin, end;
    

    ifstream MyReadFile(text_source);
    string lines[2000];
    int k = 0;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, lines[k])) {
       k++;

    }

    // Close the file
    MyReadFile.close();
    string s = "";
    double timer = 0;
    for (int i = 0; i < 5; i++) {
        int v1 = rand()%k+1;
        cout << lines[v1] << endl;
        string typedstring;
        auto start = high_resolution_clock::now();
        cin.ignore();
        
        //clock_t start = clock();
        //time(&begin);

        getline(cin, typedstring);

        //time(&end);
        //clock_t end = clock();
        auto end = high_resolution_clock::now();

        s = s + typedstring;
        //double elapsed =(double)(end-start) / CLOCKS_PER_SEC;
        auto duration = duration_cast<milliseconds>(end - start);
        //double elapsed = (double)end - begin;
        //cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
        timer = timer + (double)duration.count();

    }

    cout <<"characters typed "<< s.size() << " " << timer << " milliseconds" << endl;
    cout << "characters per minute  " << s.size()*timer / 6000 << endl;

    return 0;
}




