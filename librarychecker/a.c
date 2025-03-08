#include<stdio.h>
#include<stdlib.h>

int main(){
	int* ptr;
  int n,i;
	scanf("%d",&n);
	printf("%d\n",n);
	long sum=0;
	for(int i=0;i<n;i++){
		ptr=(int*)malloc(i*sizeof(int));
		sum+=i*sizeof(int);
		if(ptr==NULL){
			printf("%d\n",i);
			printf("failed\n");
			return 0;
		}
		else{
		}
		printf("%ld\n",sum);
	}
	printf("all successed\n");
	return 0;
}
