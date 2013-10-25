#include <stdio.h>
#include <string.h>

#define NMAX 6

int isValidSudoku(int N)
{
    int N2 = N*N;
    int table[NMAX*NMAX][NMAX*NMAX];
    char checkrow[NMAX*NMAX + 1];
    char checkcol[NMAX*NMAX][NMAX*NMAX + 1];
    char checkblock[NMAX][NMAX][NMAX*NMAX + 1];
    int i, j;
    for (i = 0; i < N2; i++) /* read table */
        for (j = 0; j < N2; j++)
            scanf("%d", &table[i][j]);

    memset(checkcol, 0, sizeof checkcol);
    memset(checkblock, 0, sizeof checkblock);
    for (i = 0; i < N2; i++) { /* check */
        memset(checkrow, 0, N2 + 1); // reserve check[0]
        for (j = 0; j < N2; j++) {
            int n = table[i][j];
            if (n >= 1 && n <= N2       // is valid number
                    && !checkrow[n]     // check row
                    && !checkcol[j][n]  // check column
                    && !checkblock[i/N][j/N][n]) { // check block
                checkrow[n] = checkcol[j][n] 
                            = checkblock[i/N][j/N][n] = 1;
            }
            else
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T, iT;
    scanf("%d", &T);
    for (iT = 1; iT <= T; ++iT) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: %s\n", iT,
            isValidSudoku(N) ? "Yes" : "No");
    }
}
