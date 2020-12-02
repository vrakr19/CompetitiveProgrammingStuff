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
const int N = 101;
int64 fib[N];

void compute_fib()
{
    fib[0] = 1LL;
    fib[1] = 1LL;

    for (int i = 2; i <= 100; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

//gives memory limit exceed.
int fibsum_bfs(int A)
{
    compute_fib();
    vector<bool> vis(A + 1, false);
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        vis[p.first] = true;
        if (p.first == A)
        {
            return p.second;
        }
        else if (p.first < A)
        {
            for (int i = 1; i <= 100; i++)
            {
                if (p.first + fib[i] <= A && !vis[p.first + fib[i]])
                {
                    q.push(make_pair(p.first + fib[i], p.second + 1));
                }
                else
                {
                    break;
                }
            }
        }
    }

    return -1;
}

int fibsum(int A)
{
    fib[0] = 1LL;
    fib[1] = 1LL;
    int j = 1;
    for (int i = 2; i <= 50; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > A)
        {
            j = i;
            break;
        }
    }

    j--;
    int cnt = 0;
    while (j >= 0)
    {
        if (fib[j] <= A)
        {
            A = A - fib[j];
            cnt++;
        }
        if (A == 0)
        {
            break;
        }
        j--;
    }

    return cnt;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    //compute_fib();
    int tc = 1;

    while (tc--)
    {
        int A;
        cin >> A;

        int ans = fibsum(A);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/