#include <signal.h> 
#include <stdio.h> 

void my_handler(int nsig){  
    if (nsig == SIGINT) {
        printf("Receive signal %d, CTRL-C pressed\n", nsig); 
    } else if (nsig == SIGQUIT) {
        printf("Receive signal %d, CTRL-  pressed\n", nsig); //не смогла прописать CTRL-\
    }
} 

int main(void){  
    (void)signal(SIGINT, my_handler);  
    (void)signal(SIGQUIT, my_handler); 
    while(1); 
    return 0; 
}
