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
const int N = 1e3 + 5, M = 1e3 + 5;
int n, m;

bool ischeck(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    return true;
}

int solve(int A, int B, vector<string> &C)
{
    n = A;
    m = B;
    vector<vector<int>> dist(A, vector<int>(B, INF));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        // if (p.first == n - 1 && p.second == m - 1)
        // {
        //     break;
        // }

        if (C[p.first][p.second] == 'U')
        {
            if (ischeck(p.first - 1, p.second) && dist[p.first - 1][p.second] > dist[p.first][p.second])
            {
                dist[p.first - 1][p.second] = dist[p.first][p.second];
                q.push({p.first - 1, p.second});
            }
            if (ischeck(p.first, p.second + 1) && dist[p.first][p.second + 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second + 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second + 1});
            }
            if (ischeck(p.first, p.second - 1) && dist[p.first][p.second - 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second - 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second - 1});
            }
            if (ischeck(p.first + 1, p.second) && dist[p.first + 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first + 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first + 1, p.second});
            }
        }
        else if (C[p.first][p.second] == 'R')
        {
            if (ischeck(p.first - 1, p.second) && dist[p.first - 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first - 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first - 1, p.second});
            }
            if (ischeck(p.first, p.second + 1) && dist[p.first][p.second + 1] > dist[p.first][p.second])
            {
                dist[p.first][p.second + 1] = dist[p.first][p.second];
                q.push({p.first, p.second + 1});
            }
            if (ischeck(p.first, p.second - 1) && dist[p.first][p.second - 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second - 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second - 1});
            }
            if (ischeck(p.first + 1, p.second) && dist[p.first + 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first + 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first + 1, p.second});
            }
        }
        else if (C[p.first][p.second] == 'L')
        {
            if (ischeck(p.first - 1, p.second) && dist[p.first - 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first - 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first - 1, p.second});
            }
            if (ischeck(p.first, p.second + 1) && dist[p.first][p.second + 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second + 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second + 1});
            }
            if (ischeck(p.first, p.second - 1) && dist[p.first][p.second - 1] > dist[p.first][p.second])
            {
                dist[p.first][p.second - 1] = dist[p.first][p.second];
                q.push({p.first, p.second - 1});
            }
            if (ischeck(p.first + 1, p.second) && dist[p.first + 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first + 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first + 1, p.second});
            }
        }
        else
        {
            if (ischeck(p.first - 1, p.second) && dist[p.first - 1][p.second] > dist[p.first][p.second] + 1)
            {
                dist[p.first - 1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first - 1, p.second});
            }
            if (ischeck(p.first, p.second + 1) && dist[p.first][p.second + 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second + 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second + 1});
            }
            if (ischeck(p.first, p.second - 1) && dist[p.first][p.second - 1] > dist[p.first][p.second] + 1)
            {
                dist[p.first][p.second - 1] = dist[p.first][p.second] + 1;
                q.push({p.first, p.second - 1});
            }
            if (ischeck(p.first + 1, p.second) && dist[p.first + 1][p.second] > dist[p.first][p.second])
            {
                dist[p.first + 1][p.second] = dist[p.first][p.second];
                q.push({p.first + 1, p.second});
            }
        }
    }

    return dist[n - 1][m - 1];
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        int A, B;
        cin >> A >> B;

        vector<string> C(A, "");
        for (int i = 0; i < A; i++)
        {
            cin >> C[i];
        }

        int ans = solve(A, B, C);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/