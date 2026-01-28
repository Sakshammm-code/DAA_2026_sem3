#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void display(vector<int>& num){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<"  ";
    }
    cout<<endl;
}
void merge(vector<int>& num,int p , int q ,int r){
    int size1=(q-p)+1;
    int size2=(r-q);

    vector<int> L(size1);
    vector<int> R(size2);

    for(int i=0;i<L.size();i++){
        L[i]=num[p+i];
    }
    for(int i=0;i<R.size();i++){
        R[i]=num[q+i+1];
    }

    int k=p;
    int i=0,j=0;
    while(i<size1 && j<size2 ){
        if(L[i]>=R[j]){
            num[k++]=R[j++];
            
        }
        else{
            num[k++]=L[i++];
        }
    }
    while(i<size1){
        num[k++]= L[i++];
    }
    while(j<size2){
        num[k++]=R[j++];
    }

}
void MergeSort(vector<int>& num,int p ,int r){
    if(p<r){
        int q = p + ((r-p)/2) ;
        MergeSort(num,p,q);
        MergeSort(num,q+1,r);
        merge(num,p,q,r);
    }
    else{
        return;
    }
}

int main(){
    vector<int> n ={2,6,4,1,8,5};
    display(n);
    MergeSort(n,0,5);
    display(n);

    vector <int> r ={38,27,43,3,9,82,10};
    display(r);
    MergeSort(r,0,r.size()-1);
    display(r);
}