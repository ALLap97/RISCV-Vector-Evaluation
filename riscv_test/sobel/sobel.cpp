#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <vector>
#include "riscv_vector.h"

using namespace cv;
using namespace std;


long long read_instrets(void)
{
  long long instrets;
  asm volatile ("rdinstret %0" : "=r" (instrets));
  return instrets;
}


/*sobel 算子模板
[1  2  1         [1  0  -1
 0  0  0          2  0  -2
 -1 -2 -1]        1  0  -1]
*/

void sobel(Mat& src, Mat& dst){
	int rows = src.rows ;
	int cols = src.cols ;
	uchar* data_src = src.data;
	uchar* data_dst = dst.data;
	for(int i = 1;i<rows-1;i++){
		for(int j = 1;j<cols-1; j++){
			int x = 0;
			x += *(data_src + cols*(i-1) + j-1);
			x += *(data_src + cols*(i-1) + j)*2;
			x += *(data_src + cols*(i-1) + j+1);
			x -= *(data_src + cols*(i+1) + j-1);
			x -= *(data_src + cols*(i+1) + j)*2;
			x -= *(data_src + cols*(i+1) + j+1);
			int y = 0;
			y += *(data_src + cols*(i-1) + j-1);
			y += *(data_src + cols*(i) + j-1)*2;
			y += *(data_src + cols*(i+1) + j-1);
			y -= *(data_src + cols*(i-1) + j+1);
			y -= *(data_src + cols*(i) + j+1)*2;
			y -= *(data_src + cols*(i+1) + j+1);
			
			//float z = sqrt(x*x+y*y);

			// if(z>128){
			// 	*(data_dst + cols*(i) + j) = 255;
			// }else{
			// 	*(data_dst + cols*(i) + j) = 0;
			// }

			int z = x*x+y*y;
			if(z>128*128){
				*(data_dst + cols*(i) + j) = 255;
			}else{
				*(data_dst + cols*(i) + j) = 0;
			}
		}
		
	}
}


/*sobel 算子模板
[1  2  1         [1  0  -1
 0  0  0          2  0  -2
 -1 -2 -1]        1  0  -1]
*/

void sobelRVV(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;
	//unsigned char* src, unsigned char* des
	for(int i =1;i<rows-1;i++){
		int n = cols-2;
		for(int j = 1;j<cols-1;){
			int vl=vsetvl_e32m1(n);
			//x
			vle_v0_u8m1(data_src + cols*(i-1) + j-1);
			vle_v1_u8m1(data_src + cols*(i-1) + j);
			vmacc_v01_vx_i32m1(2);
			vle_v1_u8m1(data_src + cols*(i-1) + j+1);
			vmacc_v01_vx_i32m1(1);

			vle_v1_u8m1(data_src + cols*(i+1) + j-1);
			vnmsac_v01_vx_i32m1(1);
			vle_v1_u8m1(data_src + cols*(i+1) + j);
			vnmsac_v01_vx_i32m1(2);
			vle_v1_u8m1(data_src + cols*(i+1) + j+1);
			vnmsac_v01_vx_i32m1(1);

			vmul_v00_vv_i32m1();
			//y

			vle_v1_u8m1(data_src + cols*(i-1) + j-1);
			vle_v2_u8m1(data_src + cols*(i) + j-1);
			vmacc_v12_vx_i32m1(2);
			vle_v2_u8m1(data_src + cols*(i+1) + j-1);
			vmacc_v12_vx_i32m1(1);

			vle_v2_u8m1(data_src + cols*(i-1) + j+1);
			vnmsac_v12_vx_i32m1(1);
			vle_v2_u8m1(data_src + cols*(i) + j+1);
			vnmsac_v12_vx_i32m1(2);
			vle_v2_u8m1(data_src + cols*(i+1) + j+1);
			vnmsac_v12_vx_i32m1(1);
			vmul_v11_vv_i32m1();

			//x*x+y*y
			vadd_v10_vv_i32m1();

			vmsgt_v01_vx_i32m1(128*128);
			vmul_v00_vx_i32m1(255);

			vse_v0_u8m1(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
	}
}

void sobelRVV_m2(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;
	//unsigned char* src, unsigned char* des
	for(int i =1;i<rows-1;i++){
		int n = cols-2;
		for(int j = 1;j<cols-1;){
			int vl=vsetvl_e32m2(n);
			//x
			vle_v0_u8m2(data_src + cols*(i-1) + j-1);
			vle_v1_u8m2(data_src + cols*(i-1) + j);
			vmacc_v01_vx_i32m2(2);
			vle_v1_u8m2(data_src + cols*(i-1) + j+1);
			vmacc_v01_vx_i32m2(1);

			vle_v1_u8m2(data_src + cols*(i+1) + j-1);
			vnmsac_v01_vx_i32m2(1);
			vle_v1_u8m2(data_src + cols*(i+1) + j);
			vnmsac_v01_vx_i32m2(2);
			vle_v1_u8m2(data_src + cols*(i+1) + j+1);
			vnmsac_v01_vx_i32m2(1);

			vmul_v00_vv_i32m2();
			//y

			vle_v1_u8m2(data_src + cols*(i-1) + j-1);
			vle_v2_u8m2(data_src + cols*(i) + j-1);
			vmacc_v12_vx_i32m2(2);
			vle_v2_u8m2(data_src + cols*(i+1) + j-1);
			vmacc_v12_vx_i32m2(1);

			vle_v2_u8m2(data_src + cols*(i-1) + j+1);
			vnmsac_v12_vx_i32m2(1);
			vle_v2_u8m2(data_src + cols*(i) + j+1);
			vnmsac_v12_vx_i32m2(2);
			vle_v2_u8m2(data_src + cols*(i+1) + j+1);
			vnmsac_v12_vx_i32m2(1);
			vmul_v11_vv_i32m2();

			//x*x+y*y
			vadd_v10_vv_i32m2();

			vmsgt_v01_vx_i32m2(128*128);
			vmul_v00_vx_i32m2(255);

			vse_v0_u8m2(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
	}
}

void sobelRVV_m4(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;
	//unsigned char* src, unsigned char* des
	for(int i =1;i<rows-1;i++){
		int n = cols-2;
		for(int j = 1;j<cols-1;){
			int vl=vsetvl_e32m4(n);
			//x
			vle_v0_u8m4(data_src + cols*(i-1) + j-1);
			vle_v1_u8m4(data_src + cols*(i-1) + j);
			vmacc_v01_vx_i32m4(2);
			vle_v1_u8m4(data_src + cols*(i-1) + j+1);
			vmacc_v01_vx_i32m4(1);

			vle_v1_u8m4(data_src + cols*(i+1) + j-1);
			vnmsac_v01_vx_i32m4(1);
			vle_v1_u8m4(data_src + cols*(i+1) + j);
			vnmsac_v01_vx_i32m4(2);
			vle_v1_u8m4(data_src + cols*(i+1) + j+1);
			vnmsac_v01_vx_i32m4(1);

			vmul_v00_vv_i32m4();
			//y

			vle_v1_u8m4(data_src + cols*(i-1) + j-1);
			vle_v2_u8m4(data_src + cols*(i) + j-1);
			vmacc_v12_vx_i32m4(2);
			vle_v2_u8m4(data_src + cols*(i+1) + j-1);
			vmacc_v12_vx_i32m4(1);

			vle_v2_u8m4(data_src + cols*(i-1) + j+1);
			vnmsac_v12_vx_i32m4(1);
			vle_v2_u8m4(data_src + cols*(i) + j+1);
			vnmsac_v12_vx_i32m4(2);
			vle_v2_u8m4(data_src + cols*(i+1) + j+1);
			vnmsac_v12_vx_i32m4(1);
			vmul_v11_vv_i32m4();

			//x*x+y*y
			vadd_v10_vv_i32m4();

			vmsgt_v01_vx_i32m4(128*128);
			vmul_v00_vx_i32m4(255);

			vse_v0_u8m4(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
	}
}

void sobelRVV_m8(Mat& src, Mat& dst){
	int rows = src.rows;
	int cols = src.cols;
	unsigned char* data_src = src.data;
	unsigned char* data_dst = dst.data;
	//unsigned char* src, unsigned char* des
	for(int i =1;i<rows-1;i++){
		int n = cols-2;
		for(int j = 1;j<cols-1;){
			int vl=vsetvl_e32m8(n);
			//x
			vle_v0_u8m8(data_src + cols*(i-1) + j-1);
			vle_v1_u8m8(data_src + cols*(i-1) + j);
			vmacc_v01_vx_i32m8(2);
			vle_v1_u8m8(data_src + cols*(i-1) + j+1);
			vmacc_v01_vx_i32m8(1);

			vle_v1_u8m8(data_src + cols*(i+1) + j-1);
			vnmsac_v01_vx_i32m8(1);
			vle_v1_u8m8(data_src + cols*(i+1) + j);
			vnmsac_v01_vx_i32m8(2);
			vle_v1_u8m8(data_src + cols*(i+1) + j+1);
			vnmsac_v01_vx_i32m8(1);

			vmul_v00_vv_i32m8();
			//y

			vle_v1_u8m8(data_src + cols*(i-1) + j-1);
			vle_v2_u8m8(data_src + cols*(i) + j-1);
			vmacc_v12_vx_i32m8(2);
			vle_v2_u8m8(data_src + cols*(i+1) + j-1);
			vmacc_v12_vx_i32m8(1);

			vle_v2_u8m8(data_src + cols*(i-1) + j+1);
			vnmsac_v12_vx_i32m8(1);
			vle_v2_u8m8(data_src + cols*(i) + j+1);
			vnmsac_v12_vx_i32m8(2);
			vle_v2_u8m8(data_src + cols*(i+1) + j+1);
			vnmsac_v12_vx_i32m8(1);
			vmul_v11_vv_i32m8();

			//x*x+y*y
			vadd_v10_vv_i32m8();

			vmsgt_v01_vx_i32m8(128*128);
			vmul_v00_vx_i32m8(255);

			vse_v0_u8m8(data_dst + cols*i + j);
			n-=vl;
			j+=vl;
		}
	}
}




string pixel[6] = {"256_256", "512_512","640_480","800_600","1024_768", "800_603"};

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
			sobel(src, dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_scalar.jpg", dst1);
			break;
		}
		case 1:{
			//RVV指令实现
			Mat dst2 = src.clone();
			instrets_start = read_instrets();
			sobelRVV(src, dst2);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVV.jpg", dst2);
			break;
		}
		case 2:{
			//RVVm2
			Mat dst3 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m2(src, dst3);
			instrets_end = read_instrets();
			printf("RVVm2 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm2.jpg", dst3);
			break;
		}
		case 4:{
			//RVVm4
			Mat dst4 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m4(src, dst4);
			instrets_end = read_instrets();
			printf("RVVm4 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm4.jpg", dst4);
			break;
		}
		case 8:{
			//RVVm8
			Mat dst5 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m8(src, dst5);
			instrets_end = read_instrets();
			printf("RVVm8 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm8.jpg", dst5);
			break;
		}
		default:{
				//标量指令实现
			Mat dst1 = src.clone();
			instrets_start = read_instrets();
			sobel(src, dst1);
			instrets_end = read_instrets();
			printf("Scalar Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_scalar.jpg", dst1);

			//RVV指令实现
			Mat dst2 = src.clone();
			instrets_start = read_instrets();
			sobelRVV(src, dst2);
			instrets_end = read_instrets();
			printf("RVV Instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVV.jpg", dst2);

			//RVVm2
			Mat dst3 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m2(src, dst3);
			instrets_end = read_instrets();
			printf("RVVm2 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm2.jpg", dst3);

			//RVVm4
			Mat dst4 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m4(src, dst4);
			instrets_end = read_instrets();
			printf("RVVm4 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm4.jpg", dst4);

			//RVVm8
			Mat dst5 = src.clone();
			instrets_start = read_instrets();
			sobelRVV_m8(src, dst5);
			instrets_end = read_instrets();
			printf("RVVm8 instrets = %lld\n", instrets_end - instrets_start);
			imwrite("./imgs/blur_RVVm8.jpg", dst5);
		}
	}
	return 0;
}