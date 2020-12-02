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
vector<vector<string>> ans;
map<string, vector<string>> adj;
map<int, string> idx;
map<string, int> stridx;
set<vector<string>> ansset;

void construct_graph(string start, string end, vector<string> &dict)
{
    map<string, int> vis;
    int n = dict.size();
    for (int i = 0; i < n; i++)
    {
        string tmp = dict[i];
        for (int j = 0; j < tmp.length(); j++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                string nstr = tmp;
                nstr[j] = ch;

                if (vis.find(nstr) != vis.end())
                {
                    continue;
                }

                if (find(dict.begin(), dict.end(), nstr) != dict.end())
                {
                    adj[tmp].push_back(nstr);
                    adj[nstr].push_back(tmp);
                }
                else if (nstr == start)
                {
                    adj[start].push_back(tmp);
                    adj[tmp].push_back(start);
                }
                else if (nstr == end)
                {
                    adj[end].push_back(tmp);
                    adj[tmp].push_back(end);
                }
            }
        }
        vis[tmp] = 1;
    }

    int i = 1;
    for (auto it : adj)
    {
        idx[i] = it.first;
        stridx[it.first] = i;
        i++;
    }
}

void find_path(int u, vector<string> path, vector<vector<int>> parent)
{
    if (u == -1)
    {
        reverse(path.begin(), path.end());
        ansset.insert(path);
        return;
    }

    for (auto it : parent[u])
    {
        path.push_back(idx[u]);
        find_path(it, path, parent);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string start, string end, vector<string> &dict)
{
    ans.clear();
    adj.clear();
    idx.clear();
    stridx.clear();
    ansset.clear();

    construct_graph(start, end, dict);
    queue<int> q;
    vector<int> dist(dict.size() + 3, INF);
    vector<vector<int>> parent(dict.size() + 3);

    q.push(stridx[start]);
    parent[stridx[start]].push_back(-1);
    dist[stridx[start]] = 0;

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (auto it : adj[idx[tmp]])
        {
            if (dist[stridx[it]] > dist[tmp] + 1)
            {
                dist[stridx[it]] = dist[tmp] + 1;
                q.push(stridx[it]);
                parent[stridx[it]].clear();
                parent[stridx[it]].push_back(tmp);
            }
            else if (dist[stridx[it]] == dist[tmp] + 1)
            {
                parent[stridx[it]].push_back(tmp);
            }
        }
    }

    vector<string> path;
    find_path(stridx[end], path, parent);

    for (auto it : ansset)
    {
        ans.push_back(it);
    }
    return ans;
}

/**************************************/

/********** Main()  function **********/
int main()
{
    int tc = 1;

    while (tc--)
    {
        string start, end;
        cin >> start >> end;

        vector<string> dict;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            dict.push_back(str);
        }

        vector<vector<string>> ans = findLadders(start, end, dict);
        for (auto it : ans)
        {
            for (string str : it)
            {
                cout << str << " ";
            }
            cout << endl;
        }
    }
}
/********  Main() Ends Here *************/