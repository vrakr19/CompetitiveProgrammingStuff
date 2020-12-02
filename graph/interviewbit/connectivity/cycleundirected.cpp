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
const int N = 6e+4, M = 1e5;
vector<int> adj[N + 1];
bool vis[N + 1], isCycle = false;
int parent[N + 1];

void dfs(int i)
{
    if (isCycle)
    {
        return;
    }

    vis[i] = true;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            parent[it] = i;
            dfs(it);
        }
        else
        {
            if (parent[i] != it)
            {
                isCycle = true;
                return;
            }
        }
    }
}
bool solve(int n, vector<vector<int>> &B)
{
    int m = B.size();
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        vis[i] = false;
        adj[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && !isCycle)
            dfs(i);
    }

    return isCycle;
}
/**************************************/

/********** Main()  function **********/
int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> B;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp(2, 0);
            cin >> tmp[0] >> tmp[1];
            B.push_back(tmp);
        }
        bool ans = solve(n, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/