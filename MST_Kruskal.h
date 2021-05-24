#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_MST_KRUSKAL_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_MST_KRUSKAL_H

#include <iostream>
#include "Graph.h"

class MST_Kruskal {

    public:
        void MST_handler();                     // główna funkcja obsługująca działanie programu

    private:
        Graph * graph;                          // wskaźnik na graf z którego zostanie stworzone drzewo MST
        Edge * queue;                           // kolej z posorotwanymi krawedziami według wagi
        Edge * mst_edges;                       // lista składająca się z krawedzi drzewa mst
        int number_of_vertexes;                 // liczba wierzchołków grafu
        int number_of_edges;                    // liczba krawędzi grafu (nie mylić z mst)
        int mst_size;                           // wielkosc mst w trakcie pracy z kolejka
        int ** mst_matrix;                      // macierz sąsiedztwa MST

        void read_file(std::string file_name);                                  // funckja wczytująca plik tekstowy
        void sort_queue();                                                      // funkcja sortująca krawędzie grafu według wag
        bool has_cycle(int ** checking_matrix, int v);                          // funckja sprawdzająca czy można dodać do drzewa krawędz od danych wierzchołkach
        int ** create_checking_matrix(int v_1, int v_2, int mst_actual_size);   // funkcja tworzy macierz za pomoca krawędzi mst oraz kolejnej krawedzi dodanej z kolejki
        void create_mst_by_kruskal_algorithm();                                 // tworzenie drzewa według algorytmu kruskala
        void display_mst_edges();                                               // wyswietlanie krawedzi mst
        int count_weight();                                                     // funkcja licząca wage drzewa
        void display_queue();                                                   // wyswietlanie kolejki
        bool DFS(int ** checking_matrix, int v, bool visited[], int parents[], bool is_cycle); //funckja przeszukujaca
        void display_mst_matrix();                                              // wyswietla macierz sasiedztwa dla MST
};

#endif