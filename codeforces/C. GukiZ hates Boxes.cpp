//Don't despair and never lose hope ^_^
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include <bitset>
#include<algorithm>
#include<fstream>
#include<string>
#include<stdio.h>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define PI 3.14159265
#define ebs 1e-8
using namespace std;

int n, m;
vector<ll>v;

bool can(ll md){

	vector<ll>vv;
	vv = v;
	int c = 0;
	for (int i = 0; i < m; i++){
		
		ll tm = md - c;

		for (int j = c; j < n&&tm; j++){
			tm--;
			if (tm >= vv[j]){
				c = j + 1, tm -= vv[j], vv[j] = 0;
			}
			else{
				c = j, vv[j] -= tm, tm = 0;
			}

		}
	}

	for (auto i : vv){
		if (i)return false;
	}
	return true;
}

ll bs(){

	ll s = 0, e = 1e15, md, ans = 1e15;
	while (s <= e){
		md = s + (e - s) / 2;
		if (can(md)){
			ans = min(ans, md);
			e = md - 1;
		}
		else{
			s = md + 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	cout << bs();

	return 0;
}
