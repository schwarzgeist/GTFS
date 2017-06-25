//
//  File: gtfs_handler.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef GTFS_HANDLER_HPP_
#define GTFS_HANDLER_HPP_

#include "gtfs-realtime.pb.h"

class GTFS_Handler{
public:
	GTFS_Handler(void);
	~GTFS_Handler(void);

	const void parse_gtfs_file(transit_realtime::FeedMessage feed);
};

#endif // GTFS_PARSER_HPP_