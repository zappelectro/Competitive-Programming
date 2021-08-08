#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Mint {
private:
	const static int mod = 1e9 + 7;
	int val;

public:
	Mint () {val = 0;}

	Mint(long long _val) {val = (_val < mod ? _val : _val % mod);}

	Mint& operator += (const Mint &o) {val = (val + o.val < mod ? val + o.val : val + o.val - mod); return *this;}
	template <typename T> Mint& operator += (const T &o) {return *this += Mint(o);}

	Mint& operator -= (const Mint &o) {val = (val < o.val ? val - o.val + mod : val - o.val); return *this;}
	template <typename T> Mint& operator -= (const T &o) {return *this -= Mint(o);}

	Mint& operator *= (const Mint &o) {return *this = (1LL * val * o.val >= mod ? (1LL * val * o.val) % mod : val * o.val);}
	template <typename T> Mint& operator *= (const T &o) {return *this *= Mint(o);}

	friend bool operator == (const Mint &o1, const Mint &o2) {return (o1.val == o2.val);}
	template <typename T> friend bool operator == (const Mint &o1, const T &o2) {return (o1 == Mint(o2));}
	template <typename T> friend bool operator == (const T &o1, const Mint &o2) {return (Mint(o1) == o2);}

	friend bool operator != (const Mint &o1, const Mint &o2) {return (o1.val != o2.val);}
	template <typename T> friend bool operator != (const Mint &o1, const T &o2) {return (o1 != Mint(o2));}
	template <typename T> friend bool operator != (const T &o1, const Mint &o2) {return (Mint(o1) != o2);}

	friend Mint operator + (const Mint &o1, const Mint &o2) {return Mint(o1) += o2;}
	template <typename T> friend Mint operator + (const Mint &o1, const T &o2) {return Mint(o1) += o2;}
	template <typename T> friend Mint operator + (const T &o1, const Mint &o2) {return Mint(o1) += o2;}

	friend Mint operator - (const Mint &o1, const Mint &o2) {return Mint(o1) -= o2;}
	template <typename T> friend Mint operator - (const Mint &o1, const T &o2) {return Mint(o1) -= o2;}
	template <typename T> friend Mint operator - (const T &o1, const Mint &o2) {return Mint(o1) -= o2;}

	friend Mint operator * (const Mint &o1, const Mint &o2) {return Mint(o1) *= o2;}
	template <typename T> friend Mint operator * (const Mint &o1, const T &o2) {return Mint(o1) *= o2;}
	template <typename T> friend Mint operator * (const T &o1, const Mint &o2) {return Mint(o1) *= o2;}

	Mint power(long long y) {
		Mint ans = 1;
		Mint x = *this;

		while (y > 0) {
			if (y & 1) ans *= x;
			y >>= 1;
			x *= x;
		}
		return ans;
	}

	Mint inverse () {return power(mod - 2);}

	Mint& operator /= (const Mint &o) {return *this *= Mint(o).inverse();}
	template <typename T> Mint& operator /= (const T &o) {return *this *= Mint(o).inverse();}

	friend Mint operator / (const Mint &o1, const Mint &o2) {return Mint(o1) /= o2;}
	template <typename T> friend Mint operator / (const Mint &o1, const T &o2) {return Mint(o1) /= o2;}
	template <typename T> friend Mint operator / (const T &o1, const Mint &o2) {return Mint(o1) /= o2;}

	bool operator ~ () const {return ~(this -> val);}
	bool operator ! () const {return (this -> val == 0);}
	void operator ++ () {*this += 1;}
	void operator -- () {*this -= 1;}
	void operator ++ (int) {*this += 1;}
	void operator -- (int) {*this -= 1;}

	friend ostream &operator << (ostream &os, const Mint &o) {os << o.val; return os;}
};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		Mint ans = 0;
		//All operators are overloaded here.
	}
}