#include <iostream>
#include <string>

using namespace std;




class country{
    //Atributes
    private:
        string Name;
        long int Population;
        string Language;
        string Currency;
        string Capital;    
    public:
    

    
    //Constructor

    country (string name){
        Name=name;
    }

    country (string name, int population, string currency, string capital){
        Name=name;
        Population=population;
        Currency=currency;
        Capital=capital;

    };
    //Setters
        
    void changePop(int temp){
        Population=temp;
    };

    
    void changeCap(string temp){
        Capital=temp;
    };

    void changeCurr(string temp){
        Currency=temp;
    }

    void changeCap(string temp){
        Capital=temp;
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

};



int main()
{
    
    return 0;
}




/*----------Limitations---------------*/

/*
1-country.Language can only have one language, I'd use std:vector but my teacher won't let me do it.
2-
3-
4-
5-
6-
*/

