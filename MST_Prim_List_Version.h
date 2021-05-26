#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_MST_PRIM_LIST_VERSION_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_MST_PRIM_LIST_VERSION_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Node.h"
#include "Edge.h"

class MST_Prim_List_Version {
    public:
        void MST_handler();                     // główna funkcja obsługująca działanie programu

    private:
        int number_of_vertexes;                 // liczba wierzchołków grafu
        int number_of_edges;                    // liczba krawędzi grafu (nie mylić z mst)
        int mst_size = 0;                       // wielkosc mst w trakcie pracy z kolejka
        Edge * mst_edges;
        std::vector<Node> * list;


        void read_file(std::string file_name);                                  // funckja wczytująca plik tekstow
        void create_mst_by_prim_algorithm();                                    // tworzenie drzewa według algorytmu kruskala
        void show_list();
        bool is_vertex_in_mst(int v, int w, int weight);
        void show_mst_edges();
        void DFS(bool visited[]);
};


#endif