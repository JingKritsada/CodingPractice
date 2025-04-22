int findDiff(node *n, int &mx, KeyT &ans)
{
    if (n == NULL)
        return 0;

    int depthL = findDiff(n->left, mx, ans);
    int depthR = findDiff(n->right, mx, ans);

    int diff = std::abs(depthL - depthR);

    if (mx < diff || (mx == diff && n->data.first < ans))
    {
        mx = diff;
        ans = n->data.first;
    }

    return std::max(depthL, depthR) + 1;
}

KeyT getValueOfMostImbalanceNode()
{
    KeyT ans = mRoot->data.first;
    int maxDiff = 0;

    findDiff(mRoot, maxDiff, ans);

    return ans;
}
