#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<int>& A, int N, int M, int maxAllowedOr) {
    int segments = 1;
    int currentOr = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] | maxAllowedOr) > maxAllowedOr) {
            return false;
        }

        if ((currentOr | A[i]) <= maxAllowedOr) {
            currentOr |= A[i];
        } else {
            segments++;
            currentOr = A[i];
        }
    }
    return segments <= M;
}

int solve() {
    int N, M;
    cout<<"Enter the values of N and M : \n";
    if (!(cin >> N >> M)) return 0;

    vector<int> A(N);
    int maxOrSum = 0;
    cout<<"Enter the array elements : \n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxOrSum |= A[i];
    }

    int low = 0, high = maxOrSum;
    int result = maxOrSum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    cout << solve() << endl;
    return 0;
}