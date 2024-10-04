#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
char *filename = "ls";
char *arg1 = " a";
char *arg2 = " s";
printf("Before calling exec function.");
execlp(filename, arg1, arg2, NULL);
printf(" nWill this line be printed? Check!");
return 0;
}
