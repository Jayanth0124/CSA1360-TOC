#include <stdio.h>
#include <string.h>
int check_string(char *str) {
	int len = strlen(str);
	int i = 0, j = len - 1;
	while (i <= j) {
		if (str[i] != str[j]) {
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}
int main() {
	char str[100];
	printf("Enter a string: ");
	scanf("%s", str);
	if (check_string(str)) {
		printf("The string belongs to the language defined by the CFG\n");
	} else {
		printf("The string does not belong to the language defined by the CFG\n");
	}
	return 0;
}