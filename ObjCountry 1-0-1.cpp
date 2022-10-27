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

    public:
        
        string Continent;    

    
    //Constructor

    Country (string name="z", int population=-1, string currency="empty", string capital="empty", string continent="empty"){
        Name=name;
        Population=population;
        Currency=currency;
        Capital=capital;
        Continent=continent;

    };

    //Destructor;

    ~Country(){}

    //Setters
        
    void changePop(int temp){
        Population=temp;
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

    string getName(){
        return Name;
    }


};

string capitalize(string text);

void AddCountry(Country arr[]);

void ModCountry(Country arr[]);

int counter={0};

int main()
{
    //Prints Menu
    string MultilineString =
        "1. Register a country\n"
        "2. Modification of some characteristic of the country\n"
        "3. Country Elimination\n"
        "4. Country Specific Inquiry\n"
        "5. Consultation of the countries of some continent\n"
        "6. To be defined by the team\n"
        "7. To be defined by the team\n"
        "0. Exit\n";
    int option;
    Country countries[50];
    
    cout<<MultilineString;
    cout<<"--------------------------------------------\n";


    //Calls  
    do
    {

        cout<<"Select what you want to do: ";
        cin>>option;
        cout<<'\n';


        switch (option)
        {
        case 1:


            AddCountry(countries);
            break;
        
        case 2:
            ModCountry(countries);
            break;

        case 3:
            /* Elimination of country */
            break;

        case 4:
            /* Specific inquiry */
            break;

        case 5:
            /* Countries of a continent */
            break;

        case 6:
            /* TO BE DEFINED */
            break;

        case 7:
            /* TO BE DEFINED */
            break;

        case 0:

            break;
                
        default:
            cout<<"Input is not Valid";
            break;
        }

        } while (option!=0);

    
    cout<<countries[0].getPop();

    return 0; 



}
//asks for a lot of stuff
void AddCountry(Country arr[]){
    if ( cin.peek() == '\n' )
		cin.ignore();

    string name;
    cout<<" Type the name of the country: ";
    getline(cin,name);
    capitalize(name);


    int population;
    cout<<" How many people live in your country: ";
    cin>>population;
    
    //I use this to clear "cin"'s buffer, since it skips the getline function if it isn't cleared.
    if ( cin.peek() == '\n' )
		cin.ignore();    
    
    string currency;
    cout<<" What's the name of the currency they use: ";
    getline(cin,currency);

    string capital; 
    cout<<" What's the capital of your country: ";
    getline(cin,capital);

    string continent;
    cout<<" In wich continent is it located in: ";
    getline(cin,continent);


    arr[counter]= Country(name,population,currency,capital,continent);

    counter++;
}

void ModCountry(Country arr[]){


    string country;
    cout<<"  |How's your country called?";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);


    int objIndex;
    int menuIndex;    

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(country))
        {
            objIndex=i;
            break;
        }
    }

    
    do{
        cout<<"  |What do you want to change?\n  |1.Population\n  |2.Currency\n  |3.Capital\n  |0.Exit";
        cin>>menuIndex;


        if (menuIndex==0)
        {

            return;
        }else if (menuIndex==1){
            //Changes the population
            int newpop;
            
            cout<<"   |How many people live in your Country?: ";
            cin>>newpop;
            
            arr[objIndex].changePop(newpop);
            
            break;

        }else if (menuIndex==2){
            
            //Changes the currency
            string newcurr;
            cout<<"   |What's the new currency of your Country?: ";

            if ( cin.peek() == '\n' )
		        cin.ignore(); 
            
            getline(cin,newcurr);

            arr[objIndex].changeCurr(newcurr);

            break;
        }else if (menuIndex==3)
        {
            string newcap;
            cout<<"   |What's the new capital of your Country?: ";

            if ( cin.peek() == '\n' )
		        cin.ignore(); 
            
            getline(cin,newcap);

            arr[objIndex].changeCurr(newcap);

            break;
        }


    }while (menuIndex!=0);

}

void DelCountry(Country arr[]){
    string country;
    cout<<"  |How's your country called?";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);


    int objIndex;
    int menuIndex;



}
string capitalize(string text) {

	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}else{
            text[x]= tolower(text[x]);
        }
	}

	return text;
}

/*----------Limitations---------------*/

/*
1-country.Language can only have one language, I'd use std:vector but my teacher won't let me do it.
2-Since you can't create an objetc with an identifier named as 
3-Capitalization MATTERS when adding the name of the country. 
4-
5-
6-
*/

