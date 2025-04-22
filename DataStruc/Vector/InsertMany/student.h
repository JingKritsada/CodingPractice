#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "vector.h"

template <typename T>

void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
  std::sort(data.begin(), data.end());
  int cnt = 0, len = mSize + data.size();
  T *newData = new T[len];

  for (int i = 0, j = 0, k = 0; i < len; i++)
  {
    if (i == data[j].first + cnt)
    {
      newData[i] = data[j].second;
      cnt++;
      j++;
    }
    else
    {
      newData[i] = mData[k];
      k++;
    }
  }

  mCap = len;
  mSize = len;

  delete[] mData;
  mData = newData;
}

#endif