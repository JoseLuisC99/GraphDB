#include "Exceptions.hpp"
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
    
    vertexIndex[e.getInID()]->addInEdge(e);
    vertexIndex[e.getOutID()]->addOutEdge(e);

    E.push_back(&e);

    return e.getID();
}

Vertex* Graph::findVertexByID(uint64_t id) {
    return vertexIndex.at(id);
}

bool Graph::hasVertex(uint64_t id) {
    return vertexIndex.find(id) != vertexIndex.end();
}