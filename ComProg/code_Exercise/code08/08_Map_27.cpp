#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> charToKey = {
    {'a', "2"}, {'b', "22"}, {'c', "222"}, {'d', "3"}, {'e', "33"}, {'f', "333"}, {'g', "4"}, {'h', "44"}, {'i', "444"}, {'j', "5"}, {'k', "55"}, {'l', "555"}, {'m', "6"}, {'n', "66"}, {'o', "666"}, {'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"}, {'t', "8"}, {'u', "88"}, {'v', "888"}, {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"}, {' ', "0"}};

unordered_map<string, char> keyToChar = {
    {"2", 'a'}, {"22", 'b'}, {"222", 'c'}, {"3", 'd'}, {"33", 'e'}, {"333", 'f'}, {"4", 'g'}, {"44", 'h'}, {"444", 'i'}, {"5", 'j'}, {"55", 'k'}, {"555", 'l'}, {"6", 'm'}, {"66", 'n'}, {"666", 'o'}, {"7", 'p'}, {"77", 'q'}, {"777", 'r'}, {"7777", 's'}, {"8", 't'}, {"88", 'u'}, {"888", 'v'}, {"9", 'w'}, {"99", 'x'}, {"999", 'y'}, {"9999", 'z'}, {"0", ' '}};

string text2key(string &str)
{
    string result = "";
    for (char c : str)
    {
        c = tolower(c);
        if (charToKey.find(c) != charToKey.end())
        {
            result += charToKey[c] + " ";
        }
    }

    return result;
}

string key2text(string &str)
{
    stringstream ss(str);
    string key, result = "";

    while (ss >> key)
    {
        if (keyToChar.find(key) != keyToChar.end())
        {
            result += keyToChar[key];
        }
    }

    return result;
}

int main()
{
    string command, line, ans;
    while (cin >> command)
    {
        cin.ignore();
        getline(cin, line);

        if (command == "T2K")
        {
            ans = text2key(line);
        }
        else if (command == "K2T")
        {
            ans = key2text(line);
        }

        cout << ">> " << ans << "\n";
    }

    return 0;
}