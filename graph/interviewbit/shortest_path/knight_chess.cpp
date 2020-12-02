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
const int N = 505, M = 505;
int n, m;
vector<vector<int>> dist(N, vector<int>(M, INF));

bool ischeck(int x, int y)
{
    if (x <= 0 || y <= 0 || x > n || y > m)
    {
        return false;
    }
    return true;
}

int solve(int A, int B, int C, int D, int E, int F)
{
    n = A;
    m = B;
    //intialize the dist vector
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dist[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(C, D));
    dist[C][D] = 0;

    int x[8] = {1, -1, 1, -1, 2, 2, -2, -2};
    int y[8] = {2, 2, -2, -2, 1, -1, 1, -1};

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == E && p.second == F)
        {
            return dist[E][F];
        }

        for (int i = 0; i < 8; i++)
        {
            if (ischeck(p.first + x[i], p.second + y[i]))
            {
                if (dist[p.first + x[i]][p.second + y[i]] > 1 + dist[p.first][p.second])
                {
                    q.push(make_pair(p.first + x[i], p.second + y[i]));
                    dist[p.first + x[i]][p.second + y[i]] = dist[p.first][p.second] + 1;
                }
            }
        }
    }

    return -1;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        int A, B, C, D, E, F;
        cin >> A >> B >> C >> D >> E >> F;

        int ans = solve(A, B, C, D, E, F);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/