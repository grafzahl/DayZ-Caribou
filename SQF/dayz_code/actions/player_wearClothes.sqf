/*
_item call player_wearClothes;
TODO: female
*/
private["_hasHelmet","_hasLowBody","_hasHighBody","_bodyProtection","_headrotection","_item","_onLadder","_hasclothesitem","_config","_text","_isFemale","_myModel","_humanity","_isBandit","_isHero","_itemNew","_model"];

_item = _this;
call gear_ui_init;
r_action_count = 0; //reset for strange glitch
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

_hasclothesitem = _this in magazines player;
_config = configFile >> "CfgMagazines";
_text = getText (_config >> _item >> "displayName");

if (!_hasclothesitem) exitWith {cutText [format[(localize "str_player_31"),_text,(localize "str_player_31_wear")] , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText [localize "str_player_fail_wear1", "PLAIN DOWN"]};

_isFemale = ((typeOf player == "SurvivorW2_DZ")||(typeOf player == "BanditW1_DZ"));
if (_isFemale) exitWith {cutText [localize "str_player_fail_wear2", "PLAIN DOWN"]};

_myModel = (typeOf player);
_humanity = player getVariable ["humanity",0];
_isBandit = _humanity <= 0;
_isHero = _humanity > 5000;
_itemNew = "Skin_" + _myModel;

if ( !(isClass(_config >> _itemNew)) ) then {
	_itemNew = if (!_isFemale) then {"Skin_Survivor2_DZ"} else {"Skin_SurvivorW2_DZ"};
};
_model = "Survivor2_DZ";
switch (_item) do {
	case "Skin_Camo2_DZ": {
		_model = "Camo2_DZ";
	};
	case "Skin_Sniper1_DZ": {
		_model = "Sniper1_DZ";
	};
	case "Skin_Camo1_DZ": {
		_model = "Camo1_DZ";
	};
	case "Skin_Soldier1_DZ": {
		_model = "Soldier1_DZ";
	};
	case "Skin_Survivor2_DZ": {
		_model = "Survivor2_DZ";
		if (_isBandit) then {
			_model = "Bandit1_DZ";
		};
		if (_isHero) then {
			_model = "Survivor3_DZ";
		};
	};
	default {
		_config = configFile >> "CfgMagazines" >> _item;
		_model = getText (_config >> "usemodel");
	};
};

if (_model != _myModel) then {
	player removeMagazine _item;
	player addMagazine _itemNew;
	[dayz_playerUID, dayz_characterID, _model] spawn player_humanityMorph;

	//All Models with visual Helmet, Body Armor & Co
	_hasHelmet = _model in CB_Helmet;
	_hasLowBody = _model in CB_lowBody;
	_hasHighBody = _model in CB_highBody;
	_bodyProtection = 0;
	_headProtection = 0;
	if(_hasLowBody) then { _bodyProtection = 15} 	else {
		if(_hasHighBody) then { _bodyProtection = 25};
	};
	if(_hasHelmet) then {
		_headProtection = 30;
	};
	if(_hasHelmet || _hasLowBody || _hasHighBody) then {
		cutText [format["\n\nYour new Clothes offer Damage-Protection || Body: %1%3 / Head: %2%3",_bodyProtection,_headProtection,"%"], "PLAIN DOWN"];
	};
} else {
	cutText ["\n\nYou are already wearing these Clothes!", "PLAIN DOWN"]
};