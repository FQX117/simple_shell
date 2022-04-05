#include "main.h"
/*
 */int main(void) {
    for (;;) {
        char input[PRMTSIZ + 1] = { 0x0 };
        char *ptr = input;
	char **gline = &ptr;
        char *args[MAXARGS + 1] = { NULL };
        int wstatus;
        long unsigned int i = 0, x[PRMTSIZ], *size = x;
       

        /**
        *prompt
        **/
        _printf("%s ", getpid() == 0 ? "#" : "$");
        getline(gline, size, stdin);

        /**
        *ignore empty input
        **/
        if (*ptr == '\n') continue;

        /**
        *convert input line to list of arguments
        **/
        for (; i < sizeof(args) && *ptr; ptr++) {
            if (*ptr == ' ') continue;
            if (*ptr == '\n') break;
            for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
            *ptr = '\0';
        }

        /**
        *built-in: exit
        **/
        if (strcmp(EXITCMD, args[0]) == 0) return 0;

        /**
        *fork child and execute program
        **/
        signal(SIGINT, SIG_DFL);
        if (fork() == 0) exit(execvp(args[0], args));
        signal(SIGINT, SIG_IGN);

        /**
        *wait for program to finish and print exit status
        **/
        wait(&wstatus);
        if (WIFEXITED(wstatus)) printf("<%d>", WEXITSTATUS(wstatus));
    }
}
