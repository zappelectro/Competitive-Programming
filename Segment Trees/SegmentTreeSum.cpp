#include<bits/stdc++.h>
using namespace std;
#define int long long int

class segtree {
public:
	int size;
	vector<int> tree;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2 * size, 0ll);
	}

	void update(int i, int val, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = val;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid)
			update(i, val, 2 * x + 1, lx, mid);
		else
			update(i, val, 2 * x + 2, mid, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];

	}

	void update(int i, int val) {
		update(i, val, 0, 0, size);
	}

	int sum(int l, int r, int x, int lx, int rx) {
		if (l >= rx || r <= lx) return 0;
		if (lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx) / 2;
		int s1 = sum(l, r, 2 * x + 1, lx, mid);
		int s2 = sum(l, r, 2 * x + 2, mid, rx);
		return s1 + s2;
	}

	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	segtree st;
	st.init(n);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.update(i, a[i]);
	}

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