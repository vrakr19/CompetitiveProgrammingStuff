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

/******** User-defined Function *******/
const int N = 1e5 + 5, M = 1e5 + 5;
int n, m;
vector<int> adj[N];
bool vis[N], color[N];

int dfs(int src)
{
    for (auto it : adj[src])
    {
        if (color[src] == color[it])
        {
            return 0;
        }
        if (!vis[it])
        {
            vis[it] = true;
            color[it] = 1 - color[src];

            if (!dfs(it))
            {
                return 0;
            }
        }
    }

    return 1;
}

int solve(int A, vector<vector<int>> &B)
{
    n = A;
    m = B.size();

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        color[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            color[i] = 0;

            if (!dfs(i))
            {
                return 0;
            }
        }
    }

    return 1;
}
/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        int A;
        cin >> A;

        cin >> m;

        vector<vector<int>> B(m, vector<int>(2, 0));
        for (int i = 0; i < m; i++)
        {
            cin >> B[i][0] >> B[i][1];
        }

        int ans = solve(A, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/