
class CfgActions {
	class None; // External class reference
	class Rearm : None {
		show = 0;
	};
	class Heal : None {
		show = 0;
	};
	class HealSoldier : None {
		show = 0;
	};
	class FirstAid : None {
		show = 0;
	};
	class TakeBag : None {
		show = 0;
	};
};
class CfgAISkill {
	aimingaccuracy[] = {0, 0, 1, 1};
	aimingshake[] = {0, 0, 1, 1};
	aimingspeed[] = {0, 0, 1, 1};
	commanding[] = {0, 0, 1, 1};
	courage[] = {0, 1, 1, 1};
	endurance[] = {0, 0, 1, 1};
	general[] = {0, 0, 1, 1};
	reloadspeed[] = {0, 0, 1, 1};
	spotdistance[] = {0, 0, 1, 0.6};
	spottime[] = {0, 0, 1, 1};
};

class CfgLoadingTexts {
	titlesDefault[] = {""};
};

class CfgInGameUI
{
    class PeripheralVision
    {
        cueColor[] = {0,0,0,0};
        cueFriendlyColor[] = {0,0,0,0};
        cueEnemyColor[] = {0,0,0,0};
    };
	
    class IslandMap
    {
        colorFriendly[] = {0,0.5,0,0}; //{0,0.5,0,1}; 
        colorEnemy[] = {0.5,0,0,0};    //{0.5,0,0,1};	  
        colorNeutral[] = {1.0,0.5,0,0};//{1.0,0.5,0,1};
        colorCivilian[] = {0,0,1,0};   //{0,0,1,0};
        colorUnknown[] = {1.0,0.5,0,0};//{1.0,0.5,0,0.8};
        shadow = 2;
        iconPlayer = "\ca\ui\data\map_player_ca.paa";
        iconPlayerDirection = "\ca\ui\data\map_dir_ca.paa";
        iconCheckpoint = "\ca\ui\data\map_target_ca.paa";
        iconCamera = "\ca\ui\data\map_camera_ca.paa";
        iconSelect = "\ca\ui\data\map_select_ca.paa";
        iconSensor = "\ca\ui\data\map_trigger_ca.paa";
        sizeLeader = 24;
        size = 26;
        sizePlayer = 26;
        colorTracks[] = {0.2,0.13,0,1};
        colorRoads[] = {0.2,0.13,0,1};
        colorMainRoads[] = {0,0,0,1};
        colorTracksFill[] = {0,0,0,0};
        colorRoadsFill[] = {1,0.88,0.65,1};
        colorMainRoadsFill[] = {0.94,0.69,0.2,1};
        cursorLineWidth = 1;
        colorGrid[] = {0.05,0.1,0,0.6};
        colorGridMap[] = {0.05,0.1,0,0.4};
    };
    	
	
	class MPTable
	{
		color[] = {0,0,0,0}; //{0.7,0.7,0.7,1};
		colorTitleBg[] = {0,0,0,0}; //{0.1,0.15,0.15,1};
		colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.9};
		colorSelected[] = {0,0,0,0}; //{0.7,0.7,0.7,0.4};
		colorWest[] = {0,0,0,0}; //{0.7,0.95,0.7,1};
		colorEast[] = {0,0,0,0}; //{0.95,0.7,0.7,1};
		colorCiv[] = {0,0,0,0}; //{0.8,0.8,0.8,1};
		colorRes[] = {0,0,0,0}; //{0.7,0.7,0.95,1};
		font = "EtelkaNarrowMediumPro";
		size = "0"; //"( 21 / 408 )";
		class Columns
		{
			class Order
			{
				width = 0; //0.046;
				colorBg[] = {0,0,0,0}; //{0.1,0.27,0.1,0.8};
				doubleLine = 0;
			};
			class Player
			{
				width = 0; //0.25;
				colorBg[] = {0,0,0,0}; //{0.1,0.23,0.1,0.8};
				doubleLine = 0;
			};
			class KillsInfantry
			{
				width = 0; //0.11;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_infantry_ca.paa";
			};
			class KillsSoft
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_soft_ca.paa";
			};
			class KillsArmor
			{
				width = 0; //0.11;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_armored_ca.paa";
			};
			class KillsAir
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_air_ca.paa";
			};
			class Killed
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.15,0.1,0.8};
				picture = ""; //"\ca\ui\data\stats_killed_ca.paa";
			};
			class KillsTotal
			{
				width = 0; //0.1;
				doubleLine = 0;
				colorBg[] = {0,0,0,0}; //{0.1,0.35,0.1,0.9};
				picture = ""; //"\ca\ui\data\stats_total_ca.paa";
			};
		};
	};
};

class CfgVoice {
	class NoVoice {
		protocol = "RadioProtocolBase";
		variants[] = {1};
		directories[] = {"", ""};
		identityTypes[] = {"Default", "Zombie1", "Zombie2", "Zombie3"};
	};
};

class CfgIdentities {
	class Zombie1 {
		name = "Zombie";
		face = "Zombie1";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	
	class Zombie2 {
		name = "Zombie";
		face = "Zombie2";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	
	class Zombie3 {
		name = "Zombie";
		face = "Zombie3";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
};

class CfgMissions
{
	 class Cutscenes
	 {
	  class DayZModIntro1
		  {
			directory = "z\addons\dayz_code\Configs\CfgWorlds\intro.dayzmod";
		  };
	 };
};

class CfgSurvival {
	class Inventory {
		class Default {
			RandomMagazines = 3;
			GuaranteedMagazines[] = {"ItemBandage","HandRoadFlare"};
			RandomPossibilitieMagazines[] = {"ItemBandage","ItemPainkiller"};
			backpackWeapon = "";
			//backpack = "DZ_Patrol_Pack_EP1";
		};
	};
	class Meat {
		class Default {
			yield = 2;
			rawfoodtype = "FoodmeatRaw";
		};
		class Cow: Default {
			yield = 6;
			rawfoodtype = "FoodbeefRaw";
		};
		class Cow01: Cow {};
		class Cow02: Cow {};
		class Cow03: Cow {};
		class Cow04: Cow {};
		class Goat: Default {
			yield = 4;
			rawfoodtype = "FoodgoatRaw";
		};
		class Sheep: Default {
			yield = 4;
			rawfoodtype = "FoodmuttonRaw";
		};
		class WildBoar: Default {
			yield = 4;
			rawfoodtype = "FoodbaconRaw";
		};
		class Hen: Default {
			yield = 2;
			rawfoodtype = "FoodchickenRaw";
		};
		class Rabbit: Default {
			yield = 2;
			rawfoodtype = "FoodrabbitRaw";
		};
	};
};
