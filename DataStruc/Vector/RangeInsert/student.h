#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last)
{
  int numInsert = last - first;
  int newSize = mSize + numInsert;
  int insertPos = position - this->begin();

  T *newData = new T[newSize];
  auto itr = first;

  for (int i = 0, j = 0; i < newSize; i++)
  {
    if (i < insertPos)
    {
      newData[i] = mData[j];
      j++;
    }
    else if (itr != last)
    {
      newData[i] = *itr;
      itr++;
    }
    else
    {
      newData[i] = mData[j];
      j++;
    }
  }

  mCap = newSize;
  mSize = newSize;

  delete[] mData;
  mData = newData;
}

#endif
