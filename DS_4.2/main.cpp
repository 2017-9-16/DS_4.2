#include "stdlib.h"
#include "stdio.h"
#define STRINGMAX 81
#define LEN sizeof(struct string)        //串的定义
struct string{
    //int len;
    struct string* next;
    char c;
};
typedef struct string STRING;

STRING* creat(){
    char c;
    STRING *head;
    STRING *p,*tail;
    head=(STRING*)malloc(sizeof(STRING));
    if (head==NULL) {
        return NULL;
}      head->next=NULL;
    tail=head;
    printf("请输入数据:\n");
    scanf("%c",&c);
    while (c!='\n') {
        p=(STRING*)malloc(sizeof(STRING));
        if (p==NULL) {
            return NULL;
        }
        p->c=c;
        tail->next=p;
        tail=p;
        tail->next=NULL;
        scanf("%c",&c);
        
    }
    return head;
}
int length(STRING* head)
{
    STRING* p=head;
    int j=0;
    while (p->next!=NULL) {
        p=p->next;
        j++;
    }
    return j;
}
void concat(STRING* s,STRING* t){
    int j;
    STRING*cur=s;
    if(length(s)+length(t)>(STRINGMAX-1))   //连接操作合法性验证
        printf("too long!cannot concat!!");
    
    else{
        j=length(s);
        while (cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=t;     //将串t中字符序列放入串s的尾部
        free(t);
    }
}
STRING *substr(STRING *s,int start,int len){
    int i;
    STRING *t,*tail,*p,*cur;
    t=(STRING *)malloc(sizeof(STRING));
    if (start<0&&start>=length(s))       //取子串的合法性验证
    {
        printf("截取不合法");
        return NULL;
    }
    else
        if (len>=1&&len<=length(s)-start){
            cur=s;
            for (i=0; i<start; i++) {
                cur=cur->next;
            }
            if (t==NULL) {
                return NULL;
            }
            t->next=NULL;
            tail=t;
            
            for (i=1; i<len; i++) {
                p=(STRING*)malloc(sizeof(STRING));
                if (p==NULL) {
                    return NULL;
                }
                p->c=cur->c;
                tail->next=p;
                tail=p;
                tail->next=NULL;
                cur=cur->next;
            }
            
            return t;
        }
        else
            return NULL;
}
void del(STRING * s,int start,int len){
    int i;
    STRING* p=s,*q=s;
    while (s->next!=NULL) {
        if (start<=length(s)&&len>=0&&start+len<=length(s)) {
            for (i=1; i<start; i++) {
                p=p->next;
            }
            for (i=0; i<start+len; i++) {
                q=q->next;
            }
            p->next=q->next;
            free(q);
    }
        else printf("不能删除");
}
} void print(STRING* s){    //输出串的字符序列
    int i;
    STRING *cur=s->next;
    if (cur->next==NULL) {
        printf("串为空");
    }
    while (cur->next!=NULL) {
        printf("%c",cur->c);
        cur=cur->next;
    }
    printf("%c",cur->c);
    printf("\n");
}
int main(){
    STRING *head,*t,*v;                    //定义三个采用静态存储形式的串
    int start,len;
    //t=(STRING )malloc(LEN);          //为三个串分配相应的存储空间
    // s=(STRING )malloc(LEN);
    //v=(STRING )malloc(LEN);
    printf("please input the string s: ");       //创建S串
    head=creat();
    print(head);
    t=creat();
    print(t);
    concat(head, t);
    print(head);
    printf("plese input the start position(substr): ");    //输入截取子串的起始位置
    scanf("%d",&start);
    printf("please input the length: ");        //输入截取子串的长度
    scanf("%d",&len);
    v=substr(head,start,len);                   //截取子串
    printf("the substring: ");
    print(v);
    
    

    /*printf("please input the string t: ");      //创建T串
    concat(s,t);                          //连接并输出相应的串
    printf("the new string s: ");
    print(s);

   
    printf("plese input the start position: ");    // 输入删除串的起始位置
    scanf("%d",&start);
    printf("please input the length(del): ");        //输入删除串的长度
    scanf("%d",&len);
    del(s,start,len);     //删除串
    printf("the deleted string s: ");
    print(s);*/
}
