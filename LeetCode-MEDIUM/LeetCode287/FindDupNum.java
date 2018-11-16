package Medium.LeetCode287;

public class FindDupNum {
    public static void main(String[] args) {
        int[] nums = {1, 2, 2, 3, 4};
        System.out.println(findDuplicate(nums));

    }

    public static int findDuplicate(int[] nums) {
        int n = nums.length-1;

        int low = 1;
        int high = n;

        int mid = 0;
        int count = 0;

        while(low < high) {
            mid = (low + high) / 2;
            count = 0;

            for(int i=0; i<=n; i++) {
                if(nums[i] <= mid) {
                    count++;
                }
            }

            if(count > mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}
