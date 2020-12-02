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
int find_DS(VI parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find_DS(parent, parent[x]);
    }
}

void union_DS(VI parent, VI rank, int u, int v)
{
    int uParent = find_DS(parent, u);
    int vParent = find_DS(parent, v);

    if (uParent == vParent)
    {
        return;
    }

    if (rank[uParent] > rank[vParent])
    {
        parent[vParent] = uParent;
    }
    else if (rank[vParent] > rank[uParent])
    {
        parent[uParent] = vParent;
    }
    else
    {
        parent[vParent] = uParent;
        rank[uParent]++;
    }
}

int solve(int A, vector<vector<int>> B)
{
    VI parent(A + 1), rank(A + 1);
    for (int i = 0; i <= A; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
    for (int i = 0; i < B.size(); i++)
    {
        pq.push(make_pair(B[i][2], make_pair(B[i][0], B[i][1])));
    }

    int i = 0, minCost = 0;
    while (i < A - 1)
    {
        pair<int, PII> p = pq.top();
        pq.pop();

        int u = p.second.first, v = p.second.second, wt = p.first;

        if (find_DS(parent, u) != find_DS(parent, v))
        {
            minCost += wt;
            union_DS(parent, rank, u, v);
        }
        i++;
    }

    return minCost;
}
/**************************************/

/********** Main()  function **********/
int main()
{
    int tc;
    SCD(tc);

    while (tc--)
    {
        int n, m, u, v, wt;
        cin >> n >> m;

        vector<vector<int>> B;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            cin >> u >> v >> wt;

            tmp.push_back(u);
            tmp.push_back(v);
            tmp.push_back(wt);

            B.push_back(tmp);
        }

        int ans = solve(n, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/