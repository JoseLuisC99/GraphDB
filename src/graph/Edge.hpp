#ifndef GRAPHDB_EDGE_HPP
#define GRAPHDB_EDGE_HPP

#include <vector>
#include <map>
#include <any>
#include "Vertex.hpp"

class Edge {
    uint64_t _id;
    Vertex* _in;
    Vertex* _out;
    std::map<std::string, std::any> attr;

    static uint64_t EDGE_ID;
public:
    Edge(Vertex&, Vertex&);

    uint64_t getID();
    uint64_t getInID();
    uint64_t getOutID();
    template<typename T> void addAttr(std::string, T);
    template<typename T> T getValue(std::string);
};

#include "Edge.tpp"

#endif