private ["_maxRange","_humanitycheck","_humanity","_skaroTag","_cursorTarget","_bandit","_hero","_color","_string","_targetControl"];
//Created by Skaronator - http://www.skaronator.com - Version 1.3
Waituntil{!isNull player};

_maxRange = 5; // Max. Range from the Target // Default: 5 meter
_humanitycheck = true; //true = Bandit: Red / Hero: Blue / Survivor: White <<<>>> false = always white (POSSIBLE VALUES: true // false)
_bandit = 0; //Player Humanity for a Bandit
_hero = 5000; //Player Humanity for a Hero


//Other Stuff do not change!
_humanity = 2500; //Don't change this! It's only a failsave if getVariable failed
_blood = 12000;
_targetControl = _display displayCtrl 1199;
_string = "";
dayz_humanitytarget = "";

while {true} do {
	_humanityTarget = cursorTarget;
	if (!isNull _humanityTarget and isPlayer _humanityTarget and alive _humanityTarget) then {
			_distance = (player distance _humanityTarget);
		if (_distance < _maxRange) then {
			_size = (1-(floor(_distance/5)*0.1)) max 0.1;
			_humanity = _humanityTarget getVariable ["humanity",2500];
			_blood = _humanityTarget getVariable ["USEC_BloodQty",12000];
			_blood = (round(_blood / 120)) max 1;
			if (_humanitycheck) then {
				_color = "color='#ffffff'";
				if(_humanity <= _bandit) then {
					_color = "color='#ff0000'";
				} else {
					if(_humanity => _hero) then {
						_color = "color='#3333ff'";
					};
				};
			} else {
			_color = "color='#ffffff'";
			};
			_string = format["<t %2 align='center' size='%3'>%1 (%4%5)</t>",(name _humanityTarget),_color,_size,_blood,"%"];
		};
	};

	// update gui if changed
	if (dayz_humanitytarget != _string) then {
			_targetControl ctrlSetStructuredText (parseText _string);
			dayz_humanitytarget = _string;
	};

sleep 0.5;
};


