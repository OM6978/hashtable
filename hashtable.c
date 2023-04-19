#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tableelem
{
    char* val;
    struct tableelem* Next;
    struct tableelem* Prev;
}tableelem;
typedef tableelem* Ptrelem;

typedef struct hashtableelem
{
    Ptrelem First;
}hashtableelem;

hashtableelem hash[13];

void Initializetableelem(char* val,int key)
{
    Ptrelem Current=hash[key].First,Parent=NULL;
    while(Current!=NULL)
    {
        Parent=Current;
        Current=Current->Next;
    }
    Current=(Ptrelem)malloc(sizeof(tableelem));
    Current->val=val;
    Current->
}

int hashfunction(char* str)
{
    int key,sum=0;
    for(int i=0;str[i]!='\0';i++)
    {
        sum+=(int)str[i];
    }
    key=sum%13;
    return key;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int N;
    scanf("%d",&N);
    char str[N+1];
    scanf("%s",str);
    str[N]='\0';
    int key=hashfunction(str);
    printf("%d\n",key);
    Initializetableelem()
    }
    return 0;
}