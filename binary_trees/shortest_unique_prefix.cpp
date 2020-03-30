/*
Find shortest unique prefix to represent each word in the list.
Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.
*/
class Node {
    public:
    char val;
    int count;
    vector<Node*> child;
    Node(char x) {
        val = x;
        count = 0;
        child.resize(26);
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
 
void insert(Node*& root, const string& word, int i) {
    if (i >= word.size()) return;
    int cur = word[i] - 'a';
    if (root->child[cur] == NULL) root->child[cur] = new Node(word[i]);
    (root->child[cur])->count++;
    insert(root->child[cur], word, i + 1);
    return;
}
 
string find(Node* root, const string& word, int i) {
    if (i >= word.size()) return "";
    int cur = word[i] - 'a';
    string ans;
    ans.push_back(word[i]);
    if ((root->child[cur])->count == 1) return ans;
    if (i == word.size() - 1) return ans;
    return ans + find(root->child[cur], word, i + 1);
}
 
vector<string> Solution::prefix(vector<string> &A) {
    if (A.size() == 0){
        vector<string> v(0);
        return v;
    }
    Node* root = new Node('a');
    for (int i = 0; i < A.size(); i++) {
        insert(root, A[i], 0);
    }
    vector<string> ans(A.size());
    for (int i = 0; i < A.size(); i++) {
        ans[i] = find(root, A[i], 0);
    }
    return ans;
}
