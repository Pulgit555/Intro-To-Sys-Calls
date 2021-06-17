Q1=>

Assumptions=> 
1.) if number of inputs is not according to requirement ,it will not work.
2.) if the input file does not exist it will give the required perror.
3.) if the input file is empty it will give error since file is empty and since according to question, 
	it will print 100% then also it will create the new empty file and directory.
4.) nothing is mentioned regarding group and others permission for file and directory i have given only read 
	permissions.
5.) "Assignment" Directory and output file will be formed where code is executed.
6.) If directory already exist , it will use that folder only.
7.) if output file already exists new output file will replace it.

Logic=>
	I am reading the file from end using lseek system call and at one time reading 10^8 bytes using buffer reversing
	and storing it output file till finish reading the full file.


Q2=>

Assumptions=>
1.) if number of inputs is not according to requirement ,it will not work.
2.) if any of the file or directory does not exist ,it will not print the permissions for that.
3.) if the input file does not exist it will give the required perror.
4.) it will check for reverse content between the files only if both files exist.

Logic=>
	Using similar logic from Q1, it will read newfile from end and old file from beginning (at one time 10^8 bytes)
	and compare their characters .If no character is different that is newfile is reverse of old file.

