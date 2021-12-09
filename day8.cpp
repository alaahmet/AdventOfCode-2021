#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
const int n = 200;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a[] = {'a','b','c','d','e','f','g'};
	sort(a,a+7);
	long long ans=0,sum=0;
	for(int i=0;i<n;i++){
		string temp="";
		string s[10];
	 	for(int j=0;j<10;j++){
			cin >> s[j];
		}
		do{
			bool ok = true;
			map <char,char> m;
			for(char j=0;j<='g';++j){
				m[j]=a[j-'a'];
			}
			for(int j=0;j<10;++j){
				if(s[j].size()==2){
					if(s[j].find(m['c'])!=-1 and s[j].find(m['f'])!=-1);
					else ok=false;
				}
				else if(s[j].size()==3){
					if(s[j].find(m['a'])!=-1 and s[j].find(m['c'])!=-1 and s[j].find(m['f'])!=-1);
					else ok=false;
				}
				else if(s[j].size()==4){
					if(s[j].find(m['b'])!=-1 and s[j].find(m['c'])!=-1 and s[j].find(m['d'])!=-1 and 
						s[j].find(m['f'])!=-1);
					else ok=false;
				}
				else if(s[j].size()==5){

					if(s[j].find(m['a'])!=-1 and s[j].find(m['c'])!=-1 and s[j].find(m['d'])!=-1 and 
						s[j].find(m['e'])!=-1 and s[j].find(m['g'])!=-1);
					else if(s[j].find(m['a'])!=-1 and s[j].find(m['c'])!=-1 and s[j].find(m['d'])!=-1 and 
						s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);
					else if(s[j].find(m['a'])!=-1 and s[j].find(m['b'])!=-1 and s[j].find(m['d'])!=-1 and 
						s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);	
					else ok=false;
				}
				else if(s[j].size()==6){
					if(s[j].find(m['a'])!=-1 and s[j].find(m['b'])!=-1 and s[j].find(m['c'])!=-1 and 
						s[j].find(m['e'])!=-1 and s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);
					else if(s[j].find(m['a'])!=-1 and s[j].find(m['b'])!=-1 and s[j].find(m['c'])!=-1 and 
						s[j].find(m['d'])!=-1 and s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);
					else if(s[j].find(m['a'])!=-1 and s[j].find(m['b'])!=-1 and s[j].find(m['d'])!=-1 and 
						s[j].find(m['e'])!=-1 and s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);
					else ok=false;
				}
				else if(s[j].size()==7){
					if(s[j].find(m['a'])!=-1 and s[j].find(m['b'])!=-1 and s[j].find(m['c'])!=-1 
						and s[j].find(m['d'])!=-1 and s[j].find(m['e'])!=-1 
						and s[j].find(m['f'])!=-1 and s[j].find(m['g'])!=-1);
					else ok=false;
				}		
			}
			if(ok){
				string dummy;cin >> dummy;
				long long ax=10000;
				string t[4];
				for(int k=0;k<4;k++){
					ax = ax/10; 
					cin >> t[k];
					sort(t[k].begin(),t[k].end());
					if(t[k].size()==2){
					if(t[k].find(m['c'])!=-1 and t[k].find(m['f'])!=-1)ans+=ax*1;
					else ok=false;
					}
					else if(t[k].size()==3){
						if(t[k].find(m['a'])!=-1 and t[k].find(m['c'])!=-1 and t[k].find(m['f'])!=-1)ans+=ax*7;
						else ok=false;
					}
					else if(t[k].size()==4){
						if(t[k].find(m['b'])!=-1 and t[k].find(m['c'])!=-1 and t[k].find(m['d'])!=-1 and 
							t[k].find(m['f'])!=-1)ans+=ax*4;
						else ok=false;
					}
					else if(t[k].size()==5){

						if(t[k].find(m['a'])!=-1 and t[k].find(m['c'])!=-1 and t[k].find(m['d'])!=-1 and 
							t[k].find(m['e'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*2;
						else if(t[k].find(m['a'])!=-1 and t[k].find(m['c'])!=-1 and t[k].find(m['d'])!=-1 and 
							t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*3;
						else if(t[k].find(m['a'])!=-1 and t[k].find(m['b'])!=-1 and t[k].find(m['d'])!=-1 and 
							t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*5;
						else ok=false;
					}
					else if(t[k].size()==6){
						if(t[k].find(m['a'])!=-1 and t[k].find(m['b'])!=-1 and t[k].find(m['c'])!=-1 and 
							t[k].find(m['e'])!=-1 and t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*0;
						else if(t[k].find(m['a'])!=-1 and t[k].find(m['b'])!=-1 and t[k].find(m['c'])!=-1 and 
							t[k].find(m['d'])!=-1 and t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*9;
						else if(t[k].find(m['a'])!=-1 and t[k].find(m['b'])!=-1 and t[k].find(m['d'])!=-1 and 
							t[k].find(m['e'])!=-1 and t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*6;
						else ok=false;
					}
					else if(t[k].size()==7){
						if(t[k].find(m['a'])!=-1 and t[k].find(m['b'])!=-1 and t[k].find(m['c'])!=-1 
							and t[k].find(m['d'])!=-1 and t[k].find(m['e'])!=-1 
							and t[k].find(m['f'])!=-1 and t[k].find(m['g'])!=-1)ans+=ax*8;
						else ok=false;
					}
				}
				sum+=ans;
				ans=0;
			}
		}while(next_permutation(a,a+7));
	}

	cout << sum << endl;
}
