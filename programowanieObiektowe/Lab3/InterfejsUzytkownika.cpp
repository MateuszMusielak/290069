#include "InterfejsUzytkownika.h"
#include <iostream>
#include <string>
#include <cstdlib>

void InterfejsUzytkownika::wyswietlMenu() {
    std::cout << "\n-------- MENU --------\n";
    std::cout << "1. Dodaj osobe\n";
    std::cout << "2. Wyswietl wszystkie osoby\n";
    std::cout << "3. Edytuj osobe\n";
    std::cout << "4. Usun osobe\n";
    std::cout << "5. Zmien obecnosc\n";
    std::cout << "6. Zmien obecnosc wszystkim\n";
    std::cout << "7. Zakoncz program\n";
    std::cout << "Wybor: ";
}

void InterfejsUzytkownika::obsluzDodawanie(){
    std::string imie, nazwisko;
    int nrIndexu;

    std::cout<<"Podaj imie (0 - anuluj): ";
    std::getline(std::cin,imie);
    if(imie == "0"){
        std::cout<<"anulowano\n";
        return;
    }

    std::cout<<"Podaj nazwisko: ";
    std::getline(std::cin,nazwisko);

    std::cout<<"Podaj nr Indexu: ";
    nrIndexu = wczytajLiczbe("Podaj numer indexu: ");

    if(imie.length() < 1 || nazwisko.length() < 1){
        std::cout<<"Imie i Nazwisko nie moga byc puste\n";
        return;
    }

    switch(lista.dodajOsobe(imie, nazwisko, nrIndexu)) {
        case WynikDodawania::SUKCES:
            std::cout << "Dodano pomyslnie!\n";
            break;
        case WynikDodawania::BRAK_MIEJSCA:
            std::cout << "Blad: Osiagnieto maksymalna liczbe studentow (" << MAX_OSOB << ")\n";
            break;
        case WynikDodawania::DUPLIKAT_INDEKSU:
            std::cout << "Blad: Student z numerem " << nrIndexu << " juz istnieje w bazie\n";
            break;
    }

}

void InterfejsUzytkownika::obsluzWyswietlanie(){
    lista.wyswietlWszytskie();
}
void InterfejsUzytkownika::obsluzEdytowanie(){
    if(lista.getLiczbaOsob()==0){
        std::cout<<"Brak osob do edycji\n";
        return;
    }

    lista.wyswietlWszytskie();

    int nrIndexu;
    std::cout<<"Podaj numer indexu (anuluj - 0): ";
    nrIndexu = wczytajLiczbe("Podaj numer indexu: ");
    

    if(nrIndexu==0){
        std::cout<<"anulowano\n";
        return;
    }

    if(!lista.czyIndexIstnieje(nrIndexu)){
        std::cout<<"Nie ma takiego indexu o numerze: "<<nrIndexu<<"\n";
        return;
    }

    std::string noweImie, noweNazwisko;
    int nowyNrIndexu;

    std::cout<<"Nowe imie: ";
    std::getline(std::cin,noweImie);

    std::cout<<"Nowe nazwisko: ";
    std::getline(std::cin,noweNazwisko);

    std::cout<<"Nowy nr Indexu: ";
    nowyNrIndexu = wczytajLiczbe("Podaj numer indexu: ");

    if(noweImie.length() < 1 || noweNazwisko.length() < 1){
        std::cout<<"Imie i Nazwisko nie moga byc puste\n";
        return;
    }

      switch(lista.edytujOsobe(nrIndexu,noweImie,noweNazwisko,nowyNrIndexu)){
    case WynikEdycji::SUKCES:
            std::cout << "Edytowano pomyslnie!\n";
            break;
        case WynikEdycji::DUPLIKAT_INDEKSU:
            std::cout << "Blad: Student o takim indexie juz istnieje\n";
            break;
        case WynikEdycji::NIE_ZNALAZIONO:
            std::cout << "Blad: Nie znaleziono studenta o takim indexie\n";
            break;
  }
}
void InterfejsUzytkownika::obsluzUsuwanie(){
    if(lista.getLiczbaOsob()==0){
        std::cout<<"Brak osob do usuniecia\n";
        return;
    }

    lista.wyswietlWszytskie();

    int nrIndexu;
    std::cout<<"Podaj nr Indexu osoby do usuniecia: ";
    nrIndexu = wczytajLiczbe("Podaj numer indexu: ");

    std::cout<<"Czy na pewno chcesz usunac te osobe? (t/n): ";
    char potwierdzenie;
    std::cin>>potwierdzenie;
    std::cin.ignore();

    if(potwierdzenie != 't' &&  potwierdzenie != 'T'){
        std::cout<<"Anulowano\n";
        return;
    }

      switch(lista.usunOsobe(nrIndexu)){
    case WynikUsuwania::SUKCES:
            std::cout << "Usunieto pomyslnie!\n";
            break;
        case WynikUsuwania::PUSTA_LISTA :
            std::cout << "Blad: Brak studentow do usuniecia\n";
            break;
        case WynikUsuwania::NIE_ZNALAZIONO :
            std::cout << "Blad: Nie znaleziono studenta o takim indexie\n";
            break;
  }


}
void InterfejsUzytkownika::obsluzZmienObecnosc(){
    if(lista.getLiczbaOsob()==0){
        std::cout<<"brak osob do zmiany";
        return;
    }

    lista.wyswietlWszytskie();

    int nrIndexu;
    std::cout<<"Podaj numer indexu osoby (0 - anuluj): ";
    nrIndexu = wczytajLiczbe("Podaj numer indexu: ");

    if(nrIndexu==0){
        std::cout<<"Anulowano\n";
        return;
    }

      switch(lista.przelaczObecnosc(nrIndexu)){
    case WynikPrzelaczenia::SUKCES:
            std::cout << "Przelaczono pomyslnie!\n";
            break;
        case WynikPrzelaczenia::NIE_ZNALAZIONO:
            std::cout << "Blad: Brak studentow do usuniecia\n";
            break;
        
  }
}

void InterfejsUzytkownika::uruchom(){
    int wybor;

    while(true){
        wyswietlMenu();
        std::cin>>wybor;
        std::cin.ignore();

        switch(wybor) {
            case 1: obsluzDodawanie(); break;
            case 2: obsluzWyswietlanie(); break;
            case 3: obsluzEdytowanie(); break;
            case 4: obsluzUsuwanie(); break;
            case 5: obsluzZmienObecnosc(); break;
            case 6: obsluzZmienObecnoscWszytskim(); break;
            case 7:
                std::cout << "Koniec programu.\n";
                exit(0);
            default:
                std::cout << "Nieprawidlowy wybor.\n";
        }
    }
}
void InterfejsUzytkownika::obsluzZmienObecnoscWszytskim(){
    std::string obecny;
    bool status;
    std::cout<<"Podaj czy kazdy ma miec status obecny czy nieobecny: ";
    std::getline(std::cin,obecny);
    

    if(obecny == "obecny"){
        status=true;
    }else if(obecny == "nieobecny"){
        status = false;
    }else{
        std::cout<<"Podano nie poprawna wartosc\n";
        return;
    }
   switch(lista.przelaczWszytskich(status)){
    case WynikPrzelaczenia::SUKCES:
            std::cout << "Przelaczono pomyslnie!\n";
            break;
        case WynikPrzelaczenia::NIE_ZNALAZIONO:
            std::cout << "Blad: Brak studentow do usuniecia\n";
            break;
        
  }

    
}
int InterfejsUzytkownika::wczytajLiczbe(const std::string& prompt) {
    int wartosc;
    while(true) {
        std::cout << prompt;
        std::cin >> wartosc;
        
        if(std::cin.fail()) {
            std::cin.clear();  // wyczyść flagę błędu
            std::cin.ignore(1000, '\n');  // usuń złą linię z bufora
            std::cout << "Blad: Wprowadz liczbe calkowita!\n";
        } else {
            std::cin.ignore(1000, '\n');  // wyczyść resztę linii
            return wartosc;
        }
    }
}