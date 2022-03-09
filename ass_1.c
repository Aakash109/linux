#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void main ()
{
int f1,f2,len,total;
char buff_copy[100];
char new[100];
f1=open("hello.txt",O_RDONLY,777);

read(f1,buff_copy,100);
total=lseek(f1,0,SEEK_END);
close(f1);
printf("total=%d \n",total);

f2=open("new1.txt",O_RDWR|O_CREAT,777);
write(f2,buff_copy,total);
read(f2,new,total);
printf("the data=%s\n",new);

close(f2);

}
