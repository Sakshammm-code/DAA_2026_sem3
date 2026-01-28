#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch(vector<int>& n,int target){
    int low = 0,high = n.size()-1;
    int mid;
    while(low<=high){
        mid = low + ((high-low)/2);

        if(n[mid]==target){
            return true;
        }

        else if(n[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return false;
}

int main(){
    vector<int> num={2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    if(BinarySearch(num,23)){
        cout<<"Number found\n";
    }
    else{
        cout<<"Number not found\n";
    }
}