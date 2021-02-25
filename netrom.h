#pragma once

/*
    Laget vårsemesteret 2021 av Morten Svendgård
    Egnet for å gjøre livet litt lettere under øvinger i C++
    
    URL: https://github.com/MSNetrom/ovingsmenu

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

#include <iostream>
#include <string>
#include <vector>

namespace netrom{
    //Holder vinduet åpent
    void my_window_open();

    //Et valg i menyen
    struct MenuChoice{
        void (*executer)();
        std::string description = "";
    };

    // Organize our menu
    class Menu{
    private:
        std::string heading;
        std::vector<MenuChoice> choices;
    public:
        //Constructor with optinioal heading
        Menu(std::string heading);

        //Add menu choice
        void addChoice(void (*executer)(), std::string description);
        //Add new line with info
        void addInfo(std::string info);
        //Vis meny, og returnere om bruker vil avslutte
        bool runMenu() const;
    };
}
