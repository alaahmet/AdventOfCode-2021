#include <bits/stdc++.h>
using namespace std;
long long dp[259][9];
long long st[259][9];
int main(){
	// INPUT
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	vector <long long> v;
	string s;cin >> s;
	string temp="";
	for(int i=0;i<s.length();++i){
		temp = s[i];
		if(i%2==0)v.push_back(stoi(temp));
	}
	//INPUT

	long long x = 256;
	long long ans=0;

	for(int i=0;i<v.size();++i){ // base case
		dp[0][v[i]]++;
	}

	for(int i=1;i<=x;++i){
		for(int j=0;j<7;++j){
			if(j==6){
				dp[i][j]+= dp[i-1][0];
				st[i][8]+=dp[i-1][0];
			}
			else
				dp[i][j]+= dp[i-1][j+1];
		}
		dp[i][6]+=st[i-1][0];
		st[i][8]+=st[i-1][0];
		for(int j=0;j<=7;++j){
			st[i][j]+= st[i-1][j+1]; 
		}
	}

	for(int i=0;i<9;++i){
		ans+=dp[x][i]+st[x][i];
	}
	cout << ans << endl;
}
