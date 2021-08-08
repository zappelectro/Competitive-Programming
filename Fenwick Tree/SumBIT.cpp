#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;

class Fenwick {
public:
	vector <int> BIT;
	int size;

	void init(int n) {
		BIT.assign(size + 1, 0);
	}

	void update(int i, int v) {
		for (++i; i <= size; i += i & -i)
			BIT[i] += v;
	}

	int query(int i) {
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += BIT[i];
		return sum;
	}
};

int main()
{
	int n, i;
	cin >> n;

	vector<int> a(n + 1);

	Fenwick ft;
	ft.init(n);

	for (i = 1; i <= n; i++) {
		cin >> a[i];
		ft.update(i, a[i]);
	}

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int index, v;
			cin >> index >> v;
			ft.update(index, v);
		}
		else {
			int x;
			cin >> x;
			cout << ft.query(x) << "\n";
		}
	}

	return 0;
}