#include <stdio.h>
#include <iostream>
#include "riscv_vector.h"
using namespace std;
long long read_instrets(void)
{
  long long instrets;
  asm volatile ("rdinstret %0" : "=r" (instrets));
  return instrets;
}

void addxy(int n, int* x, int* y){
	int a = *x;
	int b = *y;
	while(n>0){
		a = a + b;
		n-=1;
	}
	*x = a;
	return ;
}

void addxyrvv(int n, int* x, int* y){
	int vl = vsetvl_e32m1(n);
	//printf("vl = %d ", vl);
	vle_v0_i32m1(x);
	vle_v1_i32m1(y);
	int num = 800*600;
	while(num>0){
		vadd_v01_vv_i32m1();
		num-=1;
	}
	vse_v0_i32m1(x);
	return;
}

void addxyrvvm2(int n, int* x, int* y){
	int vl = vsetvl_e32m2(n);
	//printf("vl = %d ", vl);
	vle_v0_i32m2(x);
	vle_v1_i32m2(y);
	int num = 800*600;
	while(num>0){
		vadd_v01_vv_i32m2();
		num-=1;
	}
	vse_v0_i32m2(x);
	return;
}

void addxyrvvm4(int n, int* x, int* y){
	int vl = vsetvl_e32m4(n);
	//printf("vl = %d ", vl);
	vle_v0_i32m4(x);
	vle_v1_i32m4(y);
	int num = 800*600;
	while(num>0){
		vadd_v01_vv_i32m4();
		num-=1;
	}
	vse_v0_i32m4(x);
	return;
}

void addxyrvvm8(int n, int* x, int* y){
	int vl = vsetvl_e32m8(n);
	//printf("vl = %d ", vl);
	vle_v0_i32m8(x);
	vle_v1_i32m8(y);
	int num = 800*600;
	while(num>0){
		vadd_v01_vv_i32m8();
		num-=1;
	}
	vse_v0_i32m8(x);
	return;
}


int main(){

	int n = 800*600;
	long long instrets_start, instrets_end;

	int a[4]={1,2,3,4};
	int b[4]={101,102,103,104};
	instrets_start = read_instrets();
	addxy(n,&a[0],&b[0]);
	instrets_end = read_instrets();
	printf("scalar : instrets = %lld\n", instrets_end - instrets_start);


	int x[4]={1,2,3,4};
	int y[4]={101,102,103,104};
	instrets_start = read_instrets();
	addxyrvv(1,&x[3],&y[3]);
	instrets_end = read_instrets();
	printf("1 data: instrets = %lld\n", instrets_end - instrets_start);


	int x2[4]={1,2,3,4};
	int y2[4]={101,102,103,104};
	instrets_start = read_instrets();
	addxyrvv(2,&x2[2],&y2[2]);
	instrets_end = read_instrets();
	printf("2 data: instrets = %lld\n", instrets_end - instrets_start);

	int x3[4]={1,2,3,4};
	int y3[4]={101,102,103,104};
	instrets_start = read_instrets();
	addxyrvv(3,&x3[1],&y3[1]);
	instrets_end = read_instrets();
	printf("3 data: instrets = %lld\n", instrets_end - instrets_start);


	int x4[4]={1,2,3,4};
	int y4[4]={101,102,103,104};
	instrets_start = read_instrets();
	addxyrvv(4,&x4[0],&y4[0]);
	instrets_end = read_instrets();
	printf("4 data: instrets = %lld\n", instrets_end - instrets_start);

	// int x5[4]={1,2,3,4};
	// int y5[4]={101,102,103,104};
	// instrets_start = read_instrets();
	// addxyrvvm2(4,&x5[0],&y5[0]);
	// instrets_end = read_instrets();
	// printf("4 data m2: instrets = %lld\n", instrets_end - instrets_start);

	int x7[8]={1,2,3,4,5,6,7,8};
	int y7[8]={101,102,103,104,105,106,107,108};
	instrets_start = read_instrets();
	addxyrvvm2(5,&x7[3],&y7[3]);
	instrets_end = read_instrets();
	printf("5 data m2: instrets = %lld\n", instrets_end - instrets_start);

	int x8[8]={1,2,3,4,5,6,7,8};
	int y8[8]={101,102,103,104,105,106,107,108};
	instrets_start = read_instrets();
	addxyrvvm2(6,&x8[2],&y8[2]);
	instrets_end = read_instrets();
	printf("6 data m2: instrets = %lld\n", instrets_end - instrets_start);

	int x9[8]={1,2,3,4,5,6,7,8};
	int y9[8]={101,102,103,104,105,106,107,108};
	instrets_start = read_instrets();
	addxyrvvm2(7,&x9[1],&y9[1]);
	instrets_end = read_instrets();
	printf("7 data m2: instrets = %lld\n", instrets_end - instrets_start);

	int x10[8]={1,2,3,4,5,6,7,8};
	int y10[8]={101,102,103,104,105,106,107,108};
	instrets_start = read_instrets();
	addxyrvvm2(8,&x10[0],&y10[0]);
	instrets_end = read_instrets();
	printf("8 data m2: instrets = %lld\n", instrets_end - instrets_start);

	int x11[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	int y11[16]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	for(int i = 9;i<=16;i++){
		for(int j = 0;j<16;j++){
			x11[j]=j;
		}
		instrets_start = read_instrets();
		addxyrvvm4(i,&x11[16-i],&y11[16-i]);
		instrets_end = read_instrets();
		printf("%d data m4: instrets = %lld\n", i, instrets_end - instrets_start);
	}
	

	// int x11[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	// int y11[16]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	// instrets_start = read_instrets();
	// addxyrvvm4(16,&x11[0],&y11[0]);
	// instrets_end = read_instrets();
	// printf("16 data m4: instrets = %lld\n", instrets_end - instrets_start);

	int x12[32]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	int y12[32]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	instrets_start = read_instrets();
	addxyrvvm8(32,&x12[0],&y12[0]);
	instrets_end = read_instrets();
	printf("32 data m8: instrets = %lld\n", instrets_end - instrets_start);



	return 0;
}
