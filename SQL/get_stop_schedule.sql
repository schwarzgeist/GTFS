SELECT * FROM stop_times 
INNER JOIN trips ON stop_times.trip_id = trips.trip_id 
AND stop_times.stop_id = "7663" --This is the stop ID of the station you want the schedule for 
AND trips.service_id = "3"; --This should depict the kind of service (day) you want.
--In my case, my local transit authority uses
--Service ID 1 = Weekday Service
--Service ID 2 = Saturday Service
--Service ID 3 = Sunday Service

--So if I were to run this on my SQL tables, it would return a query that essentially is the northbound schedule for stop 7663 for Sundays