#include <iostream>
#include "Graph.h"

void Graph::add_edge(Edge edge) {
    if (actual_vertex_index == 0){
        list_of_edges = new Edge[this -> number_of_edges];
    }

    list_of_edges[actual_vertex_index] = edge;
    std::cout<<std::endl;
    actual_vertex_index ++;
}

void Graph::show_edges() {
    for (int i = 0 ; i < number_of_edges; i++){
        list_of_edges[i].show_edge();
        std::cout<<std::endl;
    }
}


void Graph::create_list_of_vertexes() {
    list_of_vertexes = new int [number_of_vertexes];

    for (int i = 0; i < number_of_vertexes ; i++){
        list_of_vertexes[i] = i;
    }
}

void Graph::show_vertexes() {
    for(int i = 0; i < number_of_vertexes ; i++){
        std::cout<<list_of_vertexes[i];
        std::cout<<" ";
    }
}

Edge * Graph::get_list_of_edges() {
    return this -> list_of_edges;
}

int ** Graph::create_weighted_matrix() {
    int rows = this -> number_of_vertexes;
    int cols = this -> number_of_vertexes;

    int **matrix = new int * [rows];

    for (int i = 0 ; i < rows ; i++){
        matrix[i] = new int [cols];
    }

    for (int i = 0 ; i < rows ; i++){
        for (int k = 0 ; k < cols ; k++){
            matrix[i][k] = 0;
        }
    }

    for (int i = 0 ; i < this -> number_of_edges; i++){

        int v = this -> list_of_edges[i].get_first_vertex();
        int w = this -> list_of_edges[i].get_second_vertex();
        int weight = this -> list_of_edges[i].get_weight();

        matrix[v][w] = weight;
        matrix[w][v] = weight;
    }

    this -> weighted_matrix = matrix;
}

int ** Graph::get_weighted_matrix() {
    return this -> weighted_matrix;
}

Edge Graph::find_edge(int v, int weight) {

    for (int i = 0 ; i < number_of_edges ; i++){
        Edge edge = list_of_edges[i];
        int v_1 = edge.get_first_vertex();
        int v_2 = edge.get_second_vertex();
        int edge_weight = edge.get_weight();

        if ((v_1 == v or v_2 == v) and weight == edge_weight){
            return edge;
        }
    }
}


