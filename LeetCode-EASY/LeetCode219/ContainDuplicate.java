package Easy.LeetCode219;

import java.util.HashMap;

public class ContainDuplicate {
    public static void main(String[] args) {
        int[] nums = {1,2,3,1};
        System.out.println(containsNearbyDuplicate(nums, 3));
    }

    private static boolean containsNearbyDuplicate(int[] nums, int k) {

        if(nums.length <= 1) {
            return false;
        }

        HashMap<Integer, Integer> numsMap = new HashMap<>();
        for(int i=0; i<nums.length; i++) {
            if(numsMap.containsKey(nums[i]) && (Math.abs(i - numsMap.get(nums[i]))<=k)) {
                return true;
            }

            numsMap.put(nums[i], i);
        }

        return false;
    }
}
