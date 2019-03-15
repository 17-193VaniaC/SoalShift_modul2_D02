#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define READ_END 0
#define WRITE_END 1

int main() {
  pid_t child_id;
  pid_t child_id2;
  int status, fd[2];
  char *arg[]={"ls","/home/cikei/Desktop/prak2/soal3/*.txt","\0"};
  char *argu[]={"xargs", "-n1","basename",">>","daftar.txt","\0"};

pipe(fd);
child_id=fork();

if(child_id == 0){
dup2(fd[WRITE_END], STDOUT_FILENO);
close(fd[READ_END]);
close(fd[WRITE_END]);
execl("ls", "ls"," /home/cikei/Desktop/prak2/soal3/*.txt", (char*) 0);
fprintf(stderr, "failed\n");
exit(1);
}

else{
child_id=fork();
	if(child_id==0){
	dup2(fd[READ_END],STDIN_FILENO);
	close(fd[WRITE_END]);
	close(fd[READ_END]);
	execvp(argu[0],argu);
	fprintf(stderr, "failed second\n");
	exit(1);
	}
	else{
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(child_id, &status, 0);
	}
}
return 0;
	
}


//}
//char *argv[4]={"ls","/home/cikei/Desktop/prak2/soal3/*.txt | xargs -n1 basename", ">> daftar.txt"};
//execv("/bin/dir", argv);
//printf("anak\n");
//}

//child_id2=fork();
//if(child_id2 == 0 && getppid()>0){
//char *argv[4]={"cd","*.txt",">daftar.txt"};
//char *hupla[3]={"cd","campur2/",NULL};
//execv("cd:","hupla");

//printf("unzipfile\n");
//}

//char *lala[3] = {"unzip","campur2.zip", NULL};
//execv("/usr/bin/unzip", lala);

//printf("id ini %d\n", getpid());
//printf("id ppid %d\n",getppid()); 
//return 0;
//}


