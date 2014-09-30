#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Random(x) (rand()%x)

void print_array(int* array,int index){
    //input:array is point to array.
    //output:printing to screen.
    int i;
    for(i=1;i<index+1;i++)
        printf("%d ",array[i]);
    printf("\n");

}
int* product_array(int n,int flag){
    //function:product array.
    //input:n is number of array,and you will hand input when flag=1.
    //output:one array which is fit heapsort as array[0] is sentinel.
    int* array = malloc((n+1)*sizeof(int));
    int i;
    array[0]=-1;
    if(flag==1){
       printf("Please input element of array in following:\n");
       for(i=1;i<n+1;i++)
           scanf("%d",&array[i]);
       
    }else{
       printf("Following is pruduced by random.\n");
       for(i=1;i<n+1;i++)
           array[i]=Random(100);

    }
    printf("So,following is your input:\n");
    print_array(array,n);

    return array;

}


int* bottom_up_heap(int* array,int n){
    //function:product a heap from array[1] to array[n].
    //input:array and n that is array boundary.
    //output:array[1] to array[n] is sorted by bottom-up.
    int i,temp;
    for(i=n;i>1;i--){
        if(i%2==0){
            if(array[i]>array[i/2]){
                temp = array[i];
                array[i]=array[i/2];
                array[i/2]=temp;
            }
        }else{
            if(array[i]>=array[i-1]){
                if(array[i]>=array[(i-1)/2]){
                    temp = array[i];
                    array[i]=array[(i-1)/2];
                    array[(i-1)/2]=temp;
                
                }

            }else{
                if(array[i-1]>array[(i-1)/2]){
                    temp = array[i-1];
                    array[i-1]=array[(i-1)/2];
                    array[(i-1)/2]=temp;
                
                }

            }

        }
    }
    return array;
}
int* maxdelete(int* heap,int n){
    //function:delete root in maximum-top-heap.
    //input:one heap.
    //output:one heap which was deleted root.
    int temp;
    temp=heap[1];
    heap[1]=heap[n];
    heap[n]=temp;
    print_array(heap,n);
    return heap;


}
int* heapsort(int* heap,int n){
    //function:This heap will be sorted by heapsort.
    //input:heap is array that is a set of number and n is length of array.
    //output:one array which is sorted alreadly.
    
    int i;
    int *bottom_heap,*rootdel;
    for(i=n;i>1;i--){
         bottom_heap = bottom_up_heap(heap,i);
         rootdel = maxdelete(bottom_heap,i);
    }
    return rootdel;
    
}


int main(){
    int *heap,*heap_sorted;
    int n;
    clock_t start,end;
    double times;
    printf("Please input length of heap:\n");
    scanf("%d",&n);
    printf("Now,we will be product a heap:\n");
    heap = product_array(n,1);
    printf("Now,begining sorting:\n");
    start = clock();
    heap_sorted = heapsort(heap,n);
    end = clock();
    print_array(heap_sorted,n);
    times = (double)(end-start);
    printf("Sorted numbers of %d is %lf\n",n,times);
   // free(heap_sorted);
   // free(heap);
    return 0;
}
