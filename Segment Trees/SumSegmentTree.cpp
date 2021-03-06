#include<bits/stdc++.h>
using namespace std;

//Implementation credits - pashka
class segtree {
public:
	int size;
	vector<int> tree;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2 * size, 0ll);
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
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void build(vector<int> &a) {
		return build(a, 0, 0, size);
	}

	void update(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) update(i, v, 2 * x  + 1, lx, m);
		else update(i, v, 2 * x + 2, m, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}

	int sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (l <= lx && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		int s1 = sum(l, r, 2 * x + 1, lx, m);
		int s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}

	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
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
			st.update(i, v);
		}
		else if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << "\n";
		}
	}

	return 0;
}