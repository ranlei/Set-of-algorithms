#include<stdlib.h>
#include<stdio.h>

double* compare(double* c1,double* c2,int n){
    //function:compare accumulate  of two array,return minimum above.
    //input:two arrays which has equaivalent numbers.
    //output:one arrays or 0.
    double val1,val2,temp;
    int i;
    double* ptr;
    ptr = malloc(2*sizeof(double));
    for(i=0;i<n;i++){
        val1 += c1[i];
        val2 += c2[i];
    }

    if(val1==val2){

        ptr[0]=0;
        ptr[1]=0;
        return ptr;
    }else{
        temp = (val1<val2)?val1:val2;
        if(temp==val1){
            return c1;
        }else{
            return c2;
        }
    }
        
}

double* fake_coin(double* coinset,int n){
    //funtion:Finding a fake coin above a numbers of coin.
    //input:one fake coin set and a numbers of coins.
    //output: weight of fake coin.
    double *ptr,*min,*coin_1,*coin_2,*temp1,*temp2;
    int i;
    if(n==2){
        temp1 = malloc(sizeof(double));
        temp2 = malloc(sizeof(double));
        min = malloc(sizeof(double));
        *temp1 = coinset[0];
        *temp2 = coinset[1];
        min=compare(temp1,temp2,1);
        return min;      
    }else if(n%2==0){
        printf("bingo:\n");
        coin_1 = malloc(n/2 * sizeof(double));
        coin_2 = malloc(n/2 * sizeof(double));
        min = malloc(n/2 * sizeof(double));
        for(i=0;i<n/2;i++){
            coin_1[i]=coinset[i];
            coin_2[i]=coinset[n/2+i];
        }
        min = compare(coin_1,coin_2,n/2);
        return fake_coin(min,n/2);
    }else if(n%2==1){
        coin_1 = malloc(n/2 * sizeof(double));
        coin_2 = malloc(n/2 * sizeof(double));
        min = malloc(n/2 * sizeof(double));
        temp1 = malloc(2 * sizeof(double));
        for(i=0;i<n/2;i++){
            coin_1[i]=coinset[i];
            coin_2[i]=coinset[n/2+i];
        }
        *temp1=coinset[n-1];
        min = compare(coin_1,coin_2,n/2);
        if(min[0]==0){
            return temp1;
        }else{
            return fake_coin(min,n/2);
        
        }
    
    }else if(n==1){
        return coinset;
    
    }else{
    
        printf("error!");
    
    }
    
}
double* init_coinset(int n){
    double* coin;
    int i;
    coin = malloc(n*sizeof(double));
    for(i=0;i<n;i++){
        scanf("%lf",&coin[i]);
    }
    printf("Coin set as Following:\n");
    for(i=0;i<n;i++)
       printf("%lf ",coin[i]);
    printf("\n");

    return coin;

}
void output_fake_coin(double* argv){
    printf("weight of fake coin:%lf\n",*argv);

}

int main(){
    double *c1,*fake;
    c1 = init_coinset(5);
    fake = fake_coin(c1,5);
    output_fake_coin(fake);
    free(c1);
    free(fake);
    return 0;
}

