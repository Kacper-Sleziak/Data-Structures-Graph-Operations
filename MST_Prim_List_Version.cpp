#include "MST_Prim_List_Version.h"

void MST_Prim_List_Version::read_file(std::string file_name) {
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
    this -> list = new std::vector<Node> [n];

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

            Node node_v(v, weight, 0);
            Node node_w(w, weight, 0);

            list[w].push_back(node_v);
            list[v].push_back(node_w);

            int size_v = list[v].size();
            int size_w = list[w].size();

            if(size_v > 0){
                int previous_index = size_v - 1;
                list[v][previous_index].next = &list[v][size_v];
            }

            if(list[w].size() > 0){
                int previous_index = size_w - 1;
                list[w][previous_index].next = &list[v][size_w];
            }
        }
    }
}

void MST_Prim_List_Version::show_list(){
    for(int i = 0 ; i < number_of_vertexes ; i++){
        int size = list[i].size();
        std::cout<<"lista wierzcholka " << i<<std::endl;

        for(int k = 0 ; k< size ; k++){
            list[i][k].show_node();
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}

void MST_Prim_List_Version::show_mst_edges() {
    for (int i = 0 ; i < this->number_of_vertexes - 1; i++){
        this -> mst_edges[i].show_edge();
        std::cout<<std::endl;
    }
}


void MST_Prim_List_Version::create_mst_by_prim_algorithm() {

    bool * visited = new bool [this -> number_of_vertexes];

    int max = INT_MAX;

    for (int i = 0 ; i < number_of_vertexes ; i++){
        if (i == 0){
            visited[i] = true;
        }

        else{
            visited[i] = false;
        }
    }
    DFS(visited);
}

bool MST_Prim_List_Version::is_vertex_in_mst(int v, int w, int weight){

    bool is_vertex = true;

    for(int i = 0 ; i < mst_size ; i++){
        Edge edge = mst_edges[i];

        if((edge.vertex == w or edge.vertex_other == w)
        and (edge.vertex == v or edge.vertex_other == v) and edge.weight == weight){
            is_vertex = false;
        }
    }
    return is_vertex;
}

void MST_Prim_List_Version::DFS(bool *visited) {
    int shortest_path = INT_MAX;

    int end_v = -1;                                             //index wierzcholka koncowego krawdz
    int start_v = -1;
    int index_to_delete;

    for (int k = 0 ; k < this -> number_of_vertexes ; k++) {
        if (visited[k]) {                                       //przeszukujemy tylko krawedzie odwiedzonych wierzcholkow

            Node *node = list[k][0];

            for(int i = 0 ; i < list[k].size() ; i++){
                if (node.is_in_mst == false) {
                    if (&node.weight < shortest_path) {
                        shortest_path =& node.weight;
                        start_v = k;
                        end_v = &node.vertex;
                    }
                }
                node = node.next;
                node.show_node();
                std::cout<<std::endl;
            }
        }
    }

    if (end_v != -1){
        Edge edge(start_v, end_v, shortest_path);
        visited[end_v] = true;

        DFS(visited);
    }
}

void MST_Prim_List_Version::MST_handler(){
    std::string file_name;

    std::cout<<"Wczytaj plik: ";
    std::cin>> file_name;

    this -> read_file(file_name);
    this -> show_list();

    this->create_mst_by_prim_algorithm();

    std::cout<<"MST krawędzi: "<<std::endl;
    this -> show_mst_edges();
}

