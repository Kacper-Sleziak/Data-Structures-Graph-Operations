#include <iostream>
#include "MST_Kruskal.h"
#include "MST_Prim.h"

void menu(){
    while (true) {
        char x;

        std::cout << "Wcisnij 1 aby utworzyc drzewo MST algorytmem Kruskala" << std::endl;
        std::cout << "Wcisnij 2 aby utworzyc drzewo MST algorytmem Prima" << std::endl;
        std::cout << "Wcisnij 3 aby zakonczyc dzialanie programu" << std::endl;
        std::cout << "Wybierz numer: ";
        std::cin >> x;
        std::cout <<std::endl;

        if (x == '1'){
            MST_Kruskal mst;
            mst.MST_handler();
        }

        else if (x == '2'){
           MST_Prim MST;
           MST.MST_handler();
        }

        else if (x == '3'){
            break;
        }

        else{
            std::cout<<"Wybrales zly numer, sprobuj jeszcze raz!"<<std::endl;
        }
    }

}

int main() {
    menu();
}