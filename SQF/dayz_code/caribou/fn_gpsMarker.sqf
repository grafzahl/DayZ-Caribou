waituntil {!isNull player};

/*
while {true} do {
	private ["_hasGPS"];
	_hasGPS = "ItemGPS" in items player;
	if !(_hasGPS) then{
		while {(count (waypoints _group)) > 0} do {
			deleteWaypoint ((waypoints _group) select 0);
		};
	}
};
*/
diag_log("Starting GPS-Marker");
onMapSingleClick "[_pos, _shift, _alt] call DAM_GPS_coPilot;";

DAM_GPS_coPilot = {
	diag_log("Marker has been triggered");
	private ["_marker","_vehicle", "_hasGPS", "_inVehicle", "_pilot", "_thePlayer","_pos", "_shift", "_alt", "_wp", "_mesage", "_nearestLocation", "_nearestLocationName", "_group"];
	_pos = _this select 0;
	_shift = _this select 1;
	_alt = _this select 2;

	_nearestLocation = (nearestLocations [_pos,["NameCityCapital","NameCity","NameVillage"],5000]) select 0;
	_nearestLocationName = text _nearestLocation;

	_thePlayer = player;	// Whoever is calling the script
	_hasGPS = "ItemGPS" in items player;
	_group = group player;

	if (_shift) then {
		if(_hasGPS) then {
			// Delete existing waypoint(s)
			// deleteWaypoint [_group, all]; // dunno if this works
			while {(count (waypoints _group)) > 0} do {
				deleteWaypoint ((waypoints _group) select 0);
			};

			_wp = _group addWaypoint [[_pos select 0, _pos select 1], 0]; // add a waypoint
			_wp setWaypointType "MOVE";
			_marker= createMarkerLocal ["DistanceMarker",[_pos select 0, _pos select 1]];
			"DistanceMarker" setMarkerTypeLocal "Warning";
			_message = format["A new waypoint has been set near %1 by %2", _nearestLocationName, _thePlayer];
			cutText [_message,"PLAIN DOWN"];
		} else {
			cutText ["You need a GPS to set a Mapmarker","PLAIN DOWN"];
		};
	};
};