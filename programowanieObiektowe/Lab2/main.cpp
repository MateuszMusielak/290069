#include "Osoba.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>


void wypiszMenu();
void dodajOsobe(std::vector<Osoba>& osoby, std::map<int,bool>& obecnosci);
void edytujOsobe(std::vector<Osoba>& osoby);
void wyswietlOsoby(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci);
void zmienObecnosc(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci);
void usunOsobe(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci);




int main(){
int wybor=6;
std::vector<Osoba> osoby;
std::map<int,bool> obecnosci;


do{
    wypiszMenu();
    std::cin>>wybor;

    switch(wybor){
        case 1:{//Dodawanie
            dodajOsobe(osoby,obecnosci);
            break;
        }
         case 2:{//Edycja
            edytujOsobe(osoby);
            break;
        }
         case 3:{//Wysiwtl
            wyswietlOsoby(osoby,obecnosci);     
            break;
        }
         case 4:{//Obecnosc
            zmienObecnosc(osoby,obecnosci);
            break;
        }
         case 5:{//Usun
            usunOsobe(osoby,obecnosci);
            break;
        }
         case 6:{//Zamknij
            exit;
            break;
        }
         default:{
            printf("Nie poprawna wartosc");
            break;
        }
    }



}while(true);

    return 0;
}

void wypiszMenu(){
    printf("1.Dodaj Osobe\n2.Edytuj Osobe\n3.Wypisz liste Osob\n4.Ustaw Obecnosc\n5.Usun Osoben\n6.zamknij\n");
}
void dodajOsobe(std::vector<Osoba>& osoby, std::map<int,bool>& obecnosci){
   std::string imie, nazwisko;
    int nrIndexu;
   std::cin.ignore(); 
   std::cout<<"Imie: "; getline(std::cin,imie);
   std::cout<<"Nazwisko: "; getline(std::cin, nazwisko);
   std::cout<<"Nr Indexu: "; std::cin>>nrIndexu;

   auto it = find(osoby.begin(),osoby.end(),nrIndexu);
   if(osoby.end()!=it){
    std::cout<<"Istnieje juz osoba o takim indexie\n";
    return;
   }

   osoby.push_back(Osoba(imie,nazwisko,nrIndexu));
   obecnosci[nrIndexu] = false;


}
void edytujOsobe(std::vector<Osoba>& osoby){
bool kontynuuj = true;
int ix;
    if(osoby.empty()){
        std::cout<<"Brak osob na liscie\n";
        return;
    }

while(kontynuuj){
    std::cout<<"Wybierz osobe do edytowania, 0 - anuluj\n";
    for(size_t i=0;i<osoby.size();i++){
        std::cout<<(i+1)<<".";
        osoby[i].wyswietl();
    }
    
    std::cin>>ix;
    std::cin.ignore();

    if(ix==0) return;

    if(ix<1||ix>(int)osoby.size()){
        std::cout<<"nie ma takiej osoby\n";
    }else{
        kontynuuj=false;
    }
}
ix=ix-1;

std::cout<<"Jakie dane chcesz edytowac?\n1.Imie\n2.Nazwisko\n3.Index\n4.Wszytsko\n5.anuluj\n";
int wybor;
std::cin>>wybor;
std::cin.ignore();

std::string noweImie,noweNazwisko;
int nowyIndex;

switch(wybor){
    case 1:{
        std::cout<<"Aktualne imie: "<<osoby[ix].getImie()<<"\n";
        getline(std::cin,noweImie);
        osoby[ix].setImie(noweImie);
        std::cout<<"Zmieniono imie\n";
        break;
    }
     case 2:{
        std::cout<<"Aktualne nazwisko: "<<osoby[ix].getNazwisko()<<"\n";
        getline(std::cin,noweNazwisko);
        osoby[ix].setNazwisko(noweNazwisko);
        std::cout<<"Zmieniono Nazwisko\n";
        break;
    }
     case 3:{
        std::cout<<"Aktualny index: "<<osoby[ix].getIndex()<<"\n";
        std::cin>>nowyIndex;
        std::cin.ignore();

        auto it = find(osoby.begin(),osoby.end(),nowyIndex);
        if(it==osoby.end()){
            osoby[ix].setIndex(nowyIndex);
            std::cout<<"Zmieniono index\n";
        }else{
            std::cout<<"Juz istnieje taki index\n";
        }
        
        break;
    }
    case 4:{
        std::cout<<"Aktualne imie: "<<osoby[ix].getImie()<<"\n";
        getline(std::cin,noweImie);
        std::cout<<"Aktualne nazwisko: "<<osoby[ix].getNazwisko()<<"\n";
        getline(std::cin,noweNazwisko);
        
        std::cout<<"Aktualny index: "<<osoby[ix].getIndex()<<"\n";
        std::cin>>nowyIndex;
        std::cin.ignore();

        auto it = find(osoby.begin(),osoby.end(),nowyIndex);
       if(it==osoby.end()){
            osoby[ix].setImie(noweImie);
         osoby[ix].setNazwisko(noweNazwisko);
          osoby[ix].setIndex(nowyIndex);
        std::cout<<"Zmieniono dane\n";
        }else{
            std::cout<<"Nie udalo sie zmeinic danych\n";
        }
         
        break;
    }
    case 5:{
        return;
        break;
    }
    default:{
        std::cout<<"Podaj wlasciwa opcje\n";
        break;
    }
}



}
void wyswietlOsoby(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci){
        if(osoby.empty()){
        std::cout<<"Brak osob na liscie\n";
        return;
    }

    printf("nr : imie : nazwisko : nr Indexu : obecnosc\n");
for(size_t i = 0; i < osoby.size(); i++) {
    int nrIndexu = osoby[i].getIndex();
    
    
    auto it = obcenosci.find(nrIndexu);
    bool czyObecny = (it != obcenosci.end()) ? it->second : false;
    
    printf("%d : %s : %s : %d : %s\n", i + 1,
           osoby[i].getImie().c_str(),
           osoby[i].getNazwisko().c_str(),
           nrIndexu,
           czyObecny ? "obecny" : "nieobecny");
}
}
void zmienObecnosc(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci){
int wybor,ix;
bool kontynuuj = true;
    if(osoby.empty()){
        std::cout<<"Brak osob na liscie\n";
        return;
    }


while(kontynuuj){
    std::cout<<"Komu chcesz zmienic obecnosc\n1.wybierz osobe\n2.wszystkim na obecni\n3.zakoncz\n";
    std::cin>>wybor;
    std::cin.ignore();

    switch(wybor){
        case 1:{
        std::cout<<"Wybierz z listy\n";
        wyswietlOsoby(osoby,obcenosci);
        std::cin>>ix;
        std::cin.ignore();

        if(ix<1||ix>osoby.size()){
            std::cout<<"nie ma takiej osoby\n";
        }else{
           int nrIndexu = osoby[ix-1].getIndex();
           obcenosci[nrIndexu] = !obcenosci[nrIndexu];
        }
        
        break;
        }
        case 2:{
            for(size_t i=0;i<osoby.size();i++){
                int nrIndexu = osoby[i].getIndex();
                obcenosci[nrIndexu] = true;
            }
        break;
        }
        case 3:{
            kontynuuj = false;
        break;
        }
        default:{
            std::cout<<"Podaj poprawna wartosc\n";
        break;
        }
    }


}
std::cout<<"zmieniono obecnosc\n";

}
void usunOsobe(std::vector<Osoba>& osoby, std::map<int,bool>& obcenosci){
 bool kontynuuj = true;
 int wybor,ix;
    if(osoby.empty()){
        std::cout<<"Brak osob na liscie\n";
        return;
    }

while(kontynuuj){
    std::cout<<"Wybierz osobe do usunieca, 0 - anuluj\n";
    wyswietlOsoby(osoby,obcenosci);
    std::cin>>ix;
    std::cin.ignore();

    if(ix==0) return;
    if(ix<1||ix>osoby.size()){
        std::cout<<"nie ma takiej osoby\n";
    }else{
        ix=ix-1;
        int nrIndexu = osoby[ix].getIndex();   
        osoby.erase(osoby.begin()+ ix);     
        obcenosci.erase(nrIndexu); 
    }





}
    
}
