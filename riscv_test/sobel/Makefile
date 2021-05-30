build_sobel:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d -O3 sobel.cpp  -o sobel  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_sobel:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk sobel

build_sobel_cycle:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d -O3 sobel_cycle.cpp  -o sobel_cycle  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_sobel_cycle:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk sobel_cycle
