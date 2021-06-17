#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
int main(int a, char** b)
{
	if(a!=2)
	{
		//if no. of inputs are not correct.
		char s1[100000];
		sprintf(s1,"Please enter correct no. of inputs\n");
		write(1,s1,strlen(s1)+1);
	}
	else
	{
		long long int z=0,t,k=0;
		double per;
		long long int fd,l,m,n=100000000,p,q,o=-1;
		char s2[200000]="Assignment/",s3[100000],s4[100000];
		size_t sz;
		struct stat sb;
		stat(b[1],&sb);
		sz = sb.st_size;
		t=(long long int)sz;
		for(int i=strlen(b[1])-1;i>=0;i--)
		{
			if(b[1][i]=='/')
			{
				o=i;
				break;
			}
		}
		if(o==-1)
		{
			for(int i=0;i<strlen(b[1]);i++)
			{
				s4[i]=b[1][i];
			}
		}
		else
		{
			for(int i=o+1;i<strlen(b[1]);i++)
			{
				s4[i-o-1]=b[1][i];
			}
		}
		for(int i=11;i<11+strlen(b[1]);i++)
		{
			s2[i]=s4[i-11];
		}

		fd = open(b[1],O_RDONLY);
		if(fd<0)
		{
			//file doesn't exist so print error
			perror("e1");
		}
		else
		{
			DIR *fd1 = opendir("Assignment");
			if(fd1==NULL)
			{
				//if directory already doesnot exist form it.
				int fd2 = mkdir("Assignment",0744);
			}
			int fd4 = open(s2,O_RDONLY);
			if(fd4>0)
			{
				//if output file already exist delete that file
				remove(s2);
			}
			//else create output file
			int fd3 =open(s2, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if((long int)sz==0)
			{
				//if input file is empty.
				sprintf(s3,"Percentage 100%c",'%');
				write(1,s3,strlen(s3)+1);
				sprintf(s3,"There is no content in file");
				write(1,s3,strlen(s3)+1);
			}
			while((long long int)sz>0)
			{
				char *c = (char *) calloc(n, sizeof(char));
				char *c1 = (char *) calloc(n, sizeof(char));
				if(sz<n)
				{
					q=sz;
					k=k-q;
					lseek(fd,k, SEEK_END);
					l = (long long int)read(fd,c,sz);
				}
				else
				{
					q=n;
					k=k-q;
					lseek(fd, k, SEEK_END);
					l= (long long int)read(fd,c,n);
				}
				//percentage progress
				z=z+(long long int)q;
				per=(double)((double)z*100)/t;
				sprintf(s3,"Percentage %0.2lf%c \r",per,'%');
				write(1,s3,strlen(s3)+1);

				for(int i=0;i<l;i++)
				{
					c1[l-i-1]=c[i];
				}
				sz=(long long int)sz-q;
				m = write(fd3,c1,l);
				free(c);
				free(c1);
			}
			sprintf(s3,"\n");
			write(1,s3,strlen(s3)+1);
			close(fd);
			close(fd3);
		}
	}
	return 0;
}