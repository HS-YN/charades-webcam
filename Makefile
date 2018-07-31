all: wrapper

wrapper: wrapper.cpp
	    g++ -o run wrapper.cpp -I$(HOME)/anaconda3/envs/object-detection/include/python3.5m -I/$(HOME)/anaconda3/envs/object-detection/lib/ -L$(HOME)/anaconda3/envs/object-detection/lib -Wno-unused-result -Wsign-compare -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -O3 -pipe -fuse-linker-plugin -DNDEBUG -fwrapv -O3 -Wall -lpython3.5m -lpthread -ldl -lutil -lrt -lm -Xlinker -export-dynamic -I/home/hsynterry/charades-webcam/utils -L/home/hsynterry/charades-webcam/utils

clean:
	    rm -rf run
