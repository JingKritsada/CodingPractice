#include <bits/stdc++.h>
using namespace std;

int main()
{
    struct student
    {
        string num;
        double gpa;
        char com;
        char cal1;
        char cal2;
    };

    student a, b;
    cin >> a.num >> a.gpa >> a.com >> a.cal1 >> a.cal2;
    cin >> b.num >> b.gpa >> b.com >> b.cal1 >> b.cal2;

    if ((a.com == 'A' && a.cal1 <= 'C' && a.cal2 <= 'C') ||
        (b.com == 'A' && b.cal1 <= 'C' && b.cal2 <= 'C'))
    {
        if (a.com != 'A' || a.cal1 > 'C' || a.cal2 > 'C')
        {
            cout << b.num;
            return 0;
        }
        else if (b.com != 'A' || b.cal1 > 'C' || b.cal2 > 'C')
        {
            cout << a.num;
            return 0;
        }

        if (a.gpa == b.gpa)
        {
            if (a.cal1 == b.cal1)
            {
                if (a.cal2 == b.cal2)
                {
                    cout << "Both";
                }
                else if (a.cal2 < b.cal2)
                {
                    cout << a.num;
                }
                else
                {
                    cout << b.num;
                }
            }
            else if (a.cal1 < b.cal1)
            {
                cout << a.num;
            }
            else
            {
                cout << b.num;
            }
        }
        else if (a.gpa > b.gpa)
        {
            cout << a.num;
        }
        else
        {
            cout << b.num;
        }
    }
    else
    {
        cout << "None";
    }

    return 0;
}