// ehtesham_1234@live.com

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[])
{ //Setting the seed for Rand()
    srand((unsigned int)time(NULL));

    //String Array to Read All the lines from file
    string lines[2000];
    //Input File Stream
    ifstream file("shakespeare.txt");
    int n = 0;

    //Couting No of lines in Lines
    while (getline(file, lines[n]))
    {
        n++;
    }

    string random_sentences[5];
    int i = 0;
    int charcount = 0;
    cout << "Enter these Lines to Check your speed" << endl;
    // time Variables to Measure start and end time .
    time_t start, end;
    time(&start);
    while (i < 5)
    {
        int line = rand() % n;
        cout << lines[line] << endl;
        getline(cin, random_sentences[i]);
        cout << endl;
        charcount += random_sentences[i].size();
        i++;
    }
    time(&end);
    cout << "You typed " << charcount << " Characters" << endl;
    double diff = double(end - start);
    cout << "Your Time was " << fixed << diff << " seconds" << endl;
    int cpm = (int)(charcount * 60) / diff;
    cout << "You Typed " << cpm << " Characters per minute" << endl;
}
