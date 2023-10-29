// write a c program to do matrix chain multiplication using dynamic programming
#include <stdio.h>
#include <limits.h>

void printParenthesis(int i, int j, int parenth[][j + 1]) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printParenthesis(i, parenth[i][j], parenth);
        printParenthesis(parenth[i][j] + 1, j, parenth);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int dp[n][n];
    int parenth[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        parenth[i][i] = i;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int subResult = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (subResult < dp[i][j]) {
                    dp[i][j] = subResult;
                    parenth[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications required: %d\n", dp[0][n - 1]);
    printf("Matrix M dimensions: %d x %d\n", p[n-1], p[n-1]);
    printf("Matrix S dimensions: %d x %d\n", p[n-1], p[n-1]);
    printf("Optimal Parenthesization: ");
    printParenthesis(0, n - 1, parenth);
    printf("\n");
    return 0;
}
