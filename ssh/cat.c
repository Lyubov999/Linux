#include <stdio.h> 
#include <sys/types.h> //для size_t
#include <stdlib.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <fcntl.h> 

#define perms 0666

int main (int argc, char *argv[]) {
	if (argc ==2){
		int fd = open(argv[1], O_RDONLY);
		if (fd < 0){
		perror("error");
		return 1;
		}	
		char buf[100];
		size_t n;
		while ((n = read(fd, buf, sizeof(buf))) > 0){
			if (write(STDOUT_FILENO, buf, n) !=n){
			perror("error");
			close(fd);
			return 1;
			}
        	close(fd); 
    		}
    		}
    		else { 
        	int fd2 = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, perms);
        	if (fd2 < 0) {
            	perror("error");
            	return 1;
        	}
        	char c;
        	while (read(STDIN_FILENO, &c, 1) > 0) { 
            		if (write(fd2, &c, 1) != 1) {
                	perror("error");
                	close(fd2);
                	return 1;
            		}	
        	}
        	close(fd2); 
    		}	
    return 0;
}

