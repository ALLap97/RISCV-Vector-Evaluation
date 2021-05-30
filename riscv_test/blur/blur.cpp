#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include "riscv_vector.h"

using namespace cv;
using namespace std;

long long read_instrets(void)
{
  long long instrets;
  asm volatile ("rdinstret %0" : "=r" (instrets));
  return instrets;
}

void averageBlur(Mat& src, Mat& dst){
	int rows = src.rows ;
	int cols = src.cols ;
	uchar* data_src = src.data;
	uchar* data_dst = dst.data;
	for(int i = 1;i<rows-1;i++){
		for(int j = 1;j<cols-1; j++){
			float tem = 0;

			tem += *(data_src + cols*(i-1) + j-1);
			tem += *(data_src + cols*(i-1) + j);
			tem += *(data_src + cols*(i-1) + j+1);
			tem += *(data_src + cols*(i) + j-1);
			tem += *(data_src + cols*(i) + j);
			tem += *(data_src + cols*(i) + j+1);
			tem += *(data_src + cols*(i+1) + j-1);
			tem += *(data_src + cols*(i+1) + j);
			tem += *(data_src + cols*(i+1) + j+1);

			*(data_dst + cols*(i) + j) = tem/9;
		
		}
		
	}
}

void averageBlurRVV(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;

	for(int i =1;i<rows-1;i++){
		int n = cols-4;
		for(int j = 2;j<cols-2;){
			int vl=vsetvl_e32m1(n);
			vle_v0_u8m1(data_src + cols*i + j);
			vle_v1_u8m1(data_src + cols*(i-1) + j-1);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*(i-1) + j);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*(i-1) + j+1);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*i + j-1);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*i + j+1);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*(i+1) + j-1);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*(i+1) + j);
			vadd_v01_vv_i32m1();
			vle_v1_u8m1(data_src + cols*(i+1) + j+1);
			vadd_v01_vv_i32m1();

			vdiv_v0_vx_u32m1(9);
			vse_v0_u8m1(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
		
	}
}

void averageBlurRVV_m2(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;

	for(int i =1;i<rows-1;i++){
		int n = cols-4;
		for(int j = 2;j<cols-2;){
			int vl=vsetvl_e32m2(n);
			vle_v0_u8m2(data_src + cols*i + j);
			vle_v1_u8m2(data_src + cols*(i-1) + j-1);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*(i-1) + j);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*(i-1) + j+1);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*i + j-1);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*i + j+1);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*(i+1) + j-1);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*(i+1) + j);
			vadd_v01_vv_i32m2();
			vle_v1_u8m2(data_src + cols*(i+1) + j+1);
			vadd_v01_vv_i32m2();

			vdiv_v0_vx_u32m2(9);
			vse_v0_u8m2(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
		
	}
}


void averageBlurRVV_m4(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;

	for(int i =1;i<rows-1;i++){
		int n = cols-4;
		for(int j = 2;j<cols-2;){
			int vl=vsetvl_e32m4(n);
			vle_v0_u8m4(data_src + cols*i + j);
			vle_v1_u8m4(data_src + cols*(i-1) + j-1);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*(i-1) + j);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*(i-1) + j+1);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*i + j-1);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*i + j+1);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*(i+1) + j-1);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*(i+1) + j);
			vadd_v01_vv_i32m4();
			vle_v1_u8m4(data_src + cols*(i+1) + j+1);
			vadd_v01_vv_i32m4();

			vdiv_v0_vx_u32m4(9);
			vse_v0_u8m4(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
		
	}
}

void averageBlurRVV_m8(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;
	for(int i =1;i<rows-1;i++){
		int n = cols-8;
		for(int j = 4;j<cols-4;){
			int vl=vsetvl_e32m8(n);

			vle_v0_u8m8(data_src + cols*i + j);
			vle_v1_u8m8(data_src + cols*(i-1) + j-1);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*(i-1) + j);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*(i-1) + j+1);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*i + j-1);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*i + j+1);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*(i+1) + j-1);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*(i+1) + j);
			vadd_v01_vv_i32m8();
			vle_v1_u8m8(data_src + cols*(i+1) + j+1);
			vadd_v01_vv_i32m8();

			vdiv_v0_vx_u32m8(9);
			vse_v0_u8m8(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
	}
}


int main(){
	int num;
	cout<<"LUML=";
	cin>>num;
	Mat src;
	src = imread("./imgs/gray.jpg", CV_8UC1);
	if(!src.data)
	{
		printf("No image data \n");
		return -1;
	}else{
		printf("read the image!\n");
	}
	cout<<src.size()<<endl;
	long long instrets_start, instrets_end;
	switch(num){
		case 0:{
			//标量指令实现
			Mat dst1 = src.clone();
			instrets_start = read_instrets();
			averageBlur(src, dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_scalar.jpg", dst1);
			break;
		}
		case 1:{
			//RVV指令实现
			Mat dst2 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV(src, dst2);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVV.jpg", dst2);
			break;
		}
		case 2:{
			//RVVm2
			Mat dst3 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m2(src, dst3);
			instrets_end = read_instrets();
			printf("RVVm2 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm2.jpg", dst3);
			break;
		}
		case 4:{
			//RVVm4
			Mat dst4 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m4(src, dst4);
			instrets_end = read_instrets();
			printf("RVVm4 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm4.jpg", dst4);
			break;
		}
		case 8:{
			//RVVm8
			Mat dst5 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m8(src, dst5);
			instrets_end = read_instrets();
			printf("RVVm8 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm8.jpg", dst5);
			break;
		}
		default:{
				//标量指令实现
			Mat dst1 = src.clone();
			instrets_start = read_instrets();
			averageBlur(src, dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_scalar.jpg", dst1);

			//RVV指令实现
			Mat dst2 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV(src, dst2);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVV.jpg", dst2);

			//RVVm2
			Mat dst3 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m2(src, dst3);
			instrets_end = read_instrets();
			printf("RVVm2 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm2.jpg", dst3);

			//RVVm4
			Mat dst4 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m4(src, dst4);
			instrets_end = read_instrets();
			printf("RVVm4 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm4.jpg", dst4);

			//RVVm8
			Mat dst5 = src.clone();
			instrets_start = read_instrets();
			averageBlurRVV_m8(src, dst5);
			instrets_end = read_instrets();
			printf("RVVm8 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm8.jpg", dst5);
		}
	}
	return 0;
}