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
int n, m;

int solve(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<bool> vis(105, false);
    queue<pair<int, int>> q;
    q.push({1, 0});

    map<int, int> ladder, snake;

    for (int i = 0; i < n; i++)
    {
        ladder[A[i][0]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        snake[B[i][0]] = i;
    }

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        vis[p.first] = true;
        if (p.first == 100)
        {
            return p.second;
        }

        for (int i = 1; i <= 6; i++)
        {
            if (p.first + i <= 100 && !vis[p.first + 1])
            {
                if (ladder.find(p.first + i) != ladder.end())
                {
                    int idx = ladder[p.first + i];
                    q.push({A[idx][1], p.second + 1});
                }
                else if (snake.find(p.first + i) != snake.end())
                {
                    int idx = snake[p.first + i];
                    q.push({B[idx][1], p.second + 1});
                }
                else
                {
                    q.push({p.first + i, p.second + 1});
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
        cin >> n >> m;

        vector<vector<int>> A, B;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(2, 0);
            cin >> tmp[0] >> tmp[1];
            A.push_back(tmp);
        }
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp(2, 0);
            cin >> tmp[0] >> tmp[1];
            B.push_back(tmp);
        }

        int ans = solve(A, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/