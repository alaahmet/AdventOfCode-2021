#include <bits/stdc++.h>
using namespace std;
int pos[2];
int score[2];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	pos[0]=9;
	pos[1]=6;
	int dice=1;
	int turn=0;
	long long total=0;
	score[0]=0;
	score[1]=0;
	while(score[0]<1000 and score[1]<1000){
		pos[turn]=(pos[turn]+3*dice+3)%10;
		score[turn]=score[turn]+pos[turn];
		if(pos[turn]==0)
			score[turn]+=10;
		dice+=3;
		total+=3;
		dice=dice%100;
		turn=1-turn;
	}
	long long ans = score[turn]*total;
	cout << ans << endl;
}
