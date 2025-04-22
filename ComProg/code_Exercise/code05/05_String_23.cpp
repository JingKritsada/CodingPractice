#include <bits/stdc++.h>
using namespace std;

int main()
{
    string plate;
    int num;

    cin >> plate;
    cin >> num;

    int numBack = stoi(plate.substr(4, 3)) + num;
    num = numBack / 1000;

    int tmp2 = (plate[2] - 'A') + num;
    num = tmp2 / 26;

    int tmp1 = (plate[1] - 'A') + num;
    num = tmp1 / 26;

    plate[0] += num;
    plate[1] = tmp1 % 26 + 'A';
    plate[2] = tmp2 % 26 + 'A';
    plate[4] = numBack % 1000 / 100 + '0';
    plate[5] = numBack % 100 / 10 + '0';
    plate[6] = numBack % 10 + '0';

    cout << plate;

    return 0;
}

/*
int main()
{
    string tmp ;
    int num ;

    cin >> tmp ;
    cin >> num ;

    int fstNum = tmp[0] - '0' ;
    int lstNum = stoi(tmp.substr(4,3)) ;
    string str = tmp.substr(1,2) ;

    lstNum += num ;
    while(lstNum > 999)
    {
        lstNum -= 1000 ;

        if(str[1] < 'Z')
        {
            str[1]++ ;
        }
        else
        {
            str[1] = 'A' ;
            if(str[0] < 'Z')
            {
                str[0]++ ;
            }
            else
            {
                str[0] = 'A' ;
                fstNum++ ;
            }
        }
    }

    cout << fstNum << str << "-" ;

    if(lstNum < 10)
    {
        cout << "00" ;
    }
    else if(lstNum < 100)
    {
        cout << "0" ;
    }
    cout << lstNum ;

    return 0 ;
}
*/