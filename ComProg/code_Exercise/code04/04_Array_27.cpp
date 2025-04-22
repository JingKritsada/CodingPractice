#include <bits/stdc++.h>
using namespace std;

int main()
{

    // -998, -999
    /*
        int a, b, idx = 0, tmp ;
        int mnA = INT_MAX, mxA = 0 ;
        int mnB = INT_MAX, mxB = 0 ;

        while(true)
        {
            cin >> a ;
            if(a == -998 || a == -999)
            {
                break ;
            }

            cin >> b ;

            if(idx % 2 != 0)
            {
                tmp = a ;
                a = b ;
                b = tmp ;
            }
            idx++ ;

            if(a < mnA) mnA = a ;
            if(a > mxA) mxA = a ;
            if(b < mnB) mnB = b ;
            if(b > mxB) mxB = b ;

            //cout << a << " " << b << "\n" ;
        }

        if(a == -998)
        {
            cout << mnA << " " << mxB ;
        }
        else
        {
            cout << mnB << " " << mxA ;
        }
    */

    // Zig - Zag
    /*
        int n, a, b, mnA = INT_MAX, mnB = INT_MAX, mxA = INT_MIN, mxB = INT_MIN;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cin >> a >> b;
            }
            else
            {
                cin >> b >> a;
            }

            if (a < mnA) mnA = a ;
            if (a > mxA) mxA = a ;
            if (b < mnB) mnB = b ;
            if (b > mxB) mxB = b ;

            //cout << "\n" << mnA << " " << mnB << " " << mxA << " " << mxB ;
        }

        string cmd ;
        cin >> cmd ;

        if (cmd == "Zig-Zag")
        {
            cout << mnA << " " << mxB ;
        }
        else
        {
            cout << mnB << " " << mxA ;
        }
    */

    return 0;
}