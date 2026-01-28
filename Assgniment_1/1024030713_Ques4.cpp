#include <iostream>
#include <vector>

using namespace std;


int MaxSubarraySum(vector<int>& num){
    int max_so_far = -1e9;
    int curr_max=0;
    for(auto&x : num){
        curr_max=(x+curr_max >= x) ? x+curr_max : x ;
        if(curr_max > max_so_far){
            max_so_far=curr_max;
        }
    }
    return max_so_far;
}

int main(){
    vector<int> n = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << MaxSubarraySum(n) << endl; 
    return 0;
}

