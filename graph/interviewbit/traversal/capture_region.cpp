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
const int N = 1005, M = 1005;
bool vis[N][M];
int n, m;

bool ischeck(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(vector<vector<char>> &A, int i, int j)
{
    vis[i][j] = true;
    A[i][j] = 'Y';

    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};

    for (int k = 0; k < 4; k++)
    {
        if (ischeck(i + x[k], j + y[k]))
        {
            if (!vis[i + x[k]][j + y[k]] && A[i + x[k]][j + y[k]] == 'O')
            {
                dfs(A, i + x[k], j + y[k]);
            }
        }
    }
}

void solve(vector<vector<char>> &A)
{
    n = A.size();
    m = A[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }

    //1st column and last column
    for (int i = 0; i < n; i++)
    {
        if (A[i][0] == 'O' && !vis[i][0])
        {
            dfs(A, i, 0);
        }

        if (A[i][m - 1] == 'O' && !vis[i][m - 1])
        {
            dfs(A, i, m - 1);
        }
    }

    //1st row and last row
    for (int j = 0; j < m; j++)
    {
        if (A[0][j] == 'O' && !vis[0][j])
        {
            dfs(A, 0, j);
        }

        if (A[n - 1][j] == 'O' && !vis[n - 1][j])
        {
            dfs(A, n - 1, j);
        }
    }

    //change all 'O' not in the boundry or connected to boundry to 'X'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'O')
            {
                A[i][j] = 'X';
            }
        }
    }

    //change all 'Y' in the boundry and connected to it back to original state
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'Y')
            {
                A[i][j] = 'O';
            }
        }
    }
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

        vector<vector<char>> A;
        for (int i = 0; i < n; i++)
        {
            vector<char> tmp;
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                tmp.push_back(x);
            }
            A.push_back(tmp);
        }
        solve(A);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}
/********  Main() Ends Here *************/