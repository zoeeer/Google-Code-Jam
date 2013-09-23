/* Problem C. Sorting
 *
 * Alex and Bob are brothers and they both enjoy reading very much. 
 * They have widely different tastes on books so they keep their 
 * own books separately. However, their father thinks it is good 
 * to promote exchanges if they can put their books together. Thus 
 * he has bought an one-row bookshelf for them today and put all 
 * his sons' books on it in random order. He labeled each position 
 * of the bookshelf the owner of the corresponding book ('Alex' or 'Bob').
 *
 * Unfortunately, Alex and Bob went outsi??de and didn't know what
 * their father did. When they were back, they came to realize the
 * problem: they usually arranged their books in their own orders, 
 * but the books seem to be in a great mess on the bookshelf now. 
 * They have to sort them right now!!
 *
 * Each book has its own worth, which is represented by an integer. 
 * Books with odd values of worth belong to Alex and the books with 
 * even values of worth belong to Bob. Alex has a habit of sorting 
 * his books from the left to the right in an increasing order of 
 * worths, while Bob prefers to sort his books from the left to the 
 * right in a decreasing order of worths.
 *
 * At the same time, they do not want to change the positions of the 
 * labels, so that after they have finished sorting the books according 
 * their rules, each book's owner's name should match with the label 
 * in its position.
 *
 * Here comes the problem. A sequence of N values s0, s1, ..., sN-1 
 * is given, which indicates the worths of the books from the left to 
 * the right on the bookshelf currently. Please help the brothers to 
 * find out the sequence of worths after sorting such that it satisfies 
 * the above description.
 *
 */
# include <iostream>
using namespace std;

# define INF INT_MAX
# define NMAX 1000

void merge(int A[], int p, int q, int r)
{
    int nL = q - p + 1;
    int nR = r - q;
    int *L = (int*)malloc(sizeof A[0] * (nL+1));
    int *R = (int*)malloc(sizeof A[0] * (nR+1));
    int *pA = A + p;
    int *pL = L;
    int *pR = R;
    while (pA <= A + q)
        *pL++ = *pA++;
    *pL = INF;  // sentinel
    while (pA <= A + r)
        *pR++ = *pA++;
    *pR = INF;  // sentinel
    pA = A + p; pL = L; pR = R;
    while (pA <= A + r)
        *pA++ = (*pL <= *pR) ? *pL++ : *pR++;
    free(L);
    free(R);
}

void merge_sort(int A[], int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int T, iCase;
    scanf("%d", &T);
    for(iCase = 1; iCase <= T; ++iCase) {
        int N;
        cin >> N;
        int A[NMAX], B[NMAX], isodd[NMAX];
        int *pA = A;
        int *pB = B;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            if (isodd[i] = x & 1)
                *pA++ = x;
            else
                *pB++ = x;
        }
        merge_sort(A, 0, pA - A - 1);
        merge_sort(B, 0, pB - B - 1);
        pA = A; // print A[] in increasing order
        --pB;   // print B[] in decreasing order
        printf("Case #%d:", iCase);
        for (int i = 0; i < N; ++i) {
            if (isodd[i])
                cout << ' ' << *pA++;
            else
                cout << ' ' << *pB--;
        }
        cout << endl;
    }
    return 0;
}
