_locations = [
	[871.95148, 3584.4463, 0],
	[814.74286, 3757.9092, 0],
	[879.36884, 3857.4563, 0],
	[921.26154, 3848.3284, 0],
	[1065.4023, 3612.7598, 0],
	[1093.3182, 3590.9519, 0],
	[1064.0433, 3466.0867, 0],
	[1011.9445, 3535.6526, 0],
	[914.81653, 3633.2551, 0],
	[986.43652, 3602.5171, 0],
	[1034.719, 3777.4661, 0],
	[1738.8835, 3639.7412, 0],
	[3173.6387, 2496.4626, 0],
	[3232.3459, 2373.7856, 0],
	[3224.2271, 2421.1082, 0],
	[3291.3538, 2464.5447, 0],
	[3326.7136, 2366.0222, 0],
	[3036.4719, 3136.3086, 0],
	[3169.3801, 2833.9951, 0],
	[5175.6655, 3657.0842, 0],
	[5288.9189, 3709.7307, 0],
	[5163.5601, 3600.3335, 0]
];

{
	diag_log format["Searching for Fences on new Position %1",_x];
	_list = nearestObjects [_x, [], 2];
	{
		
		if ((_x != player) && !(_x isKindOf "AllVehicles")) then {
			diag_log format["Smashing Fence %1",_x];
			//_x hideObject true;
			//deleteCollection _x;
			//deleteVehicle _x;
			_x setDamage 1;
		};
	} foreach _list;
} foreach _locations;