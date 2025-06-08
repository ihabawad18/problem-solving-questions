#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FastRead                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

int t = 1;

int n, k, m;

string s;

int MOD = 1e9 + 7;

map<char, set<char>> x;

vector<int> e[26];

int memo[1005][1005];

int dp(int i, int k)
{
    int j = n - i - 1;

    if (i > j)
        return 1;

    if (i == j)
    {
        if (k == 0)
            return 1;
        return 26;
    }

    int &ret = memo[i][k];

    if (ret != -1)
        return ret;

    ret = 0;

    // set<char> temp = x[s[i]];

    for (char w = 'a'; w <= 'z'; w++)
    {
        // if(x[w].size()<=1)continue;
        for (auto p : x[w])
        {

            int ops1 = s[i] != w, ops2 = s[j] != p;

            // cout << s[i] << " " << w << " " << p << " "  << ops1+ops2 <<" " << '\n';

            if (k >= ops1 + ops2)
                (ret += (dp(i + 1, k - ops1 - ops2))) %= MOD;
        }
    }
    return ret;
}

vector<int> visited(26, 0), component(26, -1);

void dfs(int i, int c)
{
    visited[i] = 1;
    component[i] = c;
    for (auto x : e[i])
    {
        if (!visited[x])
        {
            dfs(x, c);
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();

        cin >> k >> m;

        // for (char i = 'a'; i <= 'z'; i++)
        // {
        //     x[i].clear();
        // }

        for (int i = 0; i < 26; i++)
        {
            e[i].clear();
            visited[i] = 0;
            component[i] = -1;
        }

        while (m--)
        {
            char a, b;

            cin >> a >> b;
            // cout << a << " " << b << endl;
            e[a - 'a'].push_back(b - 'a');
            e[b - 'a'].push_back(a - 'a');
        }
        int c = 0;
        for (int i = 0; i < 26; i++)
        {
            if (!visited[i] && e[i].size() > 0)
            {
                dfs(i, c);
                c++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (component[i] == component[j] && component[i] != -1)
                {
                    x[i + 'a'].insert(j + 'a');
                }
            }
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            if (x[i].size() > 1)
            {
                cout << i << endl;

                for (auto p : x[i])
                {
                    cout << p << " ";
                }
                cout << endl;
            }
        }

        // for (auto p : component)
        // {
        //     cout << p << " ";
        // }
        // cout << endl;
        // for(char i ='a';i<='z';i++){
        //     x[i].insert(i);
        // }

        // for(char i ='a';i<='z';i++){
        //     if(x[i].size()>1){
        //         cout << i << " ";

        //         for(auto p:x[i]){
        //             cout << p << " ";
        //         }

        //         cout << '\n';
        //     }
        // }

        memset(memo, -1, sizeof(memo));

        int answ = dp(0, k);
        cout << answ << '\n';
    }

    return 0;
}