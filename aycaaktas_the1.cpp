

// AYCA AKTAS



#include <iostream>
#include <string>
using namespace std;

int main()
{
    string roomname;
    int roomc;  //original room capacity
    float allowedc;
    int students,zoomstudents, alloweds;

    cout<< "Welcome to CS201 physical classroom capacity checker."<<endl;
    cout<< "Please enter the room name: ";cin>>roomname;
    cout<< "Please enter the room capacity: ";cin>>roomc;
    if ( roomc<0)
    {
        cout<<"You have entered an invalid value for room capacity."<<endl;
    }
    else
    {
        cout<<"Please enter the allowed capacity coefficient: "; cin >> allowedc;   // allowed capacity cooficent
        if( 0> allowedc || 1<allowedc)
        {
            cout<<"You have entered an invalid value for capacity coefficient."<<endl;
        }
        else
        {
            cout<< "Please enter how many students are registered to your course: ";cin>>students;  //registerred students
            if ( students <0)
            {
                cout<< "You have entered an invalid value for registered students."<<endl;
            }
            else
            {
             
                alloweds= roomc * allowedc;     // allowed students = original room capacity * allowed capacity
                if (students <= alloweds )
                {
                    cout<<roomname<< " can allow all students to attend physical lectures."<<endl;

                }
                else
                {
                    zoomstudents=  students - alloweds;       //zoom students = registered students - allowed students
                    cout<< roomname<< " cannot allow all students to attend physical lectures."<<endl;
                    cout<<"For each lecture "<< zoomstudents << " students must be selected to watch on Zoom."<<endl;
                }
            }
        }
    }
    return 0;
}
