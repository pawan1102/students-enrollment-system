#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct stu
{
int id;
char name[20];
}
s;
FILE *fp, *t;
int idno, found, op;
char sname[20], ch;
void newstu();
void enquiry();
void report();
void upd();
void del();

void line()
{
puts("-------------------------------------------------");
}
void main()
{
//clrscr();
system("cls");
line();
puts("\t\t\t STUDENT ENROLLMENT SYSTEM");
line();
puts("\t\t\t 1. New stu");
puts("\t\t\t 2. Enquiry");
puts("\t\t\t 3. Report");
puts("\t\t\t 4. Update");
puts("\t\t\t 5. Delete");
puts("\t\t\t 6. Exit");
line();
printf("\t\t\t Enter Ur option[ ]\b\b");

scanf("%d",&op);
switch(op)
{
case 1:
newstu();
break;
case 2:
enquiry();
break;
case 3:
report();
break;
case 4:
upd();
break;
case 5:
del();
break;

case 6:
exit(0);
default:
printf("Invalid selection");
}
getch();
main(); /* recursioin*/
}
void newstu()
{
//clrscr();
system("cls");
fp = fopen("11am.dat","a");
while(1)
{
printf("Enter stu id, name ");
scanf("%d %s",&s.id,s.name);
fwrite(&s,sizeof(s),1,fp);
puts("1 row created");

//flushall();
fflush(stdin);
printf("Next stu [y/n] ");
scanf("%c",&ch);
if(ch!='y'&&ch!='Y')break;
}
fclose(fp);
}

void enquiry()
{
//clrscr();
system("cls");
found=0;
fp = fopen("11am.dat","r");
puts("1. Id wise");
puts("2. Name wise");
line();
printf("Enter Ur Option: ");
scanf("%d",&op);

if(op==1)
{
printf("Enter stu id to search ");
scanf("%d",&idno);
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(idno==s.id)
{
puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
found=1;
break;
}
fread(&s,sizeof(s),1,fp);
}
}

else if(op==2)
{
printf("Enter stu name to search ");
scanf("%s",&sname);
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(stricmp(sname,s.name)==0)
{
puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
found=1;
break;
}
fread(&s,sizeof(s),1,fp);
}
}

fclose(fp);
if(found==0)puts("Stu not found");
}

void report()
{
//clrscr();
system("cls");
fp = fopen("11am.dat","r");
puts("Id\tName");
line();
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
printf("%d\t%s\n",s.id,s.name);
fread(&s,sizeof(s),1,fp);
}
fclose(fp);

}

void upd()
{
//clrscr();
system("cls");
found=0;
fp = fopen("11am.dat","r+"); /* read and write */
printf("Enter stu id to update ");
scanf("%d",&idno);
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(idno==s.id)
{
puts("id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
printf("Enter new id, name ");

scanf("%d %s",&s.id,s.name);
fseek(fp, ftell(fp)-sizeof(s),0);
fwrite(&s,sizeof(s),1,fp);
puts("1 row updated");
found=1;
break;
}
fread(&s,sizeof(s),1,fp);
}
fclose(fp);
if(found==0)puts("Stu not found");
}

void del()
{
//clrscr();
system("cls");
fp = fopen("11am.dat","r");
t = fopen("temp","w");

printf("Enter stu id to delete ");
scanf("%d",&idno);
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(idno==s.id)
{
puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
found=1;
}
else fwrite(&s,sizeof(s),1,t);
fread(&s,sizeof(s),1,fp);
}
fclose(fp);
fclose(t);
if(found==0)

puts("Stu not found");
else
{
//flushall();
fflush(stdin);
printf("R u sure to delete ");
scanf("%c",&ch);
if(ch=='y'||ch=='Y')
{
remove("11am.dat");
rename("temp","11am.dat");
puts("One row deleted");
}
else
puts("Operation cancelled");
}
}