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

if (isServer) then {
	"PVDZ_plr_Death"		addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerDied};
	"PVDZ_plr_Save"			addPublicVariableEventHandler {_id = (_this select 1) call server_playerSync;};
	"PVDZ_obj_Publish"		addPublicVariableEventHandler {(_this select 1) call server_publishObj};
	"PVDZ_veh_Save" 		addPublicVariableEventHandler {(_this select 1) call server_updateObject};
	"PVDZ_plr_Login1"		addPublicVariableEventHandler {_id = (_this select 1) call server_playerLogin};
	"PVDZ_plr_Login2"		addPublicVariableEventHandler {(_this select 1) call server_playerSetup};
	"PVDZ_plr_LoginRecord"	addPublicVariableEventHandler {_id = (_this select 1) spawn dayz_recordLogin};
	"PVDZ_obj_Delete"		addPublicVariableEventHandler {(_this select 1) spawn server_deleteObj};
	"PVDZ_send" addPublicVariableEventHandler {(_this select 1) call server_sendToClient};

	"PVDZ_objgather_Delete" addPublicVariableEventHandler {
		_obj = ((_this select 1) select 0);
		_player = ((_this select 1) select 1);
		_type = typeOf _obj;
		_dis = _player distance _obj;

		if (_dis < 3) then {
			if (_type in Dayz_plants) then {
				deleteVehicle _obj;
			};
		};	
	};

	"PVDZ_serverStoreVar" addPublicVariableEventHandler {
		_obj = ((_this select 1) select 0);
		_name = ((_this select 1) select 1);
		_value = 0;

		switch (_name) do {
			case "looted": {
				_obj =  ((_this select 1) select 0);
				_name = "looted";
				_value = ((_this select 1) select 2);
				
				_obj setVariable [_name, _value];
			};
			case "zombieSpawn": {
				_obj = ((_this select 1) select 0);
				_name = "zombieSpawn";
				_value = ((_this select 1) select 2);
				
				_obj setVariable [_name, _value];
			};
			case "USEC_BloodQty": {
				_obj = ((_this select 1) select 0);
				_name = ((_this select 1) select 1);
				_value = ((_this select 1) select 2);
				//diag_log format ["%1, %2, %3", _obj, _name, _value]; 
				if (isPlayer _obj) then {
					_obj setVariable [_name, _value];
				};
			};
		};
	};

	"PVDZ_receiveVar" addPublicVariableEventHandler {
		_owner = ((_this select 1) select 0);
		_object = ((_this select 1) select 1);
		_name = ((_this select 1) select 2);
		_value = ((_this select 1) select 3);

		switch (_name) do {
			case "looted": {
				diag_log format ["%4 - %1, %2, %3", _object, _name, _value, "receive looted"]; 
			};
			case "zombieSpawn": {
				//diag_log format ["%4 - %1, %2, %3", _object, _name, _value, "receive zombieSpawn"]; 
			};
		};

		_ownerID = owner _owner;
		_return = _object getVariable [_name,_value];
		a=0;
		b=5;
		while {a<b} do {a=a+1};

		diag_log format ["%1", _return];	

		PVCDZ_SetVar = [_object,_name,_return];
		_ownerID publicVariableClient "PVCDZ_SetVar";
	};
};

//Client only
if (!isDedicated) then {
	"dayzSetDate"				addPublicVariableEventHandler {setDate (_this select 1)};
	"PVDZ_obj_RoadFlare"		addPublicVariableEventHandler {(_this select 1) spawn object_roadFlare};
	"PVDZ_drg_RaDrag"   		addPublicVariableEventHandler {(_this select 1) execVM "\z\addons\dayz_code\medical\publicEH\animDrag.sqf"};
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
};
