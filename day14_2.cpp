#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
long long n=100;
long long step=40;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	string s;cin >> s;
	map <string,long long> m;
	map <string,char> hsh;
	map<char,long long> let;
	vector <string> v;
	for(long long i=0;i<n;++i){
		string t;cin >> t;
		string l;cin >> l;
		char r;cin >> r;
		hsh[t] = r;
		v.push_back(t);
	}
	for(long long i=0;i<s.length()-1;++i){
		let[s[i]]++;
		string add="";
		for(long long j=i;j<i+2;++j)add+=s[j];
		m[add]++;
	}
	let[s[s.length()-1]]++;
	for(long long ij=0;ij<step;++ij){
		map <string,long long> mp;
		map <string,long long>::iterator it;
		for(it=m.begin();it!=m.end();++it){
			string x=it->first;
			long long y=it->second;
			mp[x]=y;
		}
		for(long long i=0;i<n;++i){
			string t = v[i];
			string l="",r="";
			l+=t[0];l+=hsh[t];
			mp[l]+=m[t];
			r+=hsh[t];r+=t[1];
			mp[r]+=m[t];
			mp[t]-=m[t];
			let[hsh[t]]+=m[t];
		}
		for(it=mp.begin();it!=mp.end();++it){
			string x=it->first;
			long long y=it->second;
			m[x]=y;
		}
	}
	set <long long> st;
	for(auto it=let.begin();it!=let.end();++it){
		long long y = it->second;
		st.insert(y);
	}
	auto kit=st.begin();
	auto lit=st.end();
	--lit;
	cout << (*lit-*kit) << endl;
}
