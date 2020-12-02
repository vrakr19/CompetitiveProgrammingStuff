#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int d, vector<vector<int>> arr, vector<int> &vis, int i, int effort, int &min_effort)
{
    if (i == n)
    {
        cout << effort << endl;
        min_effort = min(min_effort, effort);
        return;
    }

    for (int j = 0; j < d; j++)
    {
        if (i < n && (vis[j] == 0 || vis[j] == 1))
        {
            if (vis[j] == 0)
            {
                vis[j] = 1;
            }
            dfs(n, d, arr, vis, i + 1, effort + arr[j][i], min_effort);
        }
        vis[j] = 2;
    }
}

int main()
{
    // your code goes here
    int n, d;
    cin >> n >> d;

    vector<vector<int>> arr;
    vector<int> vis;
    for (int i = 0; i < d; i++)
    {
        vector<int> tmp;
        vis.push_back(0);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        arr.push_back(tmp);
    }

    int min_effort = INT_MAX, effort = 0;
    dfs(n, d, arr, vis, 0, effort, min_effort);
    cout << min_effort << endl;
    return 0;
}