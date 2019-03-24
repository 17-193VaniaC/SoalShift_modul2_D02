#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{      
        pid_t child_id, child_id2, child_id3;
	int status;

        child_id = fork();
	if(child_id == 0)
        {
		char *argv[5] = {"unzip","-n","campur2.zip","*.txt", NULL};
		execv("/usr/bin/unzip", argv);
        }

	child_id = fork();
	if(child_id == 0)
	{
		char *argv2[3] = {"touch", "daftar.txt", NULL};
		execv("/bin/touch", argv2);
	}
	
	// bagian pipe disini
	printf("kuy menunggu");
	while(wait(&status)>0);
	printf("selesai ea");

	int pipa[2];
	pipe(pipa);
	child_id3 = fork();

	printf("pipe terbetuk");

	if(child_id3 == 0)
	{
		close(pipa[0]);
		dup2(pipa[1], 1);
		char *argv3[3] = {"list", "campur2", NULL};
		execv("/bin/ls", argv3);
		printf("list selesai");
	}
	
	char temp[1000];

	FILE *daftar = fopen("daftar.txt", "w");
	FILE *isi_ls = fdopen(pipa[0], "r");

	while(fgets(temp, sizeof(temp), isi_ls) != NULL)
		{fprintf(daftar, "%s", temp);}
	
	printf("SUDAH TERTULIS");

	fclose(daftar);

}
