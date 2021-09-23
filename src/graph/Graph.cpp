#include "../utils/Exceptions.hpp"
#include "Graph.hpp"
#include "Vertex.hpp"

uint64_t Graph::addVertex(Vertex& v) {
    if(hasVertex(v.getID()))
        throw VertexIDCollisionException(v.getID());
    V.push_back(&v);
    vertexIndex[v.getID()] = V[V.size() - 1];

    return v.getID();
}

uint64_t Graph::addEdge(Edge& e) {
    if(!hasVertex(e.getInID()))
        throw VertexNotFoundException(e.getInID());
    if(!hasVertex(e.getOutID()))
        throw VertexNotFoundException(e.getOutID());
    E.push_back(&e);
    edgeIndex[e.getID()] = E[E.size() - 1];

    return e.getID();
}

Vertex* Graph::findVertexByID(uint64_t id) {
    return vertexIndex.at(id);
}

bool Graph::hasVertex(uint64_t id) {
    return vertexIndex.find(id) != vertexIndex.end();
}

Edge* Graph::findEdgeByID(uint64_t id) {
    return edgeIndex.at(id);
}

bool Graph::hasEdge(uint64_t id) {
    return edgeIndex.find(id) != edgeIndex.end();
}