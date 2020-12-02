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
string multiple(int A)
{
    if (A <= 1)
        return "1";

    vector<bool> vis(A + 1, false);
    vector<int> parent(A + 1, -1), step(A + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = true;
    step[1] = 1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        if (p == 0)
        {
            break;
        }
        int n1 = (p * 10) % A;
        if (!vis[n1])
        {
            vis[n1] = true;
            parent[n1] = p;
            step[n1] = 0;
            q.push(n1);
        }
        int n2 = ((p * 10) + 1) % A;
        if (!vis[n2])
        {
            vis[n2] = true;
            parent[n2] = p;
            step[n2] = 1;
            q.push(n2);
        }
    }

    string ans = "";
    int state = 0;
    while (state != -1)
    {
        ans += (step[state] + '0');
        state = parent[state];
    }
    reverse(ans.begin(), ans.end());
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
        int A;
        cin >> A;

        string ans = multiple(A);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/