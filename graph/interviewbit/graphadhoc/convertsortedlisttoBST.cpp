#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for binary tree
 **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for singly-linked list.
 **/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

pair<ListNode *, ListNode *> findMidPrev(ListNode *A)
{
    ListNode *fnode = A, *snode = A, *prev = NULL;
    while (fnode)
    {
        fnode = fnode->next;
        if (fnode)
        {
            prev = snode;
            snode = snode->next;
            fnode = fnode->next;
        }
    }

    return {snode, prev};
}

TreeNode *sortedListToBST(ListNode *A)
{
    if (A == NULL)
    {
        return NULL;
    }

    pair<ListNode *, ListNode *> midPrev = findMidPrev(A);
    TreeNode *root = new TreeNode((midPrev.first)->val);

    if ((midPrev.second) != NULL)
    {
        (midPrev.second)->next = NULL;
        root->left = sortedListToBST(A);
    }

    if ((midPrev.first)->next != NULL)
    {
        root->right = sortedListToBST((midPrev.first)->next);
        (midPrev.first)->next = NULL;
    }

    return root;
}