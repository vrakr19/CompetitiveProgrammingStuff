#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

const int N = 5e3 + 5;
int solve(string A, string B, vector<string> C)
{
    unordered_map<string, int> vis, mp;
    for (auto it : C)
    {
        mp[it] = 1;
    }

    queue<pair<string, int>> q;
    q.push(make_pair(A, 0));
    vis[A] = 1;

    while (!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();

        if (p.first == B)
        {
            return p.second + 1;
        }

        for (int i = 0; i < (p.first).length(); i++)
        {
            string tmp = p.first;
            for (int j = 0; j < 26; j++)
            {
                tmp[i] = 'a' + j;
                if (mp.find(tmp) != mp.end() && vis.find(tmp) == vis.end())
                {
                    q.push(make_pair(tmp, p.second + 1));
                    vis[tmp] = 1;
                }
            }
        }
    }

    return 0;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        string A, B;
        cin >> A >> B;
        int n;
        cin >> n;
        vector<string> C;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            C.push_back(str);
        }
        int ans = solve(A, B, C);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/