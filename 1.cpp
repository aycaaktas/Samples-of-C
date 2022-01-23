
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int securePasswords( const vector<string> & v)
{
    string current;
    int len;
    int totalcounter=0;
    for(unsigned int k =0; k<v.size();k++)
    {
        current = v[k];
        len = v[k].length();
        int counterupper=0;
        int counterlower=0;
        int counterdigit=0;
        for( int m=0;m<len;m++)
        {
            if( current.at(m) <= 'z' && current.at(m) >='a')
            {
                counterlower++;
            }
            else if (current.at(m) <= 'Z' && current.at(m) >='A')
            {
                counterupper++;
            }
            else if( current.at(m) >= '0' && current.at(m) <='9')
            {
                counterdigit++;
            }
        }
        if((counterlower >=1) && (counterupper >=1) && (counterdigit >=1))
        {
            
            totalcounter++;
        }

        
    }
    
    return totalcounter;
}


int main(){
    
    
    vector<string> passwords;
    passwords.push_back("123456");
    passwords.push_back("password");
    passwords.push_back("password1");

    cout << "Vector has " << securePasswords(passwords) << " secure passwords" << endl;
    
    
    
    
}


