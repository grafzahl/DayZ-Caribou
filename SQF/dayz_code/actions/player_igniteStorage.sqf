private["_objectID","_objectUID","_obj","_id"];
_obj = _this select 3;
_objectID 	= _obj getVariable["ObjectID","0"];
_objectUID	= _obj getVariable["ObjectUID","0"];
canAbort = false;

	player removeAction s_player_ignite_storage;
	s_player_ignite_storage = -1;

	player playActionNow "Medic";
	sleep 7;

	[player,"tentpack",0,false] call dayz_zombieSpeak;

	PVDZ_obj_Fire = [_obj,3,time,false,true];
	publicVariable "PVDZ_obj_Fire";
	_obj setvariable ["fadeFire",true,true];
	_id = PVDZ_obj_Fire spawn BIS_Effects_Burn;

//	dayzFire = [_obj,3,time,false,true];
//	publicVariable "dayzFire";
//	_id = dayzFire spawn BIS_Effects_Burn;
 
	_obj setDamage 2;

	//["PVDZ_obj_Delete",[_objectID,_objectUID]] call callRpcProcedure;
	PVDZ_obj_Delete = [_objectID,_objectUID];
	publicVariableServer "PVDZ_obj_Delete";
	if (isServer) then {
		PVDZ_obj_Delete call server_deleteObj;
	};
	//deleteVehicle _obj;

canAbort = false;