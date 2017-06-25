//
//  File: wrapper.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef WRAPPER_HPP_
#define WRAPPER_HPP_


#ifdef __cplusplus
extern "C" {
#endif

	const void GTFS_Handler::parse_gtfs_file(transit_realtime::FeedMessage feed);

#ifdef __cplusplus
}
#endif

#endif //WRAPPER_HPP_