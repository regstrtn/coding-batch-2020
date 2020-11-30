// hatim.khambati26@gmail.com

// Assignment-I : Typing Speed Calculator

// Assumptions
// 1) User will enter one word at a time.
// 2) User has to press Enter key to submit the word.
//    (Regardless of User enters whitespace after the word or not).
// 3) User cannot proceed to the next word,
//    unless he/she types the current word correctly.
// 4) Whitespaces are not considered in calculation.

// Results
// 1) Characters Typed
// 2) Time Taken (in seconds)
// 3) Speed - Characters per Minute (cpm) [Whitespace excluded]
// 4) Accuracy (in pecentage) [Extra]

#include <bits/stdc++.h>
using namespace std;

vector<string> stok;
string test5[5];

int main()
{
    // Storing each line of the file
    ifstream file("shakespeare.txt");
    int i = 0;
    string inpline[1396], s;
    if (file.is_open())
    {
        while (getline(file, s))
        {
            inpline[i] = s;
            i++;
        }
        file.close();
    }

    // Take Random 5 Lines from the Input file for the Typing Speed Test
    int cc = 0;
    srand(time(0));
    for (int i = 0; i < 5; ++i)
    {
        test5[i] = (inpline[rand() % 1396]);
        cc += test5[i].size();
    }

    // Instruction Screen
    system("clear");
    cout << string(16, '*') << " Typing Speed Calculator " << string(16, '*') << "\n\n";
    cout << string(20, ' ') << " Instructions!\n\n";
    cout << "1) You will have enter one word at a time.\n\n";
    cout << "2) You have to press Enter key to submit the word.\n   (Regardless of you enter whitespace after the word or not).\n\n";
    cout << "3) You cannot proceed to the next word,\n   unless you type the current word correctly.\n\n";
    cout << string(16, '*') << " Press Enter to Begin!! " << string(16, '*') << endl;
    cin.ignore();

    // Logic for Test begins here!!
    int wc = 0, typedwords = 0;

    // Initializing the Start time of the test
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 5; ++i)
    {
        // Tokenizing the Sentence
        stringstream ss(test5[i]);
        string token;
        while (getline(ss, token, ' '))
            stok.push_back(token);

        // Looping through all tokens
        for (auto w : stok)
        {
            string inp = "";
            wc++;

            // Taking input until the current word is correctly typed
            while (inp != w)
            {
                system("clear");
                cout << "(" << i + 1 << " of 5) " << test5[i] << "\n\n";
                cout << "  Current word" << endl;
                cout << string(16, '*') << endl;
                cout << w << endl;
                cout << "->";
                cin >> inp;
                ++typedwords;
            }
        }
        stok.clear();
    }

    // Initializing the End time of the test
    auto stop = chrono::steady_clock::now();

    // Calculating the duration of test in and seconds
    auto d_s = chrono::duration_cast<chrono::seconds>(stop - start).count();
    // Calculating Characters per Minute
    int cpm = (cc - wc + 1) * 60 / d_s;
    // Calculating Accuracy
    int acc = (wc * 100) / typedwords;

    // Displaying Results
    system("clear");
    cout << string(16, '*') << " Typing Speed Calculator " << string(16, '*') << "\n\n";
    cout << string(23, ' ') << " Results!\n\n";
    cout << "Characters Typed: " << cc << "\n\n";
    cout << "Time Taken: " << d_s << " sec\n\n";
    cout << "Speed - Characters per Minute: " << cpm << " cpm\n\n";
    cout << "Accuracy: " << acc << "%\n";
    return 0;
}