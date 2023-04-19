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

void Insert(char* val,int key)
{
    Ptrelem Current=hash[key].First,Parent=NULL;
    while(Current!=NULL)
    {
        Parent=Current;
        Current=Current->Next;
    }
    Current=(Ptrelem)malloc(sizeof(tableelem));
    Current->val=val;
    Current->Prev=Parent;
    Current->Next=NULL;
    if(Parent==NULL){hash[key].First=Current;}
    else{Parent->Next=Current;}
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

void Printhashtablelem(int key)
{
    Ptrelem Current=hash[key].First;
    while(Current!=NULL)
    {
        printf("%s ",Current->val);
        Current=Current->Next;
    }
    printf("\n");
    return;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    char *storage[Test];
    for(int i=0;i<Test;i++)
    {
    int N;
    scanf("%d",&N);
    storage[i]=(char*)malloc(sizeof(char)*(N+1));
    scanf("%s",storage[i]);
    storage[i][N]='\0';
    int key=hashfunction(storage[i]);
    Insert(storage[i],key);
    }
    for(int i=0;i<13;i++)
    {
        printf("%d: ",i);
        Printhashtablelem(i);
    }
    return 0;
}
