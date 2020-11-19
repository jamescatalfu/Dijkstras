#include "Graph.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <utility>

void Graph::addVertex(std::string label)
{
    Vertex* v = new Vertex(); //allocate memory for new vertex
    v -> setLabel(label); //create label for vertex
    vertices.push_back(v); //add vertex to vertex list
}

void Graph::removeVertex(std::string label)
{
    for(auto v : vertices) //search vertex list
    {
        if(v -> getLabel() == label) //if vertex is found...
        {
            delete v; //delete vertex
        }
    }

    for(auto e : edges) //search list of edges
    {
        if(e -> getStart() == label || e -> getEnd() == label) //if edge containing vertex is found
        {
            delete e; //remove edge from edge list
        }
    }
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    //check if vertex 1 exists
    if(!checkForVertex(label1))
    {
        std::cout << "Vertex 1 does not exist.\n";
        return;
    }
    
    //check if vertex 2 exists
    if(!checkForVertex(label2))
    {
        std::cout << "Vertex 2 does not exist.\n";
        return;
    }

    //check if it an edge to itsself
    if(label1 == label2)
    {
        std::cout << "Vertices cannot have an edge to themselves.\n";
        return;
    }

    //check if the edge already exists
    for(auto e : edges)
    {
        if(e -> getStart() == label1 && e -> getEnd() == label2)
        {
            std::cout << "This edge already exists.\n";
            return;
        }
    }

    Edge* e = new Edge(label1, label2, weight); //create new edge
    edges.push_back(e); //add new edge to edge list

}

void Graph::removeEdge(std::string label1, std::string label2)
{
    for(auto e : edges) //search for edge in list
    {
        if(e -> getStart() == label1 && e -> getEnd() ==label2) //if edge is found...
        {
            delete e; //delete edge
        }
    }

}

void Graph::createList()
{

    for(auto v : vertices) //for all vertices in vertex list...
    {
        for(auto e : edges) //for all edges in edge list...
        {
            if(e ->getStart() == v -> getLabel()) //if starting vertex of edge ==  current vertex in list...
            {   
                //add adjacent vertices to list
                adjacent[v ->getLabel()].push_back((std::make_pair(e ->getWeight(), e -> getEnd())));
                adjacent[e -> getEnd()].push_back(std::make_pair(e ->getWeight(), v -> getLabel()));

            }
        }
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{

    createList(); //create adjacency list

    std::map<std::string, unsigned long> distance;
    std::priority_queue<std::pair<unsigned long, std::string>, std::vector<std::pair<unsigned long, std::string> >, std::greater<std::pair<unsigned long, std::string> > >pq;

    
    for(auto v : vertices) //for all vertices in vertex list...
    {
        if(v -> getLabel() == startLabel) //if current vertex is starting vertex...
        {
            continue; //skip current vertex
        }

        distance[v -> getLabel()] = 9999999; //set all other vertices to infinity
    }
    
    pq.push(std::make_pair(0, startLabel)); //set distance of starting vertex to 0 and add to priority queue
    

    while(!pq.empty()) //while the priority queue is not empty...
    {
    
        std::string s = pq.top().second; //save vertex label
        pq.pop(); //remove vertex from priority queue

        std::vector<std::pair<unsigned long, std::string>>::iterator it;
        for(it = adjacent[s].begin(); it != adjacent[s].end(); it++) //for each element in adjacency list...
        {

            unsigned long weight = it -> first; //save weight of edge
            std::string label = it -> second; //save vertex label

            if(distance[label] > distance[s] + weight) //if path to endLabel is shorter than path through s...
            {
                distance[label] = distance[s] + weight; //update distance
                pq.push(std::make_pair(distance[label], label)); //add distance and vertex to priority queue
            }
        }
        
    }

    return distance[endLabel]; //return shortest distance
    
}

bool Graph::checkForVertex(std::string label)
{
    for(auto v : vertices) //for all vertices in vertex list
    {
        if(v -> getLabel() == label) //if vertex is found...
        {
            return true; 
        }
    }

    return false;
}