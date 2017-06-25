all: gtfs-realtime.pb.cc gtfs_handler.cpp
	@pkg-config --cflags protobuf # fails if protobuf is not installed
	@c++ gtfs_handler.cpp gtfs-realtime.pb.cc main.cpp -o gtfs_parse_cpp `pkg-config --cflags --libs protobuf`

clean:
	@rm gtfs_parse_cpp