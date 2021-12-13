#include <bits/stdc++.h>
using namespace std;
const int n=23;
map <string,vector < string> > m;
long long ans=0;
void go(string x,map <string,int> vis,string path){
	if(x=="end"){
		++ans;
		path+="end";
		return;
	}	bool ok = true;
	for(int i=0;i<x.length();++i)
		if(x[i]<'A' or x[i]>'Z')
			ok=false;
	if(!ok){
		if(vis[x]>=1)return;
		else vis[x]++;
	}
	for(int i=0;i<m[x].size();i++){
		string y = m[x][i];
		go(y,vis,path+x+",");
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	for(int i=0;i<n;++i){
		string s,t,r;cin >> s;
		int j=0;
		t="";
		r="";
		bool ok=false;
		while(j<s.length()){
			if(s[j]=='-'){
				ok=true;
			}
			else if(!ok){
				t+=s[j];
			}
			else if(ok){
				r+=s[j];
			}

			j++;
		}
		if(r=="start"){
			m[r].push_back(t);
		}
		else if(t=="start"){
			m[t].push_back(r);
		}
		else{
			m[t].push_back(r);
			m[r].push_back(t);	
		}
	}
	map <string,int> vis;
	string path = "";	
	go("start",vis,path);
	cout << ans << endl;
}


