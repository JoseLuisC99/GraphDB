#ifndef GRAPHDB_VERTEX_HPP
#define GRAPHDB_VERTEX_HPP

#include <vector>
#include <map>
#include <string>
#include <any>

class Vertex {
    uint64_t _id;
    std::map<std::string, std::any> attr;
    std::vector<uint64_t> _in;
    std::vector<uint64_t> _out;

    static uint64_t VERTEX_ID;
public:
    Vertex(): _id(VERTEX_ID++) {}

    uint64_t getID();
    void addIn(uint64_t);
    void addOut(uint64_t);
    template<typename T> void addAttr(std::string, T);
    template<typename T> T getValue(std::string);
};

#include "Vertex.tpp"

#endif