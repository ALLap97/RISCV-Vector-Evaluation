#include<stddef.h>

/*-------------------------------------------------------------------------------------------*                                                                        
The Intrinsic functions of subset of RISC-V Vector Extension 0.8 version                     *
                                                                                             *
RV-V 0.8 : https://github.com/riscv/riscv-v-spec/releases/download/0.8/riscv-v-spec-0.8.pdf  *
                                                                                             * 
--------------------------------------------------------------------------------------------/*



/* 配置设置
vsetvl_e*m*: 设置vtype及vl寄存器，返回vl的值
e* : SEW为e*  向量寄存器单个元素占*位 
m* : LUML为m* 向量寄存器按*个值组合
*/
inline size_t vsetvl_e32m1 (size_t avl){
	size_t res=0;
	asm volatile("vsetvli %0,%1,e32,m1 \t\n"
				:"=r"(res)
				:"r"(avl));
	return res;
}

inline size_t vsetvl_e32m2 (size_t avl){
	size_t res=0;
	asm volatile("vsetvli %0,%1,e32,m2 \t\n"
				:"=r"(res)
				:"r"(avl));
	return res;
}

inline size_t vsetvl_e32m4 (size_t avl){
	size_t res=0;
	asm volatile("vsetvli %0,%1,e32,m4 \t\n"
				:"=r"(res)
				:"r"(avl));
	return res;
}

inline size_t vsetvl_e32m8 (volatile size_t avl){
	size_t res=0;
	asm volatile("vsetvli %0,%1,e32,m8 \t\n"
				:"=r"(res)
				:"r"(avl));
	return res;
}


/*---------内存存储指令-----------*
* vector load                     *
* vector strided load             *
* vector store                    *
---------------------------------/*


/* 数据加载 vector load
vle_v*_type_m*: 加载type数据到v*寄存器中，寄存器分组为m*
m1时：_v1_ 对应 v1
m8时：_v1_ 对应 v8
*/

inline void vle_v0_u8m1(const unsigned char* load_address){
		asm volatile("vlbu.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_u8m2(const unsigned char* load_address){
		asm volatile("vlbu.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_u8m4(const unsigned char* load_address){
		asm volatile("vlbu.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_u8m8(const unsigned char* load_address){
		asm volatile("vlbu.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_u8m1(const unsigned char* load_address){
		asm volatile("vlbu.v v1,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_u8m2(const unsigned char* load_address){
		asm volatile("vlbu.v v2,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_u8m4(const unsigned char* load_address){
		asm volatile("vlbu.v v4,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_u8m8(const unsigned char* load_address){
		asm volatile("vlbu.v v8,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v2_u8m1(const unsigned char* load_address){
		asm volatile("vlbu.v v2,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v2_u8m2(const unsigned char* load_address){
		asm volatile("vlbu.v v4,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v2_u8m4(const unsigned char* load_address){
		asm volatile("vlbu.v v8,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v2_u8m8(const unsigned char* load_address){
		asm volatile("vlbu.v v16,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_i32m1(const  int* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_i32m2(const  int* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_i32m4(const  int* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_i32m8(const  int* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_i32m1(const  int* load_address){
	asm volatile("vle.v v1,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_i32m2(const  int* load_address){
	asm volatile("vle.v v2,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_i32m4(const  int* load_address){
	asm volatile("vle.v v4,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_i32m8(const  int* load_address){
	asm volatile("vle.v v8,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_f32m1(const  float* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_f32m2(const  float* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_f32m4(const  float* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v0_f32m8(const  float* load_address){
	asm volatile("vle.v v0,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_f32m1(const  float* load_address){
		asm volatile("vle.v v1,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_f32m2(const  float* load_address){
		asm volatile("vle.v v2,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_f32m4(const  float* load_address){
		asm volatile("vle.v v4,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v1_f32m8(const  float* load_address){
		asm volatile("vle.v v8,(%0)\t\n"
	            :
	            :"r"(load_address));
}

inline void vle_v2_f32m1(const  float* load_address){
		asm volatile("vle.v v2,(%0)\t\n"
	            :
	            :"r"(load_address));
}

/* 跨步长数据加载 Vector Strided Load
vlse_v*_type m*: 跨步长加载type数据到v*寄存器中，分组为m*
m1时：_v1_ 对应 v1
m8时：_v1_ 对应 v8
*/
inline void vlse_v0_u8m1(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v0,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v0_u8m2(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v0,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v0_u8m4(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v0,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v0_u8m8(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v0,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v1_u8m1(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v1,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v1_u8m2(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v2,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v1_u8m4(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v4,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v1_u8m8(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v8,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v2_u8m1(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v2,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v2_u8m2(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v4,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v2_u8m4(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v8,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v2_u8m8(const unsigned char* load_address, int stride){
		asm volatile("vlsbu.v v16,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v0_f32m1(const float* load_address, int stride){
		asm volatile("vlse.v v0,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v1_f32m1(const float* load_address, int stride){
		asm volatile("vlse.v v1,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

inline void vlse_v2_f32m1(const float* load_address, int stride){
		asm volatile("vlse.v v2,(%0), %1\t\n"
	            :
	            :"r"(load_address), "r"(stride));
}

/* 数据存放 vector store
vse_v*_type_m*: 将v*寄存器中数据存放到store_address上，寄存器分组为m*
m1时：_v1_ 对应 v1
m8时：_v1_ 对应 v8
*/

inline void vse_v0_u8m1(unsigned char* store_address){
	asm volatile("vsb.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_u8m2(unsigned char* store_address){
	asm volatile("vsb.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_u8m4(unsigned char* store_address){
	asm volatile("vsb.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_u8m8(unsigned char* store_address){
	asm volatile("vsb.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_i32m1(int* store_address){
	asm volatile("vse.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_i32m2(int* store_address){
	asm volatile("vse.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_i32m4(int* store_address){
	asm volatile("vse.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_i32m8(int* store_address){
	asm volatile("vse.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v0_f32m1(float* store_address){
	asm volatile("vse.v v0,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v1_f32m1( float* store_address){
	asm volatile("vse.v v1,(%0) \n\t"
				:
				:"r"(store_address));
}

inline void vse_v1_f32m8( float* store_address){
	asm volatile("vse.v v8,(%0) \n\t"
				:
				:"r"(store_address));
}
   
/*---------算术运算指令-----------*
_vx_ ：vector-scalar              *
_vf_ : vector-float               *
_vv_ ：vector-vector              *
----------------------------------*
* vector add : vadd               *
* vector multiply : vmul          *
* vector division : vdiv          *
* vector multiply-add : vmacc     *
* vector multiply-sub : vnmsac    *
---------------------------------/*


/* vector add : vadd
_vx_ ：vector-scalar
_vf_ : vector-float
_vv_ ：vector-vector 
_vij_ : 使用的向量寄存器vi、vj,并最终将结果写入vi寄存器中
*/

// v0[i] = k+v0[i]
inline void vadd_v00_vx_i32m1(int k);
inline void vadd_v00_vx_i32m8(int k);
inline void vadd_v00_vx_f32m1(int k);

// v0[i] = v0[i]+v1[i]
inline void vadd_v01_vv_i32m1(){
	asm volatile("vadd.vv v0,v0,v1 \n\t"
                :
                :);
}

// v0~1[i] = v0~1[i]+v2~3[i]
inline void vadd_v01_vv_i32m2(){
	asm volatile("vadd.vv v0,v0,v2 \n\t"
                :
                :);
}

// v0~3[i] = v0~3[i]+v4~7[i]
inline void vadd_v01_vv_i32m4(){
	asm volatile("vadd.vv v0,v0,v4 \n\t"
                :
                :);
}

// v0~7[i] = v0~7[i]+v8~15[i]
inline void vadd_v01_vv_i32m8(){
	asm volatile("vadd.vv v0,v0,v8 \n\t"
                :
                :);
}

// v1[i] = v1[i]+v0[i]
inline void vadd_v10_vv_i32m1(){
	asm volatile("vadd.vv v1,v1,v0 \n\t"
                :
                :);
}

// v2~3[i] = v2~3[i]+v0~1[i]
inline void vadd_v10_vv_i32m2(){
	asm volatile("vadd.vv v2,v2,v0 \n\t"
                :
                :);
}

// v4~7[i] = v4~7[i]+v0~3[i]
inline void vadd_v10_vv_i32m4(){
	asm volatile("vadd.vv v4,v4,v0 \n\t"
                :
                :);
}

// v8~15[i] = v8~15[i]+v0~7[i]
inline void vadd_v10_vv_i32m8(){
	asm volatile("vadd.vv v8,v8,v0 \n\t"
                :
                :);
}


// v0[i] = v0[i]+v1[i]
inline void vfadd_v01_vv_f32m1(){
	asm volatile("vfadd.vv v0,v0,v1 \n\t"
                :
                :);
}

// v0~1[i] = v0~1[i]+v2~3[i]
inline void vfadd_v01_vv_f32m2(){
	asm volatile("vfadd.vv v0,v0,v2 \n\t"
                :
                :);
}

// v0~3[i] = v0~3[i]+v4~7[i]
inline void vfadd_v01_vv_f32m4(){
	asm volatile("vfadd.vv v0,v0,v4 \n\t"
                :
                :);
}

// v0~7[i] = v0~7[i]+v8~15[i]
inline void vfadd_v01_vv_f32m8(){
	asm volatile("vfadd.vv v0,v0,v8 \n\t"
                :
                :);
}

/* vector multiply: vmul
_vx_ ：vector-scalar
_vf_ : vector-float
_vv_ ：vector-vector 
_vij_ : 使用的向量寄存器vi、vj,并最终将结果写入vi寄存器中
*/

// v0[i] = k*v0[i]
inline void vmul_v00_vx_i32m1(int k){
	asm volatile("vmul.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

// v0~1[i] = k*v0~1[i]
inline void vmul_v00_vx_i32m2(int k){
	asm volatile("vmul.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

// v0~3[i] = k*v0~3[i]
inline void vmul_v00_vx_i32m4(int k){
	asm volatile("vmul.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

// v0~7[i] = k*v0~7[i]
inline void vmul_v00_vx_i32m8(int k){
	asm volatile("vmul.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

// v0[i] = k*v0[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmul_v00_vf_f32m1(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmul.vf v0,v0,fs2 \n\t"
                :
                :);
}

// v0~1[i] = k*v0~1[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmul_v00_vf_f32m2(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmul.vf v0,v0,fs2 \n\t"
                :
                :);
}

// v0~3[i] = k*v0~3[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmul_v00_vf_f32m4(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmul.vf v0,v0,fs2 \n\t"
                :
                :);
}

// v0~7[i] = k*v0~7[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmul_v00_vf_f32m8(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmul.vf v0,v0,fs2 \n\t"
                :
                :);
}

// v0[i] = v0[i]*v0[i]
inline void vmul_v00_vv_i32m1(){
	asm volatile("vmul.vv v0,v0,v0 \n\t"
                :
                :);
}

// v0~1[i] = v0~1[i]*v0~1[i]
inline void vmul_v00_vv_i32m2(){
	asm volatile("vmul.vv v0,v0,v0 \n\t"
                :
                :);
}

// v0~3[i] = v0~3[i]*v0~3[i]
inline void vmul_v00_vv_i32m4(){
	asm volatile("vmul.vv v0,v0,v0 \n\t"
                :
                :);
}

// v0~7[i] = v0~7[i]*v0~7[i]
inline void vmul_v00_vv_i32m8(){
	asm volatile("vmul.vv v0,v0,v0 \n\t"
                :
                :);
}

// v1[i] = v1[i]*v1[i]
inline void vmul_v11_vv_i32m1(){
	asm volatile("vmul.vv v1,v1,v1 \n\t"
                :
                :);
}

// v2~3[i] = v2~3[i]*v2~3[i]
inline void vmul_v11_vv_i32m2(){
	asm volatile("vmul.vv v2,v2,v2 \n\t"
                :
                :);
}

// v4~7[i] = v4~7[i]*v4~7[i]
inline void vmul_v11_vv_i32m4(){
	asm volatile("vmul.vv v4,v4,v4 \n\t"
                :
                :);
}

// v8~15[i] = v8~15[i]*v8~15[i]
inline void vmul_v11_vv_i32m8(){
	asm volatile("vmul.vv v8,v8,v8 \n\t"
                :
                :);
}

// v0[i] = v1[i]*v0[i]
inline void vmul_v01_vv_i32m1(){
	asm volatile("vmul.vv v0,v0,v1 \n\t"
                :
                :);
}

// v0[i] = v1[i]*v0[i]
inline void vfmul_v01_vv_f32m1(){
	asm volatile("vfmul.vv v0,v0,v1 \n\t"
                :
                :);
}

/* vector div : vdiv
_vx_ ：vector-scalar
_vf_ : vector-float
_vv_ ：vector-vector 
_vij_ : 使用的向量寄存器vi、vj,并最终将结果写入vi寄存器中
*/

//v0[i] = v0[i]/k
inline void vdiv_v0_vx_u32m1(int k){
	asm volatile("vdivu.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

//v0~1[i] = v0~1[i]/k
inline void vdiv_v0_vx_u32m2(int k){
	asm volatile("vdivu.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

//v0~3[i] = v0~3[i]/k
inline void vdiv_v0_vx_u32m4(int k){
	asm volatile("vdivu.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

//v0~7[i] = v0~7[i]/k
inline void vdiv_v0_vx_u32m8(int k){
	asm volatile("vdivu.vx v0,v0,%0 \n\t"
                :
                :"r"(k));
}

/* vector multiply and add : vmacc
_vx_ ：vector-scalar
_vf_ : vector-float
_vv_ ：vector-vector 
_vij_ : 使用的向量寄存器vi、vj,并最终将结果写入vi寄存器中
*/

// v0[i] = k*v1[i]+v0[i]
inline void vmacc_v01_vx_i32m1(int k){
	asm volatile("vmacc.vx v0, %0, v1 \n\t"
                :
                :"r"(k));
}

// v0~1[i] = k*v2~3[i]+v0~1[i]
inline void vmacc_v01_vx_i32m2(int k){
	asm volatile("vmacc.vx v0, %0, v2 \n\t"
                :
                :"r"(k));
}

// v0~3[i] = k*v4~7[i]+v0~3[i]
inline void vmacc_v01_vx_i32m4(int k){
	asm volatile("vmacc.vx v0, %0, v4 \n\t"
                :
                :"r"(k));
}

// v0~7[i] = k*v8~15[i]+v0~7[i]
inline void vmacc_v01_vx_i32m8(int k){
	asm volatile("vmacc.vx v0, %0, v8 \n\t"
                :
                :"r"(k));
}

// v1[i] = k*v2[i]+v1[i]
inline void vmacc_v12_vx_i32m1(int k){
	asm volatile("vmacc.vx v1, %0, v2 \n\t"
                :
                :"r"(k));
}

// v2~3[i] = k*v4~5[i]+v2~3[i]
inline void vmacc_v12_vx_i32m2(int k){
	asm volatile("vmacc.vx v2, %0, v4 \n\t"
                :
                :"r"(k));
}

// v4~7[i] = k*v8~11[i]+v4~7[i]
inline void vmacc_v12_vx_i32m4(int k){
	asm volatile("vmacc.vx v4, %0, v8 \n\t"
                :
                :"r"(k));
}

// v8~15[i] = k*v16~23[i]+v8~15[i]
inline void vmacc_v12_vx_i32m8(int k){
	asm volatile("vmacc.vx v8, %0, v16 \n\t"
                :
                :"r"(k));
}

// v0[i] = k*v1[i]+v0[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v01_vf_f32m1(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v1 \n\t"
                :
                :);
}

// v0~1[i] = k*v2~3[i]+v0~1[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v01_vf_f32m2(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v2 \n\t"
                :
                :);
}

// v0~3[i] = k*v4~7[i]+v0~3[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v01_vf_f32m4(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v4 \n\t"
                :
                :);
}

// v0~7[i] = k*v8~15[i]+v0~7[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v01_vf_f32m8(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v8 \n\t"
                :
                :);
}

// v0[i] = k*v2[i]+v0[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v02_vf_f32m1(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v2 \n\t"
                :
                :);
}

// v0~1[i] = k*v4~5[i]+v0~1[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v02_vf_f32m2(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v4 \n\t"
                :
                :);
}

// v0~3[i] = k*v8~11[i]+v0~3[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v02_vf_f32m4(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v8 \n\t"
                :
                :);
}

// v0~7[i] = k*v16~23[i]+v0~7[i]
// 手动读取浮点数到特定寄存器，不然会读不进来
inline void vfmacc_v02_vf_f32m8(float k){
	asm volatile("flw fs2,%0 \n\t"
                :
                :"m"(k));
	asm volatile("vfmacc.vf v0, fs2, v16 \n\t"
                :
                :);
}

// v0[i] = k*v1[i]-v0[i]
inline void vnmsac_v01_vx_i32m1(int k){
	asm volatile("vnmsac.vx v0, %0, v1 \n\t"
                :
                :"r"(k));
}

// v0~1[i] = k*v2~3[i]-v0~1[i]
inline void vnmsac_v01_vx_i32m2(int k){
	asm volatile("vnmsac.vx v0, %0, v2 \n\t"
                :
                :"r"(k));
}

// v0~3[i] = k*v4~7[i]-v0~3[i]
inline void vnmsac_v01_vx_i32m4(int k){
	asm volatile("vnmsac.vx v0, %0, v4 \n\t"
                :
                :"r"(k));
}

// v0~7[i] = k*v8~15[i]-v0~7[i]
inline void vnmsac_v01_vx_i32m8(int k){
	asm volatile("vnmsac.vx v0, %0, v8 \n\t"
                :
                :"r"(k));
}

// v1[i] = k*v2[i]-v1[i]
inline void vnmsac_v12_vx_i32m1(int k){
	asm volatile("vnmsac.vx v1, %0, v2 \n\t"
                :
                :"r"(k));
}

// v2~3[i] = k*v4~5[i]-v2~3[i]
inline void vnmsac_v12_vx_i32m2(int k){
	asm volatile("vnmsac.vx v2, %0, v4 \n\t"
                :
                :"r"(k));
}

// v4~7[i] = k*v8~11[i]-v4~7[i]
inline void vnmsac_v12_vx_i32m4(int k){
	asm volatile("vnmsac.vx v4, %0, v8 \n\t"
                :
                :"r"(k));
}

// v8~15[i] = k*v16~23[i]-v8~15[i]
inline void vnmsac_v12_vx_i32m8(int k){
	asm volatile("vnmsac.vx v8, %0, v16 \n\t"
                :
                :"r"(k));
}

/* Vector Integer Comparison Instructions
vmsgt : Set if greater than, signed
vmfgt : Set if greater than, float
vmslt : Set if less than, signed
vmflt : Set if less than, float
*/


// v0[i] = v0[i] > k ? 1 : 0
inline void vmsgt_v0_vx_i32m1(int k){
	asm volatile("vmsgt.vx v0,v0,%0\n\t"
                :
                :"r"(k));
}

// v0[i] = v1[i] > k ? 1 : 0
inline void vmsgt_v01_vx_i32m1(int k){
	asm volatile("vmsgt.vx v0,v1,%0\n\t"
                :
                :"r"(k));
}

// v0~1[i] = v2~3[i] > k ? 1 : 0
inline void vmsgt_v01_vx_i32m2(int k){
	asm volatile("vmsgt.vx v0,v2,%0\n\t"
                :
                :"r"(k));
}

// v0~3[i] = v4~7[i] > k ? 1 : 0
inline void vmsgt_v01_vx_i32m4(int k){
	asm volatile("vmsgt.vx v0,v4,%0\n\t"
                :
                :"r"(k));
}

// v0~7[i] = v8~15[i] > k ? 1 : 0
inline void vmsgt_v01_vx_i32m8(int k){
	asm volatile("vmsgt.vx v0,v8,%0\n\t"
                :
                :"r"(k));
}

// v0[i] = v0[i] > k ? 1 : 0
inline void vmfgt_v0_vf_f32m1(float k){
	asm volatile("flw fs3,%0 \n\t"
                :
                :"m"(k));

	asm volatile("vmfgt.vf v0,v0,fs3\n\t"
                :
                :);
}

// v0[i] = v0[i] < k ? 1 : 0
inline void vmslt_v0_vx_i32m1(int k){
	asm volatile("vmslt.vx v0,v0,%0\n\t"
                :
                :"r"(k));
}

// v0[i] = v0[i] < k ? 1 : 0
inline void vmflt_v0_vf_f32m1(float k){
	asm volatile("flw fs3,%0 \n\t"
                :
                :"m"(k));

	asm volatile("vmflt.vf v0,v0,fs3\n\t"
                :
                :);
}



