class binarySearchTree{
public:
    static int findClosestBSTValue(int n, TreeNode * root){
        if(root == NULL) return INT_MAX;
        int mynum = root -> val;
        TreeNode * cur = root;
        int diff = INT_MAX;
        while(cur != NULL){
            if(cur -> val == n){
                return n;
            }
            if(abs(n - (cur -> val)) <= diff){
                mynum = cur -> val;
                diff = abs(mynum - n);
            }
            if(cur -> val > n){
                cur = cur -> left;
            }else if(cur -> val < n){
                cur = cur -> right;
            }
        }
        return mynum;
    }

    static vector<TreeNode*> generateBSTs(){
        vector<TreeNode*> testCases;
        TreeNode * case1 = new TreeNode(50);
        case1 -> left = new TreeNode (30);
        case1 -> right = new TreeNode (70);
        case1 -> left -> right = new TreeNode (40);
        case1 -> right -> left = new TreeNode (60);
        case1 -> left -> left = new TreeNode (10);
        case1 -> right -> right = new TreeNode (90);

        testCases.push_back(case1);
        return testCases;
    }
};


int main(){

    vector<TreeNode*> testCases = binarySearchTree::generateBSTs();
    for(auto &i : testCases){
        cout << binarySearchTree::findClosestBSTValue(44,i) << endl;
        cout << binarySearchTree::findClosestBSTValue(144,i) << endl;
        cout << binarySearchTree::findClosestBSTValue(28,i) << endl;
        cout << binarySearchTree::findClosestBSTValue(60,i) << endl;
        cout << binarySearchTree::findClosestBSTValue(59,i) << endl;
        cout << binarySearchTree::findClosestBSTValue(89,i) << endl;
    }
    return 0;
}
