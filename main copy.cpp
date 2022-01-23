
#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include"strutils.h"
#include <iomanip>

using namespace std;

int main()
{
    
    string qfile, pfile, sfile;
    ifstream qinput ,pinput, sinput;
    bool flag1 = true;
    bool flag2 = true;
    
    cout<< "Please enter a filename for QR database: "<<endl;
    
    while(flag1)
    {
        
        cin>>qfile;
        qinput.open(qfile.c_str());
        if(!(qinput.fail()))
        {
            cout<<"Please enter a filename for Price database: "<<endl;
            while(flag2)
            {
                cin>>pfile;
                pinput.open(pfile.c_str());
                if(!(pinput.fail()))
                {
                    cout<<"Please enter a filename for your shopping list: "<<endl;
                    cin>>sfile;
                    sinput.open(sfile.c_str());
                    flag1= false;
                    flag2= false;
                    
                }
                else
                {
                    cout<< "The Price file does not exists"<<endl;
                    cout << "Please enter a filename for Price database: ";
                }
            }
            
        }
        else
        {
            cout << "The QR file does not exists" << endl;
            cout << "Please enter a filename for QR database: ";
        }
     
    }
    
    string sline,qr,qline,iqr,word,pline,pqr;
    string itemname = "";
    
    int amountitem;
    double price,totalp,totalsum=0;
    
    while(getline(sinput,sline))
    {
        istringstream inputqr(sline);
        inputqr>>qr>>amountitem;
        ToLower(qr);
        
        while(getline(qinput,qline))
        {
            istringstream inputitem(qline);
            inputitem>>iqr;
            if(iqr == qr)
            {
                while(inputitem >> word)
                {
                    if(itemname == "")
                    {
                        itemname = itemname + word;
                    }
                    else
                    {
                        itemname= itemname + " " + word;
                    }
                }
                while(getline(pinput,pline))
                {
                    istringstream inputp(pline);
                    inputp>>pqr>>price;
                    ToLower(pqr);
                    if(pqr == qr)
                    {
                        totalp = amountitem * price;
                        
                       
                        cout<< itemname << "*" << setw(3) <<amountitem << setw(31)<<totalp<<endl;
                        totalsum=totalsum + totalp;
                    }
                }
                pinput.clear();
                pinput.seekg(0);
            }
            
            
        }
        
        qinput.clear();
        qinput.seekg(0);
     
    }
    
    cout << endl;
    double vat = totalsum * 0.18;
    cout << "VAT(18%):"<< setw(27)<<vat<<endl;
    
   
    totalsum = totalsum + vat;
    cout << "_______________________________________" << endl;
    cout << "Total:"<<setw(30)<<totalsum<<endl;
   
    

    

    pinput.close();
    sinput.close();
    qinput.close();


 
    return 0;
}
