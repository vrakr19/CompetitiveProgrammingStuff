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
//sorting and two pointer O(nlogn + n^2)
vector<vector<int>> threeSum(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    int n = A.size();
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int64 sum = (int64)A[j] + (int64)A[k] + (int64)A[i];
            if (sum == 0)
            {
                vector<int> tmp;
                tmp.push_back(A[i]);
                tmp.push_back(A[j]);
                tmp.push_back(A[k]);
                if (find(ans.begin(), ans.end(), tmp) == ans.end())
                {
                    ans.push_back(tmp);
                }
                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
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

        vector<vector<int>> ans = threeSum(A);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }
}
/********  Main() Ends Here *************/