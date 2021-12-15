#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
const int n=100;
int ax[]={-1,1,0,0};
int ay[]={0,0,1,-1};
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	
	//INPUT
	long long dp[5*n+1][5*n+1];
	for(int i=0;i<5*n+1;++i)for(int j=0;j<5*n+1;j++)dp[i][j]=1e15;
	long long a[5*n+1][5*n+1];
	for(int i=0;i<n;++i){
		string s;cin >> s;
		for(int j=0;j<s.length();++j){
			a[i][j]=s[j]-'0';
		}
	}
	//INPUT

	//DIJKSTRA
	priority_queue < pair <int, pair<int,int>> > pq;
	pq.push(make_pair(0,make_pair(0,0)));
	dp[0][0]=0;
	while(!pq.empty()){
		int dis = -pq.top().first;
		int x=pq.top().second.first;
		int y=pq.top().second.second; 
		pq.pop();
		if(dis!=dp[x][y])continue;
		for(int i=0;i<4;++i){
			if(x+ax[i]>=n or y+ay[i]>=n or x+ax[i]<0 or y+ay[i]<0)continue;
			int ndis=dis+a[x+ax[i]][y+ay[i]];
			if(ndis>=dp[x+ax[i]][y+ay[i]])continue;
			dp[x+ax[i]][y+ay[i]]=ndis;
			pq.push(make_pair(-ndis,make_pair(x+ax[i],y+ay[i])));
		}
	}
	//DIJKSTRA

	cout << dp[n-1][n-1] << endl;
}


