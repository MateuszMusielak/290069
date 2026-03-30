#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void printMenu();
void dodawanieOsoby(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob);
void wypiszListe(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob);
void edycjaMenu();
void edytujOsobe(string imiona[], string nazwiska[],int nrIndex[],int rozmiar,int *iloscOsob);
int szukanieNaz(string nazwiska[],string naz, int *iloscOsob);
void usuwanieOsoby(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob);
void ustawObecnosc(string nazwiska[],bool obecnosc[], int *iloscOsob);
void wypiszOsobe(string imiona[], string nazwiska[],int nrIndex[],int rozmiar,int temp);

int main(){
string imiona[100]={}, nazwiska[100]={};
bool obecnosc[100]={};
int nrIndex[100]={}, wybor, iloscOsob=0;     
const int rozmiar = 100;


do{

printMenu();
cin>>wybor;
switch(wybor){
    case 1:
    wypiszListe(imiona,nazwiska,nrIndex,obecnosc,rozmiar,&iloscOsob);
    break;

    case 2:
    dodawanieOsoby(imiona,nazwiska,nrIndex,obecnosc,rozmiar,&iloscOsob);
    break;

    case 3:
    edytujOsobe(imiona,nazwiska,nrIndex,rozmiar,&iloscOsob);

    break;
    case 4:
    usuwanieOsoby(imiona,nazwiska,nrIndex,obecnosc,rozmiar,&iloscOsob);
    break;

    case 5:
    ustawObecnosc(nazwiska,obecnosc,&iloscOsob);
    break;
    case 6:
    exit(0);
    break;

    default:
    
    break;
}


}while(true);








    return 0;
}
void printMenu(){

    printf("MENU\n 1 - Wyswietl liste\n 2 - Dodawanie osoby\n 3 - Zmienianie danych\n 4 - Usuwanie osoby\n 5 - Ustaw obecnosc \n 6 - Zamknij program\n");
}
void dodawanieOsoby(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob){
    string imie,naz;
    int nrIx;
    cout<<"Podaj: Imie, Naziwsko, nrIndexu"<<endl;
    cin>>imie>>naz>>nrIx;

    if(cin.fail()){
        cout << "Bledny format! Nr indeksu musi byc liczba." << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        return;
    }
        for(int i=0;i<*iloscOsob;i++){
        if(nazwiska[i]==naz){
            printf("Taka osoba juz istnieje\n"); return;
        }
    }
    if(*iloscOsob>99){
        cout<<"max tablicy"<<endl;
        return; 
    }
    imiona[*iloscOsob]=imie;
    nazwiska[*iloscOsob]=naz;
    nrIndex[*iloscOsob]=nrIx;
    obecnosc[*iloscOsob]=false;
    (*iloscOsob)++;
        
    }
void wypiszListe(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob){
    for(int i=0;i<*iloscOsob;i++){
       printf("%d. Imie: %s, Nazwisko: %s, Nr Indexu: %d, Obecnosc: %s\n",i+1,imiona[i].c_str(),nazwiska[i].c_str(),nrIndex[i],obecnosc[i] ? "True" : "False");
    } 
}
void edytujOsobe(string imiona[], string nazwiska[],int nrIndex[],int rozmiar,int *iloscOsob){
if(*iloscOsob==0){cout<<"brak osob"<<endl;return;}
int temp,wybor;bool flag=1;
cout<<"Podaj index do edytowania od 1"<<endl;
do{
    cin>>temp;
}while(temp<=0||temp>*iloscOsob);
temp=temp-1;

do{
edycjaMenu();
wypiszOsobe(imiona,nazwiska,nrIndex,rozmiar,temp);
cin>>wybor;
switch(wybor){
    case 1:
    cin>>imiona[temp];
    break;
    case 2:
    cin>>nazwiska[temp];
    break;
    case 3:
    cin>>nrIndex[temp];
    break;
    case 4:
    flag = false;
    break;
    default:

    break;
}


}while(flag);



}
void edycjaMenu(){
    printf("1 - Imie\n2 - Nazwisko\n3 - Nr Indeksu\n4 - zakoncz\n");
}
void usuwanieOsoby(string imiona[], string nazwiska[],int nrIndex[],bool obecnosc[],int rozmiar,int *iloscOsob){
int temp;
string naz;
if(*iloscOsob==0){cout<<"brak osob"<<endl;return;}
cout<<"Jaka osobe chcesz usunac, '-' aby przerwac"<<endl;
while(true){
    cin>>naz;

    if(naz=="-") return;
    
    temp = szukanieNaz(nazwiska,naz,iloscOsob);
    if(temp!=-1) break;
}

for(int i=temp;i<*(iloscOsob)-1;i++){
    imiona[i]=imiona[i+1];
    nazwiska[i]=nazwiska[i+1];
    nrIndex[i]=nrIndex[i+1];
    obecnosc[i]=obecnosc[i+1];
}
(*iloscOsob)--;
}
int szukanieNaz(string nazwiska[], string naz, int *iloscOsob){
    for(int i=0;i<*iloscOsob;i++){
        if(nazwiska[i]==naz)
            return i;
    }
    return -1;
}
void ustawObecnosc(string nazwiska[],bool obecnosc[], int *iloscOsob){
int temp;
string naz;
cout<<"Ustaw obecnosc, '-' aby przerwac, '+' aby ustawic wszytski obecnosc"<<endl;
while(true){
    cin>>naz;

    if(naz=="-") return;
    if(naz=="+") break;
    temp = szukanieNaz(nazwiska,naz,iloscOsob);
    if(temp!=-1) break;
}
if(naz=="+"){
    for(int i=0;i<*iloscOsob;i++)
    obecnosc[i]=true;
}
if(obecnosc[temp]==false){
obecnosc[temp]=true;return;}
else{
obecnosc[temp]=false;
}
}
void wypiszOsobe(string imiona[], string nazwiska[],int nrIndex[],int rozmiar,int temp){
    printf("%d. Imie: %s, Nazwisko: %s, Nr Indexu: %d\n",temp,imiona[temp].c_str(),nazwiska[temp].c_str(),nrIndex[temp]);
}