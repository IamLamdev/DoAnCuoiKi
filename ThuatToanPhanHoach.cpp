#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define input "dothi.txt"

void docDoThi(int A[][SIZE], int &n)
{
    FILE *fi = fopen(input,"rt");
    if (fi == NULL){
        printf("Khong mo duoc file");
        exit(0);
    }
    fscanf(fi,"%d",&n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            fscanf(fi,"%d",&A[i][j]);
        }
    }
    fclose(fi);
}

void toMau(int A[][SIZE], int n, int Mau[])
{
    int BangMau[SIZE][SIZE] = {0};
    int mauvuato;
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            if(BangMau[i][k] == 0){
                Mau[i] = k;
                mauvuato = k;
                break;
            }
        }
        for(int j=i+1; j<n; j++){
            if(A[i][j] > 0){
                BangMau[j][mauvuato] = 1;
            }
        }
    }
}

void xuat(int A[], int n, int mau)
{
    for(int i=0; i<n; i++){
        if(A[i] == mau){
           printf("%d ", i+1);
        }
    }
    printf("\n");
}

int main()
{
    int A[SIZE][SIZE], Mau[SIZE], n;
    docDoThi(A,n);
    toMau(A, n, Mau);
    int maugiongnhau=0;
    for(int i=0; i<n; i++)
    {
        xuat(Mau,n,maugiongnhau);
        maugiongnhau++;
    }
    return 0;
}

