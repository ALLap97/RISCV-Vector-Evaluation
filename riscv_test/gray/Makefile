build_gray:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d  -O3 gray.cpp  -o gray  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_gray:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk gray

build_gray_cycle:
	riscv64-unknown-linux-gnu-g++  -march=rv64gcv -mabi=lp64d  -O3 gray_cycle.cpp  -o gray_cycle  -static  -I /opt/opencv/static/include/opencv4/  -L /opt/opencv/static/lib -lopencv_imgcodecs -lopencv_imgproc  -lopencv_core -ldl  -L /opt/opencv/static/lib/opencv4/3rdparty  -llibwebp  -llibpng  -llibtiff  -llibjasper  -llibjpeg-turbo  -lquirc -lade  -lzlib -lpthread -latomic

run_gray_cycle:
	/home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/spike --isa=rv64gcv /home/pp/Desktop/riscv/rv-v/riscv-gnu-toolchain/linux/bin/pk gray_cycle

