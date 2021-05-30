#include <stdio.h>
#include "riscv_vector.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

using namespace cv;
using namespace std;

long long read_instrets(void)
{
  long long instrets;
  asm volatile ("rdinstret %0" : "=r" (instrets));
  return instrets;
}

void cvtBGR2Gray_unchar(const int size, unsigned char * src, unsigned char * dst)
{

	float R, G, B;
	for(int i = 0; i < size; i += 3){
		B = *(src+i)*0.299;
		G = *(src+i+1)*0.587;
		R = *(src+i+2)*0.114;
		*(dst+i/3) = (int)(B + G + R);
	}
}

void cvtBGR2Gray_unchar_rvv(int n, int stride, unsigned char* src, unsigned char* des, volatile float b, volatile float g, volatile float r ){
    
	while(n>0){
		int vl=vsetvl_e32m1(n);
        vlse_v0_u8m1(src, stride);
        vlse_v1_u8m1(src+1, stride);
        vlse_v2_u8m1(src+2, stride);
 		vfmul_v00_vf_f32m1(r);
 		vfmacc_v01_vf_f32m1(g);
    	vfmacc_v02_vf_f32m1(b);
        vse_v0_u8m1(des);
        n-=vl*stride;
        src+=vl*stride;
        des+=vl;
	}
}

void cvtBGR2Gray_unchar_rvv_m2(int n, int stride, unsigned char* src, unsigned char* des, volatile float b, volatile float g, volatile float r ){
    
	while(n>0){
		int vl=vsetvl_e32m2(n);
        vlse_v0_u8m2(src, stride);
        vlse_v1_u8m2(src+1, stride);
        vlse_v2_u8m2(src+2, stride);
 		vfmul_v00_vf_f32m2(r);
 		vfmacc_v01_vf_f32m2(g);
    	vfmacc_v02_vf_f32m2(b);
        vse_v0_u8m2(des);
        n-=vl*stride;
        src+=vl*stride;
        des+=vl;
	}
}

void cvtBGR2Gray_unchar_rvv_m4(int n, int stride, unsigned char* src, unsigned char* des, volatile float b, volatile float g, volatile float r ){
    
	while(n>0){
		int vl=vsetvl_e32m4(n);
        vlse_v0_u8m4(src, stride);
        vlse_v1_u8m4(src+1, stride);
        vlse_v2_u8m4(src+2, stride);
 		vfmul_v00_vf_f32m4(r);
 		vfmacc_v01_vf_f32m4(g);
    	vfmacc_v02_vf_f32m4(b);
        vse_v0_u8m4(des);
        n-=vl*stride;
        src+=vl*stride;
        des+=vl;
	}
}


void cvtBGR2Gray_unchar_rvv_m8(int n, int stride, unsigned char* src, unsigned char* des, volatile float b, volatile float g, volatile float r ){
    
	while(n>0){
		int vl=vsetvl_e32m8(n);
        vlse_v0_u8m8(src, stride);
        vlse_v1_u8m8(src+1, stride);
        vlse_v2_u8m8(src+2, stride);
 	 	vfmul_v00_vf_f32m8(r);
 		vfmacc_v01_vf_f32m8(g);
    	vfmacc_v02_vf_f32m8(b);
        vse_v0_u8m8(des);
        n-=vl*stride;
        src+=vl*stride;
        des+=vl;
	}
}


string pixel[5] = {"256_256", "512_512","640_480","800_600","1024_768"};

int main(){
	int num;
	cout<<"LUML=";
	cin>>num;
	Mat src;
	src = imread("./imgs/img.jpg");
	if(!src.data)
	{
		printf("No image data \n");
		return -1;
	}else{
		printf("read the image!\n");
	}
	cout<<src.size()<<endl;
	long long instrets_start, instrets_end;
	int size = src.size().area()*src.channels();
	uchar* data_src = src.data;
	
	switch(num){
		case 0:{
			//标量指令实现
			Mat dst1(src.rows, src.cols, CV_8UC1);
			uchar* data_dst1 = dst1.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar(size, data_src, data_dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_scalar.jpg", dst1);
			break;
		}
		case 1:{
			//RVV指令实现
			Mat dst2(src.rows, src.cols, CV_8UC1);
			uchar* data_dst2 = dst2.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv(size, 3, data_src, data_dst2, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVV.jpg", dst2);
			break;
		}
		case 2:{
			//RVVm2
			Mat dst3(src.rows, src.cols, CV_8UC1);
			uchar* data_dst3 = dst3.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m2(size, 3, data_src, data_dst3, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm2 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm2.jpg", dst3);
			break;
		}
		case 4:{
			//RVVm4
			Mat dst4(src.rows, src.cols, CV_8UC1);
			uchar* data_dst4 = dst4.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m4(size, 3, data_src, data_dst4, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm4 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm4.jpg", dst4);
			break;
		}
		case 8:{
			//RVVm8
			Mat dst5(src.rows, src.cols, CV_8UC1);
			uchar* data_dst5 = dst5.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m8(size, 3, data_src, data_dst5, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm8 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm8.jpg", dst5);
			break;
		}
		default:{
			//标量指令实现
			Mat dst1(src.rows, src.cols, CV_8UC1);
			uchar* data_dst1 = dst1.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar(size, data_src, data_dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_scalar.jpg", dst1);

			//RVV指令实现
			Mat dst2(src.rows, src.cols, CV_8UC1);
			uchar* data_dst2 = dst2.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv(size, 3, data_src, data_dst2, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVV.jpg", dst2);

			//RVVm2
			Mat dst3(src.rows, src.cols, CV_8UC1);
			uchar* data_dst3 = dst3.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m2(size, 3, data_src, data_dst3, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm2 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm2.jpg", dst3);

			//RVVm4
			Mat dst4(src.rows, src.cols, CV_8UC1);
			uchar* data_dst4 = dst4.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m4(size, 3, data_src, data_dst4, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm4 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm4.jpg", dst4);

			//RVVm8
			Mat dst5(src.rows, src.cols, CV_8UC1);
			uchar* data_dst5 = dst5.data;
			instrets_start = read_instrets();
			cvtBGR2Gray_unchar_rvv_m8(size, 3, data_src, data_dst5, 0.299, 0.587, 0.114);
			instrets_end = read_instrets();
			printf("RVVm8 Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/gray_RVVm8.jpg", dst5);
		}
	}
	return 0;
}
