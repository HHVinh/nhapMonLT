#include <stdio.h>
#include <math.h>

int main(){
    int n, dem = 0;
        printf("Hãy nhập một số bất kì: ");
        scanf("%d",&n);
        if (n<=1)
        {
            printf("%d không là số nguyên tố\n", n);
        }
        else{
            for(int i = 2; i <= sqrt(n); i++){
                if(n%i==0){
                    dem +=1;
                    break;
                }
            }
            if(dem == 0){
                printf("%d là số nguyên tố\n", n);
            }
            else{
                printf("%d không là số nguyên tố\n", n);
            }
        }
    return 0;
}