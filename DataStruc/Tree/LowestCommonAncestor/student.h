#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator CP::map_bst<KeyT, MappedT, CompareT>::recursive(node *n, CP::map_bst<KeyT, MappedT, CompareT>::iterator p, CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const
{
    if (mLess(n->data.first, (*p).first) && mLess(n->data.first, (*q).first))
    {
        return recursive(n->right, p, q);
    }
    if (mLess((*p).first, n->data.first) && mLess((*q).first, n->data.first))
    {
        return recursive(n->left, p, q);
    }

    return iterator(n);
}

template <typename KeyT, typename MappedT, typename CompareT>
typename CP::map_bst<KeyT, MappedT, CompareT>::iterator CP::map_bst<KeyT, MappedT, CompareT>::lca(CP::map_bst<KeyT, MappedT, CompareT>::iterator p, CP::map_bst<KeyT, MappedT, CompareT>::iterator q) const
{
    return recursive(mRoot, p, q);
}

#endif
