import java.util.*;
import java.io.*;
class Pair{
	public boolean isnum;
	public int num;
	public Pair(boolean isnum,Integer num) {
		this.isnum = isnum;
		this.num = num;
	}
	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		if(isnum)
			str.append(num);
		else 
			str.append((char)num);
		return str.toString();
	}
}
public class day18 {
	public static void Add(ArrayList <Pair> num,ArrayList <Pair> num2) {
		Pair p = new Pair(false,(int) '[');
		num.add(0,p);
		p = new Pair(false,(int) ',');
		num.add(p);
		for(Pair q:num2)
			num.add(q);
		p = new Pair(false,(int) ']');
		num.add(p);
	}
	public static void Reduce(ArrayList <Pair> list) {
		while(true) {
			if(!Explode(list))
				if(!Split(list))
					break;
		}
	}
	public static Integer Mag(ArrayList<Pair> num) {
		boolean loop = true;
		while(num.size()>4 && loop) {
			loop = false;
			int index = -1;
			int value = 0;
			for(int i=0;i<num.size()-4;++i) {
				Pair p = num.get(i);
				Pair p1 = num.get(i+1);
				Pair p2 = num.get(i+2);
				Pair p3 = num.get(i+3);
				Pair p4 = num.get(i+4);
				if(p.num == '[' && !p.isnum) {
					if(p1.isnum) {
						if(p2.num == ',' && !p2.isnum) {
							if(p3.isnum) {
								if(p4.num == ']' && !p4.isnum) {
									int n1 = p1.num;
									int n2 = p3.num;
									index = i;
									value = 3*n1 + 2*n2;
									break;
								}
							}
						}
					}
				}
			}
			if(index>-1) {
				num.remove(index);
				num.remove(index);
				num.remove(index);
				num.remove(index);
				Pair q = new Pair(true,value);
				num.set(index,q);
				loop = true;
			}
		}
		
		
		return num.get(0).num;
	}
	public static boolean Split(ArrayList <Pair> num) {
		Iterator <Pair> it = num.iterator();
		boolean flag = false;
		int index = -1;
		int value = -1;
		while(it.hasNext()) {
			++index;
			Pair p = it.next();
			int number = p.num;
			boolean isnum = p.isnum;
			if(isnum && number>9) {
				flag = true;
				it.remove();
				value = number;
				break;
			}
		}
		Pair [] p =new Pair[5];
		p[0] = new Pair(false,(int)'[');
		p[1] = new Pair(true,value/2);
		p[2] = new Pair(false,(int)',');
		p[3] = new Pair(true,value/2+value%2);
		p[4] = new Pair(false,(int)']');
		
		if(flag) {
			for(int i=4;i>=0;i--) {
				num.add(index,p[i]);
			}
		}
		
		return flag;
	}
	public static boolean Explode(ArrayList <Pair> num) {
		int bracket = 0;
		int index=-1; 
		for(int i=0;i<num.size();++i) {
			Pair p = num.get(i);
			if(p.isnum == false) {
				if(p.num == (int)'[') {
					bracket++;
					if(bracket>4) {
						Pair p1 = num.get(i+1);
						Pair p2 = num.get(i+2);
						Pair p3 = num.get(i+3);
						Pair p4 = num.get(i+4);
						if(p1.isnum) {
							if(p2.num == (int)',' && !p2.isnum) {
								if(p3.isnum) {
									if(p4.num == (int)']' && !p4.isnum) {
										index = i;
										int n1 = p1.num;
										int n2 = p3.num;
										for(int j=i-1;j>=0;--j) {
											Pair q = num.get(j);
											if(q.isnum) {
												q.num+=n1;
												break;
											}
										}
										for(int j=i+5;j<num.size();++j) {
											Pair q = num.get(j);
											if(q.isnum) {
												q.num+=n2;
												break;
											}
										}
										break;
									}
								}
							}
						}
					}		
				}
				else if(p.num == (int)']')
					bracket--;
			}
		}
		if(index>-1) {
			num.remove(index);
			num.remove(index);
			num.remove(index);
			num.remove(index);
			Pair q = new Pair(true,0);
			num.set(index,q);
			return true;
		}
		return false;
	}
	public static Integer SumAll(ArrayList<ArrayList<Pair>> lines) {	
		ArrayList <Pair> list = new ArrayList<Pair>();
		for(ArrayList<Pair> num : lines) {
			if(list.size()>0) {
				Add(list,num);
				Reduce(list);
			}
			else {
				for(Pair p:num) {
					list.add(p);
				}
			}
		}	

		return Mag(list);
	}
	public static void main(String[] args){
		ArrayList<ArrayList<Pair>> lines = new ArrayList<ArrayList<Pair>>();
		ArrayList<ArrayList<Pair>> lines2 = new ArrayList<ArrayList<Pair>>(); // for part2
		try {
			File file = new File("day18.in");
			Scanner sc = new Scanner(file);
			while(sc.hasNextLine()) {
				ArrayList <Pair> num = new ArrayList <Pair>();
				String s = sc.nextLine();
				for(int i=0;i<s.length();++i) {
					char c = s.charAt(i);
					Pair p = new Pair(false,0);
					if(Character.isDigit(c)) {
						p.num = (int)c-(int)'0';
						p.isnum = true;
					}
					else {
						p.num = (int)c;
						p.isnum = false;
					}
					num.add(p);
				}
				lines.add(num);
			}
			sc.close();
		}
		catch(FileNotFoundException e){
				System.out.println("File not found");
				e.printStackTrace();
		}
		for(int i=0;i<lines.size();i++) {
			ArrayList <Pair> num = new ArrayList <Pair>();
			for(int j=0;j<lines.get(i).size();j++) {
				Pair p = lines.get(i).get(j);
				boolean flag = p.isnum;
				int value = p.num; 
				Pair q = new Pair(flag,value);
				num.add(q);
			}
			lines2.add(num);
		}
		System.out.println("Part 1: "+ SumAll(lines));
		int ans=0;
		for(int i=0;i<lines2.size();i++) {
			for(int j=0;j<lines2.size();j++) {
				if(i==j)continue;	
				ArrayList<ArrayList<Pair>> list = new ArrayList<ArrayList<Pair>>();
				ArrayList <Pair> list2 = new ArrayList<Pair>();
				for(int k=0;k<lines2.get(i).size();k++) {
					Pair p = lines2.get(i).get(k);
					boolean flag = p.isnum;
					int value = p.num; 
					Pair q = new Pair(flag,value);
					list2.add(q);
				}
				list.add(list2);
				list2 = new ArrayList<Pair>();
				for(int k=0;k<lines2.get(j).size();k++) {
					Pair p = lines2.get(j).get(k);
					boolean flag = p.isnum;
					int value = p.num; 
					Pair q = new Pair(flag,value);
					list2.add(q);
				}
				list.add(list2);
				
				ans = Math.max(ans, SumAll(list));
			}
		}
		System.out.println("Part 2: "+ ans);
	}
}
