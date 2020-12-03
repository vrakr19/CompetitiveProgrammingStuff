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
vector<int> maxone(vector<int> &A, int B)
{
    int n = A.size(), cnt = 0, ms = 0, l = 0, r = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            cnt++;
        }

        while (j < n && cnt > B)
        {
            if (A[j] == 0)
            {
                cnt--;
            }
            j++;
        }

        if (ms < (i - j + 1))
        {
            l = j;
            r = i;
            ms = (i - j + 1);
        }
    }
    vector<int> ans;
    for (int i = l; i <= r; i++)
    {
        ans.push_back(i);
    }

    return ans;
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

        vector<int> ans = maxone(A, B);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
/********  Main() Ends Here *************/