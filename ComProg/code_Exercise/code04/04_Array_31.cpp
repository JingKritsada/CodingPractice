#include <bits/stdc++.h>
using namespace std;

string ones[10] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
string twos[10] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
string tens[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
string thousands[5] = {"", "thousand ", "million ", "billion ", "trillion "};

string NumtoEng(string str)
{
    int len = str.size();
    // Ex : 9,999,999,999,999

    for (int i = 4; i > 0; i--)
    {
        if (str[0] - '0' == 0)
        {
            return NumtoEng(str.substr(1, len - 1));
        }
        if (len > 3 * i)
        {
            return NumtoEng(str.substr(0, len - (3 * i))) + thousands[i] + NumtoEng(str.substr(len - (3 * i), (3 * i)));
        }
    }

    int num = stoi(str);
    // cout << num ;

    if (num < 10)
        return ones[num];
    if (num < 20)
        return twos[num - 10];
    if (num < 100)
        return tens[num / 10] + ones[num % 10];
    if (num < 1000)
        return ones[num / 100] + "hundred " + NumtoEng(str.substr(1, 2));

    return "";
}

int main()
{
    string num;
    cin >> num;

    if (num == "0")
    {
        cout << "zero";
    }
    else
    {
        cout << NumtoEng(num);
    }

    return 0;
}