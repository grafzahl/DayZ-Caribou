private ["_vel","_speed","_scalePose","_scaleMvmt","_scaleLight","_anim","_anim4","_initial","_nearFlare","_scaler","_pos","_isWater","_nearFire","_scaleSound","_building","_isPlayerInside","_audial"];
_vel = velocity (vehicle player);
_speed = (_vel distance [0,0,0]);
_pos = getPosATL player;
_scalePose = 0.9;
_scaleMvmt = 0.2;	//0.4;
_scaleLight = 0.5;
//_scaleAlert = 1;

//Assess Players Position
_anim = animationState player;
_anim4 = toArray _anim;
_anim4 resize 4;
_anim4 = toString _anim4;

if (["pknl",_anim] call fnc_inString) then {
	_scaleMvmt = 0.2;	//0.1;
	_scalePose = 0.6;	//0.4
} else {
	if (["ppne",_anim] call fnc_inString) then {
		_scaleMvmt = 0.3;
		_scalePose = 0.14;
	};
};

if (_anim4 == "aswm") then {
	_scaleMvmt = 0.3;
	dayz_isSwimming = true;

	// if surface is not water abort 
	_isWater = surfaceIsWater _pos;
	if(!_isWater) then {

		// Stops swimming in ground
		if (vehicle player == player) then {
			[objNull, player, rSwitchMove,""] call RE;
			player playActionNow "stop";
		};
		// This sleep was much needed
		sleep 5;

		dayz_isSwimming = false;
	};
} else {
	dayz_isSwimming = false;
};

_initial = 20 + (sunOrMoon * 20);

_scaleLight = (
	(sunOrMoon * 2) //add sunlight
	+ moonIntensity //add moonlight
	- (overcast * 0.2) //remove for cloud state
	- (rain * 0.2) //remove for rain state
	- (fog * 0.5));		//remove for fog state

dayz_scaleLight = _scaleLight;

_scaleSound = (1
	- (rain * 0.3) //remove for rain state
	//+ (fog * 0.3) //add for fog state
	)
	max 0;

if (_scaleLight < 0.9) then {
	//Assess if near lightsource
	_nearFlare = nearestObject [getPosATL (vehicle player),"RoadFlare"];
	if (!isNull _nearFlare) then {
		_scaler = (_nearFlare distance (vehicle player));
		if (_scaler <= 30) then {
			_scaler = 30 - _scaler;
			_scaleLight = ((_scaler / 30) * 2) + _scaleLight;
		};
	};
	_nearFire = nearestObject [getPosATL (vehicle player),"Land_Fire"];
	if (!isNull _nearFire) then {
		_scaler = 50 - (_nearFire distance (vehicle player));
		_scaleLight = ((_scaler / 50) * 2) + _scaleLight;
	};
};

//Ensure zero or above
_scaleLight = _scaleLight max 0;

//Terrain Visibility
if (["grass",dayz_surfaceType] call fnc_inString) then {
	_initial = _initial * 0.5625;
	_scaleMvmt = _scaleMvmt - 0.075;
} else {
	if (["forest",dayz_surfaceType] call fnc_inString) then {
		_initial = _initial * 0.375;
		_scaleMvmt = _scaleMvmt - 0.15;
	} else {
		if (["concrete",dayz_surfaceType] call fnc_inString) then {
			_initial = _initial * 0.9;
			_scaleMvmt = _scaleMvmt + 0.05;
		} else {
			if (["rock",dayz_surfaceType] call fnc_inString) then {
				_initial = _initial * 0.825;
				_scaleMvmt = _scaleMvmt + 0.02;
			};
		};
	};
};

if (isOnRoad _pos) then {
	_initial = _initial * 0.975;
	_scaleMvmt = _scaleMvmt + 0.1;
	//dayz_surfaceNoise = dayz_surfaceNoise + 10;
};
/*
if (_speed > 5) then {
	_speed = _speed * 1;
} else {
	if (_speed > 3) then {
		_speed = _speed * 0.7;
	} else {
		_speed = _speed * 0.3;
	};
};
*/

//Are they inside a building
_building = nearestObject [getPosATL (vehicle player), "Building"];
_isPlayerInside = [(vehicle player),_building] call fnc_isInsideBuilding;
if (_isPlayerInside) then {
	_initial = 5;
};

//Work out result
_audial = round(_speed * dayz_surfaceNoise * _scaleMvmt * _scaleSound);
if ((_audial > DAYZ_disAudial) or ((time - dayz_firedCooldown) > 0.3)) then {
	DAYZ_disAudial = _audial;
};
DAYZ_disVisual = (round((_initial + (_speed * 3)) * _scalePose * _scaleLight)) * 1.5;