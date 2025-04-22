#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const
{
  // auto temp = *this;

  // for (size_t i = 1; i < k; ++i)
  // {
  //   temp.pop();
  // }

  // return temp.top();

  size_t len = 7;
  if (mSize < 7)
  {
    len = mSize;
  }

  std::vector<T> vec(mData, mData + len);
  std::sort(vec.begin(), vec.end(), mLess);

  return vec[len - k];
}

#endif
