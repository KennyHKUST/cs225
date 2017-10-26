/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
#include <map>
#include <queue>
/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
    for(auto &v: graph.getVertices())
      graph.setVertexLabel(v, "UNVISITED");
    for(auto &e: graph.getEdges())
        e.label = "UNEXPLORED";//fail to set the label
    queue<Vertex> q;
    Vertex start = graph.getStartingVertex();
    q.push(start);
    int minWeight = INT_MAX;
    std::map<pair<Vertex, Vertex>, int> weightMap;
    while(!q.empty()){
      Vertex v = q.front();
      q.pop();
      vector<Vertex> adjacent = graph.getAdjacent(v);
      for(auto &adjacentV: adjacent){
        cout<<"edge label is "<<graph.getEdgeLabel(v, adjacentV)<<endl;
        if(graph.getVertexLabel(adjacentV) == "UNVISITED"){
          graph.setVertexLabel(adjacentV, "VISITED");
          graph.setEdgeLabel(v, adjacentV, "DISCOVERY");
          q.push(adjacentV);
          int weight = graph.getEdge(v, adjacentV).weight;
          pair<Vertex, Vertex> edge(v, adjacentV);
          weightMap.insert(pair<pair<Vertex, Vertex>, int>(edge, weight));
          // if(graph.getEdge(v, adjacentV).weight < minWeight)
          //   minWeight = 
        }
        if(graph.getEdgeLabel(v, adjacentV) == ""){
          graph.setEdgeLabel(v, adjacentV, "CROSS");
          int weight = graph.getEdge(v, adjacentV).weight;
          pair<Vertex, Vertex> edge(v, adjacentV);
          weightMap.insert(pair<pair<Vertex, Vertex>, int>(edge, weight));
          // if(graph.getEdge(v, adjacentV).weight < minWeight)
          //   minWeight = graph.getEdge(v, adjacentV).weight;
        }
      }
    }
    pair<Vertex, Vertex> minEdge;
    for(auto &it: weightMap){
      if(it.second < minWeight){
        minWeight = it.second;
        minEdge = it.first;
      }
    }
    graph.setEdgeLabel(minEdge.first, minEdge.second, "MIN");
    return minWeight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */
    for(auto &v: graph.getVertices())
      graph.setVertexLabel(v, "UNVISITED");

    queue<Vertex> q;
    q.push(start);

    unordered_map<Vertex, int> distanceMap;
    unordered_map<Vertex, Vertex> pMap;
    distanceMap.insert(pair<Vertex, int>(start, 0));
    pMap.insert(pair<Vertex, Vertex>(start, start));
    while(!q.empty()){
      Vertex v = q.front();
      q.pop();
      vector<Vertex> adjacent = graph.getAdjacent(v);
      for(auto &adjacentV: adjacent){
        if(graph.getVertexLabel(adjacentV) == "UNVISITED"){
          graph.setVertexLabel(adjacentV, "VISITED");
          graph.setEdgeLabel(v, adjacentV, "DISCOVERY");

          distanceMap.insert(pair<Vertex, int>(adjacentV, distanceMap[v]+1));
          pMap.insert(pair<Vertex, Vertex>(adjacentV, v));
          q.push(adjacentV);
        }
        if(graph.getEdgeLabel(v, adjacentV) == ""){
          graph.setEdgeLabel(v, adjacentV, "CROSS");
        }
      }
    }
    Vertex currV = end;
    while(currV != start){
      graph.setEdgeLabel(pMap[currV], currV, "MINPATH");
      currV = pMap[currV];
    }
    return distanceMap[end];
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    /* Your code here! */
  vector<Edge> Edges = graph.getEdges();
  std::sort(Edges.begin(), Edges.end());
  // for(unsigned long i = 0; i < Edges.size(); i++){
  //   cout<<Edges[i].weight<<endl;
  // }
  DisjointSets set;
  unordered_map<Vertex, int> vertexMap;
  // for(auto &v: graph.getVertices())
  //     graph.setVertexLabel(v, "UNVISITED");
  vector<Vertex> Vertices = graph.getVertices();
  for(unsigned long i = 0; i < Vertices.size(); i++){
      set.addelements(i);
      vertexMap.insert(pair<Vertex, int>(Vertices[i], i));
  }
  cout<<"size = "<<graph.getVertices().size()<<endl;
  int i = 0;
  int count = 0;
  while(count < Vertices.size() - 1){
    if(set.find(vertexMap[Edges[i].source]) != set.find(vertexMap[Edges[i].dest])){
      cout<<Edges[i].weight<<endl;
      set.setunion(vertexMap[Edges[i].source], vertexMap[Edges[i].dest]);
      graph.setEdgeLabel(Edges[i].source, Edges[i].dest, "MST");
      count++;
    }
    i++;
  }





  // queue<Vertex> q;
  // Vertex start = graph.getStartingVertex();
  // q.push(start);
  // std::map<pair<Vertex, Vertex>, int> weightMap;
  // vector<pair<Vertex, Vertex>> vertexEdge;
  // while(!q.empty()){
  //     Vertex v = q.front();
  //     q.pop();
  //     vector<Vertex> adjacent = graph.getAdjacent(v);
  //     for(auto &adjacentV: adjacent){
  //       //cout<<"edge label is "<<graph.getEdgeLabel(v, adjacentV)<<endl;
  //       if(graph.getVertexLabel(adjacentV) == "UNVISITED"){
  //         graph.setVertexLabel(adjacentV, "VISITED");
  //         graph.setEdgeLabel(v, adjacentV, "DISCOVERY");
  //         q.push(adjacentV);
  //         //int weight = graph.getEdge(v, adjacentV).weight;
  //         pair<Vertex, Vertex> edge(v, adjacentV);
  //         vertexEdge.push_back(edge);
  //         //weightMap.insert(pair<pair<Vertex, Vertex>, int>(edge, weight));
  //       }
  //       if(graph.getEdgeLabel(v, adjacentV) == ""){
  //         graph.setEdgeLabel(v, adjacentV, "CROSS");
  //         //int weight = graph.getEdge(v, adjacentV).weight;
  //         pair<Vertex, Vertex> edge(v, adjacentV);
  //         vertexEdge.push_back(edge);
  //         //weightMap.insert(pair<pair<Vertex, Vertex>, int>(edge, weight));
  //       }
  //     }
  //   }



}
