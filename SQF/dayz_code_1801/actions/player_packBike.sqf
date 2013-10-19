private["_numPlyrs","_dis","_sfx","_hasToolbox","_hasCrowbar","_bike","_object","_result","_position"];

_hasToolbox = 	"ItemToolbox" in items player;
_hasCrowbar = 	"ItemCrowbar" in items player;
_bike = _this select 3;
_numPlyrs = (position _bike) nearObjects ["Man", 6];

if(!_hasToolbox) exitWith {
	cutText ["\n\nYou need a Toolbox to pack this Folding-Bike!", "PLAIN DOWN"];
};
if (({ alive _x } count _numPlyrs) > 1 && ({isPlayer _x} count _numPlyrs > 1)) exitWith {
	cutText ["\n\nYou must be the only Player around the Folding-Bike!", "PLAIN DOWN"];
};

_result = [player,"ItemBikeBox"] call BIS_fnc_invAdd;
//check if there is enough space in inventar
if (_result) then {
	deleteVehicle _bike;
	cutText [format["You have successfully packed your Folding-Bike!"], "PLAIN DOWN"];
} else {
	//if not enought space say "not enough space"
	cutText [localize "str_player_24", "PLAIN DOWN"];
};

//wait a bit
player playActionNow "Medic";
sleep 1;

//DO Animation
_dis=20;
_sfx = "tentunpack";
[player,_sfx,0,false,_dis] call dayz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;