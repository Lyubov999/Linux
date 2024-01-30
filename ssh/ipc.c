#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    int *array1, *array2;    /* Указатели на разделяемую память */
    int shmid, shmid_2; /* IPC дескрипторы для области разделяемой памяти */
    int new = 1;   /* Флаг необходимости инициализации элементов массива */
    char pathname[] = "sys1.c"; 
    char pathname2[] = "sys2.c";

    key_t key;     /* IPC ключ */
    key_t key_2; 

    if((key = ftok(pathname,0)) < 0){
        printf("Can\'t generate key\n");
        exit(-1);
    }
    if((key_2 = ftok(pathname2, 1)) < 0){
        printf("Can\'t generate key_2\n");
        exit(-1);
    }
    if(key == key_2)
    {
	    printf("FAIL");
    }
    
    if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0){
        if(errno != EEXIST){
            printf("Can\'t create shared memory for sys1.c\n");
            exit(-1);
        } else {
            if((shmid = shmget(key, 3*sizeof(int), 0)) < 0){
                printf("Can\'t find shared memory for sys1.c\n");
                exit(-1);
            }
            new = 0; 
        }
    }
    
    if((shmid_2 = shmget(key_2, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0){
        if(errno != EEXIST){
            printf("Can\'t create shared memory for sys2.c\n");
            exit(-1);
        } else {
            if((shmid_2 = shmget(key, 3*sizeof(int), 0)) < 0){
                printf("Can\'t find shared memory for sys2.c\n");
                exit(-1);
            }
        }
    }
    
    if((array1 = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)){
        printf("Can't attach shared memory\n");
        exit(-1);
    }
    
    if((array2 = (int *)shmat(shmid_2, NULL, 0)) == (int *)(-1)){
        printf("Can't attach shared memory_2\n");
        exit(-1);
    }
    
    if(shmdt(array1) < 0){ 
        printf("Can't detach shared memory for sys1.c\n");
        exit(-1);
    }
    if(shmdt(array2) < 0){ 
        printf("Can't detach shared memory for sys2.c\n");
        exit(-1);
    }
    printf("Shared memory removed\n");
    return 0;
}
