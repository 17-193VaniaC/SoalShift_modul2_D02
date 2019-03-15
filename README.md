# SoalShift_modul2_E02

1.
```
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <dirent.h>
#include <string.h>

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

DIR *ya;
char *typenya, baru[]="_grey.png";
struct dirent *yow;
while(1) {
    ya=opendir(".");
if(ya){
while ((yow=readdir(ya))!=NULL){
        if(strstr(yow->d_name, ".png")!=NULL){
        char *nama;
        char *alamat;
        nama = malloc (strlen(yow->d_name)+12);
        strcpy(nama, yow->d_name);
        typenya = strrchr(nama,'.');
        if(typenya != NULL){
        *typenya = '\0';
        }
        alamat = malloc (strlen(nama)+6);
        strcat(alamat,"/home/cikei/modul2/gambar/");
        strcat(nama,baru);
        strcat(alamat,nama);
        rename(yow->d_name, alamat);
        printf("bisa");
}
}
closedir(ya);
}

  }
  
  exit(EXIT_SUCCESS);
}
```
Penjelasan:


