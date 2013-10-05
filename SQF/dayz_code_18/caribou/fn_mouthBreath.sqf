//Adds Condensation to Units (Non-ACRE)
//By Falcon (Original by tpw)
//Last Updated 23.01.2012

private ["_unit","_int","_nextTime", "_source", "_mylogic", "_fog"];

sleep 5;
my_breath_func = {
{
_unit = _x;
if(alive _unit) then {
_nextTime = _unit getVariable ["myNextBreathTime", -1];
if(_nextTime == -1) then {
_unit setVariable ["myNextBreathTime", diag_tickTime + (1+random(3))];
_source = "logic" createVehicleLocal (getpos _unit);
_unit setVariable ["myBreathingParticleLogic", _source];
if(_unit == player) then {_source attachto [_unit,[0,0.1,.04], "neck"];} else {_source attachto [_unit,[0,0.05,-0.08], "pilot"];};
_unit setVariable ["myBreathingParticleSource", nil];
};
_myParticleSource = _unit getVariable ["myBreathingParticleSource", nil];
if(diag_tickTime >= _nextTime) then {
if (isNil "_myParticleSource") then {
_unit setVariable ["myNextBreathTime", diag_tickTime + 0.5];
_mylogic = _unit getVariable "myBreathingParticleLogic";
_fog = "#particlesource" createVehicleLocal (getpos _mylogic);
_fog setParticleParams [["CaDataParticleEffectsUniversalUniversal", 16, 12, 13,0],
"",
"Billboard",
0.5,
0.5,
[0,0,0],
[0, 0.0, -0.3],
1, 1.275, 1, 0.2,
[0, 0.2,0],
[[1,1,1, (.01+random(.03))], [1,1,1, 0.01], [1,1,1, 0]], //Change (.01+random(.03)) for different effect 0 (less) 1 (more)
[1000],
1,
0.04,
"",
"",
_mylogic];
_fog setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
_fog setDropInterval (0.01-random(0.005)); //change drop interval for particle density 0.001 (most dense) -> .999 (least dense)

_unit setVariable ["myBreathingParticleSource", _fog];
} else {
_unit setVariable ["myNextBreathTime", diag_tickTime + (2+random(3))];
deletevehicle (_unit getVariable "myBreathingParticleSource");
_unit setVariable ["myBreathingParticleSource", nil];
};
};
} else {
_unit setVariable ["myNextBreathTime", -1];
deletevehicle (_unit getVariable "myBreathingParticleLogic");
deletevehicle (_unit getVariable "myBreathingParticleSource");
};
} forEach allUnits;
};

[my_breath_func, 0.1] call cba_fnc_addPerFrameHandler;