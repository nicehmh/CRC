#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 20
/*
   �����͵�����M
   ����P
   ����R
   ���͵�֡����F
 */
/*��ӡ����ǰnλ*/
void showarr(char *p,int n=0){
 if(n==0||n<0){
  while(*p!='\0'){
    cout<<*p;
    p++;
  }
 }else{
    for(int i=0;i<n;i++){
      cout<<p[i];
    }
 }
 cout<<endl;
}
/*��ǰ��λ*/
void getNewR(char *R,char h){
    char *C=NULL;
    int n=strlen(R);
    C=R;
    for(int i=1;i<n;i++){
      R[i-1]=C[i];
    }
    R[n-1]=h;
}
/*ģ2����*/
int sub(char *R,char *P){
    if(R[0]!='0'){
       int n=strlen(R);
       for(int i=0;i<n;i++){
            if(R[i]==P[i]){
                R[i]='0';
            }else{
                R[i]='1';
            }
       }
    }
}
/*ģ2���� ����*/
int getremainder(char *M,char *P,char *R){
      int n=strlen(P),k=strlen(M),l=n;
      strncpy(R,M,n);
      int flag=0;
      while(flag<k){
          sub(R,P);
          if(l<k){
            getNewR(R,M[l]);
          }else{
            getNewR(R,'0');
          }
          l++;
          flag++;
      }
}
int main(){
  // char *M="101001",*P="1101";
   char SM[N],SP[N];
   cout<<"����������͵����ݺͳ�����01���У�"<<endl;
   scanf("%s ",SM);
   scanf("%s",SP);
   char *M=SM,*P=SP;
   char R[N]={'0'},F[N]={'0'};
   getremainder(M,P,R);
   cout<<"����Ϊ:";
   showarr(R,strlen(P)-1);
   strcpy(F,M);
   strncat(F,R,strlen(P)-1);
   cout<<"���͵�����Ϊ:";
   showarr(F);
   getremainder(F,P,R);
   for(int i=0;i<strlen(R);i++){
        if(R[i]!='0'){
          cout<<"���г���"<<endl;
          return 0;
        }
   }
   cout<<"accept"<<endl;
   return 0;
  }
