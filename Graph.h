#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_GRAPH_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_GRAPH_H

#include "Edge.h"

class Graph{
    public:
        int number_of_edges;            // liczba krawędzi grafu
        int number_of_vertexes;         // liczba wierzchołków grafu
        int actual_vertex_index = 0;    // index kolejnego dodawanego wierzchołka
        Edge * list_of_edges;           // lista krawędzi grafu
        int * list_of_vertexes;         // lista wierzchołków
        int ** weighted_matrix;         // macierz sąsiedztwa

        Graph(int n, int e){
            number_of_vertexes = n;
            number_of_edges = e;
            this -> create_list_of_vertexes();
            weighted_matrix;
        }

        void add_edge(Edge edge);           // funkcja dodająca krawędz grafu do listy
        void create_list_of_vertexes();
        int ** create_weighted_matrix();
        void show_edges();
        void show_vertexes();
        int get_number_of_vertexes;
        int ** get_weighted_matrix();
        Edge find_edge(int v, int weight);
        Edge * get_list_of_edges();


};

#endif
