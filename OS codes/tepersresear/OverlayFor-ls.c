#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
char *filename = "ls";
char *arg1 = " a";
char *arg2 = " s";
pid_t pid;
pid = fork();
if(pid < 0)
printf("fork failed!");
return 1;
else if(pid == 0)
{
execlp(filename, arg1, arg2, NULL);
else
wait(NULL);
printf("child complete n");
return 0;
}
