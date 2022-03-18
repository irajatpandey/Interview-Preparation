#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    private:
        vector<int> pq;
    public:
        bool isEmpty(){return pq.size() == 0;}
        int getSize(){return pq.size();}
        void insert(int x){
            pq.push_back(x);
            int childIndex = pq.size() - 1;
   
        
            while(childIndex > 0){
                int parentIndex = (childIndex - 1)/2;
                if(pq[parentIndex] < pq[childIndex]){
                    swap(pq[parentIndex], pq[childIndex]);
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
            int leftIndex = 2 * parentIndex + 1;
            int rightIndex = 2 * parentIndex + 2;
            int maxIndex = parentIndex;

            while(1){
                if(leftIndex < pq.size() && pq[maxIndex] < pq[leftIndex]){
                    maxIndex = leftIndex;
                }

                if(rightIndex < pq.size() && pq[maxIndex] < pq[rightIndex]){
                    maxIndex = rightIndex;
                }

                if(parentIndex == maxIndex){
                    break;
                }
                swap(pq[maxIndex], pq[parentIndex]);
                parentIndex = maxIndex;
                leftIndex = 2 * parentIndex + 1;
                rightIndex = 2 * parentIndex + 2;

            }


            return ans;
        }
        void print(){
            for(auto it : pq) cout << it << " ";
            cout << endl;
        }


};
int main() {

    MaxHeap pq;
     int arr[] = {12, 6, 5, 100, 1, 9, 0, 14};


    for(int i = 0; i < 8; i++){
        pq.insert(arr[i]);
    }

    pq.print();

    //  cout << pq.pop() << endl;

     while(!pq.isEmpty()){
         cout << pq.pop() << " ";

     }

    return 0;
}