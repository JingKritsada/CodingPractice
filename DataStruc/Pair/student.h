#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "pair.h"

template <typename T1, typename T2>
bool CP::pair<T1, T2>::operator>=(const pair<T1, T2> &other) const
{
  if (first == other.first)
  {
    return second >= other.second;
  }

  return first >= other.first;

  return false;
}

#endif
