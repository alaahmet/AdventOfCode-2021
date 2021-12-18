#include <bits/stdc++.h>
using namespace std;
const long long mx=1e6+6;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);	

	int xmin=119; // min x value of target area
	int xmax=176; // max x value of target area
	int ymin=-141; // min y value of target area
	int ymax=-84; // max y value of target area

	int x=0;
	int ans=0;
	for(int i=-180;i<180;i++){
		for(int j=-180;j<180;j++){
			int x=0;
			int y=0;
			int velx=i;
			int vely=j;
			while(1){
				if(x>=xmin and x<=xmax
	               and y>=ymin and y<=ymax){++ans;
					break;}

				if(velx==0 and vely<0 and y<=ymin)
					break;
				x+=velx;
				y+=vely;
				if(velx>0)
					velx--;
				else if(velx<0)
					velx++;
				vely--;
			}

		}
		
	}
	cout << ans << endl;

}