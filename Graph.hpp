#ifndef Graph_hpp
#define Graph_hpp

#include "Vertex.hpp"
#include "Edge.hpp"
#include <vector>
#include <map>
#include <utility>

class Graph
{
    public:
        void addVertex(std::string label);
        void removeVertex(std::string label);
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        void removeEdge(std::string label1, std::string label2);
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
        bool checkForVertex(std::string);
        void createList();
        void removeVertices();

    private:
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;
        std::map<std::string, std::vector<std::pair<unsigned long, std::string> > > adjacent;


};

#endif
