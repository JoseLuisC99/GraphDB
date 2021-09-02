#ifndef GRAPHDB_EXCEPTIONS_HPP
#define GRAPHDB_EXCEPTIONS_HPP

#include <exception>
#include <sstream>

class VertexIDCollisionException : public std::exception{
    std::stringstream message;

public:
    VertexIDCollisionException(uint64_t id){
        message << "A vertex with the ID " << id << " already exists";
    }

    const char* what() const noexcept override{
        return message.str().c_str();
    }
};

class VertexNotFoundException : public std::exception{
    std::stringstream message;

public:
    VertexNotFoundException(uint64_t id){
        message << "The graph does not contain vertex with ID " << id;
    }

    const char* what() const noexcept override{
        return message.str().c_str();
    }
};

#endif