all: wrapper

wrapper: wrapper.cpp
	    g++ -o run wrapper.cpp `/opt/conda/envs/object-detection/bin/python3.5-config --cflags` `/opt/conda/envs/object-detection/bin/python3.5-config --ldflags`

clean:
	    rm -rf run
