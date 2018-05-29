#include <stack>

template <typename T>
struct Node {
    Node* left;
    Node* right;
    T val;
    Node(const T& v) : val(v), left(nullptr), right(nullptr) {}
};

template <typename T, typename F>
//requires F to be comparator obj for Node<T>
class BSTree {
private:
    Node<T>* root;
    F func;
public:
    typedef Node<T>* node_ptr;
    typedef F comp_f;
    BSTree(F func) : root(nullptr), func(func) {}
    void addNode(const T& val);
};

template <typename BST_o>
class BSTIterator {
private:
    typedef typename BST_o::comp_f cpm_fun;
    const BST_o* bst;
    std::stack<typename BST_o::node_ptr> stk;
public:
    BSTIterator(const BST_o& bst) : bst(&bst) {}
};

template <typename T, typename F>
void BSTree<T, F>::addNode(const T& val) {
    node_ptr np = new Node<T>(val);
    if(root == nullptr) {
        root = np;
        return;
    }
    node_ptr tp = root;
    node_ptr par_np = root;
    while(tp != nullptr) {
        par_np = tp;
        if(func(np, tp)) {
            tp = tp->right;
        } else {
            tp = tp->left;
        }
    }
    if(func(np, tp)) {
        tp->right = np;
    } else {
        tp->left = np;
    }
}


