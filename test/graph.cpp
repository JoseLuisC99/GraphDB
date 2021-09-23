#include <string>
#include <gtest/gtest.h>
#include "../src/graph/Graph.hpp"
#include "../src/graph/Vertex.hpp"
#include "../src/graph/Edge.hpp"
#include "../src/utils/Exceptions.hpp"

TEST(GraphTest, Vertices) {
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    v1->addAttr<int>("attr_1", 10);
    v1->addAttr<char>("attr_2", 'c');
    v1->addAttr<std::string>("attr_3", "Hello, world!");
    v2->addAttr<bool>("attr_1", false);
    v2->addAttr<float>("attr_2", 4.5f);

    EXPECT_NE(v1->getID(), v2->getID());
    EXPECT_EQ(v1->getValue<int>("attr_1"), 10);
    EXPECT_EQ(v1->getValue<char>("attr_2"), 'c');
    EXPECT_EQ(v1->getValue<std::string>("attr_3"), "Hello, world!");
    EXPECT_EQ(v2->getValue<bool>("attr_1"), false);
    EXPECT_EQ(v2->getValue<float>("attr_2"), 4.5f);
}

TEST(GraphTest, Edges) {
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Edge* e1 = new Edge(*v1, *v2);
    Edge* e2 = new Edge(*v2, *v1);

    e1->addAttr<int>("attr_1", 10);
    e1->addAttr<char>("attr_2", 'c');
    e1->addAttr<std::string>("attr_3", "Hello, world!");
    e2->addAttr<bool>("attr_1", false);
    e2->addAttr<float>("attr_2", 4.5f);

    EXPECT_NE(e1->getID(), e2->getID());
    EXPECT_EQ(e1->getValue<int>("attr_1"), 10);
    EXPECT_EQ(e1->getValue<char>("attr_2"), 'c');
    EXPECT_EQ(e1->getValue<std::string>("attr_3"), "Hello, world!");
    EXPECT_EQ(e2->getValue<bool>("attr_1"), false);
    EXPECT_EQ(e2->getValue<float>("attr_2"), 4.5f);
}

TEST(GraphTest, Graph) {
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Vertex* v3 = new Vertex();
    Edge* e1 = new Edge(*v1, *v2);
    Edge* e2 = new Edge(*v2, *v3);

    v1->addAttr<std::string>("name", "Vertex 1");
    v2->addAttr<std::string>("name", "Vertex 2");
    v3->addAttr<std::string>("name", "Vertex 3");
    e1->addAttr<std::string>("name", "Connection 1");
    e2->addAttr<std::string>("name", "Connection 2");

    Graph* g = new Graph();
    g->addVertex(*v1);
    g->addVertex(*v2);
    g->addEdge(*e1);
    
    EXPECT_THROW(g->addVertex(*v1), VertexIDCollisionException);
    EXPECT_THROW(g->addEdge(*e2), VertexNotFoundException);

    g->addVertex(*v3);
    g->addEdge(*e2);
    
    EXPECT_TRUE(g->hasVertex(v1->getID()));
    EXPECT_FALSE(g->hasVertex(v3->getID() + 1));
    EXPECT_NO_THROW(g->findVertexByID(v2->getID()));
    EXPECT_ANY_THROW(g->findVertexByID(v3->getID() + 1));

    EXPECT_TRUE(g->hasEdge(e1->getID()));
    EXPECT_FALSE(g->hasEdge(e2->getID() + 1));
    EXPECT_NO_THROW(g->findEdgeByID(e2->getID()));
    EXPECT_ANY_THROW(g->findEdgeByID(e2->getID() + 1));

    v1->addAttr<std::string>("name", "Main vertex");
    e1->addAttr<std::string>("name", "Main edge");

    EXPECT_EQ(g->findVertexByID(v1->getID())->getValue<std::string>("name"), "Main vertex");
    EXPECT_EQ(g->findEdgeByID(e1->getID())->getValue<std::string>("name"), "Main edge");
}