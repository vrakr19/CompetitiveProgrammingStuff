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
const int N = 6e+4, M = 6e+4;
vector<pair<int, int>> adj[N + 1];
bool vis[N + 1];
int dist[N + 1];

int solve(int n, vector<vector<int>> &B)
{
    int m = B.size();
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dist[i] = INF;
        adj[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        adj[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
        adj[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    }
    //min spanning tree using prim algo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    int minCost = 0;
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (!vis[cur.second])
            minCost += cur.first;
        vis[cur.second] = true;
        for (auto it : adj[cur.second])
        {
            if (!vis[it.first] && dist[it.first] > it.second)
            {
                dist[it.first] = it.second;
                pq.push(make_pair(it.second, it.first));
            }
        }
    }

    return minCost;
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
            vector<int> tmp(3, 0);
            cin >> tmp[0] >> tmp[1] >> tmp[2];
            B.push_back(tmp);
        }

        int ans = solve(n, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/