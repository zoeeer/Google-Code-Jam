/* Problem B. Rational Number Tree
 * 
 * Consider an infinite complete binary tree where the root node
 * is 1/1 and left and right childs of node p/q are p/(p+q) and (p+q)/q, 
 * respectively. This tree looks like:
 *
 *              1/1
 *         ______|______
 *         |           |
 *        1/2         2/1
 *      ___|___     ___|___
 *      |     |     |     |
 *     1/3   3/2   2/3   3/1
 *     ...
 *
 * It is known that every positive rational number appears exactly once 
 * in this tree. A level-order traversal of the tree results in the 
 * following array:
 *
 *     1/1, 1/2, 2/1, 1/3, 3/2, 2/3, 3/1, ...
 *
 * Please solve the following two questions:
 * 1. Find the n-th element of the array, where n starts from 1.
 *    For example, for the input 2, the correct output is 1/2.
 * 2. Given p/q, find its position in the array. As an example, 
 *    the input 1/2 results in the output 2.
 *
 */

# include <iostream>
using namespace std;

#define ULL unsigned long long

void find(ULL x, ULL &p, ULL &q)
{
    ULL index = 0x8000000000000000; // 1000000...000 (63 zeros binary)
    p = q = 1;
    while (0 == (x & index))
        index >>= 1;
    while ((index >>= 1) != 0) {
        if (x & index)
            p += q;
        else
            q += p;
    }
}

ULL findID(ULL p, ULL q)
{
    ULL index = 1;
    ULL id = 0;
    while (p != q) { // p == q only at root: 1/1
        if (p > q) { // right child of its father
            id += index; // current bit should be odd
            p -= q;
        }
        else        // left child of its father
            q -= p;
        index <<= 1;
    }
    return id += index;
}

int main()
{
    int T, iCase;
    scanf("%d", &T);
    for(iCase = 1; iCase <= T; ++iCase) {
        int id;
        cin >> id;
        printf("Case #%d:", iCase);
        if (id == 1) {
            ULL x, p, q;
            cin >> x;
            find(x, p, q);
            cout << ' ' << p << ' ' << q;
        }
        else if (id == 2) {
            ULL p, q;
            cin >> p >> q;
            cout << ' ' << findID(p, q);
        }
        cout << endl;
    }

    return 0;
}
