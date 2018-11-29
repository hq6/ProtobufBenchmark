LDFLAGS=-LPerfUtils/lib -lPerfUtils  -lprotobuf  -pthread
CPPFLAGS=-IPerfUtils/include

all: Benchmark

Benchmark: TestObj.pb.cc Benchmark.cc
	g++ $(CPPFLAGS) Benchmark.cc TestObj.pb.cc $(LDFLAGS) -o Benchmark

%.pb.cc: %.proto
	protoc TestObj.proto  --cpp_out=.
