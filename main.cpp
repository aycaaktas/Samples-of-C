#include<iostream>
#include <string>
#include <vector>
using namespace std;

void lessthan( const vector<int> & a)
{
    int k ,sum,count,m;
    vector<int> num;
    for(k=0,sum=0,count=0;k<a.size();k++)
    {
        sum =sum + a[k];
        count= count +1;
        
    }
    double avr= sum/count;
    for(m=0;m<a.size();m++)
    {
        if(a[m]<avr)
        {
            num.push_back(a[m]);
           
        }
    }
    cout<<"Numbers less than "<<avr<<" : "<<endl;
    for(int g=0;g<num.size();g++)
    {
        cout<< num[g] << " ";
    }
 
}
int main()

{
    
vector<int> v; // = {24,11,19,35,22,51,10,17,14};
v.push_back(24); v.push_back(11); v.push_back(19); v.push_back(35); v.push_back(22);
v.push_back(51); v.push_back(10); v.push_back(17); v.push_back(14);

lessthan(v);
    
    
    
    
    
}
