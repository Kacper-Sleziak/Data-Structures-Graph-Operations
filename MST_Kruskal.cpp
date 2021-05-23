#include <fstream>
#include "MST_Kruskal.h"


void MST_Kruskal::read_file(std::string file_name){
    std::fstream myfile(file_name, std::ios_base::in);
    int counter = 0;

    int data;
    int n;
    int e;

    while (myfile >> data){
        if (counter == 0){
            e = data;
        }

        else if (counter == 1){
            n = data;
            break;
        }

        else{

        }

        counter ++;
    }
    counter = 0;
    graph = new Graph(n, e);

    int v;
    int w;
    int weight;

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

            Edge edge (v, w, weight);
            graph -> add_edge(edge);

            counter = 0;
        }
    }
    myfile.close();
    //C:\Users\PC\CLionProjects\Sdizo\mst.txt
    queue = graph -> get_list_of_edges();   // tworzymy jeszcze nieposortowaną kolejke

    this -> number_of_vertexes = n;
    this -> number_of_edges = e;
    this -> mst_size = n - 1;


}

void MST_Kruskal::sort_queue(){

    int i;
    int j;
    Edge helper;
    int x = this -> number_of_edges;

    for (i = x - 2; i >= 0 ; i--){

        helper = this -> queue[i];
        j = i +1;
        int y = helper.weight;

        while((j < x) && (helper.weight > this -> queue[j].weight)){
            this -> queue[j - 1] = this -> queue [j];
            j++;
        }

        this -> queue[j - 1] = helper;
    }
}

void MST_Kruskal::create_mst_by_kruskal_algorithm(){

    int mst_actual_size = 0;

    this -> mst_edges = new Edge [this -> mst_size];

    for (int i = 0 ; i < this -> number_of_edges ; i++){

        int v_1 = queue[i].get_first_vertex();       //pierwszy wierzcholek krawedzi w kolejce
        int v_2 = queue[i].get_second_vertex();       // drugi wierzcholek krawedzi w kolejce

        int ** checking_matrix = this -> create_checking_matrix(v_1, v_2, mst_actual_size);

        if (i == 0){
            mst_actual_size ++;
            this -> mst_edges[i] = queue[mst_actual_size - 1];
        }

        else if (!this->has_cycle(checking_matrix, v_1)){
            mst_actual_size++;
            this -> mst_edges[mst_actual_size - 1] = this -> queue [i];
        }


        if (mst_actual_size >= this -> mst_size){        //przerwanie petli gdy mst jest pełne
            i = this -> number_of_edges;
        }
    }
}

void MST_Kruskal::display_mst_edges(){
    for(int i = 0; i < graph -> number_of_vertexes - 1; i++){
        this->mst_edges[i].show_edge();
        std::cout<<std::endl;
    }
}

void MST_Kruskal::display_queue(){
    for(int i = 0 ; i < this -> number_of_edges ; i++){
        this -> queue[i].show_edge();
        std::cout<<std::endl;
    }
}

bool MST_Kruskal::has_cycle(int ** checking_matrix, int v) {

    bool visited[this -> number_of_vertexes];
    int parents[this -> number_of_vertexes];

    for(int i = 0 ; i < this -> number_of_vertexes ; i++){
        visited[i] = false;
        parents[i] = - 1;
    }

    visited [v] = true;

    bool is_cycle = false;
    is_cycle = DFS(checking_matrix, v, visited, parents, is_cycle);

    if(is_cycle){
        return true;
    }

    else{
        return false;
    }
}

bool MST_Kruskal::DFS(int ** checking_matrix, int v, bool visited[], int parents[], bool is_cycle) {

    for (int i = 0; i < this -> number_of_vertexes ; i++){

        if (checking_matrix[v][i] == 1){
            bool x = visited[i];
            int y = parents[i];

            if (visited[i] == false){
                visited[i] = true;
                parents[i] = v;
                this -> DFS(checking_matrix, i, visited, parents, is_cycle);
            }

            else if(visited[i] and parents[i] != v){
                is_cycle = true;                                                //cykl znaleziony
            }
        }
    }

    return is_cycle;
}


int ** MST_Kruskal::create_checking_matrix(int v_1, int v_2, int mst_actual_size) {
    int rows = this -> number_of_vertexes;
    int cols = this -> number_of_vertexes;

    int **matrix = new int * [rows];

    for (int i = 0 ; i < rows ; i++){
        matrix[i] = new int [cols];
    }

    for (int i = 0 ; i < mst_actual_size ; i++){
        int v = mst_edges[i].get_first_vertex();
        int w = mst_edges[i].get_second_vertex();

        matrix[v][w] = 1;
        matrix[w][v] = 1;
    }

    matrix[v_1][v_2] = 1;                            // do macierzy dodajemy krawedz z kolejki.
    matrix[v_2][v_1] = 1;

    for(int i = 0 ; i < rows ; i++){                 // pozsotale miejsca w macierzy wypelniam zerami
        for (int k = 0 ; k < cols ; k++){
            if (matrix [i][k] != 1){
                matrix [i][k] = 0;
            }
        }
    }
    return matrix;
}

int MST_Kruskal::count_weigth() {
    int weight = 0;

    for (int i = 0; i < this -> number_of_vertexes - 1 ; i++){
        weight += this -> mst_edges[i].weight;
    }

    return weight;
}

void MST_Kruskal::display_mst_matrix() {

    int rows = this -> number_of_vertexes;
    int cols = this -> number_of_vertexes;

    int **matrix = new int * [rows];

    for (int i = 0 ; i < rows ; i++){
        matrix[i] = new int [cols];
    }

    for (int i = 0 ; i < this -> number_of_vertexes - 1; i++){
        int v = mst_edges[i].get_first_vertex();
        int w = mst_edges[i].get_second_vertex();

        matrix[v][w] = 1;
        matrix[w][v] = 1;
    }

    for(int i = 0 ; i < rows ; i++){                 // pozostale miejsca w macierzy wypelniam zerami
        for (int k = 0 ; k < cols ; k++){
            if (matrix [i][k] != 1){
                matrix [i][k] = 0;
            }
        }
    }

    for(int i = 0 ; i < rows ; i++){
        for(int k = 0 ; k < cols ; k++){
            std::cout<<matrix[i][k]<<", ";
        }
        std::cout<<std::endl;
    }
}

void MST_Kruskal::MST_handler() {

    std::string file_name;

    std::cout<<"Podaj nazwe pliku z ktorego chcesz utworzyc MST: ";
    std::cin >> file_name;

    this -> read_file(file_name);

    std::cout<<"Krawedzie Grafu: "<<std::endl;
    this -> graph -> show_edges();
    std::cout<<std::endl;

    this -> sort_queue();

    std::cout<<"Kolejka Priorytetowa: "<<std::endl;
    this -> display_queue();
    std::cout<<std::endl;


    this -> create_mst_by_kruskal_algorithm();

    std::cout<<"Krawedzie MST: "<<std::endl;
    this -> display_mst_edges();
    std::cout<<std::endl;

    std::cout<<"Macierz Sasiedztwa: "<<std::endl;
    this -> display_mst_matrix();
    std::cout<<std::endl;

    int weigth = this -> count_weigth();
    std::cout<<"Waga Drzewa MST: "<<weigth<<std::endl<<std::endl;
}