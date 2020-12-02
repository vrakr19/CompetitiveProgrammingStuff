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

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    int curlevel = 0;
    vector<int> tmp;
    while (!q.empty())
    {
        pair<TreeNode *, int> p = q.front();
        q.pop();

        if (p.second == curlevel)
        {
            tmp.push_back((p.first)->val);

            if ((p.first)->left)
            {
                q.push(make_pair((p.first)->left, p.second + 1));
            }

            if ((p.first)->right)
            {
                q.push(make_pair((p.first)->right, p.second + 1));
            }
        }
        else
        {
            ans.push_back(tmp);
            curlevel++;
            tmp.clear();

            tmp.push_back((p.first)->val);

            if ((p.first)->left)
            {
                q.push(make_pair((p.first)->left, p.second + 1));
            }

            if ((p.first)->right)
            {
                q.push(make_pair((p.first)->right, p.second + 1));
            }
        }
    }

    ans.push_back(tmp);
    tmp.clear();
    return ans;
}
