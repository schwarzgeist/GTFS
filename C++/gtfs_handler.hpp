#ifndef GTFS_HANDLER_HPP_
#define GTFS_HANDLER_HPP_

#include "gtfs-realtime.pb.h"

class GTFS_Handler{
private:

public:
	void parse_gtfs_file(transit_realtime::FeedMessage feed);
};

#endif // GTFS_PARSER_HPP_