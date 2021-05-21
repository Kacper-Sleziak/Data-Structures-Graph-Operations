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
    int ** matrix;                  // macierz sąsiedztwa

    Graph(int n, int e){
        number_of_vertexes = n;
        number_of_edges = e;
        this -> create_list_of_vertexes();
    }

    void add_edge(Edge edge);           // funkcja dodająca krawędz grafu do listy
    void create_list_of_vertexes();

    Edge * get_list_of_edges();
    int get_number_of_vertexes;

    void show_edges();
    void show_vertexes();

};

#endif
