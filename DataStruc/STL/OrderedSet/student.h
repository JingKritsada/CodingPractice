#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T> &A, const vector<T> &B)
{
    set<T> union_set;
    vector<T> ans;

    for (const T &x : A)
    {
        union_set.insert(x);
        ans.push_back(x);
    }

    for (const T &x : B)
    {
        if (union_set.find(x) == union_set.end())
        {
            union_set.insert(x);
            ans.push_back(x);
        }
    }

    return ans;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B)
{
    set<T> intersect_set;
    vector<T> ans;

    for (const T &x : B)
    {
        intersect_set.insert(x);
    }

    for (const T &x : A)
    {
        if (intersect_set.find(x) != intersect_set.end())
        {
            ans.push_back(x);
        }
    }

    return ans;
}
