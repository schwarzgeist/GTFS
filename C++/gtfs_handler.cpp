#include "gtfs-realtime.pb.h"

#include "gtfs_handler.hpp"

const void GTFS_Handler::parse_gtfs_file(transit_realtime::FeedMessage feed){
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
            
            //--------------------TripDescriptor--------------------
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
            
            //--------------------VehicleDescriptor--------------------
            
            //VehicleDescriptor is optional
            if(trip_update.has_vehicle()){
                const transit_realtime::VehicleDescriptor& vehicle_descriptor = trip_update.vehicle();
                
                //VehicleDescriptor.id is optional
                if(vehicle_descriptor.has_id()){
                    const std::string id = vehicle_descriptor.id();
                }
                
                //VehicleDescriptor.label is optional
                if(vehicle_descriptor.has_label()){
                    const std::string label = vehicle_descriptor.label();
                }
                
                //VehicleDescriptor.license_plate is optional
                if(vehicle_descriptor.has_license_plate()){
                    const std::string license_plate = vehicle_descriptor.license_plate();
                }
            }
            
            //--------------------StopTimeUpdate/StopTimeEvent--------------------
            
            const int stop_time_update_size = trip_update.stop_time_update_size();
            
            for (int j = 0; j < stop_time_update_size; j++){
                const transit_realtime::TripUpdate::StopTimeUpdate stop_time_update = trip_update.stop_time_update(j);
                
                //StopTimeUpdate.stop_sequence is optional
                const uint32_t stop_sequence = stop_time_update.stop_sequence();
                
                //StopTimeUpdate.stop_id is optional
                const std::string stop_id = stop_time_update.stop_id();
                
                //StopTimeUpdate.arrival is optional
                if (stop_time_update.has_arrival()){
                    const transit_realtime::TripUpdate::StopTimeEvent& stop_time_update_arrival = stop_time_update.arrival();
                    
                    if (stop_time_update_arrival.has_delay()){
                        const int32_t delay = stop_time_update_arrival.delay();
                    }
                    
                    if (stop_time_update_arrival.has_time()){
                        const int64_t time = stop_time_update_arrival.time();
                    }
                    
                    if (stop_time_update_arrival.has_uncertainty()){
                        const int32_t uncertainty = stop_time_update_arrival.uncertainty();
                    }
                }
                
                //StopTimeUpdate.departure is optional
                if (stop_time_update.has_departure()){
                    const transit_realtime::TripUpdate::StopTimeEvent& stop_time_update_departure = stop_time_update.departure();
                    
                    if (stop_time_update_departure.has_delay()){
                        const int32_t delay = stop_time_update_departure.delay();
                    }
                    
                    if (stop_time_update_departure.has_time()){
                        const int64_t time = stop_time_update_departure.time();
                    }
                    
                    if (stop_time_update_departure.has_uncertainty()){
                        const int32_t uncertainty = stop_time_update_departure.uncertainty();
                    }
                }
                
                //StopTimeUpdate.schedule_relationship is optional
                if(stop_time_update.has_schedule_relationship()){
                    const transit_realtime::TripUpdate::StopTimeUpdate::ScheduleRelationship& schedule_relationship = stop_time_update.schedule_relationship();
                    
                    switch (schedule_relationship) {
                        case transit_realtime::TripUpdate::StopTimeUpdate::SCHEDULED:
                        case transit_realtime::TripUpdate::StopTimeUpdate::SKIPPED:
                        case transit_realtime::TripUpdate::StopTimeUpdate::NO_DATA:
                        default:
                            break;
                    }
                }
            }
            
            //TripUpdate.timestamp is optional
            if (trip_update.has_timestamp()){
                const int64_t timestamp = trip_update.timestamp();
            }
            
            //TripUpdate.delay is optional
            if (trip_update.has_delay()){
                const int32_t delay = trip_update.delay();
            }
        }
        
        if(entity.has_vehicle()){
            const transit_realtime::VehiclePosition& vehicle_position = entity.vehicle();
            
            //VehiclePosition.TripDescriptor.trip is optional
            if (vehicle_position.has_trip()){
                //--------------------TripDescriptor--------------------
                //TripDescriptor is mandatory
                const transit_realtime::TripDescriptor& trip = vehicle_position.trip();
                
                //TripDescriptor.trip_id is optional
                if(trip.has_trip_id()){
                    const std::string trip_id = trip.trip_id();
                }
                
                //TripDescriptor.route_id is optional
                if(trip.has_route_id()){
                    const std::string route_id = trip.route_id();
                }
                
                //TripDescriptor.direction_id is optional
                if(trip.has_direction_id()){
                    const uint32_t direction_id = trip.direction_id();
                }
                
                //TripDescriptor.start_time is optional
                if(trip.has_start_time()){
                    const std::string start_time = trip.start_time();
                }
                
                //TripDescriptor.start_date is optional
                if(trip.has_start_date()){
                    const std::string start_date = trip.start_date();
                }
                
                //TripDescriptor.schedule_relationship is optional
                if(trip.has_schedule_relationship()){
                    const transit_realtime::TripDescriptor::ScheduleRelationship& schedule_relationship = trip.schedule_relationship();
                    
                    switch (schedule_relationship) {
                        case transit_realtime::TripDescriptor::SCHEDULED:
                        case transit_realtime::TripDescriptor::ADDED:
                        case transit_realtime::TripDescriptor::UNSCHEDULED:
                        case transit_realtime::TripDescriptor::CANCELED:
                        default:
                            break;
                    }
                }
            }
        }
        
        if(entity.has_alert()){
            const transit_realtime::Alert& alert = entity.alert();
        }
    }

}