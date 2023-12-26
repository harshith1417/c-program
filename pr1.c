#include<stdio.h>
int t,z=1;
int boo(int n)
{
    if(n == 0){
        return 1;
    }
    else{
        boo(n/10);
        if(n%10 == t%10){
            t=t/10;
        }
        else{
            z=0;
            return z;
        }
    }
return z;
}

int main(){

    int n=200002;
    t=n;
   int p= boo(n);
   
   printf("%d",p);

    }