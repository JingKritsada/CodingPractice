#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse(int a, int b)
{
    while (a < b)
    {
        T temp = mData[(mFront + a) % mCap];
        mData[(mFront + a) % mCap] = mData[(mFront + b) % mCap];
        mData[(mFront + b) % mCap] = temp;

        a++;
        b--;
    }
}

#endif