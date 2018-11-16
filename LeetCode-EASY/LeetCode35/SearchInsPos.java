package Easy.LeetCode35;

public class SearchInsPos {
    public static void main(String[] args) {

        int[] nums = {1, 3, 5, 6};

        System.out.println(searchInsert(nums, 0));

    }

    public static int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length-1;
        int mid = 0;

        while(start <= end) {
            mid = (start+end)/2;

            if(target == nums[mid]) {
                break;
            } else if(target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if(start > end) {
            return start;
        } else {
            return mid;
        }
    }
}
