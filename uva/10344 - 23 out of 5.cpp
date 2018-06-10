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

int c;
vector<int>v(5);

void solve(int i, int sum){

	if (i == 5){
		c += (sum == 23);
		return;
	}

	if (!i){
	solve(i + 1, v[0]);
	}

	else{
		solve(i + 1, sum + v[i]);
		solve(i + 1, sum - v[i]);
		solve(i + 1, sum*v[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL);

	while (cin >> v[0] && v[0]){
		for (int i = 1; i < 5; i++){
			cin >> v[i];
		}
		 c = 0;
		sort(v.begin(), v.end());
		do{
	
			solve(0, 0);
			if (c)break;
		} while (next_permutation(v.begin(), v.end()));
		cout << (c ? "Possible" : "Impossible") << '\n';
		
	}

	return 0;
}
