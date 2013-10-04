private["_dis","_sfx","_hasToolbox","_hasCrowbar","_hasBikeBox","_object","_direction","_position"];

_hasToolbox = 	"ItemToolbox" in items player;
_hasCrowbar = 	"ItemCrowbar" in items player;
_hasBikeBox = "ItemBikeBox" in magazines player;

if(!_hasToolbox or !_hasBikeBox) exitWith {
	cutText ["\n\nYou need a Toolbox and a Folding-Bike Box!", "PLAIN DOWN"];
};
//wait a bit
player playActionNow "Medic";
sleep 1;

//DO Animation
_dis=20;
_sfx = "tentunpack";
[player,_sfx,0,false,_dis] call dayz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;

player removeMagazine "ItemBikeBox";
_direction = getDir player;
_position = getPos player;
_position = [(_position select 0)+2*sin(_direction),(_position select 1)+2*cos(_direction),0.001];
_object = "MMT_Civ" createVehicle _position;
_object setDir _direction;
_object setVariable ["Sarge", "1", true];
_object setVariable ["ObjectID", "1", true];
_object setVariable ["ObjectUID", "1", true];
	cutText ["\n\nYou have successfully set up your Folding-Bike!", "PLAIN DOWN"];