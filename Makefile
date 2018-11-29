all: Benchmark

Benchmark: TestObj.pb.cc Benchmark.cc
	g++ Benchmark.cc TestObj.pb.cc -lprotobuf  -pthread -o Benchmark

%.pb.cc: %.proto
	protoc TestObj.proto  --cpp_out=.
