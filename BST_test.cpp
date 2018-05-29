#include "BSTValidator.h"

typedef struct comp_int {
    bool operator ()(const& int t1, const& int t2) {
        return t1 > t2;
    }
};


int main() {
    BSTree<int, comp_int> bstree;    
    return 0;
}
