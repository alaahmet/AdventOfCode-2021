#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
int n=100;
int step=10;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	string s;cin >> s;
	map <string,char> m;
	for(int i=0;i<n;++i){
		string t;cin >> t;
		string l;cin >> l;
		char r;cin >> r;
		m[t] = r;
	}
	list <char> l;
	for(auto c:s)l.push_back(c);
	for(int ij=0;ij<step;++ij){
		s="";
		for(auto c:l)s+=c;
		int idx=0;
		char add;
		list <char>:: iterator it = l.begin();
		++it;
		for(int i=0;i<s.length()-1;++i){
			string t = "";
			for(int j=i;j<i+2;++j)t+=s[j];
			add=m[t];
			l.insert(it,add);
			++it;
		}
	}
	s="";
	for(auto c:l)s+=c;
	map <char,int> ans;
	vector <pair<int,char> > res;
	set <int> st;
	for(auto c:s){
		ans[c]++;
	}
	for(auto c:s){
		st.insert(ans[c]);
	}
	auto kit=st.begin();
	auto lit=st.end();
	--lit;
	cout << (*lit-*kit) << endl;
}
