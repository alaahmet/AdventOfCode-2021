#include <bits/stdc++.h>
using namespace std;
const int n = 100;
const int m = 100;
vector<vector<int>> a(102,vector<int>(102,1e9)); 
int vis[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
long long val;
void dfs(int x,int y){
	if(a[x][y]==1e9 or vis[x][y]==1 or a[x][y]==9)
		return;
	vis[x][y]=1;
	val++;
	for(int i=0;i<4;++i){
		dfs(x+dx[i],y+dy[i]);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("input.txt","r",stdin);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;cin >> c;
			a[i][j] = c - '0';
		}
	}
	long long ans=1;
	vector <long long> v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			val = 0;
			dfs(i,j);
			v.push_back(val);
		}
	}
	sort(v.begin(),v.end(),greater <long long>());
	ans = v[0]*v[1]*v[2];
	cout << ans << endl;
}
