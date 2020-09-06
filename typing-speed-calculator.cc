// ghazisultan25@gmail.com
#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>
#include<cmath>

using namespace std;

#define LINE_COUNT 1400

int main(){
    string lines[LINE_COUNT];

    // Open file
    ifstream infile("Screening-Assignment/shakespeare.txt");

    string line;

    int arr_index = 0;

    while(getline(infile, line)){
        lines[arr_index++] = line;
    }
    
    cout << "-----------------------------------------------\n";
    cout << "          YOUR TOY TYPING CALCULATOR           \n";
    cout << "-----------------------------------------------\n";
    cout << "5 lines will be displayed to you and you have  \n";
    cout << "to type the lines as soon as they are displayed\n";
    cout << "Afterwards, your results will be displayed.\n\n\n";

    srand(time(NULL));

    // Assume that printing few lines and generating random nos.
    // take time in microseconds, negligible compared to 1 sec
    string user_entry;
    int char_count = 0;

    // Start measuring time
    auto begin = chrono::steady_clock::now();

    for(int i=0; i<5; i++){
        int rand_num = rand() % LINE_COUNT;
        cout << lines[rand_num] << "\n\n";
        cin.ignore();
        
        getline(cin, user_entry);

        // user may not enter all the chars, so we should count
        // user entered characters instead of characters in the
        // printed line
        char_count += user_entry.size();
        cout << endl;
    }

    // Stop measuring time and calculate the elapsed time
    auto end = chrono::steady_clock::now();
    auto time_elapsed = chrono::duration_cast<chrono::seconds>(end - begin).count();

    cout << "\nIt took you " << time_elapsed << " seconds to ";
    cout << "type " << char_count << " characters." << endl;

    int chars_per_mins = round(((double)char_count/time_elapsed)*60);
    cout << "\n\nYour typing speed(chars/min): ";
    cout << chars_per_mins << endl;
    cout << "good bye!\n";
}