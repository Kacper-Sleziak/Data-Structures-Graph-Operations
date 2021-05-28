#include "Shortest_Path_Dijkstra_List.h"

void Shortest_Path_Dijkstra_List::read_file(std::string file_name) {
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

    counter = 0;

    list = new Node *[n];

    for(int i = 0 ; i < number_of_vertexes ; i++){
        list[i] = new Node(-1, -1, NULL);
    }

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
            counter = 0;

            Node *node_w = new Node(w, weight, NULL);
            Node *node_helper;

            node_helper = list[v];


            if(node_helper->next != NULL){
                do {
                    node_helper = node_helper->next;

                } while (node_helper->next != NULL);
            }
            node_helper->next = node_w;
        }
    }
}


void Shortest_Path_Dijkstra_List::show_list(){
    for(int i = 0 ; i< number_of_vertexes ; i++){

        std::cout<<"Krawedzie z wierzcholka: "<<i<<std::endl;
        Node * node = list[i];
        int counter = 0;

        if(node -> next != NULL) {

            while (true) {
                if (counter != 0) {
                    node->show_node();
                    std::cout << std::endl;
                }

                counter++;
                node = node -> next;

                if(node == NULL){
                    break;
                }
            }
        }
        std::cout<<std::endl;
    }
}

bool Shortest_Path_Dijkstra_List::is_vertex_visited(int v) {
    for(int i = 0 ; i < visited_size ; i++){
        if(visited[i] == v){
            return true;
        }
    }
    return false;
}

void Shortest_Path_Dijkstra_List::Dijkstra_algorithm() {
    int new_visited = - 1;
    int shortest_path = INT_MAX;
    int checking_vertex = visited[visited_size -1];

    Node *node = list[checking_vertex];

    while (true){
        if(node -> vertex != -1){
            int path = node -> weight;
            int w = node ->vertex;

            if(!is_vertex_visited(w)){                    //aktualizacja tablicy kluczy
                if(path + keys[checking_vertex] < keys[w]){
                    keys[w] = path + keys[checking_vertex];
                    previous[w] = checking_vertex;
                }

                if(path < shortest_path){                                   //sprawdzenie, ktory wierzcholek sprawdzac nastepnie
                    new_visited = w;
                    shortest_path = path;
                }
            }
        }

        if(node -> next == NULL){
            break;
        }

        node = node -> next;

    }

    if(new_visited != -1){

        //relokacja visited
        visited_size++;
        visited[visited_size-1] = new_visited;


        //relokacja unvisited przez usuniecie kolejnego odwiedzonego wierzcholka


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


        std::cout<<"xd";
        this -> Dijkstra_algorithm();
    }
}

void Shortest_Path_Dijkstra_List::display_shortest_paths() {

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


void Shortest_Path_Dijkstra_List::Path_handler(std::string file_name) {

    this -> read_file(file_name);

    this->show_list();

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



