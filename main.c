#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

int print_info(char * input){
    DIR *dir = opendir(input);
    if(!dir){
        printf("Can't open directory with error: %s\n", strerror(errno));
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
}

int main(int argc, char *argv[]){
    char input [100];
    if(argc == 1){
        printf("Enter a directory path: ");
        fgets(input, 100, stdin);
        *strchr(input, '\n') = '\0';
    } else if (argc == 2) {
        strcpy(input, argv[1]);
    } else {
        printf("Only taking the first command line argument!\n");
        strcpy(input, argv[1]);
    }
    printf("%s\n", input);
    if(!opendir(input)){
        printf("%d", argc);
        printf("Can't open directory with error: %s\n", strerror(errno));
        return 0;
    }
    print_info(input);
    
    return 0;
}