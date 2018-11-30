package Hard.LeetCode45;

import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        SolutionBFS s = new SolutionBFS();

        int nums[] = {2,3,1,1,4};

        System.out.println(s.jump(nums));
    }
}

class SolutionBAG {
    private int dp[];

    public int jump(int nums[]) {
        int N = nums.length;
        dp = new int[N];

        Arrays.fill(dp,-1);

        //dynamic programming
        dp[0]=0; //initial
        for(int i=0;i<N;i++) {
            if(dp[i]==-1) { //the i cannot be arrived
                break;
            }
            for(int j=N-1;j>i;j--) {
                if(i+nums[i]>=j && (dp[i]+1<=dp[j] || dp[j]==-1)) {
                    dp[j]=dp[i]+1;
                }
            }
        }

        return dp[N-1];
    }
}

class SolutionGreedy {
    private int dp[];
    private int prev[];

    public int jump(int nums[]) {
        int N = nums.length;
        dp = new int[N];
        prev = new int[N];

        dp[0]=0; //initial
        prev[0]=0;
        int range = nums[0] + 0; //当前点所覆盖的距离
        int pre = prev[0];

        for(int i=1;i<N;i++) {
            if(i>range) {
                pre = prev[i - 1];
                range = nums[pre] + pre;
            }
            if(i>range) { //当前点无法到达
                break;
            }
            dp[i]=dp[pre]+1;
            if(nums[i]+i>nums[prev[i-1]]+prev[i-1]) {
                prev[i] = i;
            } else {
                prev[i]=prev[i-1];
            }
        }
        return dp[N-1];
    }
}

class SolutionDijkstra {
    private boolean visit[];
    private int dist[];

    class qbase {
        int id;
        int dist;
        public qbase(int id, int dist) {
            this.id=id;
            this.dist=dist;
        }
        public qbase() {
            this(0,0);
        }
    }

    public int jump(int nums[]) {
        //init
        int N = nums.length;
        visit = new boolean[N];
        dist = new int[N];
        Arrays.fill(dist,Integer.MAX_VALUE);
        Arrays.fill(visit,false);

        qbase node = new qbase();

        PriorityQueue<qbase> q = new PriorityQueue<>(N,idComparator);

        node.id = 0;
        node.dist = 0;
        dist[0] = 0;
        q.offer(node);
        while(!q.isEmpty()) {
            node = q.poll();
            if(visit[node.id]) {
                continue;
            }
            visit[node.id]=true;
            for(int i=node.id+1;(i<N && i<=node.id+nums[node.id]);i++) {
                if(!visit[i] && dist[i]>dist[node.id]+1) {
                    dist[i] = dist[node.id]+1;
                    q.offer(new qbase(i,dist[i]));
                }
            }
        }
        return dist[N-1];
    }

    private Comparator<qbase> idComparator = new Comparator<qbase>() {
        @Override
        public int compare(qbase q1, qbase q2) {
            return (int) (q1.dist-q2.dist);
        }
    };
}

class SolutionBFS {
    private int dist[];
    public int jump(int nums[]) {

        int N = nums.length;
        //init
        dist = new int[N];
        Arrays.fill(dist,0);

        ArrayDeque<Integer> q = new ArrayDeque<>(N);
        int node;

        q.addLast(0);
        dist[0] = 0;
        int maxNode=0;
        while(!q.isEmpty()) {
            node = q.pollFirst();
            if(node>=N) {
                break;
            }
            for(int i=maxNode+1;(i<N && i<=node+nums[node]);i++) {
                q.addLast(i);
                dist[i] = dist[node] + 1;
                maxNode = (maxNode < i) ? i : maxNode;
            }
        }
        return dist[N-1];
    }
}