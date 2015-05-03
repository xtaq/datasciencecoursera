#include <stdio.h>
bool map[10001][10001]={0};
int a[10001];
int main(){
	int m , n ;
	int i , j , k;
	int count ;
	int x , y ;
	scanf("%d%d" , &n ,&m);
	while( m-- )
	{
		scanf("%d%d" , &x ,&y );
		map[x-1][y-1]=map[y-1][x-1]=1;
	}
/*	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < n ; j ++ )
		{
			printf ("%d ", map[i][j] );
		}
		printf("\n");
	}
	*/
	for( i = 0; i < n ; i++ )
	{
		count = 0 ;
		for( j = 0 ; j < n ; j ++)
		{
			if (map[i][j] == 1)
			{
				a[count++] = j;
	//			printf("%d %d\n",count , j );
			}
		}
		for( j = 0 ; j < count ; j++)
		{
			for( k = j + 1 ; k < count ; k++)
			{
				if ( map[a[j]][a[k]] == 1 )
				{
	//				printf("jj%d %d\n" , j ,k );
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("1\n");
	return 0;
}
