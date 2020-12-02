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
bool ischeck(int x, int y, int A, int B)
{
    if (x < 0 || y < 0 || x >= A || y >= B)
    {
        return false;
    }
    return true;
}

void dfs(vector<string> &A, int u, int v, int n, int m)
{
    A[u][v] = 'O';

    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};

    for (int k = 0; k < 4; k++)
    {
        if (ischeck(u + x[k], v + y[k], n, m))
        {
            if (A[u + x[k]][v + y[k]] == 'X')
            {
                dfs(A, u + x[k], v + y[k], n, m);
            }
        }
    }
}

int solve(vector<string> A)
{
    int n = A.size(), m = A[0].length();

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'X')
            {
                dfs(A, i, j, n, m);
                cnt++;
            }
        }
    }

    return cnt;
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

        vector<string> A;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            A.push_back(str);
        }

        int ans = solve(A);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/