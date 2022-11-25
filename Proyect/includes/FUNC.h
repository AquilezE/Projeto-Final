#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <cmath>

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
    };

    //Destructor;

    ~Country(){}

    //Setters
        
    void changePop(int temp){
        Population=temp;
    };

    void changeCurr(string temp){
        Currency=(temp);
    }

    void changeCap(string temp){
        Capital=(temp);
    }
    
    void changeCoor(float lon,float lat){
        Lon=lon;
        Lat=lat;
    }

    void changeCont(string temp){
        Continent=(temp);
    }

    void changeName(string temp){
        Name=(temp);
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

string capitalize(string str);


#endif //FUNC_H