package Hard.LeetCode004;


public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int nums1[] = {};
        int nums2[] = {2};
        System.out.println(s.findMedianSortedArrays(nums1, nums2));
    }
}

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int i;
        int j;
        int maxLeft;
        int minRight;
        if(m>n) {
            int[] tmp = nums1;
            nums1= nums2;
            nums2 = tmp;
            int temp = m;
            m = n;
            n = temp;
        }
        i = binarySearch(nums1,nums2);
        j = (m+n+1)/2-i;

        maxLeft = (i==0) ? nums2[j-1] : (j==0) ? nums1[i-1] : Math.max(nums1[i-1], nums2[j-1]);

        if((m+n)%2==1) {
            return maxLeft;
        }

        minRight = (i==m) ? nums2[j] : (j==n) ? nums1[i] : Math.min(nums1[i], nums2[j]);


        return (maxLeft + minRight) / 2.0;
    }
    private int binarySearch(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        int l = 0;
        int r = m; //

        int i = (l + r) / 2;
        int j = (m+n+1)/2-i;
        while(l<=r) {
            if(i>0 && A[i-1]>B[j]) {
                r = i-1;
            } else if(i<m && A[i]<B[j-1]) {
                l = i+1;
            } else {
                break;
            }
            i = (l+r)/2;
            j = (m+n+1)/2-i;
        }
        return i;
    }
}
