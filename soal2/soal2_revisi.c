#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <grp.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);


struct group *grp;
pid_t anak,cucu;
char *param[4]={"chmod","0777","/home/cikei/Desktop/prak2/elen.ku",NULL};
char *param2[3]={"rm","/home/cikei/Desktop/prak2/elen.ku",NULL};
char elen[]="elenku";
char data[]="www-data",lala[100],lili[100];
int i = 0;

setgrent();
while(1){

while((grp=getgrent())!=NULL){
        strcpy(lala,grp->gr_name);
        if(strcmp(lala,data)){
        i=0;
        while(*(grp->gr_mem+i)){
                strcpy(lili,grp->gr_mem);
                if(strcmp(lili,elen)==1){
                        anak=fork();

                        if(anak==0){
                        execv("/bin/chmod",param);
                        }
                        else{
                        wait(NULL);
                        execv("/bin/rm",param2);
                        }
                }
                i++;
                }
        }

}
endgrent();

    sleep(3);
  }
  
  exit(EXIT_SUCCESS);
}
