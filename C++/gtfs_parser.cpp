#include <iostream>
#include <fstream>
#include <string>
#include "gtfs-realtime.pb.h"

int main(int argc, char ** argv) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

    transit_realtime::FeedMessage feed;
    
    std::fstream input(argv[1], std::ios::in | std::ios::binary);
    
    if (!feed.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse feed." << std::endl;
        return -1;
    }
    
    //------------------------------Feed Header------------------------------
    const transit_realtime::FeedHeader& header = feed.header();
    
    std::cout << "Realtime Version: " << header.gtfs_realtime_version() << std::endl;
    
    std::cout << "Entity Size: " << feed.entity_size() << std::endl;
    
    for (int i = 0; i < feed.entity_size(); i++){
        const transit_realtime::FeedEntity& entity = feed.entity(i);
        
        std::cout << "Entity ID: " << entity.id() << std::endl;
        
        //TripUpdate is optional
        if(entity.has_trip_update()){
            const transit_realtime::TripUpdate& trip_update = entity.trip_update();
            
            //TripDescriptor is mandatory
            const transit_realtime::TripDescriptor& trip_descriptor = trip_update.trip();
            
            //TripDescriptor.trip_id is optional
            if(trip_descriptor.has_trip_id()){
                const std::string trip_id = trip_descriptor.trip_id();
            }
            
            //TripDescriptor.route_id is optional
            if(trip_descriptor.has_route_id()){
                const std::string route_id = trip_descriptor.route_id();
            }
            
            //TripDescriptor.direction_id is optional
            if(trip_descriptor.has_direction_id()){
                const uint32_t direction_id = trip_descriptor.direction_id();
            }
            
            //TripDescriptor.start_time is optional
            if(trip_descriptor.has_start_time()){
                const std::string start_time = trip_descriptor.start_time();
            }
            
            //TripDescriptor.start_date is optional
            if(trip_descriptor.has_start_date()){
                const std::string start_date = trip_descriptor.start_date();
            }
            
            //TripDescriptor.schedule_relationship is optional
            if(trip_descriptor.has_schedule_relationship()){
                const transit_realtime::TripDescriptor::ScheduleRelationship& schedule_relationship = trip_descriptor.schedule_relationship();
                
                switch (schedule_relationship) {
                    case transit_realtime::TripDescriptor::SCHEDULED:
                    case transit_realtime::TripDescriptor::ADDED:
                    case transit_realtime::TripDescriptor::UNSCHEDULED:
                    case transit_realtime::TripDescriptor::CANCELED:
                    default:
                        break;
                }
            }
            
            //VehicleDescriptor is optional
            if(trip_update.has_vehicle()){
                const transit_realtime::VehicleDescriptor& vehicle_descriptor = trip_update.vehicle();
                
                //VehicleDescriptor.id is optional
                if(vehicle_descriptor.has_id()){
                    const std::string id = vehicle_descriptor.id();
                }
                
                //
            }
            
        }
        
        if(entity.has_vehicle()){
            const transit_realtime::VehiclePosition& vehicle_position = entity.vehicle();
        }
        
        if(entity.has_alert()){
            const transit_realtime::Alert& alert = entity.alert();
        }
        
        
    }
    
    //Delete all global objects allocated by libprotobuf.
    //google::protobuf::ShutdownProtobufLibrary();

	return 0;
}