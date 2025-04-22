#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n)
{
  if (n == NULL)
  {
    return 0;
  }

  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT> &left, map_bst<KeyT, MappedT, CompareT> &right)
{
  delete_all_nodes(left.mRoot);
  left.mRoot = mRoot->left;

  delete_all_nodes(right.mRoot);
  right.mRoot = mRoot->right;

  left.mSize = process(mRoot->left);
  right.mSize = mSize - left.mSize - 1;

  mSize = 1;
  mRoot->left = NULL;
  mRoot->right = NULL;
  mRoot->parent = NULL;

  return mRoot->data;
}

#endif
