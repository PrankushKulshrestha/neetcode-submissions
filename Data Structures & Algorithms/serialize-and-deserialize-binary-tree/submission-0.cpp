class Codec {
public:
    void serializeHelper(TreeNode* root, string& res) {
        if (!root) {
            res += "N,";
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    TreeNode* deserializeHelper(string& data, int& i) {
        int j = data.find(',', i);
        string value = data.substr(i, j - i);
        i = j + 1;
        if (value == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = deserializeHelper(data, i);
        root->right = deserializeHelper(data, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializeHelper(data, i);
    }
};