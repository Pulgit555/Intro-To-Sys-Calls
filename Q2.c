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
	if(a!=4)
	{
		//if no. of inputs are not correct.
		char s1[100000];
		sprintf(s1,"Please enter correct no. of inputs\n");
		write(1,s1,strlen(s1)+1);
	}
	else
	{
		long long int l,m,p,q,g,h,t=0,x;
		long long int fd1,fd2,n=100000000,k=100000000;
		DIR *fd = opendir(b[3]);
		size_t sz,sz1;
		struct stat sb,sb1,sb2;
		char s2[100000];
		stat(b[1],&sb);
		stat(b[2],&sb1);
		stat(b[3],&sb2);

		if(fd==NULL)
		{
			//file doesn't exist; 
			sprintf(s2,"Directory is created: No\n");
			write(1,s2,strlen(s2)+1);
		}
		else
		{
			sprintf(s2,"Directory is created: Yes\n");
			write(1,s2,strlen(s2)+1);
		}
		fd1 = open(b[1],O_RDONLY);
		if(fd1<0)
		{
			sprintf(s2,"newfile doesn't exist\n");
			write(1,s2,strlen(s2)+1);
			perror("e1");
		}
		else
		{
			fd2 = open(b[2],O_RDONLY);
			if(fd2<0)
			{
				perror("e2");
				sprintf(s2,"oldfile doesn't exist\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sz = sb.st_size;
				sz1 = sb1.st_size;
				if((long long int)sz!=(long long int)sz1)
				{
					sprintf(s2,"Whether file contents are reversed in newfile: No\n");
					write(1,s2,strlen(s2)+1);
				}
				else
				{
					t=0;
					g=0;
					k=0;
					l=(long long int)sz;
					while(l>0)
					{
						char *c = (char *) calloc(n, sizeof(char));
						char *c1 = (char *) calloc(n, sizeof(char));
						char *c2 = (char *) calloc(n, sizeof(char));
						if(l<n)
						{
							q=l;
							k=k-q;
							lseek(fd1, k, SEEK_END);
							m = read(fd1,c,q);
							lseek(fd2, g, SEEK_CUR);
							h = read(fd2,c2,q);
							g=g+q;
						}
						else
						{
							q=n;
							k=k-q;
							lseek(fd1,k, SEEK_END);
							m = read(fd1,c,q);
							lseek(fd2, g, SEEK_CUR);
							h = read(fd2,c2,q);
							g=g+q;
						}
						for(int i=0;i<m;i++)
						{
							c1[m-i-1]=c[i];
						}
						for(int i=0;i<h;i++)
						{
							if(c1[i]!=c2[i])
							{
								t++;
								break;
							}
						}
						l=l-q;
						free(c);
						free(c1);
						free(c2);
					}
					if(t==0)
					{
						/*since there is no element in newfile(read from beginning)
						 which is different from oldfile(read from end)*/
						sprintf(s2,"Whether file contents are reversed in newfile: Yes\n");
						write(1,s2,strlen(s2)+1);
					}
					else
					{
						sprintf(s2,"Whether file contents are reversed in newfile: No\n");
						write(1,s2,strlen(s2)+1);
					}
				}
			}
		}
		if(fd1!=0)
		{
			sprintf(s2,"\n");
			write(1,s2,strlen(s2)+1);
			if(sb.st_mode & S_IRUSR)
			{
				sprintf(s2,"User has read permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has read permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IWUSR)
			{
				sprintf(s2,"User has write permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has write permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IXUSR)
			{
				sprintf(s2,"User has execute permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has execute permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IRGRP)
			{
				sprintf(s2,"Group has read permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has read permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IWGRP)
			{
				sprintf(s2,"Group has write permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has write permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IXGRP)
			{
				sprintf(s2,"Group has execute permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has execute permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IROTH)
			{
				sprintf(s2,"Others has read permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has read permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IWOTH)
			{
				sprintf(s2,"Others has write permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has write permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb.st_mode & S_IXOTH)
			{
				sprintf(s2,"Others has execute permission on newfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has execute permission on newfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
		}
		if(fd2!=0)
		{
			sprintf(s2,"\n");
			write(1,s2,strlen(s2)+1);
			if(sb1.st_mode & S_IRUSR)
			{
				sprintf(s2,"User has read permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has read permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IWUSR)
			{
				sprintf(s2,"User has write permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has write permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IXUSR)
			{
				sprintf(s2,"User has execute permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has execute permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IRGRP)
			{
				sprintf(s2,"Group has read permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has read permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IWGRP)
			{
				sprintf(s2,"Group has write permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has write permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IXGRP)
			{
				sprintf(s2,"Group has execute permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has execute permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IROTH)
			{
				sprintf(s2,"Others has read permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has read permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IWOTH)
			{
				sprintf(s2,"Others has write permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has write permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb1.st_mode & S_IXOTH)
			{
				sprintf(s2,"Others has execute permission on oldfile: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has execute permission on oldfile: No\n");
				write(1,s2,strlen(s2)+1);
			}
		}
		if(fd!=NULL)
		{
			sprintf(s2,"\n");
			write(1,s2,strlen(s2)+1);
			if(sb2.st_mode & S_IRUSR)
			{
				sprintf(s2,"User has read permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has read permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IWUSR)
			{
				sprintf(s2,"User has write permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has write permission on directory: No\n");
				write(1,s2,strlen(s2)+1);	
			}
			if(sb2.st_mode & S_IXUSR)
			{
				sprintf(s2,"User has execute permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"User has execute permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IRGRP)
			{
				sprintf(s2,"Group has read permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has read permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IWGRP)
			{
				sprintf(s2,"Group has write permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has write permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IXGRP)
			{
				sprintf(s2,"Group has execute permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Group has execute permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IROTH)
			{
				sprintf(s2,"Others has read permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has read permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IWOTH)
			{
				sprintf(s2,"Others has write permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has write permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
			if(sb2.st_mode & S_IXOTH)
			{
				sprintf(s2,"Others has execute permission on directory: Yes\n");
				write(1,s2,strlen(s2)+1);
			}
			else
			{
				sprintf(s2,"Others has execute permission on directory: No\n");
				write(1,s2,strlen(s2)+1);
			}
		}
	}
	return 0;
}