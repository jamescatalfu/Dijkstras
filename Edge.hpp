#ifndef Edge_hpp
#define Edge_hpp
 
 #include "Vertex.hpp"
 #include <string>

class Edge
{
    private:
        std::string start;
        std::string end;
        unsigned long weight;

    public:
        Edge(std::string, std::string, unsigned long);
        std::string getStart();
        std::string getEnd();
        unsigned long getWeight();

};

#endif
