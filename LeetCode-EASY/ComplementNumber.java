package Before;

public class ComplementNumber {
	
	public static void main(String[] args) {
		Solution s = new Solution();
		int num = s.findComplemnt(2147483646);
		System.out.println(num);
	}

}

class Solution{
	public int findComplemnt(int num) {
		int compNum = 0;
		long twoPow = 1L;
		if(num<0) {
			num = -num;
		}
		for(int i=1; i<32; i++) {
			twoPow *= 2;
			if(num >= twoPow) {
				continue;
			} else {
				compNum = (int)(twoPow-num-1);
				break;
			}
		}
		
		return compNum;
		
	}
}