#include <stdio.h>

char N[50][5][7] = { { { 0, }, }, };
int diff[50] = { 0, };

int main(void)
{
	int i, j, k, n;
	int pictureNum = 0;
	char tmp;

	scanf("%d", &n);
	
	for (pictureNum = 0; pictureNum < n; pictureNum++)
		for (i = 0; i < 5; i++)
			for (j = 0; j < 7; j++){
				scanf("%c", &tmp);
				if (tmp == '\n') scanf("%c", &tmp);
				N[pictureNum][i][j] = tmp;
			}

	for (i = 0; i < (n - 1) * 5; i += 5){
		for (j = i + 5; j < i + 10; j++){
			for (k = 0; k < 7; k++){
				if (N[i]){}
			}
		}
	}

	return 0;
}