#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

void _ls(const char *dir, int flag_A, int flag_l, const char *argv[]){
	struct dirent *d;
	DIR *dh = opendir(dir);
	if(!dh){
		if(errno == ENOENT){
			perror("Directory doesn't exist");
		}else{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while((d = readdir(dh)) != NULL){
		if(!flag_A && d->d_name[0] == '.'){
			continue;
		}
		char buf[512];
		sprintf(buf, "%s/%s", argv[1], d->d_name);

		struct stat thestat;
		stat(buf, &thestat);

		switch (thestat.st_mode & S_IFMT) {
			case S_IFBLK:  printf("b "); break;
			case S_IFCHR:  printf("c "); break;
			case S_IFDIR:  printf("d "); break;
			case S_IFIFO:  printf("p "); break;
			case S_IFLNK:  printf("l "); break;
			case S_IFSOCK: printf("s "); break;
			default:       printf("- "); break;
		}
		printf("%s  ", d->d_name);
		if(flag_l){
			printf("\n");
		}




		if(!flag_l) printf("\n");
}
}
int main(int argc, const char *argv[]){
	if(argc == 1){
		_ls(".",0,0, argv);
	}else if(argc == 2){
		if(argv[1][0] == '-'){
			int flag_A = 0, flag_l = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'A') flag_A = 1;
				else if(*p == 'l') flag_l = 1;
				else{
					perror("invalid argument");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_ls(".", flag_A, flag_l, argv);
		}
	}
	return 0;
}
