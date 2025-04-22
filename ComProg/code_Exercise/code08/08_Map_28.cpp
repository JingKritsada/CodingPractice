#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string line;
    unordered_map<string, vector<string>> mp;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);

        int idxComma = 0;
        for (auto c : line)
        {
            if (c == ',')
            {
                break;
            }
            idxComma++;
        }

        string song = line.substr(0, idxComma);
        string singer = line.substr(idxComma + 2);
        mp[song].push_back(singer);
    }

    getline(cin, line);
    stringstream ss(line);
    string song;

    while (getline(ss, song, ','))
    {
        if (song[0] == ' ')
        {
            song = song.substr(1);
        }

        cout << song << " -> ";
        if (mp.find(song) != mp.end())
        {
            for (int i = 0; i < mp[song].size(); i++)
            {
                if (i > 0)
                {
                    cout << ", ";
                }
                cout << mp[song][i];
            }
            cout << "\n";
        }
        else
        {
            cout << "Not found\n";
        }
    }

    return 0;
}