#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"
using namespace std;

int main()
{
    /*
    for (int c = 0; c < 10; c++) {
        char fname[100];
        sprintf(fname,"%d.in",(c+1));
        ofstream inp(fname);
        int cn = (c / 5);
        inp<<cn<<endl;
        int n = 4 << (((c % 5) + 1)*3);
        int m = 3 << (((c % 5) + 1)*3);
        if (n > 100000) n = 100000;
        if (m > 100000) m = 100000;

        cout<<n<<" "<<m<<endl;
        vector<int> pp;
        int rrr = (n+m);
        if (rrr > 100000) rrr = 100000;
        for (int i = 0; i < rrr; i++) {
            pp.push_back(i);
        }
        for (int i = 0; i < pp.size(); i++) {
            swap(pp[i], pp[rand() % pp.size()]);
        }

        vector<int> a, b;
        for (int i = 0; i < n; i++) a.push_back(pp[i]);
        for (int i = 0; i < pp.size(); i++) {
            swap(pp[i], pp[rand() % pp.size()]);
        }
        for (int i = 0; i < m; i++) b.push_back(pp[i]);

        inp<<n<<endl;
        inp<<m<<endl;
        for (int i = 0; i < n; i++) inp<<a[i]<<" ";
        inp<<endl;
        for (int i = 0; i < m; i++) inp<<b[i]<<" ";
        inp<<endl;

        if (cn == 0) {
            vector<int> q = Union(a,b);
            int ct = 0;
            for (auto& x:q) {
                cout<<x<<" ";
                ct++;
                if (ct > 50) break;
            }
            cout<<endl;
        }

        if (cn == 1) {
            vector<int> q = Intersect(a,b);
            int ct = 0;
            for (auto& x:q) {
                cout<<x<<" ";
                ct++;
                if (ct > 50) break;
            }
            cout<<endl;
        }
        inp.close();
    }
    */
    int c, n, m;
    cin >> c >> n >> m;
    vector<int> a;
    vector<int> b;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        b.push_back(t);
    }
    if (c == 0)
    {
        a = Union(a, b);
    }
    else
    {
        a = Intersect(a, b);
    }
    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
