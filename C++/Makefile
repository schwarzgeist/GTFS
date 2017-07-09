all: gtfs-realtime.pb* gtfs_handler* main.cpp classes/*
	@pkg-config --cflags protobuf # fails if protobuf is not installed
	@c++ gtfs_handler.cpp gtfs-realtime.pb.cc main.cpp\
	  classes/alert.cpp\
	  classes/entity.cpp\
	  classes/entity_selector.cpp
	  classes/feed.cpp\
	  classes/feed_header.cpp\
	  classes/position.cpp\
	  classes/schedule_relationship.cpp\
	  classes/stop_time_event.cpp\
	  classes/stop_time_update.cpp\
	  classes/time_range.cpp\
	  classes/translated_string.cpp\
	  classes/trip_descriptor.cpp\
	  classes/trip_update.cpp\
	  classes/vehicle_descriptor.cpp\
	  classes/vehicle_position.cpp\
	 -o gtfs_parse_cpp `pkg-config --cflags --libs protobuf`

clean:
	@rm gtfs_parse_cpp
