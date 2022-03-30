#include "main.h"
int main(void) {
  for(;;){
  char *argv[2];
  argv [0]="/bin/sh";
  argv [1]=NULL;
  execvp(argv[0], argv);

  signal(SIGINT, SIG_DFL);
  if (fork() == 0) exit(execvp(argv[0], argv));
  signal(SIGINT, SIG_IGN);
}
}
