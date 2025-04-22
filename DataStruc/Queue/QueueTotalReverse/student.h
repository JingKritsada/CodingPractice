#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse()
{
  if (aux == 0)
  {
    aux = 1;
    mFront = (mFront + mSize - 1) % mCap;
  }
  else
  {
    aux = 0;
    mFront = ((mFront - mSize + 1) + mCap) % mCap;
  }
}

template <typename T>
const T &CP::queue<T>::front() const
{
  return mData[mFront];
}

template <typename T>
const T &CP::queue<T>::back() const
{
  if (aux == 0)
  {
    return mData[(mFront + mSize - 1) % mCap];
  }
  else
  {
    return mData[((mFront - mSize + 1) + mCap) % mCap];
  }
}

template <typename T>
void CP::queue<T>::push(const T &element)
{
  ensureCapacity(mSize + 1);

  if (aux == 0)
  {
    mData[(mFront + mSize) % mCap] = element;
  }
  else
  {
    mData[((mFront - mSize) + mCap) % mCap] = element;
  }

  mSize++;
}

template <typename T>
void CP::queue<T>::pop()
{
  if (aux == 0)
  {
    mFront = (mFront + 1) % mCap;
  }
  else
  {
    mFront = ((mFront - 1) + mCap) % mCap;
  }

  mSize--;
}

#endif