class WeaponHolder_ItemBikeBox : WeaponHolderBase {
	scope = public;
	displayName = "Folding-Bike Kit";
	model = "\z\addons\dayz_communityassets\models\crate.p3d";
	class eventHandlers {
		init = "[(_this select 0),'cfgMagazines','ItemBikeBox'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
	};
};

class WeaponHolder_ItemGeocache : WeaponHolderBase {
	scope = public;
	displayName = "Geocache Kit";
	model = "\rhnet\caribou_models\mdl\misc\rhnet_geoc";
	class eventHandlers {
		init = "[(_this select 0),'cfgMagazines','ItemGeocache'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
	};
};

class WeaponHolder_ItemFuelbarrel : WeaponHolderBase {
	scope = public;
	displayName = "Fuel Barrel";
	model = "\ca\misc\Barel5.p3d";
	class eventHandlers {
		init = "[(_this select 0),'cfgMagazines','ItemFuelbarrel'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
	};
};

class Land_Fire_barrel_burning;
class Barrel_burning_CBDZ : Land_Fire_barrel_burning {
	displayname = "Deployed Barrel (Burning)";
}

/*
class WeaponHolder_ItemDomeTent : WeaponHolderBase {
	scope = public;
	displayName = $STR_ITEM_NAME_CAMONET;
	model = "\dayz_equip\proxy\tentbag.p3d";
	class eventHandlers {
		init = "[(_this select 0),'cfgMagazines','ItemDomeTent'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
	};
};
*/
class GeoCache_DZ : StashSmall {
	displayname = "Geocache (Storage)";
	animated = 0;
	nameSound = "";
	model = "\rhnet\caribou_models\mdl\misc\rhnet_geoc";
	armor = 1800;
	cost = 0;
	transportMaxMagazines = 30;
	transportMaxWeapons = 5;
	transportMaxBackpacks = 1;
};

class SUV_WOODLAND_CBDZ: SUV_DZ {
	displayname = "SUV (Woodland)";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\dzcb_data\textures\suv\smd_veh_suv_army01.paa"};
};
class SUV_STONE_CBDZ: SUV_DZ {
	displayname = "SUV (BW)";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\dzcb_data\textures\suv\smd_veh_suv_stone01.paa"};
};
class CH_47F_BAF;
class CH_47F_DZ: CH_47F_BAF
{
	scope = 2;
	side = 2;
	crew = "";
	typicalCargo[] = {};
	hiddenSelections[] = {};
	radartype = 0;
	class TransportMagazines{};
	class TransportWeapons{};
	commanderCanSee = 2+16+32;
	gunnerCanSee = 2+16+32;
	driverCanSee = 2+16+32;
	transportMaxWeapons = 5;
	transportMaxMagazines = 65;
	transportmaxbackpacks = 4;
	enablemanualfire = 0;
};
class HMMWV_Armored;
class HMMWV_Armored_DZ: HMMWV_Armored
{
	displayname = "HMMWV (M240)";
	typicalCargo[] = {};
	hiddenselections[] = {};
	scope = 2;
	side = 2;
	crew = "";
	class TransportMagazines{};
	class TransportWeapons{};
	transportMaxWeapons = 10;
	transportMaxMagazines = 50;
	transportmaxbackpacks = 2;
};
class Plane;
class MV22_DZ: Plane {
	destrType = "DestructWreck";
	scope = 2;
	side = 1;
	faction = "USMC";
	displayName = "$STR_DN_MV22";
	vehicleClass = "Air";
	model = "\ca\air2\mv22\mv22.p3d";
	picture = "\ca\air2\data\UI\picture_MV22_CA.paa";
	icon = "\ca\air2\data\UI\icon_MV22_CA.paa";
	radartype = 0;
	mapSize = 28;
	crew = "USMC_Soldier_Pilot";
	accuracy = 0.5;
	soundGetIn[] = {"ca\sounds\Air\MV22\close",0.31622776,1};
	soundGetOut[] = {"ca\sounds\Air\MV22\open",0.31622776,1,40};
	soundDammage[] = {"ca\sounds\Air\MV22\int-alarm_loop",0.56234133,1};
	soundEngineOnInt[] = {"ca\sounds\Air\MV22\int_start",0.56234133,1.0};
	soundEngineOnExt[] = {"ca\sounds\Air\MV22\ext_start",0.56234133,1.0,800};
	soundEngineOffInt[] = {"ca\sounds\Air\MV22\int_stop",0.56234133,1.0};
	soundEngineOffExt[] = {"ca\sounds\Air\MV22\ext_stop",0.56234133,1.0,800};
	
	class Sounds {
	
		class EngineLowOut {
			sound[] = {"ca\sounds\Air\MV22\ext_engine_low",1.7782794,1,1000};
			frequency = "1.0 min (rpm + 0.5)";
			volume = "camPos*engineOn*(rpm factor[0.85, 0])";
		};
		class EngineHighOut {
			sound[] = {"ca\sounds\Air\MV22\ext_engine_hi",1.7782794,1,1200};
			frequency = "1";
			volume = "camPos*engineOn*(rpm factor[0.55, 1.0])";
		};
		class ForsageOut {
			sound[] = {"ca\sounds\Air\MV22\ext_forsage",1.7782794,1,1800};
			frequency = "1";
			volume = "camPos*engineOn*(thrust factor[0.5, 1.0])";
		};
		class WindNoiseOut
		{
			sound[] = {"ca\sounds\Air\MV22\int-wind1",0.017782794,0.6,100};
			frequency = "(0.1+(1.2*(speed factor[1, 100])))";
			volume = "camPos*(speed factor[1, 100])";
		};
		class EngineLowIn
		{
			sound[] = {"ca\sounds\Air\MV22\int_engine_low",1.0,1.0};
			frequency = "1.0 min (rpm + 0.5)";
			volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
		};
		class EngineHighIn
		{
			sound[] = {"ca\sounds\Air\MV22\int_engine_hi",1.0,1.0};
			frequency = "1";
			volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
		};
		class ForsageIn
		{
			sound[] = {"ca\sounds\Air\MV22\int_forsage",1.4125376,1.1};
			frequency = "1";
			volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
		};
		class WindNoiseIn
		{
			sound[] = {"ca\sounds\Air\MV22\int-wind1",0.0017782794,0.6};
			frequency = "(0.1+(1.2*(speed factor[1, 100])))";
			volume = "(1-camPos)*(speed factor[1, 100])";
		};
	};
	
	ejectSpeed[] = {0,-2,0};
	cabinOpening = 0;
	gearRetracting = 1;
	driverAction = "MV22_Pilot";
	cargoIsCoDriver[] = {1,0};
	cargoAction[] = {"MV22_Cargo","Mi17_Cargo02"};
	driverCompartments = "Compartment1";
	cargoCompartments[] = {"Compartment2"};
	maxSpeed = 556;
	transportSoldier = 24;
	vtol = 3;
	supplyRadius = 8;
	armor = 25;
	damageResistance = 0.00172;
	weapons[] = {};
	magazines[] = {};
	selectionRotorStill = "engine_static";
	selectionRotorMove = "engine_blur";
	
	class Damage
	{
		tex[] = {};
		mat[] = {"ca\air2\mv22\data\mv22_sklo.rvmat","ca\air2\mv22\data\mv22_sklo_damage.rvmat","ca\air2\mv22\data\mv22_sklo_damage.rvmat","ca\air2\mv22\data\mv22_sklo_in.rvmat","ca\air2\mv22\data\mv22_sklo_in_damage.rvmat","ca\air2\mv22\data\mv22_sklo_in_damage.rvmat","ca\air2\mv22\data\mv22_01.rvmat","ca\air2\mv22\data\mv22_01_damage.rvmat","ca\air2\mv22\data\mv22_01_destruct.rvmat","ca\air2\mv22\data\mv22_02.rvmat","ca\air2\mv22\data\mv22_02_damage.rvmat","ca\air2\mv22\data\mv22_02_destruct.rvmat"};
	};
	dammageHalf[] = {};
	dammageFull[] = {};
	
	class AnimationSources
	{
		class Door_1_1
		{
			source = "user";
			animPeriod = 0;
		};
		class Ramp
		{
			source = "user";
			animPeriod = 0;
		};
		class pack_engine_1
		{
			source = "user";
			animPeriod = 0;
		};
		class engine_prop_1_1_turn: pack_engine_1{};
		class engine_prop_1_2_turn: pack_engine_1{};
		class engine_prop_1_3_turn: pack_engine_1{};
		class engine_prop_2_1_turn: pack_engine_1{};
		class engine_prop_2_2_turn: pack_engine_1{};
		class engine_prop_2_3_turn: pack_engine_1{};
		class engine_prop_1_1_close: pack_engine_1{};
		class engine_prop_1_3_close: pack_engine_1{};
		class engine_prop_2_1_close: pack_engine_1{};
		class engine_prop_2_2_close: pack_engine_1{};
		class pack_engine_2: pack_engine_1{};
		class turn_wing: pack_engine_1{};
	};
	
	class UserActions{};
	class Reflectors
	{
		class Left
		{
			color[] = {0.8,0.8,1.0,1.0};
			ambient[] = {0.07,0.07,0.07,1.0};
			position = "L svetlo";
			direction = "konec L svetla";
			hitpoint = "L svetlo";
			selection = "L svetlo";
			size = 1;
			brightness = 1.0;
		};
		class Right
		{
			color[] = {0.8,0.8,1.0,1.0};
			ambient[] = {0.07,0.07,0.07,1.0};
			position = "P svetlo";
			direction = "konec P svetla";
			hitpoint = "P svetlo";
			selection = "P svetlo";
			size = 1;
			brightness = 1.0;
		};
	};
	class Library
	{
		libTextDesc = "$STR_LIB_MV22";
	};
	class MFD
	{
		borderLeft = 0.09;
		borderRight = 0.02;
		borderTop = 0.02;
		borderBottom = 0.1;
		class MFD1
		{
			topLeft = "HUD LH1";
			topRight = "HUD PH1";
			bottomLeft = "HUD LD1";
			borderLeft = 0;
			borderRight = 0;
			borderTop = 0;
			borderBottom = 0;
			color[] = {0,1,0,0.1};
			class Pos10Vector
			{
				type = "vector";
				pos0[] = {0.5,0.27};
				pos10[] = {"0.5+0.9","0.27+0.7"};
			};
			class Bones{};
			class Draw
			{
				alpha = 0.9;
				color[] = {0,1,0};
				clipTL[] = {0.0,0.0};
				clipBR[] = {1.0,1.0};
				condition = "on";
				class Altitude
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "altitudeASL";
					sourceScale = 1;
					pos[] = {
						{ 0.28,0.042 },1};
					right[] = {
						{ 0.32,0.042 },1};
					down[] = {
						{ 0.28,0.082 },1};
				};
				class Altitude2
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "altitudeAGL";
					sourceScale = 1;
					pos[] = {
						{ 0.45,0.042 },1};
					right[] = {
						{ 0.49,0.042 },1};
					down[] = {
						{ 0.45,0.082 },1};
				};
				class RPM
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "rpm";
					sourceScale = 100;
					pos[] = {
						{ 0.63,0.18 },1};
					right[] = {
						{ 0.67,0.18 },1};
					down[] = {
						{ 0.63,0.22 },1};
				};
				class RPM2
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "rpm";
					sourceScale = 100;
					pos[] = {
						{ 0.802,0.18 },1};
					right[] = {
						{ 0.842,0.18 },1};
					down[] = {
						{ 0.802,0.22 },1};
				};
				class Fuel
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "fuel";
					sourceScale = 100;
					pos[] = {
						{ 0.63,0.425 },1};
					right[] = {
						{ 0.67,0.425 },1};
					down[] = {
						{ 0.63,0.465 },1};
				};
				class Fuel2
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "fuel";
					sourceScale = 100;
					pos[] = {
						{ 0.802,0.425 },1};
					right[] = {
						{ 0.842,0.425 },1};
					down[] = {
						{ 0.802,0.465 },1};
				};
				class Speed
				{
					type = "text";
					align = "left";
					scale = 1;
					source = "speed";
					sourceScale = 2.23694;
					pos[] = {
						{ 0.28,0.225 },1};
					right[] = {
						{ 0.32,0.225 },1};
					down[] = {
						{ 0.28,0.265 },1};
				};
			};
		};
	};
};

class MH60S_DZ: Helicopter
{
	scope = 2;
	displayName = "$STR_DN_MH60S";
	destrType = "DestructWreck";
	vehicleClass = "Air";
	model = "\ca\air\Mh_60mg";
	mapSize = 17;
	picture = "\ca\air\data\ico\MH_60mg_CA.paa";
	Icon = "\ca\air\data\map_ico\icomap_MH60mg_CA.paa";
	radartype = 0;
	side = 1;
	faction = "USMC";
	crew = "USMC_Soldier_Pilot";
	transportMaxBackpacks = 10;
	accuracy = 1.5;
	attendant = 1;
	maxSpeed = 270;
	armor = 35;
	damageResistance = 0.00242;
	cost = 10000000;
	mainRotorSpeed = -1;
	soundGetIn[] = {"\ca\Sounds\Air\Noises\heli_door_01",0.31622776,1};
	soundGetOut[] = {"\ca\Sounds\Air\Noises\heli_door_01",0.31622776,1,30};
	soundEnviron[] = {"",0.031622775,1.0};
	soundDammage[] = {"\ca\Air\Data\Sound\alarm_loop1",0.001,1};
	soundEngineOnInt[] = {"ca\sounds\Air\UH1Y\int\int-start-final",0.1,1.0};
	soundEngineOnExt[] = {"ca\sounds\Air\UH1Y\ext\ext-motor-start",1.0,1.0,800};
	soundEngineOffInt[] = {"ca\sounds\Air\UH1Y\int\int-stop-final",0.1,1.0};
	soundEngineOffExt[] = {"ca\sounds\Air\UH1Y\ext\ext-motor-stop",1.0,1.0,800};
	class Sounds
	{
	 class Engine
	 {
			sound[] = {"ca\sounds\air\uh1y\ext\ext-fly-mode2",2.5118864,1.0,900};
			frequency = "rotorSpeed";
			volume = "camPos*((rotorSpeed-0.72)*4)";
	 };
	 class RotorLowOut
	 {
			sound[] = {"ca\sounds\air\uh1y\int\int-rotor-single5b",2.5118864,1.0,1400};
			frequency = "rotorSpeed";
			volume = "camPos*(0 max (rotorSpeed-0.1))";
			cone[] = {1.6,3.14,2.0,0.5};
	 };
	 class RotorHighOut
	 {
			sound[] = {"ca\sounds\air\uh1y\int\int-rotor-single5a",2.5118864,1.0,1600};
			frequency = "rotorSpeed";
			volume = "camPos*10*(0 max (rotorThrust-0.9))";
			cone[] = {1.6,3.14,2.0,0.5};
	 };
	 class EngineIn
	 {
			sound[] = {"ca\sounds\air\uh1y\int\int-fly-mode7",3.1622777,1.0};
			frequency = "rotorSpeed";
			volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
	 };
	 class RotorLowIn
	 {
			sound[] = {"ca\sounds\air\uh1y\int\int-rotor-single5b",3.1622777,1.0};
			frequency = "rotorSpeed";
			volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
	 };
	 class RotorHighIn
	 {
			sound[] = {"ca\sounds\air\uh1y\int\int-rotor-single5a",3.1622777,1.0};
			frequency = "rotorSpeed";
			volume = "(1-camPos)*3*(rotorThrust-0.9)";
	 };
	};
	driverInAction = "UH60_Pilot";
	driverAction = "UH60_Pilot";
	cargoAction[] = {"UH60_Cargo01","UH1Y_Cargo02","UH1Y_Cargo01","UH1Y_Cargo01","UH1Y_Cargo01","UH60_Cargo02"};
	transportSoldier = 13;
	driverCompartments = "Compartment1";
	cargoCompartments[] = {"Compartment2"};
	enableSweep = 0;
	transportAmmo = 0;
	supplyRadius = 2.5;
	initCargoAngleY = 10;
	minCargoAngleY = -60;
	maxCargoAngleY = 120;
	type = 2;
	threat[] = {0.3,1,0.4};
	typicalCargo[] = {"USMC_Soldier_Pilot","USMC_Soldier_Pilot","USMC_Soldier_Pilot"};
	cargoIsCoDriver[] = {1,0,0};
	weapons[] = {};
	magazines[] = {};
	transportMaxMagazines = 150;
	transportMaxWeapons = 30;
	forceHideDriver = 1;
	castDriverShadow = 1;
	castCargoShadow = 1;
	class AnimationSources: AnimationSources
	{
	 class ReloadAnim
	 {
			source = "reload";
			weapon = "M240_veh";
	 };
	 class ReloadMagazine
	 {
			source = "reloadmagazine";
			weapon = "M240_veh";
	 };
	 class Revolving
	 {
			source = "revolving";
			weapon = "M240_veh";
	 };
	 class ReloadAnim_2
	 {
			source = "reload";
			weapon = "M240_veh_2";
	 };
	 class ReloadMagazine_2
	 {
			source = "reloadmagazine";
			weapon = "M240_veh_2";
	 };
	 class Revolving_2
	 {
			source = "revolving";
			weapon = "M240_veh_2";
	 };
	};
	class Library
	{
	 libTextDesc = "$STR_LIB_MH60S";
	};
	class Damage
	{
	 tex[] = {};
	 mat[] = {"ca\air\Data\uh60_skla.rvmat","ca\air\Data\uh60_skla_damage.rvmat","ca\air\Data\uh60_skla_damage.rvmat","ca\air\Data\uh60_skla_in.rvmat","ca\air\Data\uh60_skla_in_damage.rvmat","ca\air\Data\uh60_skla_in_damage.rvmat","ca\air\Data\materialy\uh60_01.rvmat","ca\air\Data\materialy\uh60_01_damage.rvmat","ca\air\Data\materialy\uh60_01_destruct.rvmat"};
	};
	enableManualFire = 0;
	class Turrets: Turrets
	{
	 class MainTurret: MainTurret
	 {
			body = "mainTurret";
			gun = "mainGun";
			minElev = -80;
			maxElev = 25;
			initElev = -80;
			minTurn = 30;
			maxTurn = 150;
			initTurn = 90;
			soundServo[] = {"",0.01,1.0};
			stabilizedInAxes = "StabilizedInAxesNone";
			gunBeg = "muzzle_1";
			gunEnd = "chamber_1";
			weapons[] = {"M240_veh"};
			magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240"};
			gunnerName = "$STR_POSITION_CREWCHIEF";
			gunnerOpticsModel = "\ca\weapons\optika_empty";
			gunnerOutOpticsShowCursor = 1;
			gunnerOpticsShowCursor = 1;
			gunnerAction = "MH60_Gunner";
			gunnerInAction = "MH60_Gunner";
			gunnerCompartments = "Compartment2";
			primaryGunner = 1;
			class ViewOptics
			{
			 initAngleX = 0;
			 minAngleX = -30;
			 maxAngleX = 30;
			 initAngleY = 0;
			 minAngleY = -100;
			 maxAngleY = 100;
			 initFov = 0.7;
			 minFov = 0.25;
			 maxFov = 1.1;
			};
	 };
	 class RightDoorGun: MainTurret
	 {
			body = "Turret_2";
			gun = "Gun_2";
			animationSourceBody = "Turret_2";
			animationSourceGun = "Gun_2";
			animationSourceHatch = "";
			selectionFireAnim = "zasleh_1";
			proxyIndex = 2;
			gunnerName = "$STR_POSITION_DOORGUNNER";
			commanding = -2;
			minTurn = -150;
			maxTurn = -30;
			initTurn = -90;
			weapons[] = {"M240_veh_2"};
			stabilizedInAxes = "StabilizedInAxesNone";
			gunBeg = "muzzle_2";
			gunEnd = "chamber_2";
			primaryGunner = 0;
			gunnerCompartments = "Compartment2";
			memoryPointGun = "machinegun_2";
			memoryPointGunnerOptics = "gunnerview_2";
		};
	};
		class Reflectors
		{
		class Left
		{
			color[] = {0.8,0.8,1.0,1.0};
			ambient[] = {0.07,0.07,0.07,1.0};
			position = "L svetlo";
			direction = "konec L svetla";
			hitpoint = "L svetlo";
			selection = "L svetlo";
			size = 1;
			brightness = 1.0;
		};
		class Right
		{
			color[] = {0.8,0.8,1.0,1.0};
			ambient[] = {0.07,0.07,0.07,1.0};
			position = "P svetlo";
			direction = "konec P svetla";
			hitpoint = "P svetlo";
			selection = "P svetlo";
			size = 1;
			brightness = 1.0;
		};
	};	
};