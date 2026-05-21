#include<stdio.h>
#include<string.h>

int N, K1, K2;
char str[1101];
char* data[500000];
int data_size[500000];

void set_DNA_bank(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%s",str);
        data[i]=strdup(str);
        data_size[i] = strlen(data[i]);
    }
    scanf("%d %d",&K1,&K2);
}


int get_size(){
    return N;
}

char DNA_base(int i, int j){
    if(j<data_size[i-1])return data[i-1][j-1];
    else return '$';
}

void get_index(int* index1, int* index2){
    *index1 = K1;
    *index2 = K2;
}

void report(int index1, int index2){
    printf("%d %d\n",index1, index2);
}