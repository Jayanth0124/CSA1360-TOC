#include<stdio.h>
#include<string.h>
#define max 20
int main() {
	int trans_table[4][2]= {{1,3},{1,2},{1,2},{3,3}};
	int final_state=2, present_state=0, next_state=0, invalid=0, l, i;
	char input_string[max];
	printf("Enter a string:");
	scanf("%s",input_string);
	l=strlen(input_string);
	for(i=0; i<l; i++) {
		next_state = (input_string[i] == 'a') ? trans_table[present_state][0]
		             : (input_string[i] == 'b') ? trans_table[present_state][1]
		             : (invalid=l, next_state);
		present_state=next_state;
	}
	printf("%s", (invalid==l) ? "Invalid input\n" :
	       (present_state == final_state) ? "Accept\n" : "Don't Accept\n");
	return 0;
}