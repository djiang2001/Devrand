#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int rand_num(){
  int fd = open("/dev/random",O_RDONLY);
  int buff[1];
  read(fd,buff,sizeof(int));
  if(errno){
    printf("Errno: %d|%s\n", errno, strerror(errno));
  }
  close(fd);
  return *buff;
}

int main(){
  printf("Generating random numbers:\n");
  int arr[10];
  for(int i =0; i < 10; i++){
    arr[i] = rand_num();
    printf("%d: %d \n", i, arr[i]);
  }

  printf("Writing numbers: \n");
  int fd1 = open("rand.txt",O_CREAT | O_WRONLY,0666);
  write(fd1,arr,sizeof(int) * 10);
  close(fd1);

  printf("Reading numbers: \n");
  int arr2[10];
  int fd2 = open("rand.txt", O_CREAT | O_RDONLY, 0666);
  read(fd2, arr2, sizeof(int) * 10);
  close(fd2);

  printf("Verification of written values: \n");
  for(int i = 0;i < 10; i++){
    printf("%d: %d\n", i,arr2[i]); 
  }

  return 0;
}
