#include<bits/stdc++.h>
using namespace std;

class segtree {
public:
	int size;
	vector<int> tree;
	const int mx = -1 * (1e9 + 7);

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2 * size, mx);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size())
				tree[x] = a[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<int> &a) {
		return build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) set(i, v, 2 * x  + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	int range_max(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return mx;
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		int s1 = range_max(l, r, 2 * x + 1, lx, m);
		int s2 = range_max(l, r, 2 * x + 2, m, rx);
		return max(s1, s2);
	}

	int range_max(int l, int r) {
		return range_max(l, r, 0, 0, size);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	st.build(a);

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << st.range_max(l, r) << "\n";
		}
	}


	return 0;
}