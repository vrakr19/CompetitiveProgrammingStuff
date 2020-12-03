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
const int N = 1e5 + 5;
//O(N) solution
int solve(vector<int> &A, int B)
{
    int n = A.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp.find(A[i] + B) != mp.end() && i + 1 != mp[A[i] + B])
        {
            return 1;
        }
    }

    return 0;
}

//sorting amd two pointer O(nlogn + n)
int solve1(vector<int> &A, int B)
{
    int n = A.size();
    sort(A.begin(), A.end());

    if (n == 1)
    {
        return 0;
    }

    int i = 0, j = 1;
    while (i < n)
    {
        if (A[j] - A[i] == B && i != j)
        {
            return 1;
        }
        else if (A[j] - A[i] < B)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return 0;
}

//sorting amd binary search O(nlogn)
int solve2(vector<int> &A, int B)
{
    int n = A.size();
    sort(A.begin(), A.end());

    if (B < 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (binary_search(A.begin(), A.begin() + n - (n - i), A[i] + B))
                return 1;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (binary_search(A.begin() + i + 1, A.end(), A[i] + B))
                return 1;
        }
    }

    return 0;
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

        int B;
        cin >> B;

        int ans = solve2(A, B);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/