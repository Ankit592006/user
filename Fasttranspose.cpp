#include <iostream>
using namespace std;

int main() {
    int rows, cols, n;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    int a[50][3], t[50][3], count[50] = {0}, start[50];

    // original sparse matrix header
    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = n;

    cout << "\nEnter non-zero elements (row column value):\n";
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    // FAST TRANSPOSE HEADER
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = n;

    // Step 1: count how many elements in each column of original
    for (int i = 1; i <= n; i++)
        count[a[i][1]]++;

    // Step 2: calculate start position
    start[0] = 1;
    for (int i = 1; i < cols; i++)
        start[i] = start[i - 1] + count[i - 1];

    // Step 3: place in FAST transpose (may shuffle)
    for (int i = 1; i <= n; i++) {
        int col = a[i][1];
        int pos = start[col];

        t[pos][0] = a[i][1];
        t[pos][1] = a[i][0];
        t[pos][2] = a[i][2];

        start[col]++;
    }

    // -----------------------------------------------
    // 🔥 NOW KEEP ORIGINAL POSITION INDEXING:
    //     (no shuffle, no change of line number)
    // -----------------------------------------------
    int finalT[50][3];
    finalT[0][0] = cols;
    finalT[0][1] = rows;
    finalT[0][2] = n;

    for (int i = 1; i <= n; i++) {
        int old_r = a[i][0];
        int old_c = a[i][1];
        int old_v = a[i][2];

        finalT[i][0] = old_c;   // swap row/col
        finalT[i][1] = old_r;
        finalT[i][2] = old_v;
    }

    // PRINT ORIGINAL
    cout << "\nSparse Matrix (Triplet Form):\n";
    for (int i = 0; i <= n; i++)
        cout << a[i][0] << "  " << a[i][1] << "  " << a[i][2] << endl;

    // PRINT FAST TRANSPOSE (BUT WITHOUT SHUFFLING POSITION)
    cout << "\nFast Transpose Matrix (Triplet Form):\n";
    for (int i = 0; i <= n; i++)
        cout << finalT[i][0] << "  " << finalT[i][1] << "  " << finalT[i][2] << endl;

    return 0;
}
