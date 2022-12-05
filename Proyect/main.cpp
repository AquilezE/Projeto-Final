#include <iostream>
#include <string>
//used in distance() to calculate a square root, since a recursive exponenciation function doesn't work with .5 
#include <cmath>
#include "includes/FUNC.h"

using namespace std;

int counter={4};

int main()
{
    //Prints Menu
    string MultilineString =
        "1. Register a country\n"
        "2. Modification of some characteristic of the country\n"
        "3. Country Elimination\n"
        "4. Country Specific Inquiry\n"
        "5. Consultation of the countries of some continent\n"
        "6. Distance between two countries\n"
        "7. Show existing countries sorted\n"
        "0. Exit\n";
    int option;
    Country countries[50];
    
    cout<<MultilineString;
    cout<<"--------------------------------------------\n";
    
    //Example Countries

    Country Mexico("Mexico",2000,"Pesos","CDMX","Nor Ame",20.00,-102.00);
    Country Japan("Japan",3000,"Yen","Tokyo","Asia",35.00,137.00);
    Country Argentina("Argentina",1000,"Peso Arg","B.A.","Sud Ame",-50.00,-80.00);
    Country Peru("Peru",2500,"Sol","Lima","Sud Ame",-40.00,-90.00);
    countries[0]=Mexico;
    countries[1]=Japan;
    countries[2]=Argentina;
    countries[3]=Peru;

    //Calls  
    do
    {

        cout<<"Select what you want to do: ";
        cin>>option;
        cout<<'\n';
        if (cin.fail()){ 
            cout<<"Data entered is not of int type";
        }

        switch (option)
        {
        case 1:


            AddCountry(countries);
            break;
        
        case 2:
            ModCountry(countries);
            break;

        case 3:
            DelCountry(countries);
            
            break;

        case 4:
            InfoCountry(countries);
            break;

        case 5:
            findCont(countries);
            break;
        case 6:
            distance(countries);
            break;

        case 7:
            sortShow(countries);
            break;

        case 0:

            break;
                
        default:
            cout<<" |Invalid option\n";
            break;
        }

        } while (option!=0);


    return 0; 



}



/*----------Limitations---------------*/

/*
1-country.Langu age can only have one language, I'd use std:vector but my teacher won't let me do it.
2-Since you can't create an object with an identifier named with user input, we will use Country.getName() and it's index to identify it.
5- Distance is assuming flat map.
6-If you insert a string in an place where an Int is asked, you'll fucking break it
*/