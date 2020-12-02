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

void dfs(vector<vector<int>> &arr, int a, int b, int &cnt)
{
    arr[a][b] = 0;
    cnt++;

    int x[8] = {1, -1, 1, -1, 0, 0, 1, -1};
    int y[8] = {1, -1, -1, 1, 1, -1, 0, 0};

    for (int i = 0; i < 8; i++)
    {
        if (ischeck(a + x[i], b + y[i]) && arr[a + x[i]][b + y[i]] == 1)
        {
            dfs(arr, a + x[i], b + y[i], cnt);
        }
    }
}

int solve(vector<vector<int>> &arr)
{
    n = arr.size();
    m = arr[0].size();
    int maxcnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int cnt = 0;
                dfs(arr, i, j, cnt);
                maxcnt = max(maxcnt, cnt);
            }
        }
    }

    return maxcnt;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;
    //SCD(tc);

    while (tc--)
    {
        int x;
        cin >> n >> m;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                tmp.PB(x);
            }
            arr.PB(tmp);
        }

        int ans = solve(arr);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/