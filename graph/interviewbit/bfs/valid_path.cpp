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

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
}

/******** User-defined Function *******/
bool isValid(int x, int y, int C, int D, vector<int> E, vector<int> F)
{
    for (int i = 0; i < C; i++)
    {
        if ((x - E[i]) * (x - E[i]) + (y - F[i]) * (y - F[i]) <= D * D)
        {
            return false;
        }
    }

    return true;
}

bool ischeck(int x, int y, int A, int B)
{
    if (x < 0 || y < 0 || x > A || y > B)
    {
        return false;
    }
    return true;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    vector<vector<bool>> vis;

    for (int i = 0; i <= A; i++)
    {
        vector<bool> tmp;
        for (int j = 0; j <= B; j++)
        {
            tmp.push_back(false);
        }
        vis.push_back(tmp);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    vis[0][0] = true;

    if (!isValid(0, 0, C, D, E, F))
    {
        return "NO";
    }

    int x[8] = {1, -1, 1, -1, 0, 0, 1, -1};
    int y[8] = {1, -1, -1, 1, 1, -1, 0, 0};

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == A && p.second == B)
        {
            return "YES";
        }

        for (int i = 0; i < 8; i++)
        {
            if (ischeck(p.first + x[i], p.second + y[i], A, B))
            {
                if (!vis[p.first + x[i]][p.second + y[i]] && isValid(p.first + x[i], p.second + y[i], C, D, E, F))
                {
                    q.push(make_pair(p.first + x[i], p.second + y[i]));
                    vis[p.first + x[i]][p.second + y[i]] = true;
                }
            }
        }
    }

    return "NO";
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc;
    SCD(tc);

    while (tc--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        vector<int> E, F;
        for (int i = 0; i < C; i++)
        {
            int x;
            cin >> x;
            E.push_back(x);
        }
        for (int i = 0; i < C; i++)
        {
            int x;
            cin >> x;
            F.push_back(x);
        }

        string ans = solve(A, B, C, D, E, F);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/