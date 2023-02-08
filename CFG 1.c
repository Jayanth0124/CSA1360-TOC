#include <stdio.h>
#include <string.h>
int S(char *);
int A(char *);
int S(char *str) {
	if (str[0] == '0' && A(str + 1) && str[strlen(str) - 1] == '1')
		return 1;
	return 0;
}
int A(char *str) {
	if (str[0] == '\0')
		return 1;
	if (str[0] == '0' && A(str + 1))
		return 1;
	if (str[0] == '1' && A(str + 1))
		return 1;
	return 0;
}
int main() {
	char str[100];
	printf("Enter the string: ");
	scanf("%s", str);
	if (S(str))
		printf("The string belongs to the language defined by the CFG.\n");
	else
		printf("The string does not belong to the language defined by the CFG.\n");
	return 0;
}