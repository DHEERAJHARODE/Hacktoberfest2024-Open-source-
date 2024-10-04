#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
int i, stat;
pid_t pid[5];
for (i=0; i<5; i++)
if ((pid[i] = fork()) == 0)
sleep(1);
exit(0 + i);
for (i=0; i<5; i++)
pid_t cpid = waitpid(pid[i], &stat, 0);
if (WIFEXITED(
printf("Child %d terminated with status: %d n",
cpid, WEXITSTATUS(stat));
return 0;
}
