#include <bits/stdc++.h>
using namespace std;

#define visited first
#define children second

pair<bool, vector<int>> v[200000 + 1];

int search(int node)
{
    auto curr = v + node;
    if (curr->visited)
        return 0;
    curr->visited = true;

    int ans = 0;
    bool hasOpenEdge = false;
    for (auto child_itr = curr->children.begin(); child_itr != curr->children.end(); child_itr++)
    {
        auto child = v + *child_itr;
        if (child->visited)
            continue;
        hasOpenEdge = true;
        child->visited = true;
        int tmp_ans = 0;
        for (auto grand_child_itr = child->children.begin(); grand_child_itr != child->children.end(); grand_child_itr++)
            tmp_ans = max(tmp_ans, search(*grand_child_itr));
        ans += tmp_ans;
        child->visited = false;
    }

    curr->visited = false;

    return ans + (hasOpenEdge ? 1 : 0);
}

int main()
{
    int n, leaf = -1;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].children.push_back(b);
        v[b].children.push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (v[i].children.size() == 1)
        {
            leaf = i;
            break;
        }
    }

    cout << search(leaf);

    return 0;
}