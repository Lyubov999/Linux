#include <signal.h> 
#include <stdio.h> 

/* Функция my_handler – пользовательский обработчик сигнала */  
void my_handler(int nsig){  
    printf("Receive signal %d, Signal received\n", nsig); 
} 

int main(void){  
    for (int i = 1; i <= 64; i++) {
        (void)signal(i, my_handler); 
    }
    
    while(1); 
    return 0; 
}
