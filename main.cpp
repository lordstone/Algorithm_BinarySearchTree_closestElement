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

    static vector<int> findClosestKValue(int n, int k, TreeNode * root){
        vector<int> res;
        if(root == NULL) return res;
        queue<int> myQ;
        stack<TreeNode*> mystk;
        while(!mystk.empty() || root != NULL){
            while(root){
                mystk.push(root);
                root = root -> left;
            }
            if(!mystk.empty()){
                root = mystk.top();
                mystk.pop();
                if(myQ.size() < k){
                    myQ.push(root -> val);
                }else{
                    if(abs(n - root -> val) < abs( n - myQ.front())){
                        myQ.pop();
                        myQ.push(root -> val);
                    }else{
                        break;
                    }
                }
                root = root -> right;
            }
        }
        while(!myQ.empty()){
            res.push_back(myQ.front());
            myQ.pop();
        }
        return res;
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
        cout << "=========================" << endl;
        vector<int> resCase1 = binarySearchTree::findClosestKValue(44,3,i);
        for(auto &i : resCase1){
            cout << i << " ";
        }
        cout << endl;
        vector<int> resCase2 = binarySearchTree::findClosestKValue(88,5,i);
        for(auto &i : resCase2){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
