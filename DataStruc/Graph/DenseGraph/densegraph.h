#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__
#include <vector>

using namespace std;

class DenseGraph
{
public:
    DenseGraph()
    {
        n = 3;
        vector<bool> tmp(n, false);
        matrix.resize(n, tmp);
    }

    DenseGraph(int n_in)
    {
        n = n_in;
        vector<bool> tmp(n, false);
        matrix.resize(n, tmp);
    }

    DenseGraph(const DenseGraph &G)
    {
        n = G.n;
        matrix = G.matrix;
    }

    void AddEdge(int a, int b)
    {
        matrix[a][b] = true;
    }

    void RemoveEdge(int a, int b)
    {
        matrix[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const
    {
        return matrix[a][b];
    }

    DenseGraph Transpose() const
    {
        DenseGraph tmp(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp.matrix[i][j] = matrix[j][i];
            }
        }

        return tmp;
    }

protected:
    int n;
    vector<vector<bool>> matrix;
};

#endif
