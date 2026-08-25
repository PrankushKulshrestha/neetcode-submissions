class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root)
            return " ";
        queue<TreeNode*> next;
        next.push(root);
        string ans = "";
        int neighbor = 1;
        while(next.size()){
            TreeNode* cur = next.front();
            next.pop();
            if(!cur){
                ans += "#";
                continue;
            }
            ans += to_string(cur->val) + " ";
            next.push(cur->left);
            next.push(cur->right);
        }
        return ans;
    }
    TreeNode* helper(const string& data, int& idx){
        int i;
        TreeNode* cur = nullptr;
        int val = 0;
        bool is_neg = false;
        for(idx; idx < data.length(); idx ++){
            if(data[idx] == '#'){
                idx ++;
                break;
            }
            else if(data[idx] == ' '){
                val = (is_neg) ? -val : val;
                cur = new TreeNode(val);
                idx ++;
                break;
            }
            else if(data[idx] == '-')
                is_neg = true;
            else{
                val = val * 10 + (data[idx] - '0');
            }
        }
        return cur;
    }
    TreeNode* deserialize(string data) {
        if(data == " ")
            return nullptr;
        TreeNode* root;
        queue<TreeNode*> cur_root;
        int val = 0;
        int i = 0;
        bool is_neg = false;
        for(i ; i < data.length(); i ++){
            if(data[i] == ' '){
                val = (is_neg) ? -val : val;
                TreeNode* cur = new TreeNode(val);
                i ++;
                cur_root.push(cur);
                root = cur;
                break;
            }
            else if(data[i] == '-')
                is_neg = true;
            else{
                val = val * 10 + (data[i] - '0');
            }
        }
        while(cur_root.size()){
            TreeNode* cur = cur_root.front();
            cur_root.pop();
            cur->left = helper(data, i);
            if(cur->left)
                cur_root.push(cur->left);
            cur->right = helper(data, i);
            if(cur->right)
                cur_root.push(cur->right);
        }
        return root;
    }
};