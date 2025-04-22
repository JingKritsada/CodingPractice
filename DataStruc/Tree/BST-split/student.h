#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val)
{
  CP::map_bst<KeyT, MappedT, CompareT> result;

  node *n = mRoot;
  node *prev;
  node *l;

  while (n != NULL)
  {
    if (mLess(n->data.first, val))
    {
      n = n->right;
    }
    else
    {
      l = n->left;

      if (n == mRoot)
      {
        mRoot = l;

        if (l != NULL)
        {
          l->parent = NULL;
        }
      }
      else
      {
        n->parent->right = l;

        if (l != NULL)
        {
          l->parent = n->parent;
        }
      }

      n->left = NULL;

      if (result.mRoot == NULL)
      {
        n->parent = NULL;
        result.mRoot = n;
      }
      else
      {
        n->parent = prev;
        n->parent->left = n;
      }

      prev = n;
      n = l;
    }
  }

  return result;
}

#endif
