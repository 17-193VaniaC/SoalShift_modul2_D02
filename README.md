# SoalShift_modul2_E02

1.
``` c
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
        
}
}
closedir(ya);
}

  }
  
  exit(EXIT_SUCCESS);
}
```
Penjelasan:
```
ya=opendir(".");
yow=readdir(ya)
```
membuka folder dan membaca kontennya (yow)
```
if(strstr(yow->d_name, ".png")!=NULL)

```
mencari tahu jika terdapat string ".png" atau tidak pada nama file, jika terdapat, maka program dijalankan.
```
strcpy(nama, yow->d_name);           
```
menyalin nama file ke variabel "nama"
```
typenya = strrchr(nama,'.');
```
pointer "typenya menunjuk ke string yang dimulai oleh '.' pada string nama"
```
if(typenya != NULL){
*typenya = '\0';
}
```
jika typenya tidak NULL, maka dihilangkan.
```
strcat(alamat,"/home/cikei/modul2/gambar/");
```
membuat string alamat tujuan file dipindahkan
```
strcat(nama,baru);
```
menambahkan "_grey.png" pada nama file
```
strcat(alamat,nama);
```
menambahkan string "nama" (nama file) pada alamat tujuan
```
rename(yow->d_name, alamat);
```
mengubah nama sekaligus memindahkan file tersebut ke alamat tujuan dengan nama yang baru

Kendala :
Segmentation fault

3. 
```c
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
```
Langkah-langkah:
1. Mengekstrak file `campur2.zip` yang bertipe teks (.txt)
  ```c
  	child_id = fork();
	if(child_id == 0)
        {
		char *argv[5] = {"unzip","-n","campur2.zip","*.txt", NULL};
		execv("/usr/bin/unzip", argv);
        }
```
2. Membuat file `daftar.txt`
   ```c
     	child_id = fork();
	if(child_id == 0)
	{
		char *argv2[3] = {"touch", "daftar.txt", NULL};
		execv("/bin/touch", argv2);
	}
   ```
 3.Mendaftar nama file dalam folder `campur2` dan memasukannya ke dalam `daftar.txt` 
 ```c
 while(wait(&status)>0);

	int pipa[2];
	pipe(pipa);
	child_id3 = fork();

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

	fclose(daftar);
 ```
 
 Kendala: Tahap ketiga tidak berjalan.
