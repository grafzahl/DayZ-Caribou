private ["_timer","_timer1","_timer2"];
_timer = diag_tickTime;
_timer1 = diag_tickTime;
_spawnCheck = diag_tickTime;
_timer2 = diag_Ticktime;
_NewDay  = diag_tickTime;

while {true} do {
	//add player actions
	if ((diag_tickTime - _timer2) > 0.5) then {
		[] call fnc_usec_damageActions;
		[] call fnc_usec_selfActions;
		_timer2 = diag_Ticktime;
	};

	if ((diag_tickTime - _timer) > 300) then {
	//Other Counters
		dayz_currentGlobalAnimals = count entities "CAAnimalBase";
		dayz_currentGlobalZombies = count entities "zZombie_Base";
		
	//Animals
		[] spawn player_animalCheck;
		
		_timer = diag_tickTime;
	};
	
	if ((diag_tickTime - _timer1) > 60) then {
		_position = getPosATL player;
		//Current amounts
		dayz_spawnZombies = {alive _x AND local _x} count (_position nearEntities ["zZombie_Base",200]);
		dayz_CurrentNearByZombies = {alive _x} count (_position nearEntities ["zZombie_Base",200]);
		dayz_currentWeaponHolders = count (_position nearObjects ["ReammoBox",100]);
		
		_timer1 = diag_tickTime;
	};
	
	//spawning system
	if ((diag_tickTime - _spawnCheck) > 14) then {
		["both"] spawn player_spawnCheck;

		_spawnCheck  = diag_tickTime;
	};

	//Check if new day
	if ((diag_tickTime - _NewDay) > 5) then {
		private "_day";
		_day = round(360 * (dateToNumber date));
		if(dayz_currentDay != _day) then {
			dayz_sunRise = call world_sunRise;
			dayz_currentDay = _day;
		};
		
		_NewDay  = diag_tickTime;
	};
		
	//wait
	//sleep 5;
};