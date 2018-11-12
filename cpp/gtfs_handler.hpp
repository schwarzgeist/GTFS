//
//  File: gtfs_handler.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef GTFS_HANDLER_HPP_
#define GTFS_HANDLER_HPP_

#include <fstream>
#include <string>
#include "gtfs-realtime.pb.h"

class GTFS_Handler{
private:
	transit_realtime::FeedMessage feed;

public:
	GTFS_Handler(void);
	GTFS_Handler(transit_realtime::FeedMessage feed);
	~GTFS_Handler(void);

	const bool parse_gtfs_file(transit_realtime::FeedMessage feed);
	std::string print_gtfs_file(transit_realtime::FeedMessage feed);
};

#endif // GTFS_PARSER_HPP_