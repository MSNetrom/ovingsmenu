#include "netrom.h"

/*
    Laget vårsemesteret 2021 av Morten Svendgård
    Egnet for å gjøre livet litt lettere under øvinger i C++

    -----------------

    Eksempel på bruk:

    #include <iostream>
    #include "netrom.h"

    // Eksempelfunksjon
    void hello() {
        std::cout << "Hello World" << std::endl;
    }

    int main() {

        // Lag meny
        netrom::Menu menu("Eksempeloverskrift for meny");

        // Legg til litt info og ett valg
        menu.addInfo("\nUnderoverkrift 1:");
        menu.addChoice(hello, "Kjor funksjon hello");

        // Kjor menyen til bruker avslutter
        while(menu.runMenu());
    }
*/

namespace netrom{
    //Holder vinduet åpent
    void myWindowOpen(){
        std::cout << std::endl << "Trykk enter for a fortsette...";
        std::cin.seekg(0, std::ios::end);
        std::cin.clear();
        std::cin.get();
    }


    //Meny konstruktor

    Menu::Menu(std::string heading) : heading(heading + "\n\n0) Avslutt") {}

    //Meny funksjoner

    void Menu::addChoice(void (*executer)(), std::string description){
        choices.push_back(MenuChoise{executer, description});
    }

    void Menu::addInfo(std::string info){
        if (choices.size() == 0) {
            heading += "\n" + info;
            return;
        }
        choices.back().description += "\n" + info;
    }

    bool Menu::runMenu() const{
        //Print info
        std::cout << heading << std::endl;
        for (unsigned int i = 0; i < choices.size(); ++i){
            std::cout << i+1 << ") " << choices[i].description << std::endl; 
        }
        std::cout << std::endl << "Angi valg (0 - " << choices.size() << "): ";

        //Get choise
        unsigned int choise = -1; // -1 gir maks verdi på unsigned int?
        std::cin >> choise;
        std::cout << std::endl;

        //Check if valid choise or not
        if (choise >= 0 && choise <= choices.size()){
            if (choise == 0) return false; // Vi vil avslutte
            else {
                std::cin.ignore(); //Unngå problemer med input
                choices[choise-1].executer(); //Kjører kode
            }
        } else {
            std::cout << "Ikke et gyldig valg. Prov pa nytt" << std::endl;
        }

        //Venter, og legger til space
        myWindowOpen();
        std::cout << std::endl;

        //Returner om vi skal fortsette
        return true;
    }
}