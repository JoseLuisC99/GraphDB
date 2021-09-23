#ifndef GRAPHDB_GRAPH_HPP
#define GRAPHDB_GRAPH_HPP

#include <vector>
#include <map>
#include "Vertex.hpp"
#include "Edge.hpp"

class Graph {
    std::vector<Vertex*> V;
    std::vector<Edge*> E;
    std::map<uint64_t, Vertex*> vertexIndex;
    std::map<uint64_t, Edge*> edgeIndex;

public:
    uint64_t addVertex(Vertex&);
    uint64_t addEdge(Edge&);

    Vertex* findVertexByID(uint64_t);
    bool hasVertex(uint64_t);
    Edge* findEdgeByID(uint64_t);
    bool hasEdge(uint64_t);
};

#endif