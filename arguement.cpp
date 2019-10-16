#include<stdio.h>
#include<stack>

int main(){
    char a[100000];
    printf("qing input string:\n");
    scanf("%s",a);
    std::stack<char> st;
    int len=strlen(a);
    st.push(a[0]);

    for(int i=1;i<len;i++){
        if(st.top()=='R'&&a[i]=='L'){
            st.pop();
            while(!st.empty()&&st.top()=='R'){
                st.pop();
                
            }
            st.push('R');
            
        }
        else{
            st.push(a[i]);
        }
    }
    printf("minNum:%d\n",st.size());
    return 0;
}