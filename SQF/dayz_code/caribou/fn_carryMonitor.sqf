waituntil {!isNull player};

while {true} do {

	sleep 15;

	private ["_wpn"];
	_wpn = primaryWeapon player;

	if ((_wpn != "") && (!(_wpn in MeleeWeapons)) && (dayz_onBack != "") && (!(dayz_onBack in MeleeWeapons))) then {
		cutText ["You're trying to carry two primary weapons!","PLAIN DOWN"];
		[objNull, player, rSwitchMove,""] call RE;
		sleep 0.1;
		player playActionNow "stop";
		sleep 0.1;
		player playActionNow "PutDown";
		[player,_wpn] call BIS_fnc_invRemove;
		["gear"] call player_switchWeapon;
	};
};