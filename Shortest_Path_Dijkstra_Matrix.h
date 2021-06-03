#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_SHORTEST_PATH_DIJKSTRA_MATRIX_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_SHORTEST_PATH_DIJKSTRA_MATRIX_H


#include <string>

class Shortest_Path_Dijkstra_Matrix {
    public:
        void path_handler(std::string file_name);
        void path_random_handler();
        ~Shortest_Path_Dijkstra_Matrix();


private:
        int ** matrix;
        int * keys;                 // koszty dojscia do danego wierzcholka
        int * previous;             // tablica poprzednikow

        int * visited;              // tablica odwiedzonych
        int visited_size = 1;

        int * unvisited;
        int unvisited_size;

        int number_of_vertexes;
        int number_of_edges;
        int start_vertex;           //startowy wierzcholek

        void read_file(std::string file_name);   // funckja wczytująca plik tekstow
        void show_matrix();
        void Dijkstra_algorithm();
        bool is_vertex_visited(int v);
        void display_shortest_paths();
        void generate_random(int size, float density);

};


#endif