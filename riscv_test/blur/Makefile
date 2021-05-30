build_blur:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d -O3 blur.cpp  -o blur  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic
	
run_blur:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk blur

run_blur_rvv_1024:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv --varch=vlen:1024,elen:64,slen:1024 /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk blur

build_blur_cycle:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d -O3 blur_cycle.cpp  -o blur_cycle  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_blur_cycle:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk blur_cycle

build_blur2_cycle:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d -O3 blur2_cycle.cpp  -o blur2_cycle  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_blur2_cycle:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk blur2_cycle

