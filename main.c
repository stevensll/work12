#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#define PATH "."

void print_info(struct dirent *d){
    struct stat *stt;

}

int main(){

    


    DIR *dir = opendir(PATH);
    if(!dir){
        printf("Can't open directory with error\n%s\n", strerror(errno));
        return 0;
    }

    struct dirent *entry;
    struct stat temp;
    printf("Driectories:\n");
    long int size = 0;
    //printing directories
    while(entry=readdir(dir)){
        if (entry->d_type == 4){
            stat(entry->d_name, &temp);
            printf("\t%s\tSize:%ld Bytes\n", entry->d_name, temp.st_size);
            size+=temp.st_size;
        }
    }
    
    rewinddir(dir);

    printf("Files:\n");
    //printing files
    while(entry=readdir(dir)){
        if (entry->d_type == 8){
            stat(entry->d_name, &temp);
            printf("\t%s\tSize:%ld Bytes\n", entry->d_name, temp.st_size);
            size+=temp.st_size;
        }
    }
    printf("Total directory size: %ld Bytes\n", size);
    closedir(dir);
    return 0;
}