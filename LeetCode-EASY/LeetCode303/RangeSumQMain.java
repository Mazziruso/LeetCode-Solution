package Easy.LeetCode303;

public class RangeSumQMain {
    public static void main(String[] args) {
        int[] nums = {-2,0,3,-5,2,-1};
        NumArray obj = new NumArray(nums);
        System.out.println(obj.sumRange(2,5));
    }
}

class NumArray {
    int[] nums;

    public NumArray(int[] nums) {
        int n = nums.length;
        this.nums = new int[n];

        for(int i=0; i<n; i++) {
            this.nums[i] = nums[i];
        }
    }

    public int sumRange(int i, int j) {
        int sum = 0;

        for(int k=i; k<=j; k++) {
            sum += this.nums[k];
        }

        return sum;
    }
}
