#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class SparseGraph
{
public:
    SparseGraph() : adjList(3) {}

    SparseGraph(int n_in) : adjList(n_in) {}

    SparseGraph(const SparseGraph &G) : adjList(G.adjList) {}

    void AddEdge(int a, int b)
    {
        adjList[a].insert(b);
    }

    void RemoveEdge(int a, int b)
    {
        adjList[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const
    {
        return adjList[a].find(b) != adjList[a].end();
    }

    SparseGraph Transpose() const
    {
        SparseGraph tmp(adjList.size());
        for (int a = 0; a < adjList.size(); ++a)
        {
            for (int b : adjList[a])
            {
                tmp.AddEdge(b, a);
            }
        }
        return tmp;
    }

private:
    vector<unordered_set<int>> adjList;
};
