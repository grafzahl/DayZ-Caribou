scriptName "Functions\misc\fn_selfActions.sqf";
/***********************************************************
	ADD ACTIONS FOR SELF
	- Function
	- [] call fnc_usec_selfActions;
************************************************************/
_vehicle = vehicle player;
_inVehicle = (_vehicle != player);
_cursorTarget = cursorTarget;
_primaryWeapon = primaryWeapon player;
_currentWeapon = currentWeapon player;
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;

_nearLight = nearestObject [player,"LitObject"];
_canPickLight = false;
if (!isNull _nearLight) then {
	if (_nearLight distance player < 4) then {
		_canPickLight = isNull (_nearLight getVariable ["owner",objNull]);
	};
};
_canDo = (!r_drag_sqf and !r_player_unconscious and !_onLadder);

//Grab Flare
if (_canPickLight and !dayz_hasLight) then {
	if (s_player_grabflare < 0) then {
		_text = getText (configFile >> "CfgAmmo" >> (typeOf _nearLight) >> "displayName");
		s_player_grabflare = player addAction [format[localize "str_actions_medical_15",_text], "\z\addons\dayz_code\actions\flare_pickup.sqf",_nearLight, 1, false, true, "", ""];
		s_player_removeflare = player addAction [format[localize "str_actions_medical_17",_text], "\z\addons\dayz_code\actions\flare_remove.sqf",_nearLight, 1, false, true, "", ""];
	};
} else {
	player removeAction s_player_grabflare;
	player removeAction s_player_removeflare;
	s_player_grabflare = -1;
	s_player_removeflare = -1;
};

if (dayz_onBack != "" && !dayz_onBackActive && !_inVehicle && !_onLadder && !r_player_unconscious) then {
	if (s_player_equip_carry < 0) then {
		_text = getText (configFile >> "CfgWeapons" >> dayz_onBack >> "displayName");
		s_player_equip_carry = player addAction [format[localize "STR_ACTIONS_WEAPON", _text], "\z\addons\dayz_code\actions\player_switchWeapon.sqf", "action", 0.5, false, true];
	};
} else {
	player removeAction s_player_equip_carry;
	s_player_equip_carry = -1;
};

//fishing
if ((_currentWeapon in Dayz_fishingItems) && !dayz_fishingInprogress && !_inVehicle && !dayz_isSwimming) then {
	if (s_player_fishing < 0) then {
		s_player_fishing = player addAction [localize "STR_ACTION_CAST", "\z\addons\dayz_code\actions\player_goFishing.sqf",player, 0.5, false, true];
	};
} else {
	player removeAction s_player_fishing;
	s_player_fishing = -1;
};
if ((_primaryWeapon in Dayz_fishingItems) && !dayz_fishingInprogress && (_inVehicle and (driver _vehicle != player))) then {
		if (s_player_fishing_veh < 0) then {
			s_player_fishing_veh = _vehicle addAction [localize "STR_ACTION_CAST", "\z\addons\dayz_code\actions\player_goFishing.sqf",_vehicle, 0.5, false, true];
		};
} else {
	_vehicle removeAction s_player_fishing_veh;
	s_player_fishing_veh = -1;
};	

if (!isNull _cursorTarget and !_inVehicle and (player distance _cursorTarget < 4)) then { //Has some kind of target
	
	_isVehicle = _cursorTarget isKindOf "AllVehicles";
	_isMan = _cursorTarget isKindOf "Man";
	_isAnimal = _cursorTarget isKindOf "Animal";
	_isZombie = _cursorTarget isKindOf "zZombie_base";
	_isDestructable = (_cursorTarget isKindOf "BuiltItems") or (_cursorTarget isKindOf "Barrel_burning_CBDZ") or (_cursorTarget isKindOf "CamoNet_DZ");
	_isTent = _cursorTarget isKindOf "TentStorage";
	_isStash = _cursorTarget isKindOf "StashSmall";
	_isMediumStash = _cursorTarget isKindOf "StashMedium";
	_isHarvested = _cursorTarget getVariable["meatHarvested",false];
	_ownerID = _cursorTarget getVariable ["characterID","0"];
	_isVehicletype = typeOf _cursorTarget in ["ATV_US_EP1","ATV_CZ_EP1"];
	_isFuel = false;
	_hasFuel80 = "ItemFuelbarrel" in magazines player;
	_hasFuel20 = "ItemJerrycan" in magazines player;
	_hasFuel5 = "ItemFuelcan" in magazines player;
	_hasFuelE80 = "ItemFuelbarrelEmpty" in magazines player;
	_hasFuelE20 = "ItemJerrycanEmpty" in magazines player;
	_hasFuelE5 = "ItemFuelcanEmpty" in magazines player;
	_hasKnife = "ItemKnife" in items player;
	_hasToolbox = "ItemToolbox" in items player;
	_hasbottleitem = "ItemWaterbottle" in magazines player;
	_isAlive = alive _cursorTarget;
	_canmove = canmove _cursorTarget;
	_text = getText (configFile >> "CfgVehicles" >> typeOf _cursorTarget >> "displayName");
	_isPlant = typeOf _cursorTarget in Dayz_plants;
	_isTagbar = ((isPlayer cursorTarget) && !((getPlayerUID cursorTarget) in tag_friendlies) && !((getPlayerUID cursorTarget) in tag_req) && (alive cursorTarget) && (side cursorTarget == side player));
	if (_hasFuelE20 or _hasFuelE5) then {
		_isFuel = typeOf _cursorTarget in ["Land_Ind_TankSmall","Land_fuel_tank_big","Land_fuel_tank_stairs","Land_wagon_tanker","Land_fuelstation","Land_fuelstation_army"];
	};

	//gather
	if(_isPlant and _canDo) then {
		if (s_player_gather < 0) then {
			_text = getText (configFile >> "CfgVehicles" >> typeOf _cursorTarget >> "displayName");
			s_player_gather = player addAction [format[localize "str_actions_gather",_text], "\z\addons\dayz_code\actions\player_gather.sqf",_cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_gather;
		s_player_gather = -1;
	};

	//Allow player to delete objects
	if(_isDestructable and _hasToolbox and _canDo) then {
		if (s_player_deleteBuild < 0) then {
			s_player_deleteBuild = player addAction [format[localize "str_actions_delete",_text], "\z\addons\dayz_code\actions\remove.sqf",_cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_deleteBuild;
		s_player_deleteBuild = -1;
	};

	//Allow player to force save
	if((_isVehicle or _isTent or _isStash or _isMediumStash) and _canDo and !_isMan and (damage _cursorTarget < 1)) then {
		if (s_player_forceSave < 0) then {
			s_player_forceSave = player addAction [format[localize "str_actions_save",_text], "\z\addons\dayz_code\actions\forcesave.sqf",_cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_forceSave;
		s_player_forceSave = -1;
	};

	//flip vehicle
	if ((_isVehicletype) and !_canmove and _isAlive and (player distance _cursorTarget >= 2) and (count (crew _cursorTarget))== 0 and ((vectorUp _cursorTarget) select 2) < 0.5) then {
		if (s_player_flipveh < 0) then {
			s_player_flipveh = player addAction [format[localize "str_actions_flipveh",_text], "\z\addons\dayz_code\actions\player_flipvehicle.sqf",_cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_flipveh;
		s_player_flipveh = -1;
	};

	//Allow player to fill Fuel can
	if((_hasFuelE80 or _hasFuelE20 or _hasFuelE5) and _isFuel and !_isZombie and !_isAnimal and !_isMan and _canDo and !a_player_jerryfilling) then {
		if (s_player_fillfuel < 0) then {
			s_player_fillfuel = player addAction [localize "str_actions_self_10", "\z\addons\dayz_code\actions\jerry_fill.sqf",[], 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_fillfuel;
		s_player_fillfuel = -1;
	};

	//Allow player to fill vehicle 80L
	if(_hasFuel80 and _canDo and !_isZombie and !_isAnimal and !_isMan and _isVehicle and (fuel _cursorTarget < 1) and (damage _cursorTarget < 1)) then {
		if (s_player_fillfuel80 < 0) then {
			s_player_fillfuel80 = player addAction [format[localize "str_actions_medical_10",_text,"80"], "\z\addons\dayz_code\actions\refuel.sqf",["ItemFuelbarrel"], 0, true, true, "", "'ItemFuelbarrel' in magazines player"];
		};
	} else {
		player removeAction s_player_fillfuel80;
		s_player_fillfuel80 = -1;
	};

	//Allow player to fill vehicle 20L
	if(_hasFuel20 and _canDo and !_isZombie and !_isAnimal and !_isMan and _isVehicle and (fuel _cursorTarget < 1) and (damage _cursorTarget < 1)) then {
		if (s_player_fillfuel20 < 0) then {
			s_player_fillfuel20 = player addAction [format[localize "str_actions_medical_10",_text,"20"], "\z\addons\dayz_code\actions\refuel.sqf",["ItemJerrycan"], 0, true, true, "", "'ItemJerrycan' in magazines player"];
		};
	} else {
		player removeAction s_player_fillfuel20;
		s_player_fillfuel20 = -1;
	};

	//Allow player to fill vehicle 5L
	if(_hasFuel5 and _canDo and !_isZombie and !_isAnimal and !_isMan and _isVehicle and (fuel _cursorTarget < 1)) then {
		if (s_player_fillfuel5 < 0) then {
			s_player_fillfuel5 = player addAction [format[localize "str_actions_medical_10",_text,"5"], "\z\addons\dayz_code\actions\refuel.sqf",["ItemFuelcan"], 0, true, true, "", "'ItemFuelcan' in magazines player"];
		};
	} else {
		player removeAction s_player_fillfuel5;
		s_player_fillfuel5 = -1;
	};

	//Allow player to spihon vehicles
	if ((_hasFuelE80 or _hasFuelE20 or _hasFuelE5) and !_isZombie and !_isAnimal and !_isMan and _isVehicle and _canDo and !a_player_jerryfilling and (fuel _cursorTarget > 0) and (damage _cursorTarget < 1)) then {
		if (s_player_siphonfuel < 0) then {
			s_player_siphonfuel = player addAction [format[localize "str_siphon_start"], "\z\addons\dayz_code\actions\siphonFuel.sqf",_cursorTarget, 0, true, true, "", ""];
		};
	} else {
		player removeAction s_player_siphonfuel;
		s_player_siphonfuel = -1;
	};

	//Harvested
	if (!alive _cursorTarget and _isAnimal and _hasKnife and !_isHarvested and _canDo) then {
		if (s_player_butcher < 0) then {
			s_player_butcher = player addAction [localize "str_actions_self_04", "\z\addons\dayz_code\actions\gather_meat.sqf",_cursorTarget, 3, true, true, "", ""];
		};
	} else {
		player removeAction s_player_butcher;
		s_player_butcher = -1;
	};
//Fireplace Actions check
	if (inflamed _cursorTarget and _canDo) then {
	/*
		{
			if (_x in magazines player) then {
				_hastinitem = true;
			};
		} forEach boil_tin_cans;
		
		_rawmeat = meatraw;
		_hasRawMeat = false;
		{
			if (_x in magazines player) then {
				_hasRawMeat = true;
			};
		} forEach _rawmeat;
	*/
		_hasRawMeat = {_x in meatraw} count magazines player > 0;
		_hastinitem = {_x in boil_tin_cans} count magazines player > 0;
		
	//Cook Meat	
		if (_hasRawMeat and !a_player_cooking) then {
			if (s_player_cook < 0) then {
				s_player_cook = player addAction [localize "str_actions_self_05", "\z\addons\dayz_code\actions\cook.sqf",_cursorTarget, 3, true, true, "", ""];
			};
		}; 
	//Boil Water
		if (_hastinitem and _hasbottleitem and !a_player_boil) then {
			if (s_player_boil < 0) then {
				s_player_boil = player addAction [localize "str_actions_boilwater", "\z\addons\dayz_code\actions\boil.sqf",_cursorTarget, 3, true, true, "", ""];
			};
		};
	} else {
		if (a_player_cooking) then {
			player removeAction s_player_cook;
			s_player_cook = -1;
		};
		if (a_player_boil) then {
			player removeAction s_player_boil;
			s_player_boil = -1;
		};
	};

	if(_cursorTarget == dayz_hasFire and _canDo) then {
		if ((s_player_fireout < 0) and !(inflamed _cursorTarget) and (player distance _cursorTarget < 3)) then {
			s_player_fireout = player addAction [localize "str_actions_self_06", "\z\addons\dayz_code\actions\fire_pack.sqf",_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_fireout;
		s_player_fireout = -1;
	};

	//Packing my tent
	if(_cursorTarget isKindOf "TentStorage" and _canDo and _ownerID == dayz_characterID) then {
		if ((s_player_packtent < 0) and (player distance _cursorTarget < 3)) then {
			s_player_packtent = player addAction [localize "str_actions_self_07", "\z\addons\dayz_code\actions\tent_pack.sqf",_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_packtent;
		s_player_packtent = -1;
		};

	//Sleep
	if(_cursorTarget isKindOf "TentStorage" and _canDo and _ownerID == dayz_characterID) then {
		if ((s_player_sleep < 0) and (player distance _cursorTarget < 3)) then {
			s_player_sleep = player addAction [localize "str_actions_self_sleep", "\z\addons\dayz_code\actions\player_sleep.sqf",_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_sleep;
		s_player_sleep = -1;
	};

	//Repairing Vehicles
	if ((dayz_myCursorTarget != _cursorTarget) and _isVehicle and !_isMan and _hasToolbox and (damage _cursorTarget < 1)) then {
		if (s_player_repair_crtl < 0) then {
			dayz_myCursorTarget = _cursorTarget;
			_menu = dayz_myCursorTarget addAction [localize "str_actions_rapairveh", "\z\addons\dayz_code\actions\repair_vehicle.sqf",_cursorTarget, 0, true, false, "",""];
			s_player_repairActions set [count s_player_repairActions,_menu];
			if(!(_cursorTarget isKindOf "Motorcycle") and !(_cursorTarget isKindOf "Tractor")) then {
				_menu1 = dayz_myCursorTarget addAction [localize "str_actions_salvageveh", "\z\addons\dayz_code\actions\salvage_vehicle.sqf",_cursorTarget, 0, true, false, "",""];
				s_player_repairActions set [count s_player_repairActions,_menu1];
			};
			s_player_repair_crtl = 1;
		} else {
			{dayz_myCursorTarget removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
			s_player_repair_crtl = -1;
		};
	};

	if (_isMan and !_isAlive and !_isZombie and !_isAnimal) then {
		if (s_player_studybody < 0) then {
			s_player_studybody = player addAction [localize "str_action_studybody", "\z\addons\dayz_code\actions\study_body.sqf",_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_studybody;
		s_player_studybody = -1;
	};

	//Pack Bike
	if(_cursorTarget isKindOf "MMT_Civ" and _canDo  and (damage _cursorTarget < 1)) then {
		if ((s_player_bikepack < 0) and (player distance _cursorTarget < 3)) then {
			s_player_bikepack = player addAction ["Pack Bike", "\z\addons\dayz_code\actions\player_packBike.sqf",_cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_bikepack;
		s_player_bikepack = -1;
	};

	//Ignite all Storage-Containers
	_hasMatches = "ItemMatchbox" in items player;
	_hasFlares = "HandRoadFlare" in magazines player;
	if ( ((cursorTarget isKindOf "TentStorage") || (cursorTarget isKindOf "DomeTentStorage") || (cursorTarget isKindOf "StashMedium") || (cursorTarget isKindOf "StashSmall") || (cursorTarget isKindOf "GeoCache_DZ")) and (_hasMatches or _hasFlares) and _canDo and !(inflamed cursorTarget)) then {
		if (s_player_ignite_storage < 0) then {
			_burnTarget = "Storage";
			s_player_ignite_storage = player addAction ["Ignite " + _burnTarget, "\z\addons\dayz_code\actions\player_igniteStorage.sqf",cursorTarget, 3, false, true, "", ""];
		};
	} else {
		player removeAction s_player_ignite_storage;
		s_player_ignite_storage = -1;
	};

	if (_isTagbar) then {
		if (s_tagfriendly < 0) then {
			s_tagfriendly = player addAction [("<t color=""#FF00FF"">" + ("Tag as Friend") + "</t>"), "actions\player_tagFriendly.sqf",cursorTarget, 1, false, true, "",""];
		};
	} else {
		player removeAction s_tagfriendly;
		s_tagfriendly = -1;
	};
} else {
	player removeAction s_player_bikepack;
	s_player_bikepack = -1;
	player removeAction s_player_ignite_storage;
	s_player_ignite_storage = -1;
	//Engineering
	{dayz_myCursorTarget removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
	player removeAction s_player_repair_crtl;
	s_player_repair_crtl = -1;
	dayz_myCursorTarget = objNull;
	//Others
	player removeAction s_player_forceSave;
	s_player_forceSave = -1;
	player removeAction s_player_flipveh;
	s_player_flipveh = -1;
	player removeAction s_player_sleep;
	s_player_sleep = -1;
	player removeAction s_player_deleteBuild;
	s_player_deleteBuild = -1;
	player removeAction s_player_butcher;
	s_player_butcher = -1;
	player removeAction s_player_cook;
	s_player_cook = -1;
	player removeAction s_player_boil;
	s_player_boil = -1;
	player removeAction s_player_fireout;
	s_player_fireout = -1;
	player removeAction s_player_packtent;
	s_player_packtent = -1;
	player removeAction s_player_fillfuel;
	s_player_fillfuel = -1;
	player removeAction s_player_studybody;
	s_player_studybody = -1;
	//fuel
	player removeAction s_player_fillfuel80;
	s_player_fillfuel80 = -1;
	player removeAction s_player_fillfuel20;
	s_player_fillfuel20 = -1;
	player removeAction s_player_fillfuel5;
	s_player_fillfuel5 = -1;
	//Allow player to siphon vehicle fuel
	player removeAction s_player_siphonfuel;
	s_player_siphonfuel = -1;
	//Allow player to gather
	player removeAction s_player_gather;
	s_player_gather = -1;
	player removeAction s_tagfriendly;
	s_tagfriendly = -1;
};