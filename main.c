#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j,check=0;
  char out;
  Stack s;
  s.size=0;
  s.top=NULL;
 
  for(i=1;i<argc;i++){
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
      /*if(argv[i][j] == '{')
       {
         push(&s,argv[i][j]);
       }
      if(argv[i][j] == '[')
       {
         push(&s,argv[i][j]);
       }
      if(argv[i][j] == '}')
        {
          out = pop(&s);
          if(out != '{')
          {
             check = 1;
             break;
          }
        }
      if(argv[i][j] == ']')
        {
          out = pop(&s);
          if(out != '[')
          {
            check = 1;
            break;
          }
        }*/
      switch(argv[i][j])
      {
        case '{' :
         push(&s,argv[i][j]);
         break;
        case '[' :
         push(&s,argv[i][j]);
         break;
        case '}' :
         out = pop(&s);
         if(out != '{')
         {
           check = 1;
         }
         break;
        case ']' :
         out = pop(&s);
         if(out != '[')
         {
            check = 1;
         }
         break;
      }
     }
     //printf("%d",s.size);
     if(s.size>0 || check == 1)
     {
       printf("The parentheses do not match for %s\n", argv[i]);
       pop_all(&s);
       check = 0;
     }
     else
     {
       printf("The parentheses match successfully for %s\n",argv[i]);
     }
  }
   return 0;
}
