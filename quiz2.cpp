
#include<iostream>
#include<string>


using namespace std;



void printline( string s)
{
    int len = s.length();
    int len1 = len *2;
    int ind,in;
    for (ind=0;ind<=len-1;ind++)
    {
        for(in=0;in<=len1-1;in++)
        {
            cout<< s[ind]<<" ";
        }
        cout<<endl;
    }
}







int main()
{
    
    
    printline("a");
    printline("CS201");
    printline("GULSEN");
    return 0;
}

