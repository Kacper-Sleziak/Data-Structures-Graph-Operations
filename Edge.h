#ifndef DATA_STRUCTURES_GRAPH_OPERATIONS_EDGE_H
#define DATA_STRUCTURES_GRAPH_OPERATIONS_EDGE_H


class Edge {
public:
    int vertex;
    int vertex_other;
    int weight;

    Edge(int v, int w, int s){
        vertex = v;                      // pierwszy wierzchołek
        vertex_other = w;                // drugi wierzchołek
        weight = s;                      // waga krawędzi
    }

    Edge(){
    }

    void show_edge();
    int get_first_vertex();
    int get_second_vertex();
};


#endif //DATA_STRUCTURES_GRAPH_OPERATIONS_EDGE_H
