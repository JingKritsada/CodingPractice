#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "vector.h"

template <typename T>

void CP::vector<T>::erase_many(const std::vector<int> &pos)
{
  int len = mSize - pos.size(), cnt = 0;
  T *newData = new T[len];

  for (int i = 0; i < mSize; i++)
  {
    if (i == pos[cnt] && cnt < pos.size())
    {
      cnt++;
      continue;
    }

    newData[i - cnt] = mData[i];
  }

  mCap = len;
  mSize = len;

  delete[] mData;
  mData = newData;
}

#endif