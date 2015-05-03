#include<stdio.h>
#define MAX 600001
typedef struct node{
	bool f;
	char c[45];
	struct node *next;
}node;

typedef struct vnode{
	struct node *next;
}vnode;

vnode root[MAX+100];
bool strcmp(char* a , char* b)
{
	int i=0;
	while( a[i++] )
	{
		if( a[i] != b[i] )
			return false;
	}
	return true ;
}
int hash(char* a)
{
	int i = 0;
	long temp = 1;
	int seed = 61;
	while(a[i++])
	{
	//	printf("%ld\n",temp);
		temp = temp*seed +( a[i-1] - 'a'+ 1 );
	}
	return temp % MAX;
}
void add(char* a,int x)
{
	node *p = new node;
	p->f = true ;
	p->next = root[x].next;
	root[x].next = p;
}
int find(char* a )
{
	int x;
	x = hash(a);
//	printf("hashcode %d\n",x);
	node *p = root[x].next;
	while(p)
	{
		if( strcmp(p->c , a))
		{
			if(p->f)
			{
				printf("%s\n", a);
				p->f = false ;
				return 1;
			}
			else
			{
				return 1;
			}
		}
		p = p->next;
	}
	add( a , x );
	return 0;
}
		
int main()
{
	int n ;
	char s1[45] ;
	scanf("%d",&n);
	getchar();
	while( n-- )
	{
		scanf("%s", s1);
		find( s1 );
	}

	return 0;
}
