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

    list = new Node*[n];
    mst_edges = new Edge[n-1];

    for(int i = 0 ; i < number_of_vertexes; i++){
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

            Node *node_v = new Node(v, weight, NULL);
            Node *node_w = new Node(w, weight, NULL);

            node_w = list[w];

            if(node_w->next != NULL) {
                do {
                    node_w = node_w->next;

                } while (node_w->next != NULL);
            }
            node_w->next = node_v;

            Node *node_helper = new Node(w, weight, NULL);

            node_v = list[v];
            if(node_v->next != NULL){
                do {
                    node_v = node_v->next;

                } while (node_v->next != NULL);
            }
            node_v->next = node_helper;
        }
    }
}

void MST_Prim_List_Version::show_list(){
    Node * node;
    for(int i = 0 ; i < number_of_vertexes ; i++){
        std::cout<<"lista wierzcholka " << i<<std::endl;
        node = list[i];

        if(node->next != NULL) {
            do {
                node = node->next;
                node -> show_node();
                std::cout<<std::endl;
            } while (node->next != NULL);
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

int MST_Prim_List_Version::get_MST_weight() {
    int weight = 0;

    for(int i = 0 ; i < number_of_vertexes - 1 ; i++){
        weight += mst_edges[i].get_weight();
    }

    return weight;
}


void MST_Prim_List_Version::create_mst_by_prim_algorithm() {

    bool * visited = new bool [this -> number_of_vertexes];


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

void MST_Prim_List_Version::DFS(bool *visited) {
    int shortest_path = INT_MAX;

    int end_v = -1;                                             //index wierzcholka koncowego krawdz
    int start_v = -1;
    Node *helper;

    for (int k = 0 ; k < this -> number_of_vertexes ; k++) {
        if (visited[k]) {

            Node *node = list[k];

            while (true) {
                node = node->next;
                if(node == NULL){
                    break;
                }

                int v = node -> vertex;

                if (!node->is_in_mst and !visited[v]) {
                    if (node->weight < shortest_path) {
                        shortest_path = node->weight;
                        start_v = k;
                        end_v = node -> vertex;
                        helper = node;
                    }
                }
            }
            node = nullptr;
        }
    }

    if (end_v != -1 and mst_size < number_of_vertexes-1){
        Edge edge(start_v, end_v, shortest_path);
        helper -> is_in_mst = true;
        mst_edges[mst_size] = edge;
        mst_size ++;
        visited[end_v] = true;

        Node * same_node_of_other_vertex = list[end_v];

        while (true){
            if(helper -> weight == same_node_of_other_vertex -> weight and same_node_of_other_vertex->vertex == start_v){
                same_node_of_other_vertex ->is_in_mst = true;
                break;
            }

            same_node_of_other_vertex = same_node_of_other_vertex -> next;
        }
        helper = NULL;
        DFS(visited);
    }
}

void MST_Prim_List_Version::MST_handler(std::string file_name){


    this -> read_file(file_name);

    this->create_mst_by_prim_algorithm();

    std::cout<<"MST krawedzi: "<<std::endl;
    this -> show_mst_edges();
    std::cout<<std::endl;

    std::cout<<"Waga drzewa MST: ";
    std::cout<<this->get_MST_weight();

    std::cout<<std::endl<<std::endl;
}

