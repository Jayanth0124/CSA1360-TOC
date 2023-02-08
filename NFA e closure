#include<stdio.h>
#include<string.h>
int trans_table[10][5][3];
char symbol[5];
int e_closure[10][10];
int num_states, num_symbols, ptr, state;
void find_e_closure(int x) {
  int i, j, y[10], num_trans;
  i=0;
  while(trans_table[x][0][i] != -1) {
    y[i]=trans_table[x][0][i];
    i++;
  }
  num_trans = i;
  for(j=0; j<num_trans; j++) {
    e_closure[state][ptr] = y[j];
    ptr++;
    find_e_closure(y[j]);
  }
}
int main() {
  int i, j;
  memset(trans_table, -1, sizeof trans_table);
  num_states = 3;
  num_symbols = 2;
  symbol[10] = 'e';
  trans_table[0][0][0] = 1;
  memset(e_closure, -1, sizeof e_closure);
  for(i=0; i<num_states; i++)
    e_closure[i][0] = i;
  for(i=0; i<num_states; i++) {
    if(trans_table[i][0][0] == -1) continue;
    else {
      state = i;
      ptr = 1;
      find_e_closure(i);
    }
  }
  for(i=0; i<num_states; i++) {
    printf("e-closure(%d) = {", i);
    for(j=0; j<num_states; j++) {
      if(e_closure[i][j] != -1)
        printf("%d, ", e_closure[i][j]);
    }
    printf("}\n");
  }
  return 0;
}
