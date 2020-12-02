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
vector<int> adj[N + 1];

bool isConnected(int src, int dest)
{
    bool found = false;
    map<int, int> vis;
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        if (p == dest)
        {
            found = true;
            break;
        }

        for (auto it : adj[p])
        {
            if (vis.find(it) == vis.end())
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    while (!q.empty())
    {
        q.pop();
    }
    return found;
}

int solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{
    int n = A.size(), m = C.size();
    vector<int> idx(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        adj[C[i][0]].push_back(C[i][1]);
        adj[C[i][1]].push_back(C[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        idx[A[i]] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            int aidx = idx[A[i]], bidx = idx[B[i]];
            bool it = isConnected(aidx, bidx);
            if (!it)
            {
                return 0;
            }
            else
            {
                swap(A[aidx - 1], A[bidx - 1]);
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
        int n, m;
        cin >> n;

        vector<int> A(n, 0), B(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        cin >> m;
        vector<vector<int>> C(m, vector<int>(2, 0));
        for (int i = 0; i < m; i++)
        {
            cin >> C[i][0] >> C[i][1];
        }

        int ans = solve(A, B, C);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/