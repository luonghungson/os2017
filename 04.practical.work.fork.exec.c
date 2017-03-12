#include <stdio.h>
#include <unistd.h>
int main() {
printf("Main before fork()\n");
int pid = fork();
if (pid == 0) {
	printf("Launching ps -ef\n");
	char *args[]= { "/bin/ps", "-ef" , NULL};
	execvp("/bin/ps", args);
}
pid = fork();
if (pid == 0) {
	printf("Launching free -h\n");
	char *args[]= { "free", "-h" , NULL};
	execvp("free", args);
}
return 0;
}
