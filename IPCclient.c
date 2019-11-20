#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main(){
  ssize_t n;
  char buff[512];
  int readfd,writefd;
  printf("Trying to Connect to Server..\n");
  writefd = open(FIFO1, O_WRONLY, 0);
  readfd = open(FIFO2, O_RDONLY, 0);
  printf("Connected..\n");
  printf("Enter the filename to request from server: ");
  scanf("%s",fname);
  write(writefd, fname, strlen(fname));
  printf("Waiting for Server to reply..\n");
  while((n=read(readfd,buff,512))>0)
    write(1,buff,n);  //write to stdout
  close(readfd);
  close(writefd);
  return 0;
}

/* on terminal
gcc IPCclient.c -o IPCclient (enter)
./IPCclient (enter)
.
.
.
enter file name (in the directory you have saved your program,enter any file name present in that directory): IPCclent.c
(you will get reply in terminal of IPCserver program)
waiting for reply..
*/
