#include<stdio.h>
#include<string.h>
int subStringFinder(const char* filename,const char* substring)
{
	 FILE *fp;
  fp = fopen(filename,"r");
	if (fp == NULL)
		printf("file does not exist!\n");
	else
   {
   int count=0;
	int n = strlen(substring);
	int c;
	int i=0;
	 while(c!=EOF) {
	      c = fgetc(fp);
	      if(c==substring[0])
	      {
	      	while(i<n&&c==substring[i])
	      	{
	      	  i=i+1;
	      	  c=fgetc(fp);
	      	}
	      	if(i==n)
	      	{
	      	count=count+1;
	      	}
	      	fseek(fp,-i,SEEK_CUR);
	      	i=0;

	      }
	   }
	   return count;
	   fclose(fp);
   }
}
int main(int args,char** arg) {
	int a=subStringFinder(arg[1], arg[2]);
	   printf("The number of occurences are: %d\n",a);
	return 0;
}
