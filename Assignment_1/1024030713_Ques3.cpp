#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int&b){
    int temp=a;
    a=b;
    b=temp;
}

void Quicksort(vector<int>& n,int low,int high){
    int pivot =high;
    int i=low,j=high-1;
    if(low<high){
        while(i<=j){
            if(n[i]>n[pivot]){
                swap(n[i],n[j]);
                j--;
            }
            else{
                i++;
            }
        }
    swap(n[pivot],n[i]);
    Quicksort(n,low,i-1);
    Quicksort(n,i+1,high);
    }
    
}

void display(vector<int>& num){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int> num= { 4, 2, 6, 9, 2 };

    display(num);

    Quicksort(num,0,num.size()-1);

    display(num);

}