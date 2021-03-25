#include<stdio.h>
#include<stdlib.h>
void convertor(const char* filename)
{
  FILE* fp;
  fp=fopen(filename,"r+");
  if(fp==NULL)
  printf("file does not exist!");
  else
  {
  int c1;
  int c2;
  int k=0;
  int c;
  int d;
    while(c!=EOF)
    {
        c1=k;
    	while(c!=' '&&c!='.'&&c!=EOF)
    	{
    	  c=fgetc(fp);
    	  k=k+1;
	}
	if(c==' '||c=='.')
    	{
		c2=k-2;
		while(c1<c2)
		{
			fseek(fp,c1,SEEK_SET);
			c=fgetc(fp);
			fseek(fp,c2,SEEK_SET);
			d=fgetc(fp);
			if((d!='a'&&d!='i'&&d!='o'&&d!='e'&&d!='u')&&
			(c!='a'&&c!='i'&&c!='o'&&c!='e'&&c!='u'))
			{
				fseek(fp,c2,SEEK_SET);
				fputc(c,fp);
				fseek(fp,c1,SEEK_SET);
				fputc(d,fp);
				c2=c2-1;
				c1=c1+1;

			}
			else if(d!='a'&&d!='i'&&d!='o'&&d!='e'&&d!='u')
			{
			 c1=c1+1;
			}
			else if(c!='a'&&c!='i'&&c!='o'&&c!='e'&&c!='u')
			{
			 c2=c2-1;
			}
			else 
			{
			 c1=c1+1;
			 c2=c2-1;
			}
			
		}		
    	}
	fseek(fp,k,SEEK_SET);	 
    } 
    fclose(fp);
  }
}
int main(int arg,char** args)
{
	convertor(args[1]);
	return 0;
}
