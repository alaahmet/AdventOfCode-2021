import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day25 {

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		int n = 137; // rows
		int m = 139; // columns
		char [][] s = new char[n][m];
		try {
			File file = new File("day25.in");
			Scanner sc = new Scanner(file);
			String [] sq = new String[n];
			int idx=0;
			while(sc.hasNext()) {
				sq[idx] = sc.nextLine();
				for(int j=0;j<m;j++) {
					s[idx][j] = sq[idx].charAt(j); 
				}
				idx++;
			}
			sc.close();
		}
		catch(FileNotFoundException e){
				System.out.println("File not found");
				e.printStackTrace();
		}
		int step=0;
		while(step>=0) {
			int move=0;
			char [][] ns = new char[n][m];
			for(int i=0;i<n;++i) {
				for(int j=0;j<m;++j) {
					ns[i][j] = s[i][j];
				}
			}
			for(int i=0;i<n;++i) {
				for(int j=0;j<m;++j) {
					if(s[i][j]=='>' && s[i][(j+1)%m]=='.') {
						ns[i][(j+1)%m]='>';
						ns[i][j]='.';
						move++;
					}
				}
			}
			for(int i=0;i<n;++i) {
				for(int j=0;j<m;++j) {
					s[i][j] = ns[i][j];
				}
			}
			for(int i=0;i<n;++i) {
				for(int j=0;j<m;++j) {
					if(s[i][j]=='v' && s[(i+1)%n][j]=='.') {
						ns[(i+1)%n][j]='v';
						ns[i][j]='.';
						move++;
					}
				}
			}
			for(int i=0;i<n;++i) {
				for(int j=0;j<m;++j) {
					s[i][j] = ns[i][j];
				}
			}
			++step;
			if(move==0)break;
		}
		System.out.println(step);
		long estimatedTime = System.currentTimeMillis() - startTime;
		System.out.println("Runs in "+estimatedTime+" milliseconds");
		
		
	}

}
