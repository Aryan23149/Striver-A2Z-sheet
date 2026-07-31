public class TreeNode {
    Integer data;
    TreeNode left;
    TreeNode right;

    public TreeNode(Integer data) {
        this.data = data;
        this.left=null;
        this.right=null;
    }
    public void PreOrder(TreeNode t1){
        if(t1==null){
            return ;
        }
        System.out.printf(t1.data+" ");
        PreOrder(t1.left);
        PreOrder(t1.right);
    }
    public void PostOrder(TreeNode t1){
        if(t1==null){
            return ;
        }
        PostOrder(t1.left);
        PostOrder(t1.right);
        System.out.printf(t1.data+" ");
    }
    public void Inorder(TreeNode t1){
        if(t1==null){
            return ;
        }
        Inorder(t1.left);
        System.out.printf(t1.data+" ");
        Inorder(t1.right);
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.right = new TreeNode(5);
        root.PreOrder(root);
        System.out.println();
        root.PostOrder(root);
        System.out.println();
        root.Inorder(root);
        System.out.println();
    }
}