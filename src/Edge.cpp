#include "Edge.hpp"
#include "Vertex.hpp"

uint64_t Edge::EDGE_ID = 0;

uint64_t Edge::getID() {
    return _id;
}

uint64_t Edge::getInID() {
    return _in->getID();
}

uint64_t Edge::getOutID() {
    return _out->getID();
}

template<typename T>
void Edge::addAttr(std::string key, T val) {
    attr[key] = val;
}

template<typename T>
T Edge::getValue(std::string key) {
    return std::any_cast<T>(attr.at(key));
}