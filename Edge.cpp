//
//  Edge.cpp
//  Graph
//
//  Created by James Catalfu on 7/1/19.
//  Copyright © 2019 James Catalfu. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge(std::string label1, std::string label2, unsigned long w)
{
    start = label1;
    end = label2;
    weight = w;  
    
}

std::string Edge::getStart()
{
    return start;
}

std::string Edge::getEnd()
{
    return end;
}

unsigned long Edge::getWeight()
{
    return weight;
}