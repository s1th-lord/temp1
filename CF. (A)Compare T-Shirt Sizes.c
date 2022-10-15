#include <stdio.h>

#include <string.h>

#define N	50

int main() {

	int t;

	scanf("%d", &t);

	while (t--) {

		static char aa[N + 1], bb[N + 1];

		int n, m;

		scanf("%s%s", aa, bb), n = strlen(aa), m = strlen(bb);

		printf("%c\n", aa[n - 1] != bb[m - 1] ? (aa[n - 1] > bb[m - 1] ? '<' : '>') : (n == m ? '=' : ((aa[n - 1] == 'S') == (n > m) ? '<' : '>')));

	}

	return 0;

}
