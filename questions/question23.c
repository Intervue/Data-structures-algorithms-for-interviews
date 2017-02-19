/*
 A file "input.txt" contains a some lines of text. Collect the name of the file from the user, and then
   use the C "system()" function, and the standard UNIX command "wc", to find the number
   of lines, words and characters in the file. Ensure that the file is readable before trying the "system()"
   function.
   INPUT: read file name from command line as: ./a.out input.txt
   OUTPUT: the number of lines, words characters in the file "input.txt"                                        [2 marks]

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

   char *str = malloc(sizeof(char)*100);

   strcpy(str, "wc ");
   strcat(str, argv[1]);

   printf("%s\n", str);

   if(argc > 1){
      FILE *fp = fopen(argv[1],"r");
      if(fp != NULL){
         system(str);
      }
      fclose(fp);
   }

}