#include<stdio.h>
void adjust_down(int a[],int len,int k){
    int temp=a[k];
    for(int i=2*k+1;i<len;i=2*i+1){
        if(a[i]<a[i+1]&&i<len-1)
            ++i;
        if(a[i]>temp){
            a[k]=a[i];
            k=i;
        }
        else{
            break;
        }
        
    }
    a[k]=temp;
}

void build_heap(int a[],int len){
    for (int i=len/2-1;i>=0;--i){
        adjust_down(a,len,i);
    }
}
int main(){
    int len;
    scanf("%d",&len);
    int a[len];
    
    for(int i=0;i<len;++i){
        scanf("%d",&a[i]);
    }
    build_heap(a,len);
    for(int i=0;i<len;++i){
        printf("%d ",a[i]);
    }
    
    return 0;
}