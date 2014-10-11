#include<stdio.h>
int* quicksort(int list[],int left,int right){
    if(left < right){ 
        int i = left,j = right;
        int key = list[i];
        while(i < j){
            while(i < j && list[j] >= key){
                j--;
            }
            if(i < j){
                list[i++] = list[j];    
            }

            while(i < j && list[i] < key){
                i++;
            }

            if(i < j){
                list[j--] = list[i];
            }
        }
        list[i] = key;
        quicksort(list,left,i-1);
        quicksort(list,i+1,right);
    }

    return list;
}



int main(){
    int i=0,list[] = {2321,232,123,1923,898,100,92};
    int* result;
    result = quicksort(list,0,6);
    for(i =0;i<7;i++)
        printf("%d,",result[i]);
}
