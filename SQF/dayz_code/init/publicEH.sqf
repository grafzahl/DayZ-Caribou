"PVDZ_drg_RaLW"   		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\dayz_code\medical\publicEH\load_wounded.sqf"};
"PVDZ_drg_RLact"		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\dayz_code\medical\load\load_wounded.sqf"};
"PVDZ_hlt_Bleed"		addPublicVariableEventHandler {_id = (_this select 1) spawn fnc_usec_damageBleed};
"PVCDZ_veh_SH" 			addPublicVariableEventHandler {(_this select 1) call fnc_veh_handleDam}; // set damage to vehicle part
"PVDZ_veh_SF"			addPublicVariableEventHandler {(_this select 1) call fnc_veh_handleRepair}; // repair a part from a vehicle
"PVCDZ_obj_HideBody"	addPublicVariableEventHandler {hideBody (_this select 1)};
"PVCDZ_obj_GutBody"		addPublicVariableEventHandler {(_this select 1) spawn local_gutObject};
"PVCDZ_veh_SetFuel"		addPublicVariableEventHandler {(_this select 1) spawn local_setFuel};
"dayzInfectedCamps"		addPublicVariableEventHandler {(_this select 1) call infectedcamps};

	"PVDZ_Server_changeOwner" addPublicVariableEventHandler {		
		_agent = ((_this select 1) select 0);
		_reciever = ((_this select 1) select 1);
		_ownerID = owner _agent;
		_newownerID = 1; //1 = server

		if (typeName _reciever == "OBJECT") then {
			_newownerID = owner _reciever;
		};
		if (isnil ("Owner")) then {
			_agent setVariable ["Owner",_ownerID];
		};

		_agent setOwner _newownerID;
		diag_log ("TRANSFER OWNERSHIP: " + (typeOf _agent) + " OF _unit: " + str(_agent) + " TO _client: " + str(_reciever) );
	};

	"PVDZ_Server_Simulation" addPublicVariableEventHandler {
		_agent = ((_this select 1) select 0);
		_control = ((_this select 1) select 1);
		
		_agent enableSimulation _control;
	};

//Client only
if (!isDedicated) then {
	"dayzAnimCrash"			addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\dayz_code\caribou\fn_crashMonitor.sqf";};
	"dayzSetDate"				addPublicVariableEventHandler {setDate (_this select 1)};
	"PVDZ_obj_RoadFlare"		addPublicVariableEventHandler {(_this select 1) spawn object_roadFlare};
	"PVDZ_drg_RaDrag" 		addPublicVariableEventHandler {(_this select 1) execVM "\z\addons\dayz_code\medical\publicEH\animDrag.sqf"};
	"PVDZ_obj_Fire"				addPublicVariableEventHandler {nul=(_this select 1) spawn BIS_Effects_Burn};
	
			//Medical
	"PVCDZ_hlt_Morphine"		addPublicVariableEventHandler {(_this select 1) call player_medMorphine};
	"PVCDZ_hlt_Bandage"			addPublicVariableEventHandler {(_this select 1) call player_medBandage};
	"PVCDZ_hlt_Epi"				addPublicVariableEventHandler {(_this select 1) call player_medEpi};
	"PVCDZ_hlt_Transfuse"		addPublicVariableEventHandler {(_this select 1) call player_medTransfuse; PVCDZ_hlt_Transfuse = nil};
	"PVCDZ_hlt_PainK"			addPublicVariableEventHandler {(_this select 1) call player_medPainkiller};
	"PVCDZ_hlt_AntiB"			addPublicVariableEventHandler {(_this select 1) call player_medAntiBiotics};

	"PVCDZ_plr_Humanity"		addPublicVariableEventHandler {(_this select 1) spawn player_humanityChange};
	"PVCDZ_plr_Legs"			addPublicVariableEventHandler {
		_entity = (_this select 1) select 0;
		_entity setHit ["legs", 1];

		if (isPlayer _entity) then {
			_entity setVariable ["hit_legs", 2, true];
		};
	};
	
	"PVCDZ_SetVar" addPublicVariableEventHandler {
		_object = ((_this select 1) select 0);
		_name = ((_this select 1) select 1);
		_value = ((_this select 1) select 2);
		_object setVariable [_name,_value];
	};
	"PVCDZ_setServerTickTimeOffset"  addPublicVariableEventHandler {
		_serverTickTime = _this select 1;
		_offset = _serverTickTime - diag_tickTime;
		dayz_tickTimeOffset = _offset;
		//diag_log format["SERVER TIME: %1    OFFSET: %2    PLAYER TIME: %3    COMPUTED TIME: %4", _serverTickTime, _offset, diag_tickTime, (diag_tickTime + _offset)];
	};

	tag_req = [];
	tag_rec = [];
	tag_friendlies = [];
	"PVCDZ_tagFriend" addPublicVariableEventHandler {
		_uid = ((_this select 1) select 0);
		_name = ((_this select 1) select 1);
		_oid = ((_this select 1) select 2);
		if (_uid in tag_friendlies) then {
			titleText [format["%1 has tagged you again",_name], "PLAIN DOWN", 3];
			_myoid = ((_this select 1) select 3);
			PVCDZ_tagFriend = [(getPlayerUID player), (name player), _myoid];
			_oid publicVariableClient "PVCDZ_tagFriend";
		}
		else {
			if (_uid in tag_req) then {
				titleText [format["%1 is now tagged as friend",_name], "PLAIN DOWN", 3];
				tag_friendlies = tag_friendlies + [_uid];
			} else {
				titleText [format["%1 wants to tag you as friend",_name], "PLAIN DOWN", 3];
				tag_rec = tag_rec + [_uid];
			};
		};
	};

	[] spawn {
		setGroupIconsVisible [true, true];
		while{true} do {
			{
				clearGroupIcons group _x;
				if (((getPlayerUID _x) in tag_friendlies)) then {
					group _x addGroupIcon ["x_art"];
					group _x setGroupIconParams [[1, 0, 1 , 1], format ["%1", name _x], 0.7, true];
				};
			} forEach entities "AllVehicles";
			sleep 1;
		};
	};
};
