#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
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

bool ischeck(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    return true;
}

int solve(vector<vector<int>> &arr)
{
    n = arr.size();
    m = arr[0].size();
    vector<vector<bool>> vis;

    for (int i = 0; i <= n; i++)
    {
        vector<bool> tmp;
        for (int j = 0; j <= m; j++)
        {
            tmp.push_back(false);
        }
        vis.push_back(tmp);
    }

    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    vis[0][0] = true;

    if (arr[0][0] == 0)
    {
        return -1;
    }

    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        if (arr[p.first.first][p.first.second] == 9)
        {
            return p.second;
        }

        for (int i = 0; i < 4; i++)
        {
            if (ischeck(p.first.first + x[i], p.first.second + y[i]) && (arr[p.first.first + x[i]][p.first.second + y[i]] == 1 || arr[p.first.first + x[i]][p.first.second + y[i]] == 9) && !vis[p.first.first + x[i]][p.first.second + y[i]])
            {
                q.push(make_pair(make_pair(p.first.first + x[i], p.first.second + y[i]), p.second + 1));
                vis[p.first.first + x[i]][p.first.second + y[i]] = true;
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
        int n, m, x;
        cin >> n >> m;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                tmp.push_back(x);
            }
            arr.push_back(tmp);
        }

        int ans = solve(arr);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/