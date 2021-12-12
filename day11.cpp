#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
const int n = 10;
vector<vector<int>> a(n+2,vector<int>(n+2,1e9)); 
long long ans=0;
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
map <int,int> vis[n+2];

void increment(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]++;
		}
	}
}

void let_flash(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]>9 and a[i][j]!=0){
				ans++;
				a[i][j]=0;
				for(int idx=0;idx<8;++idx){
					if(a[i+dx[idx]][j+dy[idx]]>0)
						a[i+dx[idx]][j+dy[idx]]++;
				}
			}
		}
	}

}

void part1(){
	for(int step=1;step<=100;++step){
    	increment();
    	int cnt=0;
    	for(int i=0;i<30;++i)
    		let_flash();
    }
    cout << "ANSWER-Part1: " << ans << endl;
}

void part2(){
	for(int step=1;step<=1000;++step){
    	increment();
    	int cnt=0;
    	for(int i=0;i<30;++i)
    		let_flash();
    	for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			if(a[i][j]==0)++cnt;
    		}
    	}
    	if(cnt==100){
    		cout << "ANSWER-Part2: " << step+cnt << endl;
    		return;
    	}
    }
}

int32_t main(){

   	//INPUT
    ios_base::sync_with_stdio(0);cin.tie(0);    
    freopen("input.txt","r",stdin);
    for(int i=0;i<n;++i){
    	string s;
    	cin >> s;
    	for(int j=0;j<s.length();++j){
    		a[i+1][j+1] = s[j] - '0';
    	}
    }
    //INPUT

    part1();
    part2();
    
}