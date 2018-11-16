package Easy.LeetCode111;

public class MinimumDepthMain {
    public static void main(String[] args) {
//        TreeNode root = new TreeNode(3);
//        root.left = new TreeNode(9);
//        root.right = new TreeNode(20);
//        root.right.left = new TreeNode(15);
//        root.right.right = new TreeNode(7);

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);

        System.out.println(minDepth(root));

    }

    private static int minDepth(TreeNode root) {
        if(root != null) {
            int depthLeft = minDepth(root.left);
            int depthRight = minDepth(root.right);

            if(depthLeft==0) {
                return depthRight+1;
            } else if(depthRight == 0) {
                return depthLeft+1;
            }

            if(depthLeft >= depthRight) {
                return depthRight+1;
            } else {
                return depthLeft+1;
            }
        }

        return 0;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {
        this.val = x;
    }
}
