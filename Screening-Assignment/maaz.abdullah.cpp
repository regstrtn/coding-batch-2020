//maaz.abdullah111@gmail.com
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string line;
    vector<string> lines;

    srand(time(0));

    //input file stream
    ifstream file("shakespeare.txt");

    //count number of total lines in the file and store the lines in the string vector
    int total_lines = 0;
    while (getline(file, line))
    {

        total_lines++;
        lines.push_back(line);
    }

    string messageVar;
    long long int sum = 0;
    for (int i = 0; i < 5; i++)
    {

        //generate a random number betfirnween 0 and count of total lines
        int random_number = rand() % total_lines;

        //fetch the line where line index (starting from 0) matches with the random number

        cout << "Line to type: " << lines[random_number] << endl;
        cout << "Type your message: " << endl;
        getline(cin, messageVar);
        cout << "You typed: " << messageVar << endl;
        sum = sum + messageVar.size();
        cout << endl;
    }
    cout << "Total Character Typed: " << sum;

    return 0;
}
