#include <fstream>
#include <iostream>
#include "Shortest_Path_Dijkstra_Matrix.h"

void Shortest_Path_Dijkstra_Matrix::read_file(std::string file_name) {
    std::fstream myfile(file_name, std::ios_base::in);
    int counter = 0;

    int data;
    int n;      //number of vertexes
    int e;      //number of edges
    int start_v;

    while (myfile >> data) {
        if (counter == 0) {
            e = data;
        }

        else if (counter == 1) {
            n = data;
        }

        else if (counter == 2) {
            start_v = data;
            break;
        }

        else {

        }

        counter++;
    }

        this->number_of_edges = e;
        this->number_of_vertexes = n;
        this->start_vertex = start_v;

        this->matrix = new int * [n];

        for(int i = 0 ; i < n ; i++){
            matrix[i] = new int [n];
        }

        for(int i = 0 ; i < n ; i++){
            for(int k = 0 ; k < n ; k++){
                matrix[i][k] = 0;
            }
        }

        int v;
        int w;
        int weight;
        counter = 0;

        while (myfile >> data){

            if (counter % 3 == 0){
                v = data;
                counter ++;
            }

            else if (counter % 3 == 1){
                w = data;
                counter ++;
            }

            else if(counter % 3 == 2){
                weight = data;
                matrix[v][w] = weight;
                counter = 0;
            }
        }

        myfile.close();
    }


void Shortest_Path_Dijkstra_Matrix::show_matrix() {

    for(int i = 0 ; i < number_of_vertexes ; i++){
        for(int k = 0 ; k < number_of_vertexes ; k++){
            std::cout<<matrix[i][k]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool Shortest_Path_Dijkstra_Matrix::is_vertex_visited(int v) {
    for(int i = 0 ; i < visited_size ; i++){
        if(visited[i] == v){
            return true;
        }
    }
    return false;
}

void Shortest_Path_Dijkstra_Matrix::display_shortest_paths() {

    std::cout<<"Najkrotsza droga z wierzcholka "<<start_vertex<<" do:"<<std::endl<<std::endl;


    for(int i = 0 ; i < number_of_vertexes ; i++) {
        std::cout << "Wierzcholka: " << i << std::endl;
        std::cout << "Waga: " << keys[i] << std::endl;
        std::cout << "Droga: ";

        if (i == start_vertex) {
            std::cout << "Brak Drogi, wierzcholek startowy"<<std::endl<<std::endl;
        }

        else {

            std::cout << i;
            std::cout << "<-";

            if (i != start_vertex) {
                int k;
                int previous_vertex = previous[i];

                while (true) {

                    if (previous_vertex == start_vertex) {
                        std::cout << previous_vertex;
                        break;
                    }

                    std::cout << previous_vertex;
                    previous_vertex = previous[previous_vertex];

                    std::cout << "<-";
                }
            }
            std::cout << std::endl << std::endl;
        }
    }
}

void Shortest_Path_Dijkstra_Matrix::Dijkstra_algorithm() {

    int new_visited = - 1;
    int shortest_path = INT_MAX;
    int checking_vertex = visited[visited_size -1];

        for(int k = 0 ; k < number_of_vertexes ; k++) {

            int path = matrix[checking_vertex][k];

            if (path != 0) {
                if (!is_vertex_visited(k)) {
                    if(path + keys[checking_vertex] < keys[k]) {

                        keys[k] = path + keys[checking_vertex];     //koszt dojscia od wierzcholka startowego
                        previous[k] = checking_vertex;
                    }

                    if(path < shortest_path){
                        new_visited = k;                           // nastepny wierzcholek do sprawdzenia
                        shortest_path = path;
                    }

                }
            }
        }


    if(new_visited != -1){

        //relokacja visited
        visited_size++;
        visited[visited_size-1] = new_visited;

        //relokacja unvisited przez usuniecie kolejnego odwiedzonego wierzcholka

        for(int i = 0 ; i < unvisited_size ; i++){
            if(unvisited[i] == new_visited){
                new_visited = i;
            }
        }

        for(int i = new_visited ; i < unvisited_size ; i++){
            unvisited[i] = unvisited[i + 1];
        }

        unvisited_size --;
        int * new_unvisited_array = new int [unvisited_size];

        for(int i = 0 ; i< unvisited_size ; i++){
            new_unvisited_array[i] = unvisited [i];
        }

        unvisited = new_unvisited_array;
        new_unvisited_array = NULL;


        Dijkstra_algorithm();
    }
}

void Shortest_Path_Dijkstra_Matrix::path_handler(std::string file_name) {

    this -> read_file(file_name);

    std::cout<<"Macierz Sasiedztwa: "<<std::endl;
    this ->show_matrix();
    std::cout<<std::endl;


    previous = new int[number_of_vertexes];
    previous[start_vertex] = -1;

    keys = new int[number_of_vertexes];

    for(int i = 0 ; i < number_of_vertexes ; i++){

        if(i == start_vertex){
            keys[i] = 0;
        }

        else{
            keys[i] = INT_MAX;
        }
    }

    visited = new int [visited_size];
    visited[visited_size - 1] = start_vertex;

    unvisited_size = 0;
    unvisited = new int[number_of_vertexes -1];

    for(int i = 0 ; i < number_of_vertexes ; i++){
        if(i != start_vertex){
            unvisited_size ++;
            unvisited[unvisited_size -1] = i;
        }
    }

    this -> Dijkstra_algorithm();

    std::cout<<"Najkrotsze sciezki dla poszczegolnych wierzcholkow: "<<std::endl<<std::endl;
    this -> display_shortest_paths();

    std::cout<<std::endl<<std::endl;
}



