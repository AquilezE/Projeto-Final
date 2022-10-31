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
        Currency=temp;
    }

    void changeCap(string temp){
        Capital=temp;
    }
    
    void changeCoor(float lon,float lat){
        Lon=lon;
        Lat=lat;
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

    string getContinent(){
        return Continent;
    }

    float gLat(){
        return Lat;
    }

    float gLon(){
        return Lon;
    }


};

string capitalize(string text);

void AddCountry(Country arr[]);

void ModCountry(Country arr[]);

void DelCountry(Country arr[]);

void InfoCountry(Country arr[]);

void findCont(Country arr[]);

void distance(Country arr[]);

int counter={2};

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
        "7. To be defined by the team\n"
        "0. Exit\n";
    int option;
    Country countries[50];
    
    cout<<MultilineString;
    cout<<"--------------------------------------------\n";
    
    //Example Countries

    Country Mexico("Mexico",2000,"Pesos","CDMX","America",20,-102.00);
    Country Japan("Japan",3000,"Yen","Tokyo","America",35,137);

    countries[0]=Mexico;
    countries[1]=Japan;

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
            DelCountry(countries);
            counter--;
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
            /* TO BE DEFINED */
            break;

        case 0:

            break;
                
        default:
            cout<<"Input is not Valid";
            break;
        }

        } while (option!=0);


    return 0; 



}
//asks for a lot of stuff

void AddCountry(Country arr[]){
    if ( cin.peek() == '\n' ){
		cin.ignore();
    }

    string name;
    cout<<" |Type the name of the country: ";
    getline(cin,name);
    capitalize(name);


    int population;
    cout<<" |How many people live in your country: ";
    cin>>population;
    
    //I use this to clear "cin"'s buffer, since it skips the getline function if it isn't cleared.
    if ( cin.peek() == '\n' )
		cin.ignore();    
    
    string currency;
    cout<<" |What's the name of the currency they use: ";
    getline(cin,currency);

    string capital; 
    cout<<" |What's the capital of your country: ";
    getline(cin,capital);

    string continent;
    cout<<" |In wich continent is it located in: ";
    getline(cin,continent);

    float longitude;
    cout<<" |What's the longitude of your country";
    cin>>longitude;

    float latitude;
    cout<<" |What's the latitude of your country";
    cin>>latitude;

    if ( cin.peek() == '\n' )
		cin.ignore();  

    


    arr[counter]= Country(name,population,currency,capital,continent,longitude,latitude);

    counter++;
}

void ModCountry(Country arr[]){

//It finds the Country to modify by asking the user it's name
    string country;
    cout<<"  |How's your country called? ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);

//then It iterates over every object in array, when the name is found it saves the i value to objIndex
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
        cout<<"  |What do you want to change?\n  |1.Population\n  |2.Currency\n  |3.Capital\n  |0.Exit\n";
        cout<<"  |> ";
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
            //Changes the capital
            string newcap;
            cout<<"   |What's the new capital of your Country?: ";

            if ( cin.peek() == '\n' )
		        cin.ignore(); 
            
            getline(cin,newcap);

            arr[objIndex].changeCurr(newcap);

            //Changes the Coordinates of the capital city
//            if ( cin.peek() == '\n' )
//		        cin.ignore(); 
            cout<<"   |And what are the Coordinates of it?\n";
            
            float x,y;
            cout<<"    |Longitude: ";
            cin>>x;
            
            cout<<"    |Latitude: ";
            cin>>y;
            
            arr[objIndex].changeCoor(x,y);         
            
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

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(country))
        {
            objIndex=i;
            arr[objIndex].reset();
            break;
        }
    }

    

}

//shit don't work, sadly
string capitalize(string text){

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

void InfoCountry(Country arr[]){

//It finds the Country to modify by asking the user it's name
    string country;
    cout<<"  |How's your country called? ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);

//then It iterates over every object in array, when the name is found it saves the i value to objIndex
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
        cout<<"  |What do you want to know of the country?\n  |1.Population\n  |2.Currency\n  |3.Capital\n  |4.Coordinates\n  |0.Exit\n";
        cout<<"  |> ";
        cin>>menuIndex;
        

        if (menuIndex==0)
        {

            return;
        }else if (menuIndex==1){
            //Changes the population
            
            cout<<"  |"<<arr[objIndex].getPop()<<" people live in your Country. \n";

            break;

        }else if (menuIndex==2){
            
            cout<<"  |This country uses: "<<arr[objIndex].getCurr()<<"\n";

            break;

        }else if (menuIndex==3)
        {
            cout<<"  |This country's capital is: "<<arr[objIndex].getCap()<<"\n";

            break;

        }else if (menuIndex==4)
        {
            cout<<"  |The coordinates are: (Lat:"<<arr[objIndex].gLat()<<","<<"Long:"<<arr[objIndex].gLon()<<")\n";

            break;

        }
        


    }while (menuIndex!=0);

}

void findCont(Country arr[]){
    string continent;
    cout<<"  |What's the name of the continent: ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,continent);

    cout<<"   |The countries in that continent are: ";
    for (int i=0; i<50;i++)
    {
        if (arr[i].getContinent()==capitalize(continent))
        {
            cout<<arr[i].getName()<<" ";           
        }
    }
    cout<<"\n";
    
    

}

void distance(Country arr[]){
    string country,country2;

    cout<<"  |What's the name of the first country?: ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);
    
    cout<<"  |What's the name of the second country?: ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country2);

    int objIndex;
    int objIndex2;

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==country)
        {
            objIndex=i;
            break;
        }
    }

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==country2)
        {
            objIndex2=i;
            break;
        }
    }


    float dist = sqrt(pow(arr[0].gLat() - arr[1].gLat(), 2) + pow(arr[0].gLon() - arr[1].gLon(), 2) * 1.0);
    
    cout<<"   |The distance between them is: "<<dist<<"\n";
    cout<<"   |"<<arr[objIndex2].getName()<<" Is ";
    if (arr[0].gLat()>arr[1].gLat())
    {
       cout<<"South";
    }else if (arr[0].gLat()<arr[1].gLat()){
       cout<<"North";
    }
    
    if (arr[0].gLon()>arr[1].gLon())
    {
        cout<<" West ";
    }else if (arr[0].gLon()<arr[1].gLon()){
        cout<<" East ";
    }
    cout<<"of "<<arr[objIndex].getName()<<"\n";
}
/*----------Limitations---------------*/

/*
1-country.Language can only have one language, I'd use std:vector but my teacher won't let me do it.
2-Since you can't create an object with an identifier named with user input, we will use Country.getName() and it's index to identify it.
3-Capitalization MATTERS when adding the name of the country. 
4-calling DelCountry and inputing a name that doesn't exist, changes the counter of countries in the list; fix it
5-Distance is assuming the location of the points in a flat map
6-
*/

