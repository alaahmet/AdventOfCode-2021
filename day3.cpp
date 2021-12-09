#include <bits/stdc++.h>
using namespace std;
const int n = 1000;
int m=12;
int a[n][2];
int32_t main(){  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s[n];
    vector <string> v;
    vector <string> y;
    for(int i=0;i<n;i++){
        cin >> s[i];
        v.push_back(s[i]);
        y.push_back(s[i]);
    }
    long long ep=0;
    long long add=1<<(m-1);
    for(int j=0;j<m;j++){
        vector <string> x;
        int zero=0;
        int one=0;
        for(int i=0;i<v.size();++i){
            if(v[i][j]=='0')++zero;
            else one++;
        }
        if(zero>one){
            for(int i=0;i<v.size();++i)
                if(v[i][j]=='0')
                    x.push_back(v[i]);
        }
        else {
            ep+=add;
            for(int i=0;i<v.size();++i)
                if(v[i][j]=='1')
                    x.push_back(v[i]);
        }
        v.clear();
        for(int i=0;i<x.size();i++)
            v.push_back(x[i]);
        add/=2;
    }
    add=1<<(m-1);
    for(int j=0;j<m;j++){
        vector <string> x;
        int zero=0;
        int one=0;
        for(int i=0;i<y.size();++i){
            if(y[i][j]=='0')
                ++zero;
            else
                one++;
        }
        if(zero<=one){
            for(int i=0;i<y.size();++i)
                if(y[i][j]=='0')
                    x.push_back(y[i]);
        }
        else{
            for(int i=0;i<y.size();++i)
                if(y[i][j]=='1')
                    x.push_back(y[i]);
        }
        y.clear();
        for(int i=0;i<x.size();i++)
            y.push_back(x[i]);
    }
    long long ax=0;
    long long bx=0;
    add = 1<<(m-1);
    for(int i=0;i<v[0].size();i++){
        if(v[0][i]!='0')
            ax+=add;
        add=add/2;
    }
    add=1<<(m-1);
    for(int i=0;i<y[0].size();i++){
        if(y[0][i]!='0')
            bx+=add;
        add=add/2;
    }
    cout << (ax*bx) << endl;
}