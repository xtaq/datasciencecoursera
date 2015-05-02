#include <stdio.h>
typedef struct node{
    int num;
    struct node *next;
}node;
typedef struct vnode{
    int out;
    int in;
    struct node *next;
}vnode;
vnode root[1000001];
int stack[1000001];
int stack1[1000001];
int top1;
int top;
int empty(){
	if (top == 0)
	return 1;
	else 
	return 0;
}
int empty1(){
	if(top1 == 0)
	return 1;
	else
	return 0;
}
void push (int x)
{
	stack[top] = x;
	top ++;
}
void push1(int x)
{
	stack1[top1] = x;
	top1++;
}
int pop1 (){
	top1--;
	return stack1[top1];
}
int pop (){
	top --;
	return stack[top];
}
void add(int v1,int v2){
    root[v1].out++;
    root[v2].in++;
    node *newnode = new node;
    newnode->num = v2;
    newnode->next = root[v1].next;
    root[v1].next  = newnode;
}
int main(){
    int m , n ;
    int v1 , v2;
    int i;
    int count = 0;
    int mark;
    node *p;
    scanf ("%d%d",&n,&m);
    for(  i = 1; i <= m ; i ++)
    {
        scanf("%d%d",&v1,&v2);
        add(v1,v2);
    }
    for( i = 1; i<= n ; i ++)
    {
    	if(root[i].in == 0)
	{
		push(i);
		root[i].in = -1;
	}
    }
   /* for( i = 1; i <= n ;i ++)
    {
    	printf("\n%d",i);
	p = root[i].next;
	while(p)
	{
		printf("->%d",p->num);
		p = p->next;
	}
    }*/
    while(!empty())
    {
    	count++;
	while(!empty())
	{
		mark = pop();
		if( root[mark].next)
		{
			p = root[mark].next;
			root[p->num].in--;
			if(root[p->num].in == 0)
			{
				push1(p->num);
			}
			p = p->next;
		}
		while(p)
		{
			root[p->num].in--;
			if(root[p->num].in == 0)
			push1(p->num);
			p = p->next;
		}
	}
	/*for(i = 1; i <= n ; i ++)
	{
		if(root[i].in == 0)
		{
			push(i);
			root[i].in = -1;
		}
	}*/
	if(empty1())
	break;
	while(!empty1())
	{
		push(pop1());
	}
		
     }
     printf("%d",count );

/*
	
    for( i = 1 ; i <= n ;i ++)
    {
        printf("%d %d %d\n",i,root[i].in,root[i].out);
    }
    */
    return 0;
}
