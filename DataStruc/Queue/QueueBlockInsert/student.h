#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	size_t n = mSize;
	ensureCapacity(mSize + m);

	if (p < n - p)
	{
		for (size_t i = 0; i < p; ++i)
		{
			mData[(mFront + i - m + mCap) % mCap] = mData[(mFront + i) % mCap];
		}
		mFront = (mFront - m + mCap) % mCap;
	}
	else
	{
		for (size_t i = n; i > p; --i)
		{
			mData[(mFront + i + m - 1) % mCap] = mData[(mFront + i - 1) % mCap];
		}
	}

	for (size_t i = 0; i < m; ++i)
	{
		mData[(mFront + p + i) % mCap] = element;
	}
	mSize += m;
}

#endif
