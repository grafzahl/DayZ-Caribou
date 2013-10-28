if (isServer) then {
	waitUntil{dayz_preloadFinished};
};
_id = [] execFSM "\z\addons\dayz_code\system\player_monitor.fsm";









































































[] execVM "\z\addons\dayz_code\caribou\colorize\default_c.sqf";
[] execVM "\z\addons\dayz_code\caribou\fn_limitThirdPersonView.sqf";
[] execVM "\z\addons\dayz_code\caribou\fn_dustash.sqf";
[] execVM "\z\addons\dayz_code\caribou\fn_carryMonitor.sqf";
[] execVM "\z\addons\dayz_code\caribou\fn_hideMarker.sqf";
[] execVM "\z\addons\dayz_code\caribou\fn_skaronametags.sqf";

waituntil {!isnil "BIS_Effects_Burn"};
{
	nul = [_x, 4, time, false, false] spawn BIS_Effects_Burn;
} forEach allMissionObjects "HeliHEmpty";

setViewDistance 3000;