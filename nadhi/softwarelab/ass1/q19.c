#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct stat fileInfo;
 
    const char *filePath ;
    printf("Enter the name of the file:");
    scanf("%s",filePath);
 
    if (stat(filePath, &fileInfo) != 0) {
        printf("Error getting file information");
        return 1;
    }
 
    printf("File Properties for: %s\n", filePath);
    printf("File Size: %lld bytes\n", (long long)fileInfo.st_size);
    printf("Last Access Time: %s", ctime(&fileInfo.st_atime));
    printf("Last Modification Time: %s", ctime(&fileInfo.st_mtime));
    printf("Last Status Change Time: %s", ctime(&fileInfo.st_ctime));

    return 0;
}
