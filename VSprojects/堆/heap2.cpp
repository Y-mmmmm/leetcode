#include <iostream>
#include <vector>

using namespace std;


class Solution {
    enum { MAXN = 10000 };
    int n;
    int heap[MAXN];
    
    inline int& getRef(int root) {
        return heap[root-1];
    }
public:
    Solution() : n(0) {}
    void push(int v) {
        heap[n++] = v;
        for(int pos = n, nextPos = pos>>1; pos > 1 
                && getRef(pos) > getRef(nextPos); pos = nextPos, nextPos >>= 1) {
            swap(getRef(pos), getRef(nextPos));
        }
    }
    int pop() {
       swap(getRef(1), getRef(n));
       int res = heap[--n];
       for(int root = 1; ; ) {
           int left = root<<1;
           int right = root<<1|1;
           if(right <= n && getRef(root) < max(getRef(left), getRef(right))) {
               if(getRef(left) > getRef(right)) {
                   swap(getRef(left), getRef(root));
                   root = left;
               } else {
                   swap(getRef(right), getRef(root));
                   root = right;
               }
           } else if (left <= n && getRef(root) < getRef(left)) {
                swap(getRef(left), getRef(root));
                root = left;
                break;
           } else {
               break;
           }
       }
       return res;
    }
    int size() const {
        return n;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        for(auto v : arr) {
            this->push(v);
            if(this->size() > k) {
                this->pop();
            }
        }
        
        return vector<int>(heap, heap+k);
    }
};


