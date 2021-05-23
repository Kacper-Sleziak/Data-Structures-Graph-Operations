#include "Edge.h"
#include <iostream>

void Edge::show_edge() {
    std::cout<<"v = "<<this -> vertex<<" ";
    std::cout<<"w = "<<this -> vertex_other<<" ";
    std::cout<<"weight = "<<this -> weight<<" ";
}

int Edge::get_first_vertex() {
    return this -> vertex;
}

int Edge::get_second_vertex() {
    return this -> vertex_other;
}

int Edge::get_weight() {
    return this -> weight;
}

