#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_SHORTEST_PATH_DIJKSTRA_LIST_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_SHORTEST_PATH_DIJKSTRA_LIST_H

#include <iostream>
#include <fstream>
#include "Node.h"

class Shortest_Path_Dijkstra_List {
    public:
        void Path_handler(std::string file_name);

    private:
        Node ** list;
        int number_of_vertexes;
        int number_of_edges;
        int start_vertex;            //startowy wierzcholek

        int ** matrix;
        int * keys;                 // koszty dojscia do danego wierzcholka
        int * previous;             // tablica poprzednikow

        int * visited;              // tablica odwiedzonych
        int visited_size = 1;

        int * unvisited;
        int unvisited_size;

        void read_file(std::string file_name);   // funckja wczytująca plik tekstow
        void show_list();
        void Dijkstra_algorithm();
        bool is_vertex_visited(int v);
        void display_shortest_paths();
};


#endif