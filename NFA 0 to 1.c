#include<stdio.h>
#include<string.h>
int main() {
	int num_states, num_symbols, num_final, symbol[5];
	int mat[10][10][10], next_state[20], present_state[20];
	int i, j, k, l, m, n, flag, p, inp, inp1, prev_trans, new_trans;
	char input[20];
	printf("How many states in the NFA : ");
	scanf("%d", &num_states);
	printf("How many symbols in the input alphabet : ");
	scanf("%d", &num_symbols);
	for(i = 0; i < num_symbols; i++) {
		printf("Enter the input symbol %d : ", i + 1);
		scanf("%d", &symbol[i]);
	}
	printf("How many final states : ");
	scanf("%d", &num_final);
	int final_state[num_final];
	for(i = 0; i < num_final; i++) {
		printf("Enter the final state %d : ", i + 1);
		scanf("%d", &final_state[i]);
	}
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			for(k = 0; k < 10; k++) {
				mat[i][j][k] = -1;
			}
		}
	}
	for(i = 0; i < num_states; i++) {
		for(j = 0; j < num_symbols; j++) {
			printf("How many transitions from state %d for the input %d : ", i, symbol[j]);
			scanf("%d", &n);

			for(k = 0; k < n; k++) {
				printf("Enter the transition %d from state %d for the input %d : ", k + 1, i, symbol[j]);
				scanf("%d", &mat[i][j][k]);
			}
		}
	}
	while(1) {
		printf("Enter the input string : ");
		scanf("%s", input);
		present_state[0] = 0;
		prev_trans = 1;
		l = strlen(input);

		for(i = 0; i < l; i++) {
			if(input[i] == '0')
				inp1 = 0;
			else if(input[i] == '1')
				inp1 = 1;
			else {
				printf("Invalid input\n");
				return 0;
			}

			for(m = 0; m < num_symbols; m++) {
				if(inp1 == symbol[m]) {
					inp = m;
					break;
				}
			}
			new_trans = 0;
			for(j = 0; j < prev_trans; j++) {
				for(k = 0; k < 10; k++) {
					if(mat[present_state[j]][inp][k] != -1) {
						next_state[new_trans] = mat[present_state[j]][inp][k];
						new_trans++;
					}
				}
			}
			prev_trans = new_trans;
			for(p = 0; p < prev_trans; p++)
				present_state[p] = next_state[p];
		}
		flag = 0;
		for(i = 0; i < num_final; i++) {
			for(j = 0; j < prev_trans; j++) {
				if(present_state[j] == final_state[i]) {
					printf("Accepted\n");
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}
		if(flag == 0)
			printf("Not accepted\n");
	}
	return 0;
}