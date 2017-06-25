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