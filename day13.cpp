#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	int xmx=0;
	int ymx=0;
	vector <pair <int,int> > v;
	
	// TAKING DOTS AS INPUT
	for(int i=0;i<897;++i){
		string s; cin >> s;
		int x,y;
		string t = "";
		for(int j=0;j<s.length();++j){
			if(s[j]==','){
				x = stoi(t);
				t = "";
			}
			else{
				t+=s[j];
			}
		}
		y = stoi(t);
		v.push_back(make_pair(x,y));
		ymx=max(y,ymx);
		xmx=max(x,xmx);
	}
	// TAKING DOTS AS INPUT

	int n = ymx;
	int m = xmx;

	//DIMENSIONS OF PAPER
	n = 447*2;
	m = 655*2;
	//DIMENSIONS OF PAPER
	
	vector<vector<int>> a(n+1,vector<int>(m+1,0));
	for(int i=0;i<v.size();++i){
		int x=v[i].first;
		int y=v[i].second;
		a[y][x]|=1;
	}

	//FOLDING
	for(int q=0;q<12;++q){
		string s;cin >> s;cin >> s;cin >> s; // taking the folding input
		string t="";
		for(int i=2;i<s.length();++i)t+=s[i];
		int along = stoi(t);
		if(s[0]=='y'){
			for(int i=along+1;i<=n;++i){
				for(int j=0;j<=m;++j){
					a[along-(i-along)][j]|=a[i][j];
				}
			}
			n = along-1;
			m = m;
		}	
		else if(s[0]=='x'){
			for(int i=0;i<=n;++i){
				for(int j=along+1;j<=m;++j){
					a[i][along-(j-along)]|=a[i][j];
				}
			}
			n = n;
			m = along-1;
		}
		int ans=0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j){
				if(a[i][j]==1)++ans;
			}
		}
		if(q==0)
			cout << "PART1 ANSWER: " << ans << endl;
	}
	//FOLDING

	// READ THE CODE FROM STDOUT
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(a[i][j]==1)cout<<"#";
			else cout<<" ";
		}
		cout << endl;
	}
	//READ THE CODE FROM STDOUT
}
