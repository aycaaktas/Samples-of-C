
# include <iostream>
# include <string>
using namespace std;


bool fnc1budget (int budget ){
    if (budget<0)
    {
        return true;
    }
    else {
        return false;
    }
}

bool fnc2quan ( int quan1, int quan2 , int quan3){
    if (quan1 <=0){
        return true;
    }
    else if (quan2<=0){
        return true;
    }
    else if (quan3 <=0){
        return true;
    }
    else {
        return false;
    }
}

int fnc3 (  int quan1,int quan2,int quan3){
    int price ;
    price = (5*quan1) + (10*quan2) + (15*quan3);
    return price;
}

int fnc4 ( int pmaxp, int cprice ,int budget){
    if (pmaxp > cprice || cprice > budget){
        return pmaxp;
    }
    else  {
        return cprice;
    }
}

void fnc5 ( int quan1, int quan2, int quan3 , int budget, int & maxprice){
    
    int cprice;
   

    cprice= fnc3(quan1,quan2,quan3);
    maxprice=fnc4 (maxprice,cprice,budget);
}

int fnc6( int quan1, int quan2, int quan3 , int budget){
    int maxprice,maxpricefinal;
    maxprice= 0;
    maxpricefinal=0;
    
    fnc5(quan1,quan2,quan3,budget,maxprice);
    
    if (maxprice >maxpricefinal)
    {
        maxpricefinal = maxprice;
    }
    
    fnc5(quan1,quan3,quan2,budget,maxprice);
    if(maxprice > maxpricefinal )
    {
        maxpricefinal=maxprice;
    }
    
    fnc5(quan2,quan1,quan3,budget,maxprice);
    if(maxprice > maxpricefinal )
    {
        maxpricefinal=maxprice;
    }
    fnc5(quan2,quan3,quan1,budget,maxprice);
    if(maxprice > maxpricefinal )
    {
        maxpricefinal=maxprice;
    }
    fnc5(quan3,quan2,quan1,budget,maxprice);
    if(maxprice > maxpricefinal )
    {
        maxpricefinal=maxprice;
    }
    fnc5(quan3,quan1,quan2,budget,maxprice);
    if(maxprice > maxpricefinal )
    {
        maxpricefinal=maxprice;
    }
 
    return maxpricefinal;
}



void fnc7()
{
    int budget, quan1, quan2, quan3,maxprice,leftover;
    bool check ,check1;
    
   
    
    cout<<"Please enter your budget: ";cin>>budget;
    check= fnc1budget(budget);
    if (check )
    {
        cout<<"Budget cannot be negative."<<endl;
        return ;
    }
    
    cout<<"Please enter three quantities: ";cin>>quan1>>quan2>>quan3;
    check1=fnc2quan(quan1,quan2,quan3);
     if (check1)
    {
        cout<<"All quantities must be positive."<<endl;
        return;
    }
    maxprice=fnc6 ( quan1, quan2, quan3,budget);
    if (maxprice >= budget || maxprice == 0 )
    {
        cout<<"You cannot afford any of the permutations with these quantities and budget."<<endl;
    }
    else
    {
        leftover = budget - maxprice;
        cout<<"You have "<<leftover<<" liras left."<<endl;
    }
}



int main() {
    
    fnc7();
    cout<<endl;
    fnc7();
    cout<<endl;
    cout<<"Goodbye!"<<endl;
    

    return 0;
}
