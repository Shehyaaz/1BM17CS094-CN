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
    int readfd,writefd,fd;
    ssize_t n;
    char buff[512];
    if(mkfifo(FIFO1,PERMS)<0)
      printf("cant create fifo files \n");
    if(mkfifo(FIFO2,PERMS)<0)
      printf("cant create fifo files\n");
    printf("waiting for connection request \n");
    
    readfd=open(FIFO1,O_RDONLY,0);
    writefd=open(FIFO2,O_WRONLY,0);
    printf("connection establish \n");
    read(readfd,fname,255);
    printf("client has request file %s \n",fname);
    if((fd=open(fname,O_RDWR))<0){
    strcpy(buff,"file does not exist \n");
    write(writefd,buff,strlen(buff));
    }
    else{
    while((n=read(fd,buff,512))>0)
    write(writefd,buff,n);
    }
    close(readfd);unlink(FIFO1);
    close(writefd);unlink(FIFO2);
    }

/* in terminal ,
   gcc IPCserver.c -o IPCserver (enter)
   ./IPCserver(enter)
   (you will get)
   waiting for reply..
   (after entering the file name in terminal of IPC client and enter that ,here in server you ll get the reply of that file ,
   both the therminals for ipc server and client should be open simultaneously and first execute server program n then client)
  */
