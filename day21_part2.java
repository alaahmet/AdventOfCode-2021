
public class day21_part2 {
	static int[] ways = new int[10];
	static long p0win = 0;
	static long p1win = 0;
	public static void go(int p0pos,int p1pos,int p0score,int p1score,int turn,long numberofwaystohere) {
		if(turn==0) {// player0's turn
			for(int i=3;i<=9;i++) {
				int newpos = (p0pos + i)%10;
				if(newpos==0)
					newpos = 10;
				int newscore = p0score + newpos;
				if(newscore>=21)
					p0win = p0win + numberofwaystohere*ways[i];
				else
					go(newpos,p1pos,newscore,p1score,1,numberofwaystohere*ways[i]);
			}
		}
		else if(turn==1) {//player1's turn
			for(int i=3;i<=9;i++) {
				int newpos = (p1pos + i)%10;
				if(newpos==0)
					newpos = 10;
				int newscore = p1score + newpos;
				if(newscore>=21)
					p1win = p1win + numberofwaystohere*ways[i];
				else
					go(p0pos,newpos,p0score,newscore,0,numberofwaystohere*ways[i]);
			}
		}
	}
	public static void main(String[] args) {
		ways[3] = 1;
		ways[4] = 3;
		ways[5] = 6;
		ways[6] = 7;
		ways[7] = 6;
		ways[8] = 3;
		ways[9] = 1;
		int player0Start=4;
		int player1Start=8;
		go(player0Start,player1Start,0,0,0,1);
		System.out.println(p0win + " " + p1win);
	}

}