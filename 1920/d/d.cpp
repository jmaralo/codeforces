#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Node
{
public:
    int reps = 1;
    vector<int> ap = vector<int>(0);
    Node *b;
    ll l = -1;

    Node()
    {
        b = nullptr;
    }

    Node(Node *child)
    {
        b = child;
    }

    ll length()
    {
        if (this->l != -1)
            return this->l;

        ll l = ap.size();
        if (b)
        {
            l += b->length();
        }
        this->l = l * reps;

        return this->l;
    }

    int find(ll idx)
    {
        cout << idx << "\n";
        if (b) {
            if (idx > b->l) {
                ll i = idx - b->l;
                if (i > ap.size()) return -1;
                return ap[i];
            }
            return b->find(idx / b->reps);
        } else {
            if (idx > ap.size()) return -1;
            return ap[idx];
        }
    }
};

void solve(int tt)
{
    int n, q;
    cin >> n >> q;

    int b, x;

    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        cin >> b >> x;
        switch (b)
        {
        case 1:
            root->ap.push_back(x);
            break;

        case 2:
            root->reps += x;
            root = new Node(root);
            break;
        }
    }
    cout << root->length() << "\n";

    int k;
    for (int i = 0; i < q; i++) {
        cin >> k;
        root->find(k);
    }
    cout << "\n\n";
}

#define TESTCASES true
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES)
    {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve(i + 1);
    }
    return 0;
}