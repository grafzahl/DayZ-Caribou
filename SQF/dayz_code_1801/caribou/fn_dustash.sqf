scriptName "fn_dustash.sqf";
//--- Wind & Dust
[] spawn {
	setwind [0.201112,0.204166,true];
	while {true} do {
		_ran = ceil random 5;
		playsound format ["wind_%1",_ran];
		_obj = vehicle player;
		_pos = position _obj;

		//--- Dust
		setwind [0.201112*2,0.204166*2,false];
		_velocity = [random 10,random 10,-1];
		_color = [1.0, 0.9, 0.8];
		_alpha = 0.08 + random 0.06;
		_ps = "#particlesource" createVehicleLocal _pos;  
		_ps setParticleParams [["\Ca\Data\ParticleEffects\Universal\universal.p3d", 16, 12, 8], "", "Billboard", 1, 3, [0, 0, -6], _velocity, 1, 1.275, 1, 0, [9], [_color + [0], _color + [_alpha], _color + [0]], [1000], 1, 0, "", "", _obj];
		_ps setParticleRandom [3, [30, 30, 0], [0, 0, 0], 1, 0, [0, 0, 0, 0.01], 0, 0];
		_ps setParticleCircle [0.1, [0, 0, 0]];
		_ps setDropInterval 0.01;

		sleep (random 1);
		deletevehicle _ps;
		_delay = 10 + random 20;
		sleep _delay;
	};
};

//--- Ash
[] spawn {
	_pos = position player;
	_parray = [
	/* 00 */               ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8, 1],//"\Ca\Data\cl_water",
	/* 01 */               "",
	/* 02 */               "Billboard",
	/* 03 */               1,
	/* 04 */               4,
	/* 05 */               [0,0,0],
	/* 06 */               [0,0,0],
	/* 07 */               1,
	/* 08 */               0.000001,
	/* 09 */               0,
	/* 10 */               1.4,
	/* 11 */               [0.05,0.05],
	/* 12 */               [[0.1,0.1,0.1,1]],
	/* 13 */               [0,1],
	/* 14 */               0.2,
	/* 15 */               1.2,
	/* 16 */               "",
	/* 17 */               "",
	/* 18 */               vehicle player
	];
	_snow = "#particlesource" createVehicleLocal _pos;  
	_snow setParticleParams _parray;
	_snow setParticleRandom [0, [10, 10, 7], [0, 0, 0], 0, 0.01, [0, 0, 0, 0.1], 0, 0];
	_snow setParticleCircle [0.0, [0, 0, 0]];
	_snow setDropInterval 0.01;
	
	_oldPlayer = vehicle player;
	while {true} do {
		waituntil {vehicle player != _oldPlayer};
		_parray set [18,vehicle player];
		_snow setParticleParams _parray;
		_oldPlayer = vehicle player;
	};
};

_pos = getposATL player;
_ps = "#particlesource" createVehicleLocal _pos;  
_ps setParticleParams [["\Ca\Data\ParticleEffects\Universal\universal.p3d", 16, 12, 13, 0], "", "Billboard", 1, 10, [0, 0, -6], [0, 0, 0], 1, 1.275, 1, 0, [4], [[1, 1, 1, 0], [1, 1, 1, 0.04], [1, 1, 1, 0]], [1000], 1, 0, "", "", player];
_ps setParticleRandom [3, [40, 40, 0], [0, 0, 0], 2, 0.5, [0, 0, 0, 0.1], 0, 0];
_ps setParticleCircle [0.1, [0, 0, 0]];
_ps setDropInterval 0.004;

while {true} do {
	waituntil {vehicle player == player};
	_ps setposATL getposATL player;
	sleep 1;
};