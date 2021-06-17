# Intro To System Calls
## **Q1** 
- It will reverse the contents of file and store the result in a new directory named **Assignment**. 
- Percentage Progress will be printed on console during file writing.
- Even Large files, larger than RAM size can be given as input.
### How to Run
```
gcc Q1.c
./a.out <path of file to be reversed>
```
### Assumptions
1. If number of inputs is not according to requirement ,it will not work.
2. If the input file does not exist it will give the required perror.
3. If the input file is empty it will give error since file is empty and since according to question, it will print 100% then also it will create the new empty file and directory.
4. Nothing is mentioned regarding group and others permission for file and directory I have given only read 
	permissions.
5. "Assignment" Directory and output file will be formed where code is executed.
6. If directory already exist , it will use that folder only.
7. If output file already exists new output file will replace it.

#### Logic
	I am reading the file from end using lseek system call and at one time reading 10^8 bytes using buffer and then reversing it 
	and storing it in the output file till finish reading of the input file.


## **Q2**
- It will output the permissions for the oldfile, newfile and directory.
- It will check whether the contents of newfile are reverse of oldfile.
### How to Run
```
gcc Q2.c
./a.out <newfile> <oldfile> <directory>
```
### Assumptions
1. If number of inputs is not according to requirement ,it will not work.
2. If any of the file or directory does not exist ,it will not print the permissions for that.
3. If the input file does not exist it will give the required perror.
4. It will check for reverse content between the files only if both files exist.

#### Logic
	Using similar logic from Q1, it will read newfile from end and old file from beginning (at one time 10^8 bytes)
	and compare their characters .If no character is different we can conclude that newfile is reverse of old file.
