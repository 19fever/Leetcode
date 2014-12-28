ass Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (size_t i = 0; i < n; i++) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > n || A[A[i] - 1] == A[i]) break;
                swap(A[i],A[A[i]-1]);
            }
        }

        for (size_t i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
