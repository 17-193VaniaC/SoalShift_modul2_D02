#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{      
        pid_t child_id, child_id2, child_id3;

        child_id = fork();
	if(child_id == 0)
        {
                char *argv[3] = "unzip","/home/ALIFI/2/campur2.zip", NULL];
		execv("/bin/unzip", argv);
        }

	child_id2 = fork();
	if(child_id2 == 0)
	{
		char *argv2[3] = "touch", "/home/ALIFI/2/daftar.txt", NULL];
		execv("/bin/touch", argv2);
	}
	
	int status;
	DIR *ya;
	char *typenya;
	struct dirent *yow;
	ya = opendir(".");

	child_id3 = wait(&status);
	if(child_id3 > 0)
	{
	   FILE *fp;
	   fp = fopen("daftar.txt", "w");
	   if(ya)
		{
		   while ((yow=readdir(ya)!=NULL)
		   {
		      if(strstr(yow->d_name, ".txt")!=NULL)
		      {
		         char *nama;
			 strcpy(nama, yow->d_name);
			 int i;
			 for(i=0;i<strlen(nama); i++)
			 {
			    fputc(nama[i], fp);
			 }
		      }
		   }
		}
	   fclose(fp);
	}
	
}

