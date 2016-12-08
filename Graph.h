#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <queue>
#include <functional>

#include "Vertex.h"
using namespace std;
class Graph
{
	unordered_map<int, Vertex> _vertices;

public:

	void addVertex(Vertex vertex)
	{
		_vertices[vertex.getId()] = vertex;
	}

	//MA #12 TODO: IMPLEMENT!
	unordered_map<Vertex, int> computeShortestPath(Vertex *start)
	{
		//holds known distances
		unordered_map<Vertex, int> distances;

		//underlying heap
		priority_queue<Vertex, vector<Vertex>, PathWeightComparer> dijkstra_queue{};

		//reset start's path weight
		start->setPathWeight(0);

		//make sure that the starting vertex is in the graph
		if (start != nullptr)
			
		{
			if (_vertices[start->getId()] == *start.getId())
			{
				//push on starting vertex
				dijkstra_queue.push(*start);
					
				//while queue not empty
				while ( !dijkstra_queue.empty() )
				{
					//Top of heap not known (in distances)?
					if (distances.find(dijkstra.top()) == distances.end())
					{	
						//make known
						distances[dijkstra_queue.top()] = start->getPathWeight();
						
						//push on outgoing edges
						dijkstra_queue.push();
					}
				}
			}
		}
		return distances;
	}
};

#endif
