#include <bits/stdc++.h>
using namespace std;

unordered_map<string, char> code2num =
    {
        {"UUUU", '0'}, {"UUUL", '1'}, {"UULU", '2'}, {"UULL", '3'}, {"ULUU", '4'}, {"ULUL", '5'}, {"ULLU", '6'}, {"ULLL", '7'}, {"LUUU", '8'}, {"LUUL", '9'}, {"LULU", '-'}, {"LULL", ','}};

unordered_map<char, string> num2code =
    {
        {'0', "UUUU"}, {'1', "UUUL"}, {'2', "UULU"}, {'3', "UULL"}, {'4', "ULUU"}, {'5', "ULUL"}, {'6', "ULLU"}, {'7', "ULLL"}, {'8', "LUUU"}, {'9', "LUUL"}, {'-', "LULU"}, {',', "LULL"}};

string decrypt(string str)
{
    string after = "", code = "";
    for (char c : str)
    {
        if ('A' <= c && c <= 'Z')
        {
            code += "U";
        }
        else if ('a' <= c && c <= 'z')
        {
            code += "L";
        }

        if (code.size() == 4)
        {
            after += code2num[code];
            code = "";
        }
    }

    return after;
}

string encrypt(string text, string num)
{
    string after = "", code = "";
    for (char digit : num)
    {
        code += num2code[digit];
    }

    int idx = 0, len = text.size();
    for (char c : code)
    {
        while (!isalnum(text[idx % len]))
        {
            after += text[idx];
            idx++;
        }
        idx %= len;

        if (c == 'U')
        {
            after += toupper(text[idx]);
        }
        else
        {
            after += tolower(text[idx]);
        }
        idx++;
    }

    return after;
}

int main()
{
    string text;
    cin >> text;

    string command;
    while (getline(cin, command))
    {
        if (command[0] == 'E')
        {
            string num = command.substr(2);
            cout << encrypt(text, num) << "\n";
        }
        else if (command[0] == 'D')
        {
            string str = command.substr(2);
            cout << decrypt(str) << "\n";
        }
    }

    return 0;
}