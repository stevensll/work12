#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#define PATH "./"

void print_info(struct dirent *dir, long long *p){
    struct stat buf;
    int err = stat(dir->d_name, &buf);
    if(err == -1){
        printf("Error getting info of directory %s\n%s\n", dir->d_name, strerror(errno));
    }

}

int main(){

    DIR *dir = opendir(PATH);
    if(!dir){
        printf("Can't open directory with error\n%s\n", strerror(errno));
        return 0;
    }

    struct dirent *entry = readdir(dir);

    while(entry){
        print_info()
        entry = readdir(dir);
    }
    closedir(dir);
    // closedir(d);
    return 0;
}