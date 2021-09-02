#ifndef GRAPHDB_EDGE_HPP
#define GRAPHDB_EDGE_HPP

#include <vector>
#include <map>
#include <any>

class Edge {
    uint64_t _id;
    Vertex* _in;
    Vertex* _out;
    std::map<std::string, std::any> attr;

    static uint64_t EDGE_ID;
public:
    Edge(Vertex& a, Vertex& b): _id(EDGE_ID++), _in(&a), _out(&b) {}

    uint64_t getID();
    uint64_t getInID();
    uint64_t getOutID();
    template<typename T>
    void addAttr(std::string, T);
    template<typename T>
    T getValue(std::string);
};

#endif