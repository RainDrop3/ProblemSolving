#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int> maxheap;
    priority_queue<int> minheap;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;

        if(maxheap.size() == minheap.size())
            maxheap.push(num);
        else
            minheap.push(-num);

        if(!maxheap.empty() && !minheap.empty()){
            if(maxheap.top() > -minheap.top()){
                int maxi = maxheap.top();
                int mini = -minheap.top();

                maxheap.pop();
                minheap.pop();

                maxheap.push(mini);
                minheap.push(-maxi);
            }
        }
        cout << maxheap.top() << '\n';
    }
}