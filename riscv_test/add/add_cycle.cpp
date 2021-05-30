#include <stdio.h>
#include <iostream>
#include "riscv_vector.h"
using namespace std;
long long read_cycles(void)
{
  long long cycles;
  asm volatile ("rdcycle %0" : "=r" (cycles));
  return cycles;
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
	long long cycles_start, cycles_end;

	int a[4]={1,2,3,4};
	int b[4]={101,102,103,104};
	cycles_start = read_cycles();
	addxy(n,&a[0],&b[0]);
	cycles_end = read_cycles();
	printf("scalar : cycles = %lld\n", cycles_end - cycles_start);


	int x[4]={1,2,3,4};
	int y[4]={101,102,103,104};
	cycles_start = read_cycles();
	addxyrvv(1,&x[3],&y[3]);
	cycles_end = read_cycles();
	printf("1 data: cycles = %lld\n", cycles_end - cycles_start);


	int x2[4]={1,2,3,4};
	int y2[4]={101,102,103,104};
	cycles_start = read_cycles();
	addxyrvv(2,&x2[2],&y2[2]);
	cycles_end = read_cycles();
	printf("2 data: cycles = %lld\n", cycles_end - cycles_start);

	int x3[4]={1,2,3,4};
	int y3[4]={101,102,103,104};
	cycles_start = read_cycles();
	addxyrvv(3,&x3[1],&y3[1]);
	cycles_end = read_cycles();
	printf("3 data: cycles = %lld\n", cycles_end - cycles_start);


	int x4[4]={1,2,3,4};
	int y4[4]={101,102,103,104};
	cycles_start = read_cycles();
	addxyrvv(4,&x4[0],&y4[0]);
	cycles_end = read_cycles();
	printf("4 data: cycles = %lld\n", cycles_end - cycles_start);

	// int x5[4]={1,2,3,4};
	// int y5[4]={101,102,103,104};
	// cycles_start = read_cycles();
	// addxyrvvm2(4,&x5[0],&y5[0]);
	// cycles_end = read_cycles();
	// printf("4 data m2: cycles = %lld\n", cycles_end - cycles_start);

	int x7[8]={1,2,3,4,5,6,7,8};
	int y7[8]={101,102,103,104,105,106,107,108};
	cycles_start = read_cycles();
	addxyrvvm2(5,&x7[3],&y7[3]);
	cycles_end = read_cycles();
	printf("5 data m2: cycles = %lld\n", cycles_end - cycles_start);

	int x8[8]={1,2,3,4,5,6,7,8};
	int y8[8]={101,102,103,104,105,106,107,108};
	cycles_start = read_cycles();
	addxyrvvm2(6,&x8[2],&y8[2]);
	cycles_end = read_cycles();
	printf("6 data m2: cycles = %lld\n", cycles_end - cycles_start);

	int x9[8]={1,2,3,4,5,6,7,8};
	int y9[8]={101,102,103,104,105,106,107,108};
	cycles_start = read_cycles();
	addxyrvvm2(7,&x9[1],&y9[1]);
	cycles_end = read_cycles();
	printf("7 data m2: cycles = %lld\n", cycles_end - cycles_start);

	int x10[8]={1,2,3,4,5,6,7,8};
	int y10[8]={101,102,103,104,105,106,107,108};
	cycles_start = read_cycles();
	addxyrvvm2(8,&x10[0],&y10[0]);
	cycles_end = read_cycles();
	printf("8 data m2: cycles = %lld\n", cycles_end - cycles_start);

	int x11[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	int y11[16]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	for(int i = 9;i<=16;i++){
		for(int j = 0;j<16;j++){
			x11[j]=j;
		}
		cycles_start = read_cycles();
		addxyrvvm4(i,&x11[16-i],&y11[16-i]);
		cycles_end = read_cycles();
		printf("%d data m4: cycles = %lld\n", i, cycles_end - cycles_start);
	}
	

	// int x11[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	// int y11[16]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	// cycles_start = read_cycles();
	// addxyrvvm4(16,&x11[0],&y11[0]);
	// cycles_end = read_cycles();
	// printf("16 data m4: cycles = %lld\n", cycles_end - cycles_start);

	int x12[32]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	int y12[32]={101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108,101,102,103,104,105,106,107,108};
	for(int i = 17;i<=32;i++){
		for(int j = 0;j<32;j++){
			x12[j]=j;
		}
		cycles_start = read_cycles();
		addxyrvvm8(i,&x12[32-i],&y12[32-i]);
		cycles_end = read_cycles();
		printf("%d data m8: cycles = %lld\n", i, cycles_end - cycles_start);
	}

	return 0;
}
