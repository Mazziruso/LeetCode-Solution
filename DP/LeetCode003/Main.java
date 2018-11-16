/*
DP+HashTable
O(128*N)
HashTable记录最长无重复子字符串中每个字母的下标，否则记录-1
当当前s[i]字符的hash值为-1，那说明与之前的子串无重复字母，直接修改它的hash并将记录长度+1
否则将HashTable中值小于hashTable[s[i]]的值全部清为-1，并重新修改记录的长度
*/
package Medium.LeetCode003;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("abcabcWY-Sb"));
    }
}

class Solution {
    private int hashABC[];
    public int lengthOfLongestSubstring(String s) {
        hashABC = new int[130];
        Arrays.fill(hashABC,-1);

        int maxL = 0;
        int longest = 0;
        int len = s.length();
        for(int i=0; i<len; i++) {
            if(hashABC[s.charAt(i)] >= 0) {
                longest = i-hashABC[s.charAt(i)];
                hashClear(hashABC[s.charAt(i)]);
            } else {
                longest = longest + 1;
            }
            hashABC[s.charAt(i)] = i;
            maxL = (maxL<longest) ? longest : maxL;
        }

        return maxL;
    }
    private void hashClear(int index) {
        for(int i=0; i<130; i++) {
            hashABC[i] = (hashABC[i]<index) ? -1 : hashABC[i];
        }
    }
}
