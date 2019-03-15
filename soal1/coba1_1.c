#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
DIR *ya;
const char *para;
char *typenya, baru[]="_grey.png";
struct dirent *yow;
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
	
	printf("%s\n", nama);
}

	
}
closedir(ya);
}
return(0);
}
