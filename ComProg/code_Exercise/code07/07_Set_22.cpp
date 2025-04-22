#include <bits/stdc++.h>
using namespace std;

int main()
{
    string allNum, tmp = "";
    int idx = 0, num;
    set<int> unionSet, intersectSet, differenceSet, currentSet;

    while (getline(cin, allNum))
    {
        // if (allNum == "-1") break ;

        allNum += " ";
        currentSet.clear();
        for (auto c : allNum)
        {
            if (c != ' ')
            {
                tmp += c;
            }
            else
            {
                if (tmp != "")
                {
                    num = stoi(tmp);
                    tmp = "";

                    unionSet.insert(num);
                    currentSet.insert(num);
                }
            }
        }

        if (idx == 0)
        {
            intersectSet = currentSet;
            differenceSet = currentSet;
        }
        else
        {
            set<int> newIntersect;
            for (auto x : currentSet)
            {
                if (intersectSet.find(x) != intersectSet.end())
                {
                    newIntersect.insert(x);
                }
            }
            intersectSet = newIntersect;

            for (auto x : currentSet)
            {
                differenceSet.erase(x);
            }
        }

        idx++;
    }

    cout << "U:";
    for (auto x : unionSet)
    {
        cout << " " << x;
    }

    cout << "\nI:";
    if (intersectSet.empty())
    {
        cout << " empty set";
    }
    else
    {
        for (auto x : intersectSet)
        {
            cout << " " << x;
        }
    }

    cout << "\nD:";
    if (differenceSet.empty())
    {
        cout << " empty set";
    }
    else
    {
        for (auto x : differenceSet)
        {
            cout << " " << x;
        }
    }

    return 0;
}