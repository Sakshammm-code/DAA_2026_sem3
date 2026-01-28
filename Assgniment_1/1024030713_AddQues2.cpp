#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < N; right++) {
        while (A[right] - A[left] > 10) {
            left++;
        }
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    cout << "The maximum length of a good subsequence is: " << maxLength << endl;

    return 0;
}