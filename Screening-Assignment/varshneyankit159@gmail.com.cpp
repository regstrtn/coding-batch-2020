//varshneyankit159@gmail.com


#include<bits/stdc++.h>
#include <fstream>
#include<time.h>

using namespace std;

int cal_time(int i, string s)
{
    time_t begin, end;
    time(&begin);                                           //start time in seconds from jan 1 1970
    getline(cin,s);
    cout<<"\n\n";
    time(&end);                                             //end time in seconds from jan 1 1970
    time_t elapsed = (end - begin);
    return elapsed;
}


int main()
{
    int i,j,k,sum=0.0,upper=1395,num,t_size=0;;
    cout<<"Type the exact word shown on your screen consecutively:  \n\n";
    srand(time(0));                                         // to generate random on every loop....

    string s;
    for(i=0;i<5;i++)
    {
        num = (rand() % (upper + 1));
        std::ifstream file("shakespeare.txt");              //read txt file....
        if (file.is_open())
        {
            int c=0;
            std::string line;
            while (std::getline(file, line))
            {
                if(c==num)
                {
                    printf("%s\n", line.c_str());
                    t_size+=line.size();
                    sum+=cal_time(i,s);
                }
                c++;
            }
            file.close();
        }
    }
    cout<<"\n\n\n-----------------------------------------------------------OUTPUT-----------------------------------------------------------------------\n\n\n";
    cout<<"\n\nNumber of characters typed by the user : "<<t_size<<endl;
    cout<<"\nTotal time taken by the user (in seconds) : "<<sum;
    cout<<"\n\nThe characters per minute speed of the user : "<<(t_size*60/sum)<<endl;
}
