#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class heap
{
    // max heap
private:
    vector<int> v;
    int size;
    

public:
    heap(){
        v.push_back(-1);
        size=0;
    }
    void insert(int x)
    {
       int c,p;
       if(v.size()>=size){
        v.push_back(x);
        size=v.size;
       }
       else{
        size=size+1;
        v[size]=x;
       }
       c=size;
        

        bool ordered = v[p] > v[c];
        while (c > 1)
        {
            p = c / 2;
            if (v[p] > v[c])
            {
                return;
            }
            else
            {
                swap(v[p], v[c]);
                c = p;
            }
        }
    }
    void delete(){
        if(size==0){
            cout<<"nothing to delete";
        }
        //delete root
        v[1]=v[size];
        ///remove last node;
        //lchild 2*parent
        v.pop_back();
        size--;;
        int parent=1;
        while(parent<=size){
            if(v[parent]>v[2*parent]&&v[parent]>v[(2*parent)+1]){
                return;
            }
            else if(v[parent]<v[2*parent]){
                swap(v[parent],v[2*parent]);
                parent=2*parent;
            }
            else{
                swap(v[parent],v[(2*parent)+1]);
                parent=(2*parent)+1;
            }

        }


    }


} int main()
{
    vector<int> v;
    
}