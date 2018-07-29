#include <stdio.h>

int main(int argc, char const *argv[])
{
    int TC, a, b;
    int c = 1;
    //faster way to get data in than cin etc.
    while(scanf("%d %d",&a,&b) != EOF){
        printf("Case %d: %d\n\n", c++, a+b);
    }
    return 0;
}
