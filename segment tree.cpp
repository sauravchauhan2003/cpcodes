#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<long long> tree, lazyAdd, lazySet;
    vector<bool> hasSet;

    SegmentTree(vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        lazyAdd.resize(4 * n, 0);
        lazySet.resize(4 * n, 0);
        hasSet.resize(4 * n, false);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<long long>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void applySet(int node, int l, int r, long long val) {
        tree[node] = (r - l + 1) * val;
        lazySet[node] = val;
        lazyAdd[node] = 0;
        hasSet[node] = true;
    }

    void applyAdd(int node, int l, int r, long long val) {
        tree[node] += (r - l + 1) * val;

        if (hasSet[node])
            lazySet[node] += val;
        else
            lazyAdd[node] += val;
    }

    void push(int node, int l, int r) {
        if (l == r) return;

        int mid = (l + r) / 2;

        if (hasSet[node]) {
            applySet(node * 2, l, mid, lazySet[node]);
            applySet(node * 2 + 1, mid + 1, r, lazySet[node]);
            hasSet[node] = false;
        }

        if (lazyAdd[node] != 0) {
            applyAdd(node * 2, l, mid, lazyAdd[node]);
            applyAdd(node * 2 + 1, mid + 1, r, lazyAdd[node]);
            lazyAdd[node] = 0;
        }
    }

    void rangeAdd(int node, int l, int r,
                  int ql, int qr, long long val) {
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            applyAdd(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        rangeAdd(node * 2, l, mid, ql, qr, val);
        rangeAdd(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void rangeSet(int node, int l, int r,
                  int ql, int qr, long long val) {
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            applySet(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        rangeSet(node * 2, l, mid, ql, qr, val);
        rangeSet(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    void add(int l, int r, long long val) {
        rangeAdd(1, 0, n - 1, l, r, val);
    }

    void set(int l, int r, long long val) {
        rangeSet(1, 0, n - 1, l, r, val);
    }

    long long sum(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    long long prefixSum(int r) {
        return sum(0, r);
    }
};
