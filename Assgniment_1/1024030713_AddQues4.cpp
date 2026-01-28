#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSpecial(int idx, int k, int n, const vector<int>& A) {
    vector<int> greaterIndices;
    

    for (int i = 0; i < n; i++) {
        if (A[i] > A[idx]) {
            greaterIndices.push_back(i);
        }
    }

    if (greaterIndices.size() < k) return false;

    for (int start = 0; start <= (int)greaterIndices.size() - k; start++) {
        int end = start + k - 1;

        int leftBoundary = (start == 0) ? 0 : greaterIndices[start - 1] + 1;
        int rightBoundary = (end == (int)greaterIndices.size() - 1) ? n - 1 : greaterIndices[end + 1] - 1;

        int L_max = min(idx, greaterIndices[start]);
        int R_min = max(idx, greaterIndices[end]);

        if (L_max >= leftBoundary && R_min <= rightBoundary) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, k;
    cout << "Enter the length of sequence (n): ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> A(n);
    cout << "Enter the " << n << " elements of the sequence:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long specialtySum = 0;
    for (int i = 0; i < n; i++) {
        if (isSpecial(i, k, n, A)) {
            specialtySum += A[i];
        }
    }

    cout << "The specialty of the sequence is: " << specialtySum << endl;

    return 0;
}