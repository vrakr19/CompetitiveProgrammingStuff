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
int maxLevel = -1;
vector<int> ans;
int A, B;

void dfs(int i, int num, int level)
{
    if (level > maxLevel)
    {
        return;
    }
    if (level <= maxLevel)
    {
        if (num >= A && num <= B)
        {
            ans.push_back(num);
        }
    }
    if (i < 9)
        dfs(i + 1, num * 10 + i + 1, level + 1);
    if (i > 0)
        dfs(i - 1, num * 10 + i - 1, level + 1);
}

vector<int> stepnum(int A, int B)
{
    ::A = A;
    ::B = B;
    ans.clear();
    if (A == 0)
        ans.push_back(0);
    int n = B;
    maxLevel = 0;
    while (n)
    {
        maxLevel++;
        n = n / 10;
    }
    if (maxLevel == 1)
    {
        for (int i = A; i <= B; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }

    for (int i = 1; i <= 9; i++)
    {
        dfs(i, i, 1);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> A >> B;

        vector<int> ans = stepnum(A, B);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
/********  Main() Ends Here *************/