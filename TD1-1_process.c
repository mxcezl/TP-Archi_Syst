#include <stdio.h>
#include <unistd.h>

void create_n_process(int n) {
    int i;
    pid_t pid;
    for(i = 0; i < n; i++) {
        pid = fork();

        if (pid == -1) perror("Erreur a l'appel de fork");
        else if (pid == 0) printf("F_ PID fils : %i | PID pere : %i\n", getpid(), getppid());
        else printf("P_ PID pere : %i | PID fils : %i\n", getpid(), pid);
    }
}

int main()
{
    int n = 3;
    create_n_process(n);
    return 0;
}
