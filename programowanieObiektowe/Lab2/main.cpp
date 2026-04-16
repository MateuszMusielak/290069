#include "Osoba.h"
#include <iostream>
#include <string>
#include <cstdlib>
#define MAX_OSOB 100

void wyswietlMenu();
void dodajOsobe(Osoba* osoby, int* liczbaOsob, int pojemnosc);
void wyswietlOsoby(Osoba* osoby,bool* listaObecnosci, int liczbaOsob);
void edytujOsobe(Osoba* osoby, int liczbaOsob);
void usunOsobe(Osoba* osoby,bool* listaObecnosci, int* liczbaOsob, int pojemnosc);
void ustawObecnosc(Osoba* osoby, bool* obecnosc, int liczbaOsob);

int main(){

Osoba osoby[MAX_OSOB];
bool obecnosc[MAX_OSOB] = {false};
int liczbaOsob=0,pojemnosc = MAX_OSOB;

while(true){
    int wybor;
    wyswietlMenu();

    std::cin>>wybor;
    std::cin.ignore();

    switch(wybor){
        case 1:{//Dodawanie osoby
            dodajOsobe(osoby,&liczbaOsob,pojemnosc);
            break;
        }
        case 2:{//Wyswietl osoby
            wyswietlOsoby(osoby,obecnosc,liczbaOsob);
            break;
        }
        case 3:{//Edytowanie osoby
            edytujOsobe(osoby,liczbaOsob);
            break;
        }
        case 4:{//Usuwanie osoby
            usunOsobe(osoby,obecnosc,&liczbaOsob,pojemnosc);
            break;
        }
        case 5:{//Zmienianie obecnosci
            ustawObecnosc(osoby,obecnosc,liczbaOsob);
            break;
        }
        case 6:{//zakoncz
            exit(0);
            break;
        }
        default:{
            std::cout<<"Podano niewlascwa opcje\n";
            break;
        }
    }




}






    return 0;
}
void wyswietlMenu(){
    std::cout << "--------MENU--------\n"
              << "1. Dodaj osobe\n"
              << "2. Wyswietl osoby\n"
              << "3. Edytuj osobe\n"
              << "4. Usun osobe\n"
              << "5. Zmien obecnosc\n"
              << "6. Zakoncz\n";
}
void dodajOsobe(Osoba* osoby, int* liczbaOsob, int pojemnosc){
std::string imie, nazwisko;
int nrIndexu;


//Sprawdzenie czy max
if(*liczbaOsob >= pojemnosc){
    std::cout<<"Brak miejsca, max: "<<pojemnosc<<"\n";
}

//Wczytywanie
while(true){
std::cout << "Podaj imie: ";
getline(std::cin, imie);

 if(imie == "0") {
    std::cout << "Anulowano.\n";
    return;
}

std::cout << "Podaj nazwisko: ";
getline(std::cin, nazwisko);

std::cout << "Podaj numer indeksu: ";
std::cin >> nrIndexu;
std::cin.ignore();




//Walidacja
if(imie.length()<1 || nazwisko.length()<1){
    std::cout<<"Imie i nazwisko nie moga byc puste(0 - anuluj)\n";
    continue;
}
bool indexIstnieje = false;
for(size_t i=0;i<*liczbaOsob;i++){
    if(osoby[i].getIndex()==nrIndexu){
        indexIstnieje = true;
        break;
    }
}
if(indexIstnieje) {
std::cout << "Ten numer indeksu juz istnieje!\n";
continue;
}
break;
}
osoby[*liczbaOsob]=Osoba(imie,nazwisko,nrIndexu);
(*liczbaOsob)++;

std::cout<<"Dodano osobe\n";
}
void wyswietlOsoby(Osoba* osoby,bool* listaObecnosci, int liczbaOsob){
    if(liczbaOsob==0){
        std::cout<<"Brak osob do wyswietlenia\n";
        return;
    }

    std::cout << "\n--- LISTA OSOB ---\n";
    for(size_t i=0;i<liczbaOsob;i++){
         std::cout << (i+1) << ". "
                  << osoby[i].getImie() << " "
                  << osoby[i].getNazwisko() << " ("
                  << osoby[i].getIndex() << ") - "
                  << (listaObecnosci[i] ? "OBECNY" : "NIEOBECNY")
                  << "\n";
    }

}
void edytujOsobe(Osoba* osoby, int liczbaOsob) {
    if(liczbaOsob == 0) {
        std::cout << "Brak osob do edycji.\n";
        return;
    }
    
int znalezionaPozycja = -1;
int szukanyNumer;
while(true){
    std::cout << "Podaj numer indeksu osoby do edycji (0 - anuluj): ";
   std::cout << "\n--- LISTA OSOB ---\n";
for(size_t i = 0; i < liczbaOsob; i++) {
    std::cout << i+1 << ". ";
    osoby[i].wyswietl();
    std::cout << "\n";
}
    std::cin >> szukanyNumer;
    std::cin.ignore();
    
    if(szukanyNumer == 0) {
        std::cout << "Anulowano.\n";
        return;
    }
    
    
    for(size_t i = 0; i < liczbaOsob; i++) {
        if(osoby[i].getIndex() == szukanyNumer) {
            znalezionaPozycja = i;
            break;
        }
    }
    
    if(znalezionaPozycja == -1) {
        std::cout << "Nie znaleziono osoby z numerem " << szukanyNumer << "\n";
        ;
    }else break;
}    
    // 2. Menu edycji
    while(true) {
        std::cout << "\n--- EDYCJA OSOBY ---\n";
        std::cout << "1. Imie: " << osoby[znalezionaPozycja].getImie() << "\n";
        std::cout << "2. Nazwisko: " << osoby[znalezionaPozycja].getNazwisko() << "\n";
        std::cout << "3. Numer indeksu: " << osoby[znalezionaPozycja].getIndex() << "\n";
        std::cout << "4. Wszystkie dane\n";
        std::cout << "5. Zakoncz edycje\n";
        std::cout << "Wybor: ";
        
        int wybor;
        std::cin >> wybor;
        std::cin.ignore();
        
        switch(wybor) {
            case 1: {
                std::string noweImie;
                std::cout << "Aktualne imie: " << osoby[znalezionaPozycja].getImie() << "\n";
                std::cout << "Nowe imie: ";
                do{
                getline(std::cin, noweImie);
                }while(noweImie.length()<1);
                osoby[znalezionaPozycja].setImie(noweImie);
                
                break;
            }
            case 2: {
                std::string noweNazwisko;
                std::cout << "Aktualne nazwisko: " << osoby[znalezionaPozycja].getNazwisko() << "\n";
                std::cout << "Nowe nazwisko: ";
                
                do{
                    getline(std::cin, noweNazwisko);
                }while(noweNazwisko.length()<1);
                osoby[znalezionaPozycja].setNazwisko(noweNazwisko);
                break;
            }
            case 3: {
                int nowyNumer;
                std::cout << "Aktualny numer indeksu: " << osoby[znalezionaPozycja].getIndex() << "\n";
                
                while(true) {
                    std::cout << "Nowy numer indeksu: ";
                    std::cin >> nowyNumer;
                    std::cin.ignore();
                    
                    if(nowyNumer <= 0) {
                        std::cout << "Numer indeksu musi byc dodatni!\n";
                        continue;
                    }
                    
                    
                    bool istnieje = false;
                    for(size_t i = 0; i < liczbaOsob; i++) {
                        if(i != znalezionaPozycja && osoby[i].getIndex() == nowyNumer) {
                            istnieje = true;
                            break;
                        }
                    }
                    
                    if(istnieje) {
                        std::cout << "Ten numer indeksu juz istnieje!\n";
                    } else {
                        break;
                    }
                }
                osoby[znalezionaPozycja].setIndex(nowyNumer);
                std::cout << "Zmieniono numer indeksu.\n";
                break;
            }
            case 4: {
                std::string noweImie, noweNazwisko;
                int nowyNumer;
                
                std::cout << "Aktualne dane:\n";
                std::cout << "Imie: " << osoby[znalezionaPozycja].getImie() << "\n";
                std::cout << "Nazwisko: " << osoby[znalezionaPozycja].getNazwisko() << "\n";
                std::cout << "Numer indeksu: " << osoby[znalezionaPozycja].getIndex() << "\n";
                
                
                std::cout << "\nNowe imie: ";
                
                do{
                getline(std::cin, noweImie);
                }while(noweImie.length()<1);
                osoby[znalezionaPozycja].setImie(noweImie);
                
               
                std::cout << "Nowe nazwisko: ";
                do{
                getline(std::cin, noweNazwisko);
                }while(noweNazwisko.length()<1);
                osoby[znalezionaPozycja].setNazwisko(noweNazwisko);
                
                
                while(true) {
                    std::cout << "Nowy numer indeksu: ";
                    std::cin >> nowyNumer;
                    std::cin.ignore();
                    
                    if(nowyNumer <= 0) {
                        std::cout << "Numer indeksu musi byc dodatni!\n";
                        continue;
                    }
                    
                    bool istnieje = false;
                    for(size_t i = 0; i < liczbaOsob; i++) {
                        if(i != znalezionaPozycja && osoby[i].getIndex() == nowyNumer) {
                            istnieje = true;
                            break;
                        }
                    }
                    
                    if(istnieje) {
                        std::cout << "Ten numer indeksu juz istnieje!\n";
                    } else {
                        osoby[znalezionaPozycja].setIndex(nowyNumer);
                        break;
                    }
                }
                
                std::cout << "Zmieniono wszystkie dane.\n";
                break;
            }
            case 5: {
                std::cout << "Zakonczono edycje.\n";
                return;
            }
            default: {
                std::cout << "Nieprawidlowy wybor. Wybierz 1-5.\n";
                break;
            }
        }
    }
}
void usunOsobe(Osoba* osoby,bool* listaObecnosci, int* liczbaOsob, int pojemnosc){
if(*liczbaOsob==0){
    std::cout<<"Brak osob do usuniecia\n";
    return;
}

int szukanyNumer,znalezionaPozycja = -1;
while(true){
    std::cout << "Podaj numer indeksu osoby do edycji (0 - anuluj): ";
    std::cout << "\n--- LISTA OSOB ---\n";
for(size_t i = 0; i < *liczbaOsob; i++) {
    std::cout << i+1 << ". ";
    osoby[i].wyswietl();
    std::cout << "\n";
}
    std::cin >> szukanyNumer;
    std::cin.ignore();
    
    if(szukanyNumer == 0) {
        std::cout << "Anulowano.\n";
        return;
    }
    
    
    for(size_t i = 0; i < *liczbaOsob; i++) {
        if(osoby[i].getIndex() == szukanyNumer) {
            znalezionaPozycja = i;
            break;
        }
    }
    
    if(znalezionaPozycja == -1) {
        std::cout << "Nie znaleziono osoby z numerem " << szukanyNumer << "\n";
        
    }else break;
}   
std::cout << "Czy na pewno chcesz usunac: ";
osoby[znalezionaPozycja].wyswietl();
std::cout << "? (t/n): ";
char potwierdzenie;
std::cin >> potwierdzenie;
std::cin.ignore();
    
if(potwierdzenie != 't' && potwierdzenie != 'T') {
    std::cout << "Anulowano usuwanie.\n";
    return;
} 
for(size_t i = znalezionaPozycja; i < *liczbaOsob - 1; i++) {
        osoby[i] = osoby[i + 1];
        listaObecnosci[i] = listaObecnosci[i + 1];
}
(*liczbaOsob)--;
std::cout << "Usunieto pomyslnie.\n";
}
void ustawObecnosc(Osoba* osoby, bool* obecnosc, int liczbaOsob) {
    if(liczbaOsob == 0) {
        std::cout << "Brak osob w bazie.\n";
        return;
    }
    
    std::cout << "\n--- LISTA OBECNOSCI ---\n";
    for(int i = 0; i < liczbaOsob; i++) {
        std::cout << i+1 << ". ";
        osoby[i].wyswietl();
        std::cout << " - " << (obecnosc[i] ? "OBECNY" : "NIEOBECNY") << "\n";
    }
    
    
    std::cout << "- Wpisz numer indeksu studenta, aby przełączyć jego obecnosc\n";
    std::cout << "- Wpisz 0 aby zakonczyc\n";
    
    while(true) {
        int szukanyNumer;
        std::cout << "Numer indeksu: ";
        std::cin >> szukanyNumer;
        std::cin.ignore();
        
        if(szukanyNumer == 0) {
            std::cout << "Zakonczono ustawianie obecnosci\n";
            break;
        }
        
      
        int znalezionaPozycja = -1;
        for(size_t i = 0; i < liczbaOsob; i++) {
            if(osoby[i].getIndex() == szukanyNumer) {
                znalezionaPozycja = i;
                break;
            }
        }
        
        if(znalezionaPozycja == -1) {
            std::cout << "Nie znaleziono studenta z numerem " << szukanyNumer << "\n";
            continue;
        }
        
        
        obecnosc[znalezionaPozycja] = !obecnosc[znalezionaPozycja];
        std::cout << "Student: ";
        osoby[znalezionaPozycja].wyswietl();
        std::cout << " -> " << (obecnosc[znalezionaPozycja] ? "OBECNY" : "NIEOBECNY") << "\n";
    }
    
    
    int liczbaObecnych = 0;
    std::cout << "\n--- PODSUMOWANIE ---\n";
    for(size_t i = 0; i < liczbaOsob; i++) {
        if(obecnosc[i]) liczbaObecnych++;
    }
    std::cout << "Obecnych: " << liczbaObecnych << "/" << liczbaOsob << "\n";
}