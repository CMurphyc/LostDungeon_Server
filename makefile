test_server: ./config/*.h ./config/*.cc ./data/*.h ./data/*.cc ./entity/*.h ./entity/*.cc ./protobuf/*.h ./protobuf/*.cc ./other/*.h ./other/*.cc ./server/*.h ./server/*.cc
	ulimit -c unlimited
	protoc --proto_path=./protobuf/src/ --cpp_out=./protobuf/ ./protobuf/src/*.proto
	protoc --proto_path=./protobuf/src/ --csharp_out=./protobuf/csharp_out/ ./protobuf/src/*.proto
	g++ -g -std=c++11 ./config/*.h ./config/*.cc ./data/*.h ./data/*.cc ./entity/*.h ./entity/*.cc ./protobuf/*.h ./protobuf/*.cc ./other/*.h ./other/*.cc ./server/*.h ./server/*.cc -o my_server -lprotobuf

.PHONY clean:
	rm -f *.o