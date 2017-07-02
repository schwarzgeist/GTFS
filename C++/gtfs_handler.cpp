#include <fstream>

#include "gtfs-realtime.pb.h"

#include "gtfs_handler.hpp"

GTFS_Handler::GTFS_Handler() { }

GTFS_Handler::GTFS_Handler(transit_realtime::FeedMessage feed){

}

GTFS_Handler::~GTFS_Handler() { }

const bool GTFS_Handler::parse_gtfs_file(transit_realtime::FeedMessage feed){
    //------------------------------Feed Header------------------------------
    const transit_realtime::FeedHeader& header = feed.header();
    
    const std::string gtfs_realtime_version = header.gtfs_realtime_version();

    const int  entity_size = feed.entity_size();
    
    for (int i = 0; i < feed.entity_size(); i++){
        const transit_realtime::FeedEntity& entity = feed.entity(i);
        
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
        
        //------------------------------Vehicle Position------------------------------

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

            //VehiclePosition.vehicle is optional
            if(vehicle_position.has_vehicle()){
                const transit_realtime::VehicleDescriptor& vehicle_descriptor = vehicle_position.vehicle();
                
                //VehiclePosition.id is optional
                if(vehicle_descriptor.has_id()){
                    const std::string id = vehicle_descriptor.id();
                }
                
                //VehiclePosition.label is optional
                if(vehicle_descriptor.has_label()){
                    const std::string label = vehicle_descriptor.label();
                }
                
                //VehiclePosition.license_plate is optional
                if(vehicle_descriptor.has_license_plate()){
                    const std::string license_plate = vehicle_descriptor.license_plate();
                }
            }

            //VehiclePosition.position is optional
            if (vehicle_position.has_position()){
                const transit_realtime::Position& position = vehicle_position.position();

                //Position.latitude is mandatory
                const float latitude = position.latitude();

                //Position.longitude is mandatory
                const float longitude = position.longitude();

                //Position.bearing is optional
                if (position.has_bearing()){
                    const float bearing = position.bearing();
                }

                //Position.speed is optional
                if (position.has_speed()){
                    const float speed = position.speed();
                }
            }

            //VehiclePosition.current_stop_sequence is optional
            if (vehicle_position.has_current_stop_sequence()){
                const uint32_t current_stop_sequence = vehicle_position.current_stop_sequence();
            }

            //VehiclePosition.stop_id is optional
            if (vehicle_position.has_stop_id()){
                const std::string stop_id = vehicle_position.stop_id();
            }

            //VehiclePosition.current_status enum is optional
            if (vehicle_position.has_current_status()){
                const transit_realtime::VehiclePosition::VehicleStopStatus& vehicle_stop_status = vehicle_position.current_status();

                switch (vehicle_stop_status){
                    case transit_realtime::VehiclePosition::INCOMING_AT:
                    case transit_realtime::VehiclePosition::STOPPED_AT:
                    case transit_realtime::VehiclePosition::IN_TRANSIT_TO:
                    default:
                        break;
                }
            }

            //VehiclePosition.timestamp is optional
            if (vehicle_position.has_timestamp()){
                const uint64_t timestamp = vehicle_position.timestamp();
            }

            //VehiclePosition.congestion_level enum type is optional
            if (vehicle_position.has_congestion_level()){
                const transit_realtime::VehiclePosition::CongestionLevel& congestion_level = vehicle_position.congestion_level();

                switch (congestion_level){
                    case transit_realtime::VehiclePosition::UNKNOWN_CONGESTION_LEVEL:
                    case transit_realtime::VehiclePosition::RUNNING_SMOOTHLY:
                    case transit_realtime::VehiclePosition::STOP_AND_GO:
                    case transit_realtime::VehiclePosition::CONGESTION:
                    case transit_realtime::VehiclePosition::SEVERE_CONGESTION:
                    default:
                        break;
                }
            }

            //VehiclePosition.occupancy_status enum type is optional
            if (vehicle_position.has_occupancy_status()){
                const transit_realtime::VehiclePosition::OccupancyStatus& occupancy_status = vehicle_position.occupancy_status();

                switch(occupancy_status){
                    case transit_realtime::VehiclePosition::EMPTY:
                    case transit_realtime::VehiclePosition::MANY_SEATS_AVAILABLE:
                    case transit_realtime::VehiclePosition::FEW_SEATS_AVAILABLE:
                    case transit_realtime::VehiclePosition::STANDING_ROOM_ONLY:
                    case transit_realtime::VehiclePosition::CRUSHED_STANDING_ROOM_ONLY:
                    case transit_realtime::VehiclePosition::FULL:
                    case transit_realtime::VehiclePosition::NOT_ACCEPTING_PASSENGERS:
                    default:
                        break;
                }
            }
        }

        //------------------------------ Alert ------------------------------
        
        if(entity.has_alert()){
            const transit_realtime::Alert& alert = entity.alert();

            const int active_period_size = alert.active_period_size();

            for (int j = 0; j < active_period_size; j++){
                const transit_realtime::TimeRange& active_period = alert.active_period(j);

                if (active_period.has_start()){
                    const uint64_t start = active_period.start();
                }

                if (active_period.has_end()){
                    const uint64_t end = active_period.end();
                }
            }

            const int informed_entity_size = alert.informed_entity_size();

            for (int j = 0; j < informed_entity_size; j++){
                const transit_realtime::EntitySelector informed_entity = alert.informed_entity(j);

                if (informed_entity.has_agency_id()){
                    const std::string agency_id = informed_entity.agency_id();
                }

                if (informed_entity.has_route_id()){
                    const std::string route_id = informed_entity.route_id();
                }

                if (informed_entity.has_route_type()){
                    const uint32_t route_type = informed_entity.route_type();
                }

                if (informed_entity.has_trip()){
                    const transit_realtime::TripDescriptor& trip = informed_entity.trip();
                }

                if (informed_entity.has_stop_id()){
                    const std::string stop_id = informed_entity.stop_id();
                }
            }

            //Alert.cause is optional
            if (alert.has_cause()){
                const transit_realtime::Alert::Cause& cause = alert.cause();

                switch(cause){
                    case transit_realtime::Alert::UNKNOWN_CAUSE:
                    case transit_realtime::Alert::OTHER_CAUSE:
                    case transit_realtime::Alert::TECHNICAL_PROBLEM:
                    case transit_realtime::Alert::STRIKE:
                    case transit_realtime::Alert::DEMONSTRATION:
                    case transit_realtime::Alert::ACCIDENT:
                    case transit_realtime::Alert::HOLIDAY:
                    case transit_realtime::Alert::WEATHER:
                    case transit_realtime::Alert::MAINTENANCE:
                    case transit_realtime::Alert::CONSTRUCTION:
                    case transit_realtime::Alert::POLICE_ACTIVITY:
                    case transit_realtime::Alert::MEDICAL_EMERGENCY:
                    default:
                        break;
                }
            }

            //Alert.effect is optional
            if (alert.has_effect()){
                const transit_realtime::Alert::Effect& effect = alert.effect();

                switch(effect){
                    case transit_realtime::Alert::NO_SERVICE:
                    case transit_realtime::Alert::REDUCED_SERVICE:
                    case transit_realtime::Alert::SIGNIFICANT_DELAYS:
                    case transit_realtime::Alert::DETOUR:
                    case transit_realtime::Alert::ADDITIONAL_SERVICE:
                    case transit_realtime::Alert::MODIFIED_SERVICE:
                    case transit_realtime::Alert::OTHER_EFFECT:
                    case transit_realtime::Alert::UNKNOWN_EFFECT:
                    case transit_realtime::Alert::STOP_MOVED:
                    default:
                        break;
                
                }
            }

            //Alert.TranslatedString.url is optional
            if (alert.has_url()){
                const transit_realtime::TranslatedString& url = alert.url();

                const int translation_size = url.translation_size();

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = url.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }

            if (alert.has_header_text()){
                const transit_realtime::TranslatedString& header_text = alert.header_text();

                const int translation_size = header_text.translation_size();                

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = header_text.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }

            if (alert.has_description_text()){
                const transit_realtime::TranslatedString& description_text = alert.description_text();

                const int translation_size = description_text.translation_size();

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = description_text.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }
        }
    }

    return true;
}

std::string GTFS_Handler::print_gtfs_file(transit_realtime::FeedMessage feed){
    std::string tmp;
    //------------------------------Feed Header------------------------------
    const transit_realtime::FeedHeader& header = feed.header();
    
    const std::string gtfs_realtime_version = header.gtfs_realtime_version();
    tmp += "GTFS Realtime Version: " + gtfs_realtime_version + "\n";

    const int  entity_size = feed.entity_size();
    tmp += "Entity Size: " + std::to_string(entity_size) + "\n";
    
    for (int i = 0; i < feed.entity_size(); i++){
        const transit_realtime::FeedEntity& entity = feed.entity(i);
        
        //TripUpdate is optional
        if(entity.has_trip_update()){
            const transit_realtime::TripUpdate& trip_update = entity.trip_update();
            
            //--------------------TripDescriptor--------------------
            //TripDescriptor is mandatory
            const transit_realtime::TripDescriptor& trip_descriptor = trip_update.trip();
            
            //TripDescriptor.trip_id is optional
            if(trip_descriptor.has_trip_id()){
                const std::string trip_id = trip_descriptor.trip_id();
                tmp += "TripID: " + trip_id;
            }
            
            //TripDescriptor.route_id is optional
            if(trip_descriptor.has_route_id()){
                const std::string route_id = trip_descriptor.route_id();
                tmp += "RouteID:" + route_id;                
            }
            
            //TripDescriptor.direction_id is optional
            if(trip_descriptor.has_direction_id()){
                const uint32_t direction_id = trip_descriptor.direction_id();
                tmp += "DirectionID: " + std::to_string(direction_id);
            }
            
            //TripDescriptor.start_time is optional
            if(trip_descriptor.has_start_time()){
                const std::string start_time = trip_descriptor.start_time();
                tmp += "StartTime: " + start_time;
            }
            
            //TripDescriptor.start_date is optional
            if(trip_descriptor.has_start_date()){
                const std::string start_date = trip_descriptor.start_date();
                tmp += "StartDate: " + start_date;
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
                    tmp += "ID: " + id;
                }
                
                //VehicleDescriptor.label is optional
                if(vehicle_descriptor.has_label()){
                    const std::string label = vehicle_descriptor.label();
                    tmp += "Label: " + label;
                }
                
                //VehicleDescriptor.license_plate is optional
                if(vehicle_descriptor.has_license_plate()){
                    const std::string license_plate = vehicle_descriptor.license_plate();
                    tmp += "LicensePlate: " + license_plate;
                }
            }
            
            //--------------------StopTimeUpdate/StopTimeEvent--------------------
            
            const int stop_time_update_size = trip_update.stop_time_update_size();
            
            for (int j = 0; j < stop_time_update_size; j++){
                const transit_realtime::TripUpdate::StopTimeUpdate stop_time_update = trip_update.stop_time_update(j);
                
                //StopTimeUpdate.stop_sequence is optional
                const uint32_t stop_sequence = stop_time_update.stop_sequence();
                tmp += "StopSequence: " + std::to_string(stop_sequence);
                
                //StopTimeUpdate.stop_id is optional
                const std::string stop_id = stop_time_update.stop_id();
                tmp += "StopID: " + stop_id;
                
                //StopTimeUpdate.arrival is optional
                if (stop_time_update.has_arrival()){
                    const transit_realtime::TripUpdate::StopTimeEvent& stop_time_update_arrival = stop_time_update.arrival();
                    
                    if (stop_time_update_arrival.has_delay()){
                        const int32_t delay = stop_time_update_arrival.delay();
                        tmp += "ArrivalDelay: " + std::to_string(delay);
                    }
                    
                    if (stop_time_update_arrival.has_time()){
                        const int64_t time = stop_time_update_arrival.time();
                        tmp += "ArrivalTime: " + std::to_string(time);
                    }
                    
                    if (stop_time_update_arrival.has_uncertainty()){
                        const int32_t uncertainty = stop_time_update_arrival.uncertainty();
                        tmp += "ArrivalUncertainty: " + std::to_string(uncertainty);
                    }
                }
                
                //StopTimeUpdate.departure is optional
                if (stop_time_update.has_departure()){
                    const transit_realtime::TripUpdate::StopTimeEvent& stop_time_update_departure = stop_time_update.departure();
                    
                    if (stop_time_update_departure.has_delay()){
                        const int32_t delay = stop_time_update_departure.delay();
                        tmp += "DepartureDelay: " + std::to_string(delay);
                    }
                    
                    if (stop_time_update_departure.has_time()){
                        const int64_t time = stop_time_update_departure.time();
                        tmp += "DepartureTime: " + std::to_string(time);
                    }
                    
                    if (stop_time_update_departure.has_uncertainty()){
                        const int32_t uncertainty = stop_time_update_departure.uncertainty();
                        tmp += "DepartureUncertainty: " + std::to_string(uncertainty);
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
                tmp += "TripUpdateTimestamp: " + std::to_string(timestamp);
            }
            
            //TripUpdate.delay is optional
            if (trip_update.has_delay()){
                const int32_t delay = trip_update.delay();
                tmp += "TripUpdateDelay: " + std::to_string(delay);
            }
        }
        
        //------------------------------Vehicle Position------------------------------

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
                    tmp += "TripID: " + trip_id;
                }
                
                //TripDescriptor.route_id is optional
                if(trip.has_route_id()){
                    const std::string route_id = trip.route_id();

                    tmp += "TripRouteID: " + route_id;
                }
                
                //TripDescriptor.direction_id is optional
                if(trip.has_direction_id()){
                    const uint32_t direction_id = trip.direction_id();
                    tmp += "TripDirectionID: " + std::to_string(direction_id);
                }
                
                //TripDescriptor.start_time is optional
                if(trip.has_start_time()){
                    const std::string start_time = trip.start_time();
                    tmp += "TripStartTime: " + start_time;
                }
                
                //TripDescriptor.start_date is optional
                if(trip.has_start_date()){
                    const std::string start_date = trip.start_date();
                    tmp += "TripStartDate: " + start_date;
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

            //VehiclePosition.vehicle is optional
            if(vehicle_position.has_vehicle()){
                const transit_realtime::VehicleDescriptor& vehicle_descriptor = vehicle_position.vehicle();
                
                //VehiclePosition.id is optional
                if(vehicle_descriptor.has_id()){
                    const std::string id = vehicle_descriptor.id();
                    tmp += "VehicleID: " + id;
                }
                
                //VehiclePosition.label is optional
                if(vehicle_descriptor.has_label()){
                    const std::string label = vehicle_descriptor.label();
                    tmp += "VehicleLabel: " + label;
                }
                
                //VehiclePosition.license_plate is optional
                if(vehicle_descriptor.has_license_plate()){
                    const std::string license_plate = vehicle_descriptor.license_plate();
                    tmp += "VehicleLicensePlate: " + license_plate;
                }
            }

            //VehiclePosition.position is optional
            if (vehicle_position.has_position()){
                const transit_realtime::Position& position = vehicle_position.position();

                //Position.latitude is mandatory
                const float latitude = position.latitude();
                tmp += "VehiclePositionLatitude: " + std::to_string(latitude);

                //Position.longitude is mandatory
                const float longitude = position.longitude();
                tmp += "VehiclePositionLongitude: " + std::to_string(longitude);

                //Position.bearing is optional
                if (position.has_bearing()){
                    const float bearing = position.bearing();
                    tmp += "VehicleBearing: " + std::to_string(bearing);
                }

                //Position.speed is optional
                if (position.has_speed()){
                    const float speed = position.speed();
                    tmp += "VehicleSpeed: " + std::to_string(speed);
                }
            }

            //VehiclePosition.current_stop_sequence is optional
            if (vehicle_position.has_current_stop_sequence()){
                const uint32_t current_stop_sequence = vehicle_position.current_stop_sequence();
                tmp += "VehicleStopSequence: " + std::to_string(current_stop_sequence);
            }

            //VehiclePosition.stop_id is optional
            if (vehicle_position.has_stop_id()){
                const std::string stop_id = vehicle_position.stop_id();
                tmp += "VehicleStopID: " + stop_id;
            }

            //VehiclePosition.current_status enum is optional
            if (vehicle_position.has_current_status()){
                const transit_realtime::VehiclePosition::VehicleStopStatus& vehicle_stop_status = vehicle_position.current_status();

                switch (vehicle_stop_status){
                    case transit_realtime::VehiclePosition::INCOMING_AT:
                    case transit_realtime::VehiclePosition::STOPPED_AT:
                    case transit_realtime::VehiclePosition::IN_TRANSIT_TO:
                    default:
                        break;
                }
            }

            //VehiclePosition.timestamp is optional
            if (vehicle_position.has_timestamp()){
                const uint64_t timestamp = vehicle_position.timestamp();
                tmp += "VehicleTimestamp: " + std::to_string(timestamp);
            }

            //VehiclePosition.congestion_level enum type is optional
            if (vehicle_position.has_congestion_level()){
                const transit_realtime::VehiclePosition::CongestionLevel& congestion_level = vehicle_position.congestion_level();

                switch (congestion_level){
                    case transit_realtime::VehiclePosition::UNKNOWN_CONGESTION_LEVEL:
                    case transit_realtime::VehiclePosition::RUNNING_SMOOTHLY:
                    case transit_realtime::VehiclePosition::STOP_AND_GO:
                    case transit_realtime::VehiclePosition::CONGESTION:
                    case transit_realtime::VehiclePosition::SEVERE_CONGESTION:
                    default:
                        break;
                }
            }

            //VehiclePosition.occupancy_status enum type is optional
            if (vehicle_position.has_occupancy_status()){
                const transit_realtime::VehiclePosition::OccupancyStatus& occupancy_status = vehicle_position.occupancy_status();

                switch(occupancy_status){
                    case transit_realtime::VehiclePosition::EMPTY:
                    case transit_realtime::VehiclePosition::MANY_SEATS_AVAILABLE:
                    case transit_realtime::VehiclePosition::FEW_SEATS_AVAILABLE:
                    case transit_realtime::VehiclePosition::STANDING_ROOM_ONLY:
                    case transit_realtime::VehiclePosition::CRUSHED_STANDING_ROOM_ONLY:
                    case transit_realtime::VehiclePosition::FULL:
                    case transit_realtime::VehiclePosition::NOT_ACCEPTING_PASSENGERS:
                    default:
                        break;
                }
            }
        }

        //------------------------------ Alert ------------------------------
        
        if(entity.has_alert()){
            const transit_realtime::Alert& alert = entity.alert();

            const int active_period_size = alert.active_period_size();

            for (int j = 0; j < active_period_size; j++){
                const transit_realtime::TimeRange& active_period = alert.active_period(j);

                if (active_period.has_start()){
                    const uint64_t start = active_period.start();
                }

                if (active_period.has_end()){
                    const uint64_t end = active_period.end();
                }
            }

            const int informed_entity_size = alert.informed_entity_size();

            for (int j = 0; j < informed_entity_size; j++){
                const transit_realtime::EntitySelector informed_entity = alert.informed_entity(j);

                if (informed_entity.has_agency_id()){
                    const std::string agency_id = informed_entity.agency_id();
                }

                if (informed_entity.has_route_id()){
                    const std::string route_id = informed_entity.route_id();
                }

                if (informed_entity.has_route_type()){
                    const uint32_t route_type = informed_entity.route_type();
                }

                if (informed_entity.has_trip()){
                    const transit_realtime::TripDescriptor& trip = informed_entity.trip();
                }

                if (informed_entity.has_stop_id()){
                    const std::string stop_id = informed_entity.stop_id();
                }
            }

            //Alert.cause is optional
            if (alert.has_cause()){
                const transit_realtime::Alert::Cause& cause = alert.cause();

                switch(cause){
                    case transit_realtime::Alert::UNKNOWN_CAUSE:
                    case transit_realtime::Alert::OTHER_CAUSE:
                    case transit_realtime::Alert::TECHNICAL_PROBLEM:
                    case transit_realtime::Alert::STRIKE:
                    case transit_realtime::Alert::DEMONSTRATION:
                    case transit_realtime::Alert::ACCIDENT:
                    case transit_realtime::Alert::HOLIDAY:
                    case transit_realtime::Alert::WEATHER:
                    case transit_realtime::Alert::MAINTENANCE:
                    case transit_realtime::Alert::CONSTRUCTION:
                    case transit_realtime::Alert::POLICE_ACTIVITY:
                    case transit_realtime::Alert::MEDICAL_EMERGENCY:
                    default:
                        break;
                }
            }

            //Alert.effect is optional
            if (alert.has_effect()){
                const transit_realtime::Alert::Effect& effect = alert.effect();

                switch(effect){
                    case transit_realtime::Alert::NO_SERVICE:
                    case transit_realtime::Alert::REDUCED_SERVICE:
                    case transit_realtime::Alert::SIGNIFICANT_DELAYS:
                    case transit_realtime::Alert::DETOUR:
                    case transit_realtime::Alert::ADDITIONAL_SERVICE:
                    case transit_realtime::Alert::MODIFIED_SERVICE:
                    case transit_realtime::Alert::OTHER_EFFECT:
                    case transit_realtime::Alert::UNKNOWN_EFFECT:
                    case transit_realtime::Alert::STOP_MOVED:
                    default:
                        break;
                
                }
            }

            //Alert.TranslatedString.url is optional
            if (alert.has_url()){
                const transit_realtime::TranslatedString& url = alert.url();

                const int translation_size = url.translation_size();

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = url.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }

            if (alert.has_header_text()){
                const transit_realtime::TranslatedString& header_text = alert.header_text();

                const int translation_size = header_text.translation_size();                

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = header_text.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }

            if (alert.has_description_text()){
                const transit_realtime::TranslatedString& description_text = alert.description_text();

                const int translation_size = description_text.translation_size();

                for (int j = 0; j < translation_size; j++){
                    const transit_realtime::TranslatedString::Translation& translation = description_text.translation(j);

                    const std::string text = translation.text();

                    if (translation.has_language()){
                        const std::string language = translation.language();
                    }
                }
            }
        }
    }

    tmp += "\n\n----------------------------------------------------------------------------------\n\n";

    return tmp;
}