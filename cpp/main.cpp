//
//  File: main.cpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#include "gtfs-realtime.pb.h"

#include "gtfs_handler.hpp"

int main(int argc, char ** argv){
	GOOGLE_PROTOBUF_VERIFY_VERSION;

    transit_realtime::FeedMessage feed;

    std::ofstream output_file;
    output_file.open("output.txt");

    for (int i = 1; i < argc; i++)
    {
        std::fstream input(argv[i], std::ios::in | std::ios::binary);

        if (!feed.ParseFromIstream(&input))
        {
            std::cerr << "Failed to parse feed." << std::endl;
            return -1;
        }

        GTFS_Handler gtfs_handler;

        if (gtfs_handler.parse_gtfs_file(feed))
        {
            std::cout << "Parsed File Successfully!" << std::endl;
        }

        std::cout << "Printing GTFS File" << std::endl;

        output_file << gtfs_handler.print_gtfs_file(feed) << std::endl;
    }

    output_file.close();

    return 0;
}

int main2(int argc, char ** argv) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

    transit_realtime::FeedMessage feed;
    
    std::fstream input(argv[1], std::ios::in | std::ios::binary);
    
    if (!feed.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse feed." << std::endl;
        return -1;
    }

    GTFS_Handler gtfs_handler;

    if (gtfs_handler.parse_gtfs_file(feed)){
        std::cout << "Parsed File Successfully!" << std::endl;
    }

    std::cout << "Printing GTFS File" << std::endl;

    std::ofstream output_file;
    output_file.open("output" + std::to_string(rand()) + ".txt");

    gtfs_handler.print_gtfs_file(feed);

    output_file.close();

	return 0;
}