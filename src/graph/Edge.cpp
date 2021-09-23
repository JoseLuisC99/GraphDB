#include "Edge.hpp"

uint64_t Edge::EDGE_ID = 0;

Edge::Edge(Vertex& source, Vertex& end): _id(EDGE_ID++), _in(&source), _out(&end) {
    source.addOut(_id);
    end.addIn(_id);
}

uint64_t Edge::getID() {
    return _id;
}

uint64_t Edge::getInID() {
    return _in->getID();
}

uint64_t Edge::getOutID() {
    return _out->getID();
}