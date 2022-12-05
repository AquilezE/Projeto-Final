#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>

using namespace std;



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
    }
    //Destructor;

    ~Country(){}

    //Setters
        
    void changePop(int temp);

    void changeCurr(string temp);

    void changeCap(string temp);
    
    void changeCoor(float lon,float lat);

    void changeCont(string temp);

    void changeName(string temp);

    void reset();
    
    //Getters
    int getPop();

    string getCap();

    string getCurr();

    string getName();

    string getCont();

    float gLat();

    float gLon();


};


void AddCountry(Country arr[]);

void ModCountry(Country arr[]);

void DelCountry(Country arr[]);

void InfoCountry(Country arr[]);

void findCont(Country arr[]);

void RelativePos(Country arr[]);

void sortShow(Country arr[]);

void bubsort(Country arra[], int j);

string capitalize(string str);


#endif //FUNC_H