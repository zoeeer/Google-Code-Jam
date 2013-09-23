/* Problem A. Read Phone Number
 *
 * Do you know how to read the phone numbers in English? Now let me tell you.
 *
 * For example, In China, the phone numbers are 11 digits, like: 15012233444. 
 * Someone divides the numbers into 3-4-4 format, i.e. 150 1223 3444. 
 * While someone divides the numbers into 3-3-5 format, i.e. 150 122 33444. 
 * Different formats lead to different ways to read these numbers:
 *
 * 150 1223 3444 reads one five zero one double two three three triple four.
 *
 * 150 122 33444 reads one five zero one double two double three triple four.
 *
 * Here comes the problem:
 *
 * Given a list of phone numbers and the dividing formats, output the right ways to read these numbers.
 *
 * Rules:
 *
 * Single numbers just read them separately.
 * 2 successive numbers use double.
 * 3 successive numbers use triple.
 * 4 successive numbers use quadruple.
 * 5 successive numbers use quintuple.
 * 6 successive numbers use sextuple.
 * 7 successive numbers use septuple.
 * 8 successive numbers use octuple.
 * 9 successive numbers use nonuple.
 * 10 successive numbers use decuple.
 * More than 10 successive numbers read them all separately.
 *
 */
# include <string>
# include <list>
# include <iostream>
using namespace std;

# define NMAX 101

char *Digit[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

char *Dup[] = {
	"",
	"",
	"double",
	"triple",
	"quadruple",
	"quintuple",
	"sextuple",
	"septuple",
	"octuple",
	"nonuple",
	"decuple"
};

void ReadNumber(int num, int cnt)
{
	if (cnt < 2 || cnt > 10)
		for (int i = 1; i <= cnt; ++i)
			cout << ' ' << Digit[num];
	else
		cout << ' ' << Dup[cnt] << ' ' << Digit[num];
}

int main()
{
	int T, iCase;
	scanf("%d", &T);
	for (iCase = 1; iCase <= T; ++iCase) {
		char num[NMAX];
		list<int> divide; // use a queue to store dividing format
		cin >> num;
		do {
			int x;
			cin >> x;
			divide.push_back(x);
		} while (cin.get() == '-');

		const char *s = num;
		printf("Case #%d:", iCase);
		while (divide.size() != 0) {
			char c = *s;
			int cnt = 0;
			for (int i = divide.front(); i > 0; --i) { 
				if (*s++ == c)
					++cnt;
				else {
					ReadNumber(c - '0', cnt);
					c = *(s - 1);
					cnt = 1;
				}
			}
			ReadNumber(*(s - 1) - '0', cnt);
			divide.pop_front();
		}
		cout << endl;
	}
}
