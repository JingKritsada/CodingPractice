#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include <set>

using namespace std;
template <typename T>

void CP::vector<T>::uniq()
{
  set<T> s;
  for (auto it = this->begin(); it != this->end(); it++)
  {
    s.insert(*it);
  }

  int len = s.size();
  T *newData = new T[len];

  s.clear();
  int i = 0;
  for (auto it = this->begin(); it != this->end(); it++)
  {
    if (s.find(*it) == s.end())
    {
      newData[i] = *it;
      s.insert(*it);
      i++;
    }
  }

  mCap = len;
  mSize = len;

  delete[] mData;
  mData = newData;
}

#endif
