#include<stdio.h>
int c[10][1000]={0};
//0-1背包问题的状态方程
void knap(int w[],int v[],int m,int n){
   for(int i=1;i<n+1;++i){
      for(int j=1;j<m+1;++j){
         if((c[i-1][j-w[i]]+v[i]>c[i-1][j])&&(j>=w[i])){
            c[i][j]=c[i-1][j-w[i]]+v[i];
         }
         else{
            c[i][j]=c[i-1][j];
         }
      }
   }
}

int main()
{
   int m,n;
   printf("input max weight and the number of goods:\n");
   scanf("%d,%d",&m,&n);
   printf("input every good's weight and value:\n");
   int w[n+1],v[n+1];
   for (int i=1;i<n+1;++i){
      scanf("%d,%d",&w[i],&v[i]);
   }
   knap(w,v,m,n);
   printf("max values=");
   printf("%d\n",c[n][m]);
   return 0;
}
