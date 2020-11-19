//
//  Vertex.cpp
//  Graph
//
//  Created by James Catalfu on 7/1/19.
//  Copyright © 2019 James Catalfu. All rights reserved.
//

#include "Vertex.hpp"
#include <utility>

Vertex::Vertex()
{
    label = "";
}

void Vertex::setLabel(std::string s)
{
    label = s;
}


std::string Vertex::getLabel()
{
    return label;
}


unsigned long Vertex::getWeight(std::string)
{
    for(auto p : adjacent)
    {
        if(p.second == label)
        {
            return p.first;
        }
    }

    return 0;
}