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
int64 MODF(int64 a)
{
    return (a + MOD) % MOD;
}

//sorting and two pointer O(nlogn + n^2)
int nTriang(vector<int> &A)
{
    sort(A.begin(), A.end());
    int64 ans = 0LL, n = A.size();

    if (n <= 2)
    {
        return ans;
    }

    for (int i = n - 1; i >= 2; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (A[l] + A[r] > A[i])
            {
                ans = MODF(ans + (r - l));
                r--;
            }
            else
            {
                l++;
            }
        }
    }

    return (int)ans;
}
/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> A(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int ans = nTriang(A);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/