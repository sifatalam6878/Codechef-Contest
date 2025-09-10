#include <iostream>
#include <vector>
using namespace std;

bool canTransform(const vector<int>& A, const vector<int>& B, int N) {
    // Check the condition for each index.
    for (int i = 0; i < N; ++i) {
        // If A[i] is 0, then B[i] must also be 0
        if (A[i] == 0 && B[i] == 1) {
            return false;  // Impossible to turn 0 into 1
        }
    }
    return true;
}

int main() {
    int T;  // Number of test cases
    cin >> T;
    
    while (T--) {
        int N;  // Size of arrays
        cin >> N;
        
        vector<int> A(N), B(N);
        
        // Input for array A
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // Input for array B
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        // Apply the transformation check
        if (canTransform(A, B, N)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
