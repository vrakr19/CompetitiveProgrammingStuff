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
//sort and two pointer O(nlogn + n^2)
int threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());

    int64 n = A.size(), mindiff = INF, ans;
    for (int64 i = 0; i < n - 2; i++)
    {
        int64 l = i + 1, r = n - 1;
        while (l < r)
        {
            int64 sum = A[i] + A[l] + A[r];
            if (sum > B)
            {
                r--;
                if (mindiff > abs(sum - B))
                {
                    mindiff = abs(sum - B);
                    ans = sum;
                }
            }
            else
            {
                l++;
                if (mindiff > abs(sum - B))
                {
                    mindiff = abs(sum - B);
                    ans = sum;
                }
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
        int n, B;
        cin >> n;

        vector<int> A(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        cin >> B;

        int ans = threeSumClosest(A, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/