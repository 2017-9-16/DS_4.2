#include "stdlib.h"
#include "stdio.h"    
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
    
		STRING* cur=s;
        while (cur->next!=NULL) 
		{
            cur=cur->next;
        }
        cur->next=t->next;     //将串t中字符序列放入串s的尾部
        free(t);
}
STRING *substr(STRING *s,int start,int len){
    int i;
    STRING *t,*tail,*p,*cur;
    t=(STRING *)malloc(sizeof(STRING));
    if (start<0||start>=length(s)||len>length(s)-start)       //取子串的合法性验证
    {
        printf("截取不合法");
        return NULL;
    }
    else
        if (len>=1){
            cur=s;
            for (i=0; i<start; i++) {
                cur=cur->next;
            }
            if (t==NULL) {
                return NULL;
            }
            t->next=NULL;
            tail=t;
            
            for (i=0; i<len; i++) {
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
STRING * GetData(STRING * head,int i)
{
	STRING* p;
	int j=0;
	if(i<=0)
	{
		return NULL;
	}
	p=head;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j)
		return p;
	else return NULL;
}
void del(STRING * s,int start,int len){
    int i;
    STRING* cur,*dur;
    
        if (start<=length(s)&&len>=0&&start+len<=length(s)) {
            if(start==1)
			{	
				cur=s;
				dur=GetData(s,start+len-1);
			}
			else 
			{
				cur=GetData(s,i-1);
				dur=GetData(s,start+len-1);
			}

            cur->next=dur->next;
			free(dur);
            
    }
        else printf("不能删除");

} 
void print(STRING* s){    //输出串的字符序列
    int i;
    STRING *cur=s->next;
   
    while (cur->next!=NULL) {
        printf("%c",cur->c);
        cur=cur->next;
    }
    printf("%c",cur->c);
    printf("\n");
}
int main(){
    STRING *head,*t,*v;                   
    int start,len;
  

    printf("please input the string s: ");       //创建S串
    head=creat();
    //print(head);
    t=creat();
    //print(t);
    concat(head, t);
	printf("the new string s: ");
    print(head);
    printf("plese input the start position(substr): ");    //输入截取子串的起始位置
    scanf("%d",&start);
    printf("please input the length: ");        //输入截取子串的长度
    scanf("%d",&len);
    v=substr(head,start,len);                   //截取子串
    printf("the substring: ");
    print(v);
	//printf("%d",length(head));
    printf("plese input the start position: ");    // 输入删除串的起始位置
    scanf("%d",&start);
    printf("please input the length(del): ");        //输入删除串的长度
    scanf("%d",&len);
    del(head,start,len);     //删除串
    printf("the deleted string s: ");
    print(head);
    
}
