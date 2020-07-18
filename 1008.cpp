/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> slicing(vector<int>& arr, int X, int Y) 
    { 
        // Starting and Ending iterators 
        auto start = arr.begin() + X; 
        auto end = arr.begin() + Y + 1; 

        // To store the sliced vector 
        vector<int> result(Y - X + 1); 

        // Copy vector using copy function() 
        copy(start, end, result.begin()); 

        // Return the final sliced vector 
        return result; 
    } 
    
    TreeNode* createTree(int low, int high, vector<int>& preorder) {
        cout << "low : " << low << " high : " << high << endl;
        if (low > high || low < 0 || high < 0 || high >= preorder.size() || low >= preorder.size())
            return nullptr;
        
        if ((high-low+1) == 0)
             return nullptr;
        else if ((high-low+1) == 1) {
            TreeNode* node = new TreeNode(preorder[low]);
            return node;
        }
        
        TreeNode* root = new TreeNode(preorder[low]);
        
        int partition = low;
        while (partition <= high && preorder[partition] <= preorder[low]) {
            partition++;
        }
        cout << partition << endl;
        for (int i = low ; i <= high; i++) 
            cout << preorder[i] << " ";
        cout << endl;
        
        low++;
        root->left = createTree(low, partition-1, preorder);
        root->right = createTree(partition, high, preorder);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
             return nullptr;
        else if (preorder.size() == 1) {
            TreeNode* node = new TreeNode(preorder[0]);
            return node;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int partition = 0;
    
        while (partition < preorder.size() && preorder[partition] <= preorder[0]) {
            partition++;
            cout << partition << endl;
        }
        cout << partition << endl;
        for (auto x: preorder)
            cout << x << " ";
        cout << endl;
        
        root->left = createTree(1, partition-1, preorder);
        root->right = createTree(partition, preorder.size()-1, preorder);
                                      
        return root;
        
    }
};