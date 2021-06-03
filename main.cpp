#include <iostream>
#include "fstream"

#include "MST_Kruskal.h"
#include "MST_Prim_Matrix_Version.h"
#include "MST_Prim_List_Version.h"

#include "Shortest_Path_Dijkstra_Matrix.h"
#include "Shortest_Path_Dijkstra_List.h"

void menu_mst(){

        std::string file_name;
        std::cout<<"Wybierz plik tekstowy: ";
        std::cin >> file_name;
        std::cout<<std::endl;

        while (true) {
        char x;

        std::cout << "Wcisnij 1 aby utworzyc drzewo MST algorytmem Kruskala" << std::endl;
        std::cout << "Wcisnij 2 aby utworzyc drzewo MST algorytmem Prima przy pomocy macierzy" << std::endl;
        std::cout << "Wcisnij 3 aby utworzyc drzewo MST algorytmem Prima przy pomocy listy" << std::endl;
        std::cout << "Wcisnij 4 aby zakonczyc tworzenie MST" << std::endl;
        std::cout <<"Wybierz numer: ";
        std::cin >> x;
        std::cout <<std::endl;

        if (x == '1'){
            MST_Kruskal mst;
            mst.MST_handler(file_name);
        }

        else if (x == '2'){
           MST_Prim_Matrix_Version MST_1;
           MST_1.MST_handler(file_name);
        }

        else if(x == '3'){
            MST_Prim_List_Version MST_2;
            MST_2.MST_handler(file_name);
        }

        else if (x == '4'){
            break;
        }

        else{
            std::cout<<"Wybrales zly numer, sprobuj jeszcze raz!"<<std::endl;
        }
    }
}

void menu_shortest_path(){

    std::string file_name;
    std::cout<<"Wybierz plik tekstowy: ";
    std::cin >> file_name;
    std::cout<<std::endl;

    while (true) {
        char x;

        std::cout << "Wcisnij 1 aby znalezc najkrotsza sciezkie algorytmem Dijkstry przy pomocy macierzy" << std::endl;
        std::cout << "Wcisnij 2 aby znalezc najkrotsza sciezkie algorytmem Dijkstry przy pomocy listy" << std::endl;
        std::cout << "Wcisnij 3 aby zakonczyc wyszukiwanie najkrotszej sciezki" << std::endl;
        std::cout << "Wybierz numer: ";
        std::cin >> x;
        std::cout << std::endl;

        if (x == '1'){
            Shortest_Path_Dijkstra_Matrix name;
            name.path_handler(file_name);

        }

        else if (x == '2'){
            Shortest_Path_Dijkstra_List name_a;
            name_a.Path_handler(file_name);
        }

        else if (x == '3'){
            break;
            std::cout << std::endl<<std::endl;
        }

        else{
            std::cout<<"Wybrales zly numer!"<<std::endl;
        }
    }

}

void menu(){
    while (true) {

        char x;

        std::cout << "Wcisnij 1 aby wybrac algorytm tworzacy MST" << std::endl;
        std::cout << "Wcisnij 2 aby wybrac algorytm najkrotszej sciezki" << std::endl;
        std::cout << "Wcisnij 3 aby zakonczyc dzialanie programu" << std::endl;
        std::cout<<"Wybierz numer: ";
        std::cin >> x;
        std::cout << std::endl;

        if(x == '1'){
            menu_mst();
        }

        else if(x == '2'){
            menu_shortest_path();
        }

        else if( x == '3'){
            std::cout << std::endl<<std::endl;
            break;
        }

        else{
            std::cout<<"Wybrales zly numer!"<<std::endl;
        }
    }

};

int main() {
  menu();
}