myserver: ./config/*.h ./config/*.cc ./data/*.h ./data/*.cc ./entity/*.h ./entity/*.cc ./protobuf/*.h ./protobuf/*.cc ./server/*.h ./server/*.cc
	protoc --proto_path=./protobuf/src/ --cpp_out=./protobuf/ ./protobuf/src/*.proto
	protoc --proto_path=./protobuf/src/ --csharp_out=./protobuf/csharp_out/ ./protobuf/src/*.proto
	g++ -g -std=c++11 ./config/*.h ./config/*.cc ./data/*.h ./data/*.cc ./entity/*.h ./entity/*.cc ./protobuf/*.h ./protobuf/*.cc ./server/*.h ./server/*.cc -o myserver -lprotobuf

.PHONY clean:
	rm -f *.o