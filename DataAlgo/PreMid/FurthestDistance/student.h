#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
using namespace std;

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        int mxL = my_recur(n->left, aux);
        int mxR = my_recur(n->right, aux);
        int dis = max(mxL, mxR) + 1;

        if (mxL + mxR > aux)
        {
            aux = mxL + mxR;
        }

        return dis;
    }
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    int ans = -1;
    my_recur(mRoot, ans);

    return ans;
}

#endif
