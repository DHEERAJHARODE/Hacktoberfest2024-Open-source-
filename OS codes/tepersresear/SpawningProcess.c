#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid;
pid = fork();
char *bin_path = "/bin/ps";
char *arg1 = " Tl";
if(pid<0)
printf("fork failed");
return 1;
else if(pid == 0)
{
execl(bin_path, bin_path, arg1, NULL);
else
wait(NULL);
printf("child complete n");
return 0;
}
