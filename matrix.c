#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double** control_init_matrix(int row,int column,int flag){
    //input:Row and column is row-index and column-index in 2-dim array respectively.
    //flag is judge as produce matrix's type which have auto and hand-input.There will be hand-input when flag == 0;
    //output:Array which is 2 dimensionality.

    int max = ((row>column)?row:column),i,j;
    double** matrix = malloc(max * sizeof(double*));
    for(i=0;i<max;i++)
        matrix[i] = malloc(max * sizeof(double));
    for(i=0;i<row;i++){
        for(j=0;j<column;j++)
            if(flag==0){
                scanf("%lf",&matrix[i][j]);
            }else{
                printf("random");
                matrix[i][j]=rand();
            }
        printf("\n");
    }
    if(max == row && max != column){
            for(i=0;i<max;i++){
                for(j=column;j<max;j++){
                    matrix[i][j]=0; 
                }
            }
    
    }else if(max==column&&max!=row){
          for(i=row;i<max;i++){
              for(j=0;j<max;j++){
                matrix[i][j]=0.0;
              }      
          }
    }
    printf("Matrix has done：\n");
    for(i=0;i<max;i++){
        for(j=0;j<max;j++)
            printf("%lf ",matrix[i][j]);
        printf("\n");
    
    }
    return matrix;
}

void free_array(double** arr,int row){
    //input:row is first index in 2-dim array and 
    //arr which is double-deck point to array .
    //output:free 2-dim array.

    int i;
    for(i=0;i<row;i++){
            free(arr[i]);
    }
    free(arr);
    printf("Free memory has been completed.\n");

}

double** brute_matrix(double** ma,double** mb,int arow,int acolmun,int brow,int bcolmun){
        //function:use brute algorithm compute matrix multiplication.
        //input:ma,mb is matrix and arow,acolmun ,brow ,bcolmun is parameter.
        //output:Matrix multiplication result.
        int i,j,k;
        double** matrix;
    if(acolmun==brow){
        matrix = malloc(arow*sizeof(double*));
        for(i=0;i<acolmun;i++){
            matrix[i]=malloc(arow*sizeof(double));
        }

        for(i=0;i<arow;i++){
            for(j=0;j<bcolmun;j++){
                for(k=0;k<acolmun;k++)
                    matrix[i][j] += ma[i][k]*mb[k][j];
            }
        }
        
    }else{
        printf("Those matrix cannot use multiplication!");
    
    }
    printf("Result matrix is two-matrix multiplication output：\n");
    for(i=0;i<arow;i++){
        for(j=0;j<arow;j++)
            printf("%lf ",matrix[i][j]);
        printf("\n");
    
    }
   
    return matrix;



}
void output_matrix(double** matrix,int max){
    //function:Print matrix result.
    //inpput:Max is matrix dimension.
    
    int i,j;
    for(i=0;i<max;i++){
        for(j=0;j<max;j++)
            printf("%lf ",matrix[i][j]);
        printf("\n");
    
    }
}
double** allocate_memory(int n){
    //input:n is dimension of array. 
    //output:one two-dimension matrix;
    int i;
    double** matrix;
    matrix = malloc(n * sizeof(double*));
    for(i=0;i<n;i++)
        matrix[i]=malloc(n * sizeof(double));

    return matrix;
    

}
double** matrix_add(double** ma,double** mb,int row,int flag){
    //function:excute addition/substract.
    //input:two matrix and flag as judge addition or substract.There will be use addition when
    //flag == 1;
    //output:matrix.
     int i,j;
     double** matrix;
     matrix = allocate_memory(row);
     for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            if(flag==1){
                matrix[i][j]=ma[i][j]+mb[i][j];
            }else{
                matrix[i][j]=ma[i][j]-mb[i][j];
            }
        }
     }
    return matrix;
}

double** strassen_matrix(double** ma,double** mb,int row){
    //function:Use straseen algorithm compute two matrix multiplication.
    //input:Two matrix which is ma and mb,row is dimension of matrix.
    //output:product of multiplication.
    double **matrix,**A_00,**A_01,**A_10,
           **A_11,**B_00,**B_01,**B_10,**B_11,**C_00,**C_01,**C_10,**C_11,**m1,**m2,**m3,**m4,**m5,**m6,**m7,**temp_0,**temp_1;

    int i,j;
    matrix = allocate_memory(row);
    if(row==2){

        matrix = brute_matrix(ma,mb,row,row,row,row);
        return matrix;
    }else{
        //allocating memory.
        A_00 = allocate_memory(row/2);
        A_01 = allocate_memory(row/2);
        A_10 = allocate_memory(row/2);
        A_11 = allocate_memory(row/2);
        B_00 = allocate_memory(row/2);
        B_01 = allocate_memory(row/2);
        B_10 = allocate_memory(row/2);
        B_11 = allocate_memory(row/2);

        m1 = allocate_memory(row/2);
        m2 = allocate_memory(row/2);
        m3 = allocate_memory(row/2);
        m4 = allocate_memory(row/2);
        m5 = allocate_memory(row/2);
        m6 = allocate_memory(row/2);
        m7 = allocate_memory(row/2);
        C_00 = allocate_memory(row/2);
        C_01 = allocate_memory(row/2);
        C_10 = allocate_memory(row/2);
        C_11 = allocate_memory(row/2);
        temp_0 = allocate_memory(row/2);
        temp_1 = allocate_memory(row/2);

        for(i=0;i<row/2;i++){
            for(j=0;j<row/2;j++){//A_00~A_11 and B_00~B_11
                    A_00[i][j] = ma[i][j]; 
                    A_01[i][j] = ma[i][row/2+j];
                    A_10[i][j] = ma[row/2+i][j];
                    A_11[i][j] = ma[row/2+i][row/2+j];
                    B_00[i][j] = mb[i][j]; 
                    B_01[i][j] = mb[i][row/2+j];
                    B_10[i][j] = mb[row/2+i][j];
                    B_11[i][j] = mb[row/2+i][row/2+j];
               }
         }
        temp_0 = matrix_add(A_00,A_11,row/2,1);
        temp_1 = matrix_add(B_00,B_11,row/2,1);
        m1 = strassen_matrix(temp_0,temp_1,row/2);
        temp_0 = matrix_add(A_10,A_11,row/2,1);
        m2 = strassen_matrix(temp_0,B_00,row/2);
        temp_0 = matrix_add(B_01,B_11,row/2,0);     
        m3 = strassen_matrix(A_00,temp_0,row/2);
        temp_0 = matrix_add(B_10,B_00,row/2,0);
        m4 = strassen_matrix(A_11,temp_0,row/2);    
        temp_0 = matrix_add(A_00,A_01,row/2,1);
        m5 = strassen_matrix(temp_0,B_11,row/2);
 
       // printf("m5:\n");
  
        temp_0 = matrix_add(A_10,A_00,row/2,0);
        temp_1 = matrix_add(B_00,B_01,row/2,1);
        m6 = strassen_matrix(temp_0,temp_1,row/2);
 
        temp_0 = matrix_add(A_01,A_11,row/2,0);
        temp_1 = matrix_add(B_10,B_11,row/2,1);
        m7 = strassen_matrix(temp_0,temp_1,row/2);
    
        //calculate C00-C11
        temp_0 = matrix_add(m1,m4,row/2,1);
        temp_1 = matrix_add(temp_0,m5,row/2,0);
        C_00 = matrix_add(temp_1,m7,row/2,1);

        C_01 = matrix_add(m3,m5,row/2,1);

        C_10 = matrix_add(m2,m4,row/2,1);

        temp_0 = matrix_add(m1,m3,row/2,1);
        temp_1 = matrix_add(temp_0,m2,row/2,0);
        C_11 = matrix_add(temp_1,m6,row/2,1);
        
        //combine c00-c11 to matrix.
        for(i=0;i<row/2;i++){
            for(j=0;j<row/2;j++){
                matrix[i][j] =C_00[i][j]; 
                matrix[i][row/2+j]=C_01[i][j];
                matrix[i+row/2][j]=C_10[i][j];
                matrix[i+row/2][j+row/2]=C_11[i][j];
            }
        }
        output_matrix(matrix,row);
        return matrix;
    
    }
}


int main(){

    double **ma,**mb,**mz;
    ma = control_init_matrix(1024,1024,1);
    mb = control_init_matrix(1024,1024,1);
    //mz = brute_matrix(ma,mb,4,4,4,4);
    mz = strassen_matrix(ma,mb,1024);
    free_array(ma,1024);
    free_array(mb,1024);
    free_array(mz,1024);
    return 0;
}
