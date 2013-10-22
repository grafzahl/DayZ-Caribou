waituntil {!isNull player};

while {true} do {

	sleep 1;
	if(("ItemGPS" in items player) || ("ItemGPS" in weapons player)) then {
		[group player, currentWaypoint (group player)] setWaypointVisible true;
	} else {
		deleteWaypoint [group player, all];
		[group player, currentWaypoint (group player)] setWaypointVisible false;
	};
};

