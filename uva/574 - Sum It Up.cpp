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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL);

	int n, m;
	while (cin >> n >> m && m){

		vector<int>vv(m);
		set<vector<int>>st;

		for (int i = 0; i < m; i++){
			cin >> vv[i];
		}

		for (int i = 1; i < (1 << m); i++){
			bitset<20>b(i); int su = 0;
			vector<int>v;
			for (int j = 0; j <m; j++){

				if (b[j]){
					su += vv[j], v.push_back(vv[j]);
				}
			}
			if (su == n){
				st.insert(v);
			}
		}
		cout << "Sums of " << n << ":\n";

		if (st.size() == 0){
			cout << "NONE\n";
			continue;
		}

		set<vector<int>>::reverse_iterator vc = st.rbegin();

		for (; vc != st.rend(); vc++){

			for (int i = 0; i < (*vc).size() - 1; i++){
				cout << (*vc)[i] << "+";
			}
			cout << (*vc)[(*vc).size() - 1] << '\n';
		}
	}

	return 0;
}
