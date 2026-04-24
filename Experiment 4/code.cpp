#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long sumBitDifferences(vector<int>& A) {
    int n = A.size();
    long long ans = 0;


    for (int bit = 0; bit < 31; bit++) {
        long long countSet = 0;


        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit)) {
                countSet++;
            }
        }


        long long pairs = countSet * (n - countSet);

        ans = (ans + pairs) % MOD;
    }


    ans = (ans * 2) % MOD;

    return ans;
}

int main() {
    vector<int> A = {1, 3, 5};
    cout << sumBitDifferences(A) << endl;
    return 0;
}
