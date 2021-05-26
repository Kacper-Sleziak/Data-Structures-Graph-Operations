#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_NODE_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_NODE_H

#include <iostream>

class Node {
    public:

        int vertex;
        int weight;
        bool is_in_mst = false;
        Node *next;


        Node(int v, int w, Node *n){
            vertex = v;
            weight = w;
            next = n;
        }

        void show_node();
};




#endif
