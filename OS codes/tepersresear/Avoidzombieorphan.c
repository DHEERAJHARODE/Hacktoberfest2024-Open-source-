#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
int stat;
// This exit status (99) is reported by WEXITSTATUS
if (fork() == 0)
exit(99);
else
wait(&stat); // Parent waits for child to exit.
if (WIFEXITED(stat))
printf("Exit status: %d n", WEXITSTATUS(stat));
else if (WIFSIGNALED(stat))
p rintf nEx it signal");
return 0;
}
