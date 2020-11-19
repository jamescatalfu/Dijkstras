#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>
#include <vector>
#include <utility>

class Vertex
{
    private:
        std::string label;
        std::vector<std::pair<unsigned long, std::string> >adjacent;
        unsigned long distance;

    public:
        Vertex(); 
        void setLabel(std::string);
        std::string getLabel();
        void addAdjacent(std::string, unsigned long);
        unsigned long getWeight(std::string);

        friend class Edge;
        

};

#endif
