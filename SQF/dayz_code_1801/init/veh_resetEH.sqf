/***********************************************************
ASSIGN DAMAGE HANDLER TO A UNIT
- Function fnc_veh_ResetEH
- unit call fnc_veh_ResetEH
************************************************************/

_this removeAllEventHandlers "HandleDamage";
_this removeAllEventHandlers "Killed";
_this addeventhandler ["HandleDamage",{ _this call fnc_veh_handleDam } ];
_this addeventhandler ["Killed",{ _this call fnc_veh_handleKilled } ];

if (isServer) then {
	_this removeAllEventHandlers "GetOut";
	_this removeAllEventHandlers "GetIn";
	_this addEventHandler ["GetOut", {[(_this select 0),"all",true] call server_updateObject;}];
	_this addEventHandler ["GetIn", {[(_this select 0),"all",true] call server_updateObject;}];
};

//diag_log(format["%1: all EH reset for %2", __FILE__, _this]);