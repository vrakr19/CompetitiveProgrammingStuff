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
int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int n = A.size(), m = B.size(), o = C.size(), i = 0, j = 0, k = 0, ans = INT_MAX;

    while (i < n && j < m && k < o)
    {
        int max3 = max(A[i], max(B[j], C[k]));
        int min3 = INT_MAX, mini = -1;

        if (A[i] > B[j])
        {
            if (B[j] > C[k])
            {
                min3 = C[k];
                mini = k;
            }
            else
            {
                min3 = B[j];
                mini = j;
            }
        }
        else
        {
            if (A[i] > C[k])
            {
                min3 = C[k];
                mini = k;
            }
            else
            {
                min3 = A[i];
                mini = i;
            }
        }

        ans = min(ans, max3 - min3);
        if (i == mini && A[i] == min3)
        {
            i++;
        }
        else if (j == mini && B[j] == min3)
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    return ans;
}
/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        int n, m, o;
        cin >> n >> m >> o;

        vector<int> A, B, C;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }

        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            B.push_back(x);
        }

        for (int i = 0; i < o; i++)
        {
            int x;
            cin >> x;
            C.push_back(x);
        }

        int ans = minimize(A, B, C);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/