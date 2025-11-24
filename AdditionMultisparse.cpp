#include <iostream>
using namespace std;

int main() {
    int r, c, n1, n2;

    // Matrix A
    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;
    cout << "Enter number of non-zero elements in A: ";
    cin >> n1;

    int A[n1][3];   // triple format
    cout << "Enter A (row col value):\n";
    for (int i = 0; i < n1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    // Matrix B
    cout << "Enter number of non-zero elements in B: ";
    cin >> n2;

    int B[n2][3];
    cout << "Enter B (row col value):\n";
    for (int i = 0; i < n2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    // ----- ADDITION -----
    int C[30][3], k = 0;
    for (int i = 0; i < n1; i++)
        C[k][0] = A[i][0], C[k][1] = A[i][1], C[k][2] = A[i][2], k++;

    for (int i = 0; i < n2; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (B[i][0] == C[j][0] && B[i][1] == C[j][1]) {
                C[j][2] += B[i][2];
                found = true;
                break;
            }
        }
        if (!found)
            C[k][0] = B[i][0], C[k][1] = B[i][1], C[k][2] = B[i][2], k++;
    }

    cout << "\nAddition Result (row col value):\n";
    for (int i = 0; i < k; i++)
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;

    // ----- MULTIPLICATION -----
    int D[30][3], p = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i][1] == B[j][0]) {  // column of A = row of B
                D[p][0] = A[i][0];
                D[p][1] = B[j][1];
                D[p][2] = A[i][2] * B[j][2];
                p++;
            }
        }
    }

    cout << "\nMultiplication Result (row col value):\n";
    if (p == 0)
        cout << "No non-zero values after multiplication";
    else
        for (int i = 0; i < p; i++)
            cout << D[i][0] << " " << D[i][1] << " " << D[i][2] << endl;

    return 0;
}
