//Let minq (a, b)(“range minimum query”) denote the minimum array value in a range [a, b]. 

//This a technique using which we can process any minimum query in O(1) time after an O(n log n) time preprocessing.

//The method is due to Bender and Farach-Colton  and often called the sparse table algorithm.


const int k = 16;
const int N = 1e5;
const int ZERO = 0; // ZERO + x = x + ZERO = x (for any x)

long long table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> Arr[i];

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        long long answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = answer + table[L][j];
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }
    return 0;
}
