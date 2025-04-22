#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"

template <typename T>
T CP::queue<T>::operator[](int idx)
{
  return mData[(mFront + ((idx + mSize) % mSize) + mCap) % mCap];
}

#endif