#include <iostream>
#include <string>
#include "ListaObecnosci.h"


ListaObecnosci::ListaObecnosci() : liczbaOsob(0) {
    for(int i=0;i<MAX_OSOB;i++){
        obecnosci[i]=false;
    }
}

int ListaObecnosci::znajdzPozycje(int nrIndexu) const{
for(int i=0;i<liczbaOsob;i++){
    if(osoby[i].getIndex() == nrIndexu)
        return i;
    }
    return -1;
}
WynikDodawania ListaObecnosci::dodajOsobe(const std::string& imie, const std::string& nazwisko, int nrIndexu){
    if(liczbaOsob>= MAX_OSOB)
        return WynikDodawania::BRAK_MIEJSCA;

    if(znajdzPozycje(nrIndexu)!=-1)
        return WynikDodawania::DUPLIKAT_INDEKSU;

    osoby[liczbaOsob] = Osoba(imie,nazwisko,nrIndexu);
    obecnosci[liczbaOsob] = false;
    liczbaOsob++;

    return WynikDodawania::SUKCES;
}

WynikUsuwania ListaObecnosci::usunOsobe(int nrIndexu){
    int pozycja = znajdzPozycje(nrIndexu);
    if(liczbaOsob==0){
        return WynikUsuwania::PUSTA_LISTA;
    }
    if(pozycja==-1)
        return WynikUsuwania::NIE_ZNALAZIONO;

    for(int i = pozycja;i<liczbaOsob-1;i++){
        osoby[i]=osoby[i+1];
        obecnosci[i]=obecnosci[i+1];
    }
    liczbaOsob--;

    return WynikUsuwania::SUKCES;
}

WynikEdycji ListaObecnosci::edytujOsobe(int nrIndexu,const std::string& noweImie, const std::string& noweNazwisko, int nowyNrIndexu ){
    int pozycja = znajdzPozycje(nrIndexu);

    if(znajdzPozycje(nowyNrIndexu)!=-1)
        return WynikEdycji::NIE_ZNALAZIONO;

    if(nowyNrIndexu != nrIndexu && znajdzPozycje(nowyNrIndexu) != -1)
        return WynikEdycji::DUPLIKAT_INDEKSU;  

    osoby[pozycja].setImie(noweImie);
    osoby[pozycja].setNazwisko(noweNazwisko);
    osoby[pozycja].setIndex(nowyNrIndexu);

    return WynikEdycji::SUKCES;
}

WynikPrzelaczenia ListaObecnosci::przelaczObecnosc(int nrIndexu){
    int pozycja = znajdzPozycje(nrIndexu);
    if(pozycja==-1)
        return WynikPrzelaczenia::NIE_ZNALAZIONO;

    obecnosci[pozycja] = !obecnosci[pozycja];
    
    return WynikPrzelaczenia::SUKCES;
}
void ListaObecnosci::wyswietlWszytskie() const{
    if(liczbaOsob==0){
        std::cout<<"Brak osob w bazie\n";
        return;
    }

     std::cout << "\n--- LISTA OSOB ---\n";
    for(int i = 0; i < liczbaOsob; i++) {
        std::cout << i+1 << ". ";
        osoby[i].wyswietl(); 
        std::cout << " - " << (obecnosci[i] ? "OBECNY" : "NIEOBECNY") << "\n";
    }    
}

int ListaObecnosci::getLiczbaOsob() const {
    return liczbaOsob;
}
bool ListaObecnosci::czyIndexIstnieje(int nrIndeksu) const {
    return znajdzPozycje(nrIndeksu) != -1;
}
void ListaObecnosci::wyswietlOsobe(int nrIndexu) const {
    int pozycja = znajdzPozycje(nrIndexu);
    if(pozycja != -1) {
        osoby[pozycja].wyswietl();
    }
}
WynikPrzelaczenia ListaObecnosci::przelaczWszytskich(bool status){
    if(liczbaOsob==0){
        std::cout<<"Brak osob na liscie\n";
        return WynikPrzelaczenia::NIE_ZNALAZIONO;
    }

    for(int i=0;i<liczbaOsob;i++){
        obecnosci[i] = status;
    }
    return WynikPrzelaczenia::SUKCES;
}

