#include <stdio.h>
#include <unistd.h>

void comparer_pere_fils() {
    char repertoire[255];
    pid_t pid = fork();
    if(pid == -1) perror("Erreur a l'appel de fork");
    else if (pid == 0) {
        printf("[*] Processus fils\n");
        printf("S'endort pendant 2 secondes...\n\n");
        sleep(2);
    } else printf("[*] Processus pere\n\n");
    printf("PID : %i\nPID père : %i\nRepertoire de travail : %s\nPropriétaire réel : %i\nPropriétaire effectif : %i\nGroupe propriétaire réel : %i\nGroupe propriétaire effectif : %i\n\n", getpid(), getppid(), getcwd(repertoire, 255), getuid(), geteuid(), getgid(), getegid());
}

int main()
{
    comparer_pere_fils();
    return 0;
}
