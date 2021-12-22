#include <bits/stdc++.h>
using namespace std;
#define zaman cout<<"\n"<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds "
#define rep(i,n) for(long long (i)=0;(i)<(n);++(i))
#define ref(i,a,b) for (long long (i)=(a); (i)<=(b); ++(i))	
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
const long long mx=1e6+6;
int a[105][105][105];
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	
	freopen("input.txt","r",stdin);
	int lines=60;
	rep(ijk,lines){
		string s;cin >> s;
		int val=1;
		if(s[1]=='f')val=0;
		cin >> s;
		int j=2;
		int mul=1;
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		string t="";
		while(s[j]!='.'){
			t+=s[j];
			j++;
		}
		int xleft=(stoi(t))*mul;j+=2;t="";
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		while(s[j]!=','){
			t+=s[j];
			j++;
		}
		int xright=(stoi(t))*mul;j+=3;t="";
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		while(s[j]!='.'){
			t+=s[j];
			j++;
		}
		int yleft=(stoi(t))*mul;j+=2;t="";
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		while(s[j]!=','){
			t+=s[j];
			j++;
		}
		int yright=(stoi(t))*mul;j+=3;t="";
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		while(s[j]!='.'){
			t+=s[j];
			j++;
		}
		int zleft=(stoi(t))*mul;j+=2;t="";
		if(s[j] == '-'){
			mul=-1;
			++j;
		}else mul=1;
		while(j<s.length()){
			t+=s[j];
			j++;
		}
		int zright=(stoi(t))*mul;j+=3;t="";
		xleft=max(-50,xleft);
		xright=min(50,xright);
		yleft=max(-50,yleft);
		yright=min(50,yright);
		zleft=max(-50,zleft);
		zright=min(50,zright);
		for(int i=xleft+50;i<=xright+50;i++){
			for(int j=yleft+50;j<=yright+50;j++){
				for(int k=zleft+50;k<=zright+50;k++){
					a[i][j][k]=val;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int k=0;k<=100;k++){
				if(a[i][j][k]==1)++ans;
			}
		}
	}

	cout << ans << endl;
}
