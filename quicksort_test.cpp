#include <vector>
#include <iostream>
#include "gen_quicksort.h"

typedef struct {
    bool operator() (const int a, const int b) {
        return a < b;
    };
} intcmp;

typedef struct {
    bool operator() (const std::string& str1, const std::string& str2) {
        return str1 < str2;
    }
} strcmpf;

strcmpf str_cmp;
intcmp int_cmp;

int main() {
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    QuickSort<int, std::vector<int>::iterator, intcmp> qs(vec.begin(), vec.end(), int_cmp);
    qs.sort();
    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl; 

    std::vector<std::string> vecs;
    vecs.push_back("golden");
    vecs.push_back("final");
    vecs.push_back("finally");
    QuickSort<std::string, std::vector<std::string>::iterator, strcmpf> qsstr(vecs.begin(), vecs.end(), str_cmp);
    qsstr.sort();
    for(std::string str : vecs) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}
