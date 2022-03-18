#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    private:
        vector<int> pq;
    public:
        MinHeap(){

        }
        bool isEmpty(){
            return pq.size() == 0;
        }
        int getSize(){
            // number of elements present in min heap
            return pq.size();
        }

        int getMin(){
            if(!isEmpty()) {
                return pq[0];
            }
                return -1; 
        }

        void insert(int ele){
            pq.push_back(ele);

            int childIndex = pq.size() - 1;
           

            while(childIndex > 0){
                int parentIndex = (childIndex - 1)/2;

                if(pq[childIndex] < pq[parentIndex]){
                    swap(pq[childIndex], pq[parentIndex]);
                }
                else{
                    break;
                }
                childIndex = parentIndex;
            }
        }

        int pop(){
            if(isEmpty()) return INT_MAX;

            int ans = pq[0];
            pq[0] = pq[pq.size() - 1];
            pq.pop_back();
            
            int parentIndex = 0;
            int leftChildIndex =  2*parentIndex + 1;
            int rightChildIndex = 2*parentIndex + 2;
            while(pq.size() > leftChildIndex){
                int minIndex = parentIndex;

                if(pq.size() > leftChildIndex && pq[minIndex] > pq[leftChildIndex]){
                    minIndex = leftChildIndex;
                }

                if(pq.size() > rightChildIndex && pq[minIndex] > pq[rightChildIndex]){
                    minIndex = rightChildIndex;
                }

                if(minIndex == parentIndex)
                    break;

                swap(pq[parentIndex], pq[minIndex]);
                parentIndex = minIndex;
                leftChildIndex =  2*parentIndex + 1;
                rightChildIndex = 2*parentIndex + 2;

            }
            return ans;

        }

        void print(){
            for(auto it : pq) cout << it << " ";
            cout << endl;
        }

    

};
int main() {

    MinHeap pq;
    
    int arr[] = {12, 6, 5, 100, 1, 9, 0, 14};


    for(int i = 0; i < 8; i++){
        pq.insert(arr[i]);
    }

    // cout << pq.getSize() << endl;
    

    pq.print();


    // cout << pq.pop() << endl;
    // cout << pq.pop() << endl;
    // cout << pq.pop() << endl;


    return 0;
}