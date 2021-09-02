#include "Vertex.hpp"

uint64_t Vertex::VERTEX_ID = 0;

uint64_t Vertex::getID() {
    return _id;
}

template<typename T>
void Vertex::addAttr(std::string key, T val) {
    attr[key] = val;
}

template<typename T>
T Vertex::getValue(std::string key) {
    return std::any_cast<T>(attr.at(key));
}

void Vertex::addInEdge(Edge& e) {
    _in.push_back(&e);
}

void Vertex::addOutEdge(Edge& e) {
    _out.push_back(&e);
}