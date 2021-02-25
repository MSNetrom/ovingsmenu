# Øvingsmenu

Laget vårsemesteret 2021 av Morten Svendgård
Egnet for å gjøre livet litt lettere under øvinger i C++

-----------------

Eksempel på bruk:

#include <iostream>
#include "netrom.h"

'''C++
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
'''
