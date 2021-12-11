#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
const int n = 98; // total number of lines in the given input

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);    
    freopen("input.txt","r",stdin);
    long long ans=0;
    vector <long long> v;
    for(int kk=0;kk<n;kk++){
    	string s;cin >> s;
    	bool flag = true;
    	map <char,int> m;
    	stack <char> a;
    	for(int i=0;i<s.length();++i){
    		char c = s[i];
    		if(c=='(' or c=='[' or c=='{' or  c=='<'){
    			m[c]++;
    			a.push(c);
    		}
    		else{
    			char t = c;
    			c--;
    			if(c!='(')c--;
    			if(m[c]==-1 or a.top()!=c){
    				if(c=='(')ans+=3;
    				else if(c=='[')ans+=57;
    				else if(c=='{')ans+=1197;
    				else if(c=='<')ans+=25137;
    				flag=false;
    				break;
    			}
    			else {
    				a.pop();
    				m[c]--;
    			}
    		}
    	} 
    	long long sum=0;
    	if(a.empty() or !flag)sum=-1;
    	while(!a.empty() and flag){
    		sum*=5;
    		if(a.top()=='(')sum+=1;
    		else if(a.top()=='[')sum+=2;
    		else if(a.top()=='{')sum+=3;
    		else if(a.top()=='<')sum+=4;
    		a.pop();
    	}
    	if(sum>-1){
    		v.push_back(sum);
    	}
    }
    sort(v.begin(),v.end());
    cout << v[v.size()/2] << endl; // task2
    // cout << ans << endl; //task1
}