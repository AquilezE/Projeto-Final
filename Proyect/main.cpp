#include <iostream>
#include <string>
#include <cmath>
#include "includes/FUNC.h"

using namespace std;

/*
string capitalize(string str);

class Country{
    //Atributes
    private:
        string Name;
        long int Population;
        string Language;
        string Currency;
        string Capital;    
        float Lon,Lat;

    public:
        
        string Continent;    

    
    //Constructor

    Country (string name="zzzz", int population=-1, string currency="empty", string capital="empty", string continent="empty",float A=0.00,float L=0.00){
        Name=name;
        Population=population;
        Currency=currency;
        Capital=capital;
        Continent=continent;
        Lon=A;
        Lat=L;
    };

    //Destructor;

    ~Country(){}

    //Setters
        
    void changePop(int temp){
        Population=temp;
    };

    void changeCurr(string temp){
        Currency=capitalize(temp);
    }

    void changeCap(string temp){
        Capital=capitalize(temp);
    }
    
    void changeCoor(float lon,float lat){
        Lon=lon;
        Lat=lat;
    }

    void changeCont(string temp){
        Continent=capitalize(temp);
    }

    void changeName(string temp){
        Name=capitalize(temp);
    }

    void reset(){
        Name="zzzz";
        Population=-1;
        Currency="empty";
        Capital="empty";
        Continent="empty";
        Lon=0;
        Lat=0;
    }
    
    //Getters
    int getPop(){
        return Population;
    }

    string getCap(){
        return Capital;
    }

    string getCurr(){
        return Currency;
    }

    string getName(){
        return Name;
    }

    string getCont(){
        return Continent;
    }

    float gLat(){
        return Lat;
    }

    float gLon(){
        return Lon;
    }


};



void AddCountry(Country arr[]);

void ModCountry(Country arr[]);

void DelCountry(Country arr[]);

void InfoCountry(Country arr[]);

void findCont(Country arr[]);

void distance(Country arr[]);

void sortShow(Country arr[]);
*/

int counter={3};

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

    Country Mexico("Mexico",2000,"Pesos","CDMX","Zamerica",20.00,-102.00);
    Country Japan("Japan",3000,"Yen","Tokyo","America",35.00,137.00);
    Country Argentina("Argentina",1000,"Arg","B.A.","Sudamerica",-50.00,-80.00);
    countries[0]=Mexico;
    countries[1]=Japan;
    countries[2]=Argentina;

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
1-country.Language can only have one language, I'd use std:vector but my teacher won't let me do it.
2-Since you can't create an object with an identifier named with user input, we will use Country.getName() and it's index to identify it.
5-Distance is assuming the location of the points in a flat map
6-If you insert a string in an place where an Int is asked, you'll fucking break it
*/