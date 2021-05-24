#include "MST_Prim.h"
#include <fstream>

void MST_Prim::read_file(std::string file_name) {
    std::fstream myfile(file_name, std::ios_base::in);
    int counter = 0;

    int data;
    int n;
    int e;

    while (myfile >> data) {
        if (counter == 0) {
            e = data;
        }

        else if (counter == 1) {
            n = data;
            break;
        }

        else {

        }
        counter++;
    }

    this -> number_of_edges = e;
    this -> number_of_vertexes = n;

    counter = 0;
    this -> graph = new Graph(n, e);

    int v;
    int w;
    int weight;

    while (myfile >> data) {

        if (counter % 3 == 0) {
            v = data;
            counter++;
        }

        else if (counter % 3 == 1) {
            w = data;
            counter++;
        }

        else if (counter % 3 == 2) {
            weight = data;

            Edge edge(v, w, weight);
            graph -> add_edge(edge);
            counter = 0;
        }
    }
    graph ->create_weighted_matrix();
}

void MST_Prim::display_mst_matrix(){


    int rows = this -> number_of_vertexes;
    int cols = this -> number_of_vertexes;

    int **matrix = new int * [rows];

    for (int i = 0 ; i < rows ; i++){
        matrix[i] = new int [cols];
    }

    for (int i = 0 ; i < rows ; i++){
        for (int k = 0 ; k < cols ; k++){
            matrix[i][k] = 0;
        }
    }

    for(int i = 0 ; i < this -> number_of_vertexes - 1 ; i++){
        int v_1 = this->mst_edges[i].get_first_vertex();
        int v_2 = this->mst_edges[i].get_second_vertex();

        matrix[v_1][v_2] = 1;
        matrix[v_2][v_1] = 1;
    }

    for(int i = 0 ; i < number_of_vertexes ; i++) {
        std::cout<<std::endl;
        for (int k = 0; k < number_of_vertexes; k++) {
            std::cout << matrix[i][k] <<" ";
        }
    }

}

void MST_Prim::display_mst_edges() {
    for (int i = 0 ; i < this -> number_of_vertexes - 1; i++){
        mst_edges[i].show_edge();
        std::cout<<std::endl;
    }
}

void MST_Prim::create_mst_by_prim_algorithm(){


    bool * visited = new bool [this -> number_of_vertexes];
    int * keys = new int [number_of_vertexes];
    int ** matrix = graph -> get_weighted_matrix();

    int max = INT_MAX;

    for (int i = 0 ; i < number_of_vertexes ; i++){
        if (i == 0){
            visited[i] = true;
        }

        else{
            visited[i] = false;
        }
    }

    for(int i = 0 ; i < number_of_vertexes ; i++){
        if (i == 0){
            keys[i] = 0;
        }

        else {
            keys[i] = max;
        }
    }

    keys = DFS(matrix, visited, keys);

    this -> mst_edges = new Edge [this -> number_of_vertexes - 1];

    for(int i = 1 ; i < this -> number_of_vertexes ; i++){
            int weight = keys[i];

            Edge mst_edge = graph->find_edge(i, weight);
            int x = mst_edge.get_weight();
            mst_edges[i-1] = mst_edge;
    }

}

int * MST_Prim::DFS(int ** matrix, bool *visited, int *keys) {
    int shortest_path = INT_MAX;

    int end_v = -1;                                             //index wierzcholka koncowego krawdz
    int start_v = -1;

    for (int k = 0 ; k < this -> number_of_vertexes ; k++) {
        if (visited[k]) {                                           //przeszukujemy tylko krawedzie odwiedzonych wierzcholkow
            for (int i = 0; i < this->number_of_vertexes; i++) {
                if (matrix[k][i] != 0 and !visited[i]) {
                    if (matrix[k][i] < shortest_path) {
                        shortest_path = matrix[k][i];
                        end_v = i;
                        start_v = k;
                    }
                }
            }
        }
    }

    if (end_v != -1){
        keys[end_v] = shortest_path;
        visited[end_v] = true;
        matrix[start_v][end_v] = 0;                                 //polaczenie, ktore dodalismy do mst
        DFS(matrix, visited, keys);                                 // ustawiamy na 0 aby go ponownie nierozpatrywać
    }

    return keys;
}

int MST_Prim::count_weigth() {
    int weigth = 0;

    for(int i = 0 ; i<number_of_vertexes - 1 ; i++){
        weigth += this -> mst_edges[i].get_weight();
    }

    return weigth;
}


void MST_Prim::MST_handler() {
    std::string file_name;

    std::cout<<"Podaj nazwe pliku z ktorego chcesz utworzyc MST: ";
    std::cin >> file_name;

    this -> read_file(file_name);

    std::cout<<"Krawedzie Grafu: "<<std::endl;
    this -> graph -> show_edges();
    std::cout<<std::endl;

    this ->create_mst_by_prim_algorithm();

    std::cout<<"Krawedzie MST: "<<std::endl;
    this -> display_mst_edges();
    std::cout<<std::endl;

    std::cout<<"Macierz Sasiedztwa: ";
    this -> display_mst_matrix();
    std::cout<<std::endl<<std::endl;

    std::cout<<"Liczba Krawedzi MST: "<<this -> number_of_vertexes - 1;
    std::cout<<std::endl;

    std::cout<<"Waga drzewa MST: ";
    int x = this -> count_weigth();
    std::cout<<x<<std::endl<<std::endl;
}


