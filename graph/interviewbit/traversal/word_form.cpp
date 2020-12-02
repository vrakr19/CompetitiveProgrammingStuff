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
vector<string> arr;
string wrd;
int n, m;

bool exist_utils(int i, int j, int wrdPtr)
{
    if (wrd.length() == wrdPtr)
    {
        return true;
    }

    bool res = false;
    if (arr[i][j] == wrd[wrdPtr])
    {
        if (i - 1 >= 0)
        {
            res = res || exist_utils(i - 1, j, wrdPtr + 1);
        }
        if (i + 1 < n)
        {
            res = res || exist_utils(i + 1, j, wrdPtr + 1);
        }
        if (j - 1 >= 0)
        {
            res = res || exist_utils(i, j - 1, wrdPtr + 1);
        }
        if (j + 1 < m)
        {
            res = res || exist_utils(i, j + 1, wrdPtr + 1);
        }
    }

    return res;
}

int exist(vector<string> &board, string word)
{
    arr = board;
    wrd = word;
    n = board.size(), m = board[0].size();

    //word formed from 2D grid is smaaller in length to the given word
    if (n * m < word.length())
        return false;

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = exist_utils(i, j, 0);
            if (ans)
            {
                break;
            }
        }
        if (ans)
        {
            break;
        }
    }

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
        cin >> n;

        vector<string> A;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            A.push_back(str);
        }
        string word;
        cin >> word;

        int ans = exist(A, word);
        cout << ans << endl;
    }
}
/********  Main() Ends Here *************/