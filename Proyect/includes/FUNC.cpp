#include <iostream>
#include <string>

#include "FUNC.h"


using namespace std;

//asks for a lot of stuff
extern int counter;



string capitalize(string str){
	for (int i=0;str[i]!='\n';++i) {
		if(i==0) {
			if(islower(str[i]))
			str[i]=toupper(str[i]);
		} else {
			if(str[i]!=' ') {
				if(isupper(str[i]))
				str[i]=tolower(str[i]);
			} else {
				i++;
				if(islower(str[i]))
				str[i]=toupper(str[i]);
			}
		}
	}
    return str;
}

extern Country countries[50];


void bubsort(Country arra[], int j){
            Country temp=arra[j];
            arra[j]=arra[j+1];
            arra[j+1]=temp;
}

void AddCountry(Country arr[]){
    if ( cin.peek() == '\n' ){
		cin.ignore();
    }

    string name;
    cout<<" |Type the name of the country: ";
    getline(cin,name);
    capitalize(name);
    
    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(name))
        {
            cout<<"  |That country is already on the list\n";
            return;
        }
    }

    


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
    cout<<" |What's the longitude of your country: ";
    cin>>longitude;

    float latitude;
    cout<<" |What's the latitude of your country: ";
    cin>>latitude;

    if ( cin.peek() == '\n' )
		cin.ignore();  

    


    arr[counter]= Country(capitalize(name),population,capitalize(currency),capitalize(capital),capitalize(continent),longitude,latitude);

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
    int objIndex=-1;
    int menuIndex;    

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(country))
        {
            objIndex=i;
            break;
        }
    }

    if (objIndex==-1)
    {
        cout<<"   |Country doesn't exist\n";
        return;
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

            newcurr=capitalize(newcurr);
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
            newcap=capitalize(newcap);

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
    cout<<"  |How's your country called?: ";
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
            counter--;
            return;
        }
    }
    
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].getName()>arr[i+1].getName())
            {
                bubsort(arr,i);
            }
        }
    }
    
    cout<<"  |The Country doesn't exist\n\n";
    

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

    int c=0;
    cout<<"   |The countries in that continent are:\n";
    for (int i=0; i<50;i++)
    {
        if (arr[i].getCont()==capitalize(continent))
        {
            cout<<"   |>"<<arr[i].getName()<<"\n";
            c+=1;           
        }
    }

    if (c==0)
    {
        cout<<"--None--";
    }
    
    cout<<"\n";
    
    

}

void RelativePos(Country arr[]){
    string country,country2;

    cout<<"  |What's the name of the first country?: ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country);
    
    cout<<"  |What's the name of the second country?: ";
    if ( cin.peek() == '\n' )
	    cin.ignore(); 
    getline(cin,country2);

    if (capitalize(country)==capitalize(country2))
    {
        cout<<"   |The country is the same\n   |Can't calculate distance\n";
        return;
    }
    
    int objIndex=-1;
    int objIndex2=-1;

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(country))
        {
            objIndex=i;
            break;
        }
    }

    for (int i=0; i<50;i++)
    {
        if (arr[i].getName()==capitalize(country2))
        {
            objIndex2=i;    
            break;
        }
    }

    if (objIndex==-1)
    {
        cout<<"   |The first country doesn't exist\n";
    }else if (objIndex2==-1)
    {
        cout<<"   |The second country doesn't exist\n";
    }
    
    if (objIndex==-1||objIndex2==-1)
    {
        cout<<"   |Can't calculate distance\n";
        return;
    }
    
    

    
    
    cout<<"   |"<<arr[objIndex].getName()<<" Is ";
    if (arr[objIndex].gLat()>arr[objIndex2].gLat())
    {
       cout<<"South";
    }else if (arr[objIndex].gLat()<arr[objIndex2].gLat()){
       cout<<"North";
    }
    
    if (arr[objIndex].gLon()>arr[objIndex2].gLon())
    {
        cout<<" West ";
    }else if (arr[objIndex].gLon()<arr[objIndex2].gLon()){
        cout<<" East ";
    }
    cout<<"of "<<arr[objIndex2].getName()<<"\n";
}

void sortShow(Country arr[]){
    int opt;

    cout<<"  |How do you want to display the countries on the list?\n";
    cout<<"   |By Continent (1)\n";
    cout<<"   |By Name (2)\n";  
    cout<<"   |By Capital (3)\n";
    cout<<"   |By Population (4)\n";
    cout<<"   |By Longitude(5)\n";
    cout<<"   |By Latitude (6)\n";

    cout<<"   |>";
    cin>>opt;
    cout<<"     | Name--Continent--Capital--Population--Latitude-Altitude\n";
    switch (opt)
    {
    case 1:
    //Sorts by continent
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].getCont()>arr[i+1].getCont())
            {
                bubsort(arr,i);
            }
        }
    }

        
        break;
    case 2:
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].getName()>arr[i+1].getName())
            {
                bubsort(arr,i);
            }
        }
    }     

        
        break;
    case 3:
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].getCap()>arr[i+1].getCap())
            {
                bubsort(arr,i);
            }
        }
    }
        
        break;
    case 4:
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].getPop()<arr[i+1].getPop())
            {
                bubsort(arr,i);
            }
        }
    } 

        break;
    case 5:
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].gLat()>arr[i+1].gLat())
            {
                bubsort(arr,i);
            }
        }
    }     
  
        break;
    case 6:
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 50-k-1; i++)
        {
            if (arr[i].gLat()>arr[i+1].gLat())
            {
                bubsort(arr,i);
            }
        }
    }
        break;        
    default:
        cout<<"     |Invalid instruction\n";
        break;
    }
    
    for (int i = 0; i < 50; i++)
    {
        if (!(arr[i].getPop()==-1))
        {
            cout<<"     | "<<arr[i].getName()<<" | "<<arr[i].getCont()<<" | "<<arr[i].getCap()<<"   |  "<<arr[i].getPop()<<"     |    "<<arr[i].gLat()<<"    |     "<<arr[i].gLon()<<"\n";
        }
    }
    cout<<"     | ------------------------------------------------------------\n";


}

    //Setters

    void Country::changePop(int temp){
        Population=temp;
    };

    void Country::changeCurr(string temp){
        Currency=(temp);
    }

    void Country::changeCap(string temp){
        Capital=(temp);
    }
    
    void Country::changeCoor(float lon,float lat){
        Lon=lon;
        Lat=lat;
    }

    void Country::changeCont(string temp){
        Continent=(temp);
    }

    void Country::changeName(string temp){
        Name=(temp);
    }

    void Country::reset(){
        Name="zzzz";
        Population=-1;
        Currency="empty";
        Capital="empty";
        Continent="empty";
        Lon=0;
        Lat=0;
    }
    

    //Getters
    int Country::getPop(){
        return Population;
    }

    string Country::getCap(){
        return Capital;
    }

    string Country::getCurr(){
        return Currency;
    }

    string Country::getName(){
        return Name;
    }

    string Country::getCont(){
        return Continent;
    }

    float Country::gLat(){
        return Lat;
    }

    float Country::gLon(){
        return Lon;
    }

