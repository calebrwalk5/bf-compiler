#include <stdio.h>
#define DATASIZE 1001

void bf(char *command_pointer, char *input) {
  int bracket_flag;
  char command;
  char data[DATASIZE] = {0};
  char *dp;
  dp = &data[DATASIZE/2];
  while (command = *command_pointer++)
    switch (command) {
    case '>':   /* next memory address */
      dp++;
      break;
    case '<':   /* previous memory address */
      dp--;
      break;
    case '+':   /* increment */
      (*dp)++;
      break;
    case '-':   /* decrement */
      (*dp)--;
      break;
    case '.':   /* output */
      printf("%c", *dp);
      break;
    case ',':   /* accept a character */
      *dp = *input++;
      break;
    case '[':   /* if value = 0, move to the next cell*/
      if (!*dp) { 
        for (bracket_flag=1; bracket_flag; command_pointer++)
          if (*command_pointer == '[')
            bracket_flag++;
          else if (*command_pointer == ']')
            bracket_flag--;
      } 
      break;
    case ']':    /* go back to matching opening */
      if (*dp) {
        command_pointer -= 2;  
        for (bracket_flag=1; bracket_flag; command_pointer--)
          if (*command_pointer == ']')
            bracket_flag++;
          else if (*command_pointer == '[')
            bracket_flag--;
        command_pointer++;     
      }
      break;  
    }
  printf("\n");
}

int main() {
	char *bfCode = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."; /* brainfuck code goes here */
	char *input = ""; /* input goes here */
	bf(bfCode, input);
	return 0;
}
