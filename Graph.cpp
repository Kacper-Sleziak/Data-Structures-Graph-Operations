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


