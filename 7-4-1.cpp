//https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long long n;
    int count;
    while((scanf("%lld", &n))!=EOF){
        if(n==0)
            break;
        count=0;
        while(n>=2){
            if(n%3)
            {
                n=n/3+1;
            }
            else{
                n=n/3;
            }
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}

//https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a
int main()
{
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        long long total=pow(5,n)-4;
        long long left=pow(4,n)+n-4;
        cout<<total<<" "<<left<<endl;
    }
    return 0;
}

