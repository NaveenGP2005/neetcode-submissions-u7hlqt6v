class Codec {
public:

    // Splits by comma
    vector<string> split(string &data) {
        vector<string> result;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                result.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return result;
    }

    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "#,";
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;

        vector<string> tokens = split(data);

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            // LEFT
            if (tokens[i] != "#") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            // RIGHT
            if (i < tokens.size() && tokens[i] != "#") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
