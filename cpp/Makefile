CXX=gcc
CXXFLAGS +=`pkg-config --cflags --libs protobuf` -std=c++14

all: gtfs-realtime.pb* gtfs_handler* main.cpp classes/*
	$(CXX) $(CXXFLAGS)\
	  gtfs_handler.cpp main.cpp\
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
	 -o gtfs_parse_cpp

clean:
	@rm gtfs_parse_cpp
