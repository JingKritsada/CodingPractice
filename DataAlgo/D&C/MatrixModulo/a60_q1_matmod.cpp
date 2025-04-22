#include <bits/stdc++.h>
using namespace std;

vector<int> matMul(vector<int> &M, vector<int> &N, int k)
{
    vector<int> res(4);
    res[0] = (((M[0] * N[0]) % k) + ((M[1] * N[2]) % k)) % k;
    res[1] = (((M[0] * N[1]) % k) + ((M[1] * N[3]) % k)) % k;
    res[2] = (((M[2] * N[0]) % k) + ((M[3] * N[2]) % k)) % k;
    res[3] = (((M[2] * N[1]) % k) + ((M[3] * N[3]) % k)) % k;

    return res;
}

vector<int> matPow(int n, int k, vector<int> mat)
{
    if (n == 0)
    {
        return {1, 0, 0, 1};
    }

    if (n == 1)
    {
        for (auto &val : mat)
        {
            val %= k;
        }
        return mat;
    }

    vector<int> tmp1 = matPow(n / 2, k, mat);
    if (n % 2 == 0)
    {
        return matMul(tmp1, tmp1, k);
    }
    else
    {
        vector<int> tmp2 = matMul(tmp1, tmp1, k);
        return matMul(tmp2, mat, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(4);
    cin >> vec[0] >> vec[1] >> vec[2] >> vec[3];

    vector<int> ans = matPow(n, k, vec);
    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}