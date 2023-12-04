// #include <bits/stdc++.h>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

bool ok(vector<int> &pre, vector<array<int, 2>> &a, int mn, int k){
	int n=pre.size();
	for (int i=0, lst=0; i<n; ++i){
		if(pre[i]<mn){ // if pre[i]<mn to gasienica jest przesuwana na i+1 z nadzieja ze pre[i+1]>=mn
			lst=i+1;
			continue;
		}
		if(i<n-1&&a[i+1][0]-a[lst][0]>=k)
			return 1; // ostatni element to na pewno bedzie odejscie kogos z rejsu wiec to jest bezpieczne 
	}
	return 0;
}

int rejs(int k, const vector<int> start, const vector<int> end){
	vector<array<int, 2>> a;     // [i][j] - ith vector jth element of an array
	for (int i=0; i<(int)start.size(); ++i){
		a.push_back({start[i], 1});
		a.push_back({end[i]+1, -1}); // tutaj jest end[i]+1, warto pamietac
	}
	int n=(int)a.size();
	sort(a.begin(), a.end());
	vector<int> pre(n, 0); pre[0]=a[0][1];
	for (int i=1; i<n; ++i)
		pre[i]=pre[i-1]+a[i][1];
	int lb=1, rb=(int)start.size()+1; // [0, ilosc kolegow)
	while(lb<rb){
		int mb=(lb+rb)/2;
		if(ok(pre, a, mb, k)) lb=mb+1;
		else rb=mb;
	}
	return lb-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << rejs(20, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30});
}

/* README:
input: rejs(102, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30})
output: 0

intput: rejs(101, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30}) // nie wiem czy na pewno o to chodzi w specyfikacji ale powinno dzialac ogolnie
output: 1

input: rejs(20, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30})
output: 3

0: 0 1  //////////// cout << a[i][0] << " " << pre[i] << "\n";
1: 12 2
2: 25 3
3: 28 4
4: 31 3
5: 37 2
6: 48 3
7: 55 4
8: 66 3
9: 71 2
10: 81 1
11: 101 0
*/
