#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
main(){
FILE *fptr;
char tline[1];
fptr = fopen ("sillyfile.txt", "r");
/* check it's open */
 while ((tline = atoi(fgetc (/*tline, 100,*/ fptr)) != EOF)) {
printf ("%s",tline ); // Print it
}
fclose(fptr);


}
