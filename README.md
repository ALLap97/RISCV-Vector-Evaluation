# RISCV-Vector-Evaluation
# 实验环境
## RISC-V V0.8 GNU Compiler Toolchain
### Getting the sources
```
git clone -b rvv-0.8 https://github.com/riscv/riscv-gnu-toolchain.git
cd riscv-gnu-toolchain
git submodule update --init --recursive
```
### Prerequisites
Several standard packages are needed to build the toolchain. On Ubuntu, executing the following command should suffice:
```
sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
```
### Installation (Linux)
To build the Linux cross-compiler, pick an install path. If you choose, say, /opt/riscv, then add /opt/riscv/bin to your PATH ($RISCV) now. Then, simply run the following command:
```
../configure --prefix=$RISCV
make linux -j4
make install
```
## Spike
```
apt-get install device-tree-compiler
git clone https://github.com/riscv/riscv-isa-sim.git
cd riscv-isa-sim
mkdir build
cd build
../configure --prefix=$RISCV
make
make install
```
## RISC-V Proxy Kernel and Boot Loader
```
git clone https://github.com/riscv/riscv-pk.git
cd riscv-pk
mkdir build
cd build
../configure --prefix=$RISCV --host=riscv64-unknown-linux-gnu
make
make install
```
## OpenCV : 4.20 
Generate static link library

参考：https://blog.csdn.net/ALLap97/article/details/106194279

# 运行测试
```
cd riscv_test/gray
# build gray
riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d  -O3 gray.cpp  -o gray  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic
# run gray
spike --isa=rv64gcv pk gray
```

