/*
与题300相似
先对envelopes进行排序（以w和h递增进行排序），使得后续的DP操作可以按序进行而不破坏最优子结构
dp[i]是一个存放envelop的动态数组，保存着所有信封数量i的信封子序的后缀
对于每个env，通过二分搜索找到dp[index-1]<env<=dp[index]的index，将env压入dp[index]中
其中env>dp[index-1]要满足env只要能够装入这动态数组中任意一个信封即可
最后返回的len即是最大可装信封数
*/
package Hard.LeetCode354;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        Solution s = new Solution();
//        int[][] envelopes = {{5,4},{6,7},{2,3},{6,1},{6,2},{6,3},{7,2},{7,3},{8,3},{9,4}};
        int[][] envelopes = {{1,1}};
        System.out.println(s.maxEnvelopes(envelopes));
    }
}

class Solution {
    boolean flag = false; //true means env is equal to dp[index]
    private ArrayList<Envelop> dp[];
    public int maxEnvelopes(int[][] envelopes) {
        int N = envelopes.length;
        Envelop env[] = new Envelop[N];
        for(int i=0; i<N; i++) {
            env[i] = new Envelop(envelopes[i][0], envelopes[i][1]);
        }
        Arrays.sort(env);
        //DP
        int index;
        int len = 0;
        dp = new ArrayList[N+1];
        for(int i=0; i<N+1; i++) {
            dp[i] = new ArrayList<Envelop>();
        }
        for(int i=0; i<N; i++) {
            index = binarySearch(1,len,env[i]);
            if(!flag) {
                dp[index].add(env[i]);
            }
            len = (index>len) ? (len+1) : len;
        }
        return len;
    }
    private int binarySearch(int s, int e, Envelop env) {
        int l = s;
        int r = e;
        int mid;
        int cmp;
        flag = false;
        while(l<=r) {
            mid = (l+r)/2;
            cmp = compareEnv(mid, env);
            if(cmp == 0) {
                flag = true;
                return mid;
            } else if(cmp > 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    private int compareEnv(int index,Envelop env) {
        for(Envelop tmp : dp[index]) {
            if(env.w==tmp.w && env.h==tmp.h) {
                return 0;
            } else if(env.w>tmp.w && env.h>tmp.h) {
                return -1;
            }
        }
        return 1;
    }

}

class Envelop implements Comparable<Envelop> {
    int w;
    int h;
    public Envelop(int w, int h) {
        this.w = w;
        this.h = h;
    }
    public Envelop() {
        this(0,0);
    }
    public int compareTo(Envelop o) {
        if(this.w==o.w) {
            return Integer.compare(this.h, o.h);
        } else {
            return Integer.compare(this.w, o.w);
        }
    }
}
