#include <iostream>
#include <fstream>
#include <string>

#include "gtfs-realtime.pb.h"

#include "gtfs_parser.hpp"

int main(int argc, char ** argv) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

    transit_realtime::FeedMessage feed;
    
    std::fstream input(argv[1], std::ios::in | std::ios::binary);
    
    if (!feed.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse feed." << std::endl;
        return -1;
    }

    GTFS_Parser gtfs_handler;
    
    gtfs_handler.parse_gtfs_file(feed);

	return 0;
}