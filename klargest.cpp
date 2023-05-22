#include <queue>
#include <vector>
using namespace std;

int kth_largest(vector<int> values, int k){
    priority_queue<int, vector<int>, greater<int>> pri_queue;

    for (int i : values) {
        pri_queue.push(i);
    
        if (pri_queue.size() > k) {
            pri_queue.pop();
        }
    }
    return pri_queue.top();
}