package Easy.LeetCode437;

public class PathSumTree {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(-3);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(2);
        root.right.right = new TreeNode(11);
        root.left.left.left = new TreeNode(3);
        root.left.left.right = new TreeNode(-2);
        root.left.right.right = new TreeNode(1);

        System.out.println(pathSum(root, 8));

    }

    public static int pathSum(TreeNode root, int sum) {
        if(root != null) {
            int count = 0;

            count += preorder(root, sum, 0);

            count += pathSum(root.left, sum);
            count += pathSum(root.right, sum);

            return count;
        }

        return 0;
    }

    private static int preorder(TreeNode Node, int target, int sum) {
        if(Node != null) {
            int count = 0;
            sum += Node.val;

            count += preorder(Node.left, target, sum);
            count += preorder(Node.right, target, sum);

            if(sum == target) {
                return (count+1);
            } else {
                return count;
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
