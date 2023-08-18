#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char** argv){
    openlog(NULL, 0, LOG_USER);

    if( argc < 3 ) {
        syslog(LOG_ERR, "Please provide 2 arguments.\n");        
        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];


    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);

    FILE* fp;
    int fd = creat(writefile, 0644);

    if(fd < 0) {
        perror("create file");
        syslog(LOG_ERR,"Failed to create %s\n", writefile);
        return 1;
    };

    size_t write_bytes = strlen(writestr); 
    ssize_t nw = write(fd, writestr, write_bytes);
    
    // from LSP: For regular files, 
    // write is guaranteed to perform the entire write unless an error occurs

    if(nw == -1){
        syslog(LOG_ERR, "Failed to write to file.\n");
        return 1;
    }

    if (close (fd) == -1){
        syslog(LOG_ERR, "Couldn't close file\n");
        return 1;
    }

    return 0;
}

