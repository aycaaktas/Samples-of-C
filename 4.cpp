


#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

struct result
{
    string name;
    int carnumber;
    double finishingtime;
    
};

void sort(vector<result> & a)
{

 
    int j, k,  minındex, numelts = a.size();
    result temp;
    for(k=0; k < numelts - 1; k++)
    {
        minındex = k;
        for(j=k+1; j < numelts; j++)
        {
            if (a[j].finishingtime < a[minındex].finishingtime)
            {
                minındex = j;
            }
              
        }
    
        temp = a[k];
        a[k] = a[minındex];
        a[minındex] = temp;
    }
}

void printResults(const vector<result> & a)
{
    result winner;
    int elements = a.size();
    winner = a[0];
    double diff,diff2;
    cout<< "1."<<setw(2)<<winner.name<<setw(2)<<"(#"<<winner.carnumber<<")"<<setw(2)<<"  WINNER"<<endl;
    for(int k=1;k<elements;k++)
    {
        diff= a[k].finishingtime - a[k-1].finishingtime;
        diff2= a[k].finishingtime - winner.finishingtime;
        cout<< k+1<<"."<<setw(2)<<a[k].name<<setw(2)<<"(#"<<a[k].carnumber<<")"<<setw(2)<<"+"<<diff2<<setw(2)<<"(+"<<diff<<")"<<endl;
    }
    
    
    
}




int main()
{
    vector<result>v;
    string filename= "raceresults.txt";
    string line;
    ifstream input;
    
    input.open(filename.c_str());
    while(getline(input,line))
    {
        result r;
        int num;
        string nname,nsurname;
        double time;
        istringstream in(line);
        in>>num>>nname>>nsurname>>time;
        r.name = nname + " " + nsurname;
        r.carnumber =num;
        r.finishingtime=time;
        v.push_back(r);
    }
    
    sort(v);  // sorted from smallest finishing time to biggest.
    printResults(v);
    
  
    
    return 0;
}
