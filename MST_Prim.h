#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_MST_PRIM_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_MST_PRIM_H

#include <iostream>
#include "Graph.h"
#include "Edge.h"

class MST_Prim {
    public:
        void MST_handler();

    private:
        int start_vertex;
        int number_of_vertexes;                 // liczba wierzchołków grafu
        int number_of_edges;                    // liczba krawędzi grafu (nie mylić z mst)
        Graph * graph;
        Edge * mst_edges;
        int * DFS(int **matrix, bool visited[], int keys[]);

        void read_file(std::string file_name);  // funckja wczytująca plik tekstowy
        void display_mst_matrix();
        void create_mst_by_prim_algorithm();
        void display_mst_edges();
        int count_weigth();

};


#endif
