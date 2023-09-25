#include <stdio.h>
#include <string.h>
struct stu
{
    char a[100],pas[100];
}s[100];
struct book
{
    char bk[100],an[100];
    double p;
    int f;
}b[100];
void admin();
void student();
void add();
void view();
void Issue();
void lend();
void Return();
void student_create();
void stulogin();
void save();
void search();
int sc=0,bc=0,x=1000;

int main()
{
    int n;
    printf("--> ***** Useless Library Management ****** <--\n");
    while(1)
    {
        printf("\n1.Admin\n2.student\n3.Exit\nEnter the Choice :");
        scanf("%d",&n);
        if(n==1)
            admin();
        else if(n==2)
            student();
        else{
            printf("\n!!!!!!!!! .......... Thank You For Visit ......... !!!!!!");
            break;
        }
            
    }
    return 0;
}
void admin()
{
    char a[100],b[100];
    int n;
    printf("Enter a id :");
    scanf("%s",a);
    printf("Enter a Pass :");
    scanf("%s",b);
    if(!strcmp(a,"t4teq") && !strcmp(b,"12345"))
    {
        while(1)
        {
            printf("\n1.Add books\n2.Issue books\n3.Save Report\n4.Exit\nEnter the Choice :");
            scanf("%d",&n);
            if(n==1)
                add();
            else if(n==2)
              Issue();
            else if(n==3)
                save();
            else{
                break;
            }
        }
    }
    else
        printf("\nInvalid Id Or Password .... !!!!!");
}
void student()
{
    int n;
    while(1)
    {
        printf("\n1.Sign Up\n2.Sign In\n3.Exit\nEnter the Choice :");
        scanf("%d",&n);
        if(n==1)
            student_create();
        else if(n==2)
            stulogin();
        else{
            break;
        }
    }
}
void student_create()
{
    int i,n;
    printf("\nEnter Student Name :");
    scanf("%s",s[sc].a);
    printf("\nEnter Student Pass :");
    scanf("%s",s[sc].pas);
    printf("Student Id Is : %d",sc+500);
    sc++;
}
void stulogin()
{
    char a[100],b[100];
    int t,n;
    FILE *p;
    printf("\n Enter student name:");
    scanf("%s",a);
    printf("\nEnter Student Id :");
    scanf("%d",&t);
    printf("\nEnter Student Pass :");
    scanf("%s",b);
    p=fopen("library","a");
    fprintf(p,"\n\n__Student details__");
    fprintf(p,"\nStudent name :%s\nStudent id:%d",a,t);
    fclose(p);
    if((t>=500 && t<=(sc+500)) && !strcmp(b,s[t-500].pas))
    {
        while(1)
        {
            printf("\n1.View books\n2.search books\n3.lend books\n4.Return books\n5.Exit\nEnter the Choice :");
            scanf("%d",&n);
            if(n==1)
                view();
            else if(n==2)
                 search();
            else if(n==3)
                lend();
            else if(n==4)
                Return();
            else{
                break;
            }
        }
    }
    else
        printf("\nInvalid Id Or Password .... !!!!!");
}
void add()
{
    int i,n;FILE *p;
    printf("\nEnter the No.of Books :");
    scanf("%d",&n);
    p=fopen("library.txt","a");
    fprintf(p,"\n____The books added in the library are:___");
    for(i=0;i<n;i++)
    {
        printf("\nEnter Book Name :");
        scanf("%s",b[bc].bk);
        fprintf(p,"\nBookname:%s",b[bc].bk);
        printf("\nEnter Author Name :");
        scanf("%s",b[bc].an);
        fprintf(p,"\nAuthor name:%s",b[bc].an);
        printf("\nEnter Book Price :");
        scanf("%lf",&b[bc].p);
        fprintf(p,"\nBook price:%lf",b[bc].p);
        b[bc].f=1;
        printf("Book Id Is : %d",bc+1000);
        fprintf(p,"\nbook id :%d",bc+1000);
        bc++;
    }
    fclose(p);
    x+=n;
}
void view()
{
    int i,f=0;
    FILE *p;
    printf("\n%d",bc);
    p=fopen("library.txt","r");
    fprintf(p,"\n\n___The books in the library___");
    for(i=0;i<bc;i++)
    {
        if(b[i].f==1)
        {
            f=1;
            printf("\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\nBook Id :%d\n\n",b[i].bk,b[i].an,b[i].p,i+1000);
           
            fprintf(p,"\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\nBook Id :%d\n\n",b[i].bk,b[i].an,b[i].p,i+1000);
        }
    }
    if(f==0)
        printf("Book is Empty");
   fclose(p);
}
void Issue()
{
    int i,f=1;
    printf("\n%d",bc);
    FILE *p;
    p=fopen("library.txt","a");
    fprintf(p,"\n__The books to be issued__");
    for(i=0;i<bc;i++)
    {
        if(b[i].f!=1)
        {
            f=0;
            printf("\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\nBook Id :%d\n\n",b[i].bk,b[i].an,b[i].p,i+1000);
           fprintf(p,"\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\nBook Id :%d\n\n",b[i].bk,b[i].an,b[i].p,i+1000);
        }
    }
    if(f==1)
        printf("Book is Empty ..... !!!!!!!!!");
    fclose(p);
}
void lend()
{
    int i,f=0,n,g;
    FILE *p;
    printf("Enter You Book Id : ");
    scanf("%d",&n);
    p=fopen("library.txt","a");
    fprintf(p,"\nthe books went out from library:");
    if(g!=1)
    {
        if(n>=1000 && n<=(bc+1000))
        {
            if(b[n-1000].f==1)
            {
                b[n-1000].f=0;
                printf("lended Successfully...");
                g=1;
            }
            else
            printf("book not available ...");
        }
    }
    else if(g==1)
    {
        printf("||||||......only one book can be lended......||||||");
    }
    else
        printf("||||||......Book Not Avilable......||||||");
    for(i=0;i<bc;i++)
    {
        if(b[i].f==0)
        {
            f=1;
            
           fprintf(p,"\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\nBook Id :%d\n\n",b[i].bk,b[i].an,b[i].p,i+1000);
        }
    }
    if(f==0)
        printf("Book is Empty ..... !!!!!!!!!");
    fclose(p);
}
void Return()
{
    int i,f=0,n;
    printf("Enter You Book Id : ");
    scanf("%d",&n);
    if(n>=1000 && n<=(bc+1000))
    {
        if(b[n-1000].f==0)
        {
            b[n-1000].f=1;
            printf("Returned Successfully...");
        }
        else
            printf("not lended ...");
    }
    else
        printf("Book Not Avilable ..... !!!!!!!!!");
}
void save()
{
     FILE *p;
     p=fopen("library.txt","r");
     fclose(p);
    printf("open library file to view the saved details ");
    
}
void search()
{
    int z,f=0,i;
    FILE *p;
    p=fopen("library.txt","a");
    printf("\nEnter Book Id:");
    scanf("%d",&z);
    while(1)
    {
        sum:
        if(z<=x)
        {
            f=1;
            break;
        }
        else
        {
            i++;
            goto sum;
        }
        break;
    }
    if(f==1)
    {
        i=z-1000;
        printf("book found");
        printf("\nBook Name :%s\nAuthor Name :%s\nBook Price :%f\n\n",b[i].bk,b[i].an,b[i].p);
    }
    else
    {
        printf("book not found");
    }
}





