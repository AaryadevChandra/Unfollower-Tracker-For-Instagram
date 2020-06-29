#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    char ch1[10], ch2[10];
    fstream f1, f2;
    f1.open("1.txt", ios::in);
    f2.open("2.txt", ios::in);
    while(!f1.eof())
    {
        f1.getline(ch1, 10, '\n');
        f2.getline(ch2, 10, '\n');
        if(strcmp(ch1, ch2) == 0)
        {
            cout<<"okay"<<endl;
        }
        else if(strcmp(ch1, ch2) != 0)
        {
            cout<<ch1<<endl;
            int cur = f2.tellg();
            int len = strlen(ch2);
            f2.seekg((cur - len - 4), ios::beg);
            f2.getline(ch2, 10, '\n');
        }
    }
    f2.close();
    f1.close();
}