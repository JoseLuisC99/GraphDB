#ifndef GRAPHDB_VERTEX_HPP
#define GRAPHDB_VERTEX_HPP

#include <vector>
#include <map>
#include <string>
#include <any>
#include "Edge.hpp"

class Vertex {
    uint64_t _id;
    std::vector<Edge*> _in;
    std::vector<Edge*> _out;
    std::map<std::string, std::any> attr;

    static uint64_t VERTEX_ID;
public:
    Vertex(): _id(VERTEX_ID++) {}

    uint64_t getID();
    template<typename T>
    void addAttr(std::string, T);
    template<typename T>
    T getValue(std::string);
    void addInEdge(Edge&);
    void addOutEdge(Edge&);
};

#endif