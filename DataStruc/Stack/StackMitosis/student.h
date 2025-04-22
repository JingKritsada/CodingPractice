#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    T *arr = new T[b + 1];
    for (int i = 0; i < b + 1; i++)
    {
        arr[i] = top();
        pop();
    }

    for (int i = b; i >= 0; i--)
    {
        if (i >= a)
        {
            push(arr[i]);
        }
        push(arr[i]);
    }
}

#endif