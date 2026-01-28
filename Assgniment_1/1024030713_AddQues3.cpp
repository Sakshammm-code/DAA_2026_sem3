#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int findMedian(const vector<int>& arr, int start, int len) {
    vector<int> window;
    for (int i = 0; i < len; i++) {
        window.push_back(arr[start + i]);
    }
    sort(window.begin(), window.end());
    return window[len / 2];
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    cout << "Enter " << N << " integers: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int step = 0; step < N - 2; step++) {
        int minMedian = 2e9; 
        bool foundAny = false;

        for (int len = 3; len <= A.size(); len += 2) {
            for (int i = 0; i <= (int)A.size() - len; i++) {
                int currentMedian = findMedian(A, i, len);
                if (!foundAny || currentMedian < minMedian) {
                    minMedian = currentMedian;
                    foundAny = true;
                }
            }
        }
        if (foundAny) {
            for (auto it = A.begin(); it != A.end(); ++it) {
                if (*it == minMedian) {
                    A.erase(it);
                    break;
                }
            }
        }
    }
    long long sum = 0;
    for (int x : A) sum += x;
    
    cout << "Final sum of the 2 remaining elements: " << sum << endl;

    return 0;
}