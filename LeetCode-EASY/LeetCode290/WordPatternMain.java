package Easy.LeetCode290;

import java.util.HashMap;

public class WordPatternMain {
    public static void main(String[] args) {
        String pattern = "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdd";
        String str = "s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s t t";
        System.out.println(wordPattern(pattern, str));

    }

    private static boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");

        HashMap map = new HashMap();

        if(pattern.length() != words.length) {
            return false;
        }

        for(Integer i=0; i<words.length; i++) {
            if((Integer)map.put(pattern.charAt(i), i) != (Integer)map.put(words[i], i)) {
                return false;
            }
        }

        return true;
    }
}
