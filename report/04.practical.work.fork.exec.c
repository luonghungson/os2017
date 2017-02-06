#include <stdio.h>
#include <unistd.h>
int main() {
printf("Main before fork()\n");
int pid = fork();
if (pid == 0) {
	printf("I am child after fork(), launching ps -ef\n");
	char *args[]= { "/bin/ps", "-ef" , NULL};
	execvp("/bin/ps", args);
}
else printf("I am parent after fork(), child is %d\n", pid);

pid = fork();
if (pid == 0) {
	printf("I am child after fork(), launching ps -ef\n");
	char *args[]= { "free", "-h" , NULL};
	execvp("free", args);
}
else printf("I am parent after fork(), child is %d\n", pid);
return 0;
}
