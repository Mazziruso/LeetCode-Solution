package Before;
import java.util.*;

public class PairSum {
	public static void main(String[] args) {
		
		int[] nums = {4,2,1,5,3,7,6,8};

		mergeSort(nums, 0, (nums.length-1));
		System.out.println(Arrays.toString(nums));
		
		int sum = arrayPairSum(nums);
		System.out.println(sum);
		
	}
	
	public static int arrayPairSum(int[] nums) {
		int sum = 0;
		int len = nums.length;
		mergeSort(nums, 0, (len-1));
		for(int i=0; i<len; i+=2) {
			sum += nums[i];
		}
		
		return sum;
		
	}
	
	public static void mergeSort(int[] nums, int p, int r) {
		int q;

		if(p<r) {
			q = (p+r)/2;
			mergeSort(nums, p, q);
			mergeSort(nums, q+1, r);
			
			mergeFunc(nums, p, q, r);
		}
		
	}
	
	public static void mergeFunc(int[] nums, int p, int q, int r) {
		
		int[] arrayNew = new int[(r-p+1)];
		for(int index=0; index<(arrayNew.length); index++) {
			arrayNew[index] = nums[p+index];
		}
		
		int i = 0;
		int j = q-p+1;
		
		for(int k=p; k<=r; k++) {
			if(i==(q-p+1)) {
				nums[k] = arrayNew[j];
				j++;
			} else if(j==(r-p+1)) {
				nums[k] = arrayNew[i];
				i++;
			} else if(arrayNew[i] >= arrayNew[j]) {
				nums[k] = arrayNew[j];
				j++;
			} else if(arrayNew[i] < arrayNew[j]) {
				nums[k] = arrayNew[i];
				i++;
			}
		}

	}

}
