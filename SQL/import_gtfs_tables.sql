--Assuming these files are in your local directory, this will create tables for each file

CREATE TABLE agency (agency_id INTEGER, agency_name TEXT, agency_url TEXT, agency_timezone TEXT, agency_lang TEXT, agency_phone TEXT, agency_fare_url TEXT);
CREATE TABLE calendar (service_id INTEGER, monday INTEGER, tuesday INTEGER, wednesday INTEGER, thursday INTEGER, friday INTEGER, saturday INTEGER, sunday INTEGER, start_date INTEGER, end_date INTEGER);
CREATE TABLE calendar_dates (service_id INTEGER, date_ INTEGER, exception_type TEXT);
CREATE TABLE routes (route_id INTEGER, agency_id INTEGER, route_short_name INTEGER, route_long_name TEXT, route_desc TEXT, route_type INTEGER, route_url TEXT, route_color TEXT, route_text_color TEXT);
CREATE TABLE shapes (shape_id INTEGER, shape_pt_lat REAL, shape_pt_lon REAL, shape_pt_sequence INTEGER, shape_dist_traveled REAL);
CREATE TABLE stop_times (trip_id INTEGER, arrival_time TEXT, departure_time TEXT, stop_id INTEGER, stop_sequence INTEGER, stop_headsign INTEGER, pickup_type INTEGER, drop_off_type INTEGER, shape_dist_traveled REAL);
CREATE TABLE trips (route_id INTEGER, service_id INTEGER, trip_id INTEGER, trip_headsign TEXT, trip_short_name TEXT, direction_id INTEGER, block_id INTEGER, shape_id INTEGER);
CREATE TABLE stops (stop_id INTEGER, stop_code INTEGER, stop_name TEXT, stop_desc TEXT, stop_lat REAL, stop_lon REAL, zone_id TEXT, stop_url TEXT, location_type TEXT, parent_station TEXT, wheelchair_boarding INTEGER);
.separator ,
.import calendar.txt calendar
.import agency.txt agency
.import calendar_dates.txt calendar_dates
.import routes.txt routes
.import shapes.txt shapes
.import stop_times.txt stop_times
.import stops.txt stops
.import trips.txt trips