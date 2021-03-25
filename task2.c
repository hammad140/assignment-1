#include<stdio.h>
#define con 40
void addRecord(const char* filename)
{
   char str[con];
   FILE* fp=fopen(filename,"a+");
   printf("Enter your name:\n");
   gets(str);
gets(str);
   fputs("NAME: ",fp);
   fputs(str,fp);
   fputc('\n',fp);
   printf("Enter your Roll number:\n");
   gets(str);
   fputs("ROLL NUMBER: ",fp);
   fputs(str,fp);   printf("Enter your email:\n");
   fputc('\n',fp);
   gets(str);
   fputs("EMAIL: ",fp);
   fputs(str,fp);
   fputc('\n',fp);

}
void ReadRecord(const char* filename)
{
   int c;
   char str[con];
   printf("Enter record you want to read(0, 1 or 2) \n");
   scanf("%d", &c);
   FILE* fp=fopen(filename,"r");
   int k=(3+3*c);
	   for(int i=0;i<k;i++)
	   {
	     fgets(str,con,fp);
	     if(k-i<=3)
	     printf("%s",str);
	   }
}
void deleteRecord(const char* filename)
{
   int c;
   char str[con];
   printf("Enter record you want to delete(0, 1 or 2) \n");
   scanf("%d", &c);
   char ch;
   int temp=0;
   FILE* fp=fopen(filename,"r");
   FILE* fileptr2 = fopen("replica.c", "w");
   int k=3*c;
    while (ch != EOF)
    {
        ch = getc(fp);
        if (ch == '\n')
            temp++;
            if(temp!=k && temp!=k+1 &&temp!=k+2)
	    {
                putc(ch, fileptr2);
            }
    }
    fclose(fp);
    fclose(fileptr2);
    remove(filename);
    rename("replica.c", filename);
}

int main()
{
int c;
char b;
 printf("To add record press 1\n To Read record press 2\n To delete a record press 3\n");
 scanf("%d",&c);
  if(c==2)
ReadRecord("file2.txt");
else if(c==1)
{
addRecord("file2.txt");

}
else if(c==3)
deleteRecord("file2.txt");
return 0;
}
