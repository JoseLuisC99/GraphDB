#include "Vertex.hpp"

uint64_t Vertex::VERTEX_ID = 0;

void Vertex::addIn(uint64_t e) {
    _in.push_back(e);
}

void Vertex::addOut(uint64_t e) {
    _out.push_back(e);
}

uint64_t Vertex::getID() {
    return _id;
}