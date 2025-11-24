#include <iostream>
using namespace std;

int main() {
    int rows, cols, n;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    int a[20][3];  // original sparse matrix (triplet form)
    int t[20][3];  // transpose matrix (triplet form)

    // Header: (rows, cols, non-zero count)
    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = n;

    cout << "\nEnter elements as (row column value) using 0-based index.\n";
    cout << "Example for 2x2 matrix: 0 1 5 means element at row 0, col 1 = 5\n\n";

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2]; // row, col, value
    }

    // ---- SIMPLE TRANSPOSE: just swap row and column for each element ----
    t[0][0] = cols;  // new rows = old cols
    t[0][1] = rows;  // new cols = old rows
    t[0][2] = n;     // same number of non-zero elements

    for (int i = 1; i <= n; i++) {
        t[i][0] = a[i][1]; // new row  = old col
        t[i][1] = a[i][0]; // new col  = old row
        t[i][2] = a[i][2]; // value stays same
    }

    // ---- PRINT ORIGINAL ----
    cout << "\nSparse Matrix (Triplet Form):\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i][0] << "  " << a[i][1] << "  " << a[i][2] << endl;
    }

    // ---- PRINT TRANSPOSE ----
    cout << "\nTranspose Matrix (Triplet Form):\n";
    for (int i = 0; i <= n; i++) {
        cout << t[i][0] << "  " << t[i][1] << "  " << t[i][2] << endl;
    }

    return 0;
}
