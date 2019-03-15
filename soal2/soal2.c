#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
DIR *ya;
char *alamat[]="/home/cikei/Desktop/prak2/soal2/hatiku/"
char elen[]="elenku";
char wdata[]="www-data"
char *para[] = {"/bin/chmod", "777", "/home/cikei/Desktop/prak2/soal2/hatiku/elen.ku",NULL};
char *typenya, baru[]="_grey.png";
struct dirent *yow;
pid_t child;
ya=opendir(alamat)
yow=readdir(ya);

child=fork();
if(child==0){ 
if(strcmp(yow->d_name,"elen.ku")!=0){
if(strcmp(yow->pw_owner,wdata)!=0){
	execvp("chmod",para);}
}

}

while()

closedir(ya);
}
return(0);
}


