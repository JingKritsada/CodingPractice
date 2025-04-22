#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  int j = 0, k = 0, len = mSize - pos.size();

  T *newData = new T[len];
  sort(pos.begin(), pos.end());

  for (int i = 0; i < mSize; i++)
  {
    if (i != pos[j])
    {
      newData[k] = mData[(mFront + i) % mCap];
      k++;
    }
    else
    {
      j++;
    }
  }

  delete[] mData;

  mData = newData;
  mSize = len;
  mCap = len;
  mFront = 0;
}

#endif
