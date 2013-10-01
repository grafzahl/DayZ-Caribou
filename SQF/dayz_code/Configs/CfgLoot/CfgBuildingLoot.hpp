#include "CfgLoot.hpp"

class CfgBuildingLoot {
	class Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_suit1","z_suit2","z_worker1","z_worker2","z_worker3","z_villager1","z_villager2","z_villager3"};
		lootChance = 0;
		lootPos[] = {};
		lootType[] = {};
		hangPos[] = {};
		vehPos[] = {};
	};
	class Master {
		weapons[] = {"SMAW","Javelin","G36C","Stinger"};
	};
	//New System
	class Church: Default {
		zombieChance = 0.3;
		minRoaming = 1;
		maxRoaming = 3;
		zombieClass[] = {"z_priest","z_priest","z_priest"};
		lootChance = 0.3;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemMatchbox","generic",0.02},
		//weapons
		//special
		//mags special
			{"ItemBookBible","magazine",0.03},
			//{"8Rnd_9x18_Makarov","magazine",0.03}, //this is church! no weapons allowed :)
		//bags
		//multiple spawns	
			{"","Church",0.50},
			{"","generic",0.50}
		};
	};
	class Castle: Default {
		lootChance = 0.2;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemMatchbox","weapon",0.01},
			{"ItemKnife","weapon",0.01},
			{"ItemMap","generic",0.01},
			{"ItemCompass","weapon",0.01},
			{"ItemFlashlight","weapon",0.01},
		//weapons
			{"WeaponHolder_ItemHatchet","object",0.01},
			{"RH_anac","weapon",0.005},//RH_6Rnd_44_Mag
			{"RH_bull","weapon",0.005},//RH_6Rnd_44_Mag
		//special
			{"WeaponHolder_ItemDomeTent","object",0.05},
		//mags special
			{"PartWoodPile","magazine",0.04},
		//bags
			{"DZ_Patrol_Pack_EP1","object",0.01},
		//Multiple spawns	
			{"","Residential",0.60},
			{"","generic",0.40}
		};
	};	
	class Residential: Default {
		zombieChance = 0.3;
		maxRoaming = 2;
		zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_villager1","z_villager2","z_villager3","z_new_villager2","z_new_villager3","z_new_villager4"};
		lootChance = 0.4;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemWatch","generic",0.03},
			{"ItemFlashlight","generic",0.01},
			{"ItemFishingPole","generic",0.02}, //move it to boats and boatstations
		//weapons
			{"MR43","weapon",0.02},
			{"Winchester1866","weapon",0.02},
			{"LeeEnfield","weapon",0.01},
			{"MeleeBaseBallBat","weapon",0.02},
		//RH:Handguns
			{"RH_mk22","weapon",0.005},//RH_8Rnd_9x19_Mk
			{"RH_m1911old","weapon",0.01},//RH_8Rnd_45cal_m1911
			{"RH_mk2","weapon",0.005},//RH_10Rnd_22LR_mk2
			{"RH_tt33","weapon",0.005},//RH_8Rnd_762_tt33
			{"RH_vz61","weapon",0.005},//RH_20Rnd_32cal_vz61
			{"RH_ppk","weapon",0.005},//RH_7Rnd_32cal_ppk
			{"RH_p38","weapon",0.005},//RH_8Rnd_9x19_p38
			{"RH_python","weapon",0.002},//RH_6Rnd_357_Mag
			{"RH_pm","weapon",0.01},//8Rnd_9x18_Makarov
			{"RH_aps","weapon",0.003},//RH_20Rnd_9x18_aps
		//special
			{"WeaponHolder_ItemFuelcan","object",0.03},
		//mags special
			{"ItemPainkiller","magazine",0.04},
			{"ItemBandage","magazine",0.06},
		//bags
			{"DZ_Patrol_Pack_EP1","object",0.05},
			{"DZ_Assault_Pack_EP1","object",0.04},
		//multiple spawns	
			{"","Residential",0.50},
			{"","generic",0.50}
		};
	};
	class Industrial: Default { //254
		zombieChance = 0.4;
		zombieClass[] = {"z_worker1","z_worker2","z_worker3","z_new_worker2","z_new_worker3","z_new_worker4"};
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemKnife","weapon",0.03},
			{"ItemToolbox","weapon",0.06},
			{"ItemFlashlight","weapon",0.02},
			{"ItemShovel","weapon",0.02},
		//weapons
			{"WeaponHolder_ItemCrowbar","object",0.08},
			{"WeaponHolder_ItemHatchet","object",0.05},
		//special
			{"WeaponHolder_PartGeneric","object",0.04},
			{"WeaponHolder_PartWheel","object",0.05},
			{"WeaponHolder_PartFueltank","object",0.02},
			{"WeaponHolder_PartEngine","object",0.02},
			{"WeaponHolder_PartGlass","object",0.04},
			//{"WeaponHolder_PartVRotor","object",0.01}, //move it to helichash and ss_hangar 
			{"WeaponHolder_ItemJerrycan","object",0.04},
			{"WeaponHolder_ItemFuelcan","object",0.03},
		//mags special
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
		//bags
		//multiple spawns	
			{"","Industrial",0.50},
			{"","generic",0.50}
		};
	};
	class Farm: Default {
		zombieChance = 0.3;
		maxRoaming = 3;
		zombieClass[] = {"zZombie_Base","z_hunter","z_hunter","z_hunter","z_villager1","z_villager2","z_villager3","z_new_villager2","z_new_villager3","z_new_villager4"};
		lootChance = 0.5;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemMatchbox","weapon",0.05},
		//weapons
			{"WeaponHolder_ItemHatchet","object",0.05},
			{"huntingrifle","weapon",0.02},
			{"LeeEnfield","weapon",0.03},
			{"Winchester1866","weapon",0.03},
			{"Crossbow_DZ","weapon",0.03},
			{"MR43","weapon",0.05},
			{"MeleeMachete","weapon",0.04},
		//special
			{"WeaponHolder_ItemJerrycan","object",0.03},
		//mags special
			{"TrapBear","magazine",0.01},
			{"PartWoodPile","magazine",0.08},
		//bags
		//multiple spawns		
			{"","Farm",0.50},
			{"","generic",0.50}
		};
	};
	class Supermarket: Default {
		lootChance = 0.4;
		minRoaming = 2;
		maxRoaming = 6;
		zombieChance = 0.3;
		zombieClass[] = {"zZombie_Base","zZombie_Base","z_teacher","z_suit1","z_suit2","z_new_villager2","z_new_villager3","z_new_villager4"};
		lootType[] = {
		//one spawn
		//tools
			{"ItemWatch","generic",0.05},
			{"ItemCompass","generic",0.01},
			{"ItemMap","generic",0.06},
			{"ItemFlashlight","generic",0.05},
			{"ItemKnife","generic",0.02},
			{"ItemMatchbox","generic",0.05},
			{"Binocular","weapon",0.03},
		//weapons
			{"Makarov","weapon",0.02},
			//{"Colt1911","weapon",0.02}, //mil/police
			{"LeeEnfield","weapon",0.01},
			{"revolver_EP1","weapon",0.03},
			{"Winchester1866","weapon",0.02},
			{"Crossbow_DZ","weapon",0.03},
			{"MR43","weapon", 0.04},			
		//special
			{"WeaponHolder_ItemTent","object",0.02},
			{"WeaponHolder_ItemDomeTent","object",0.01},
			{"ItemGeocache","magazine",0.01},
		//mags special
			{"PartWoodPile","magazine",0.04},
		//bags
			{"DZ_Patrol_Pack_EP1","object",0.05}, //12
			{"DZ_ALICE_Pack_EP1","object",0.02}, // 16
			{"DZ_TK_Assault_Pack_EP1","object",0.02}, // 16
		//multiple spawns		
			{"","food",0.05},
			{"","Supermarket",0.60},
			{"","generic",0.50}
		};
	};	
	class Office: Residential {
		maxRoaming = 3;
		lootChance = 0.2;
		zombieClass[] = {"z_suit1","z_suit2"};
		lootType[] = {
		//one spawn
		//tools
			{"ItemWatch","weapon",0.08},
			{"ItemMap","weapon",0.06}, 
		//weapons
		//special
		//mags special
			{"ItemAntibacterialWipe","magazine",0.04},
			{"ItemPainkiller","magazine",0.04},
		//bags
		//multiple spawns
			{"","generic",0.80}
		};
	};
	class InfectedCamps: Default { //5
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemWatch","generic",0.05},
			{"ItemCompass","generic",0.05},
			{"ItemFlashlight","generic",0.06},
			{"ItemKnife","generic",0.07},
			{"ItemMatchbox","generic",0.06},
			{"Binocular","weapon",0.06},
		//weapons
			{"Makarov","weapon",0.04},
			//{"Colt1911","weapon",0.04}, //mil/police
			{"LeeEnfield","weapon",0.03},
			{"revolver_EP1","weapon",0.04},
			{"Winchester1866","weapon",0.03},
			{"Crossbow_DZ","weapon",0.01},
			{"MR43","weapon",0.03},
			{"MeleeBaseBallBat","weapon",0.02},
			{"WeaponHolder_ItemCrowbar","object",0.08},
		//special
			{"WeaponHolder_PartGeneric","object",0.04},
			{"WeaponHolder_PartWheel","object",0.02},
			{"WeaponHolder_PartFueltank","object",0.02},
			{"WeaponHolder_PartEngine","object",0.02},
			{"WeaponHolder_ItemFuelcan","object",0.03},
			{"WeaponHolder_ItemTent","object",0.005},
			{"WeaponHolder_ItemFuelcan","object",0.03},
			{"MedBox0","object",0.05},
			{"MedBox1","object",0.05},
			{"FoodBox0","object",0.05},
		//mags special
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
			{"ItemSodaMdew","magazine",0.01},
			{"PartWoodPile","magazine",0.06},
			{"Skin_Camo1_DZ","magazine",0.01},
			{"ItemBookBible","magazine",0.02},
		//bags
			{"DZ_ALICE_Pack_EP1","object",0.01}, // 16
			{"DZ_TK_Assault_Pack_EP1","object",0.02}, // 16
		//multiple spawns
			{"","medical",0.10},
			{"","generic",0.50}
		};
	};
	class HeliCrashWEST: Default {
		zombieChance = 1;
		maxRoaming = 8;
		zombieClass[] = {"z_soldier_pilot"};
		lootChance = 0.5;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"NVGoggles","weapon",0.04},
		//weapons
			{"FN_FAL","weapon",0.08},
			{"BAF_LRR_scoped_W","weapon",0.01},
			{"Mk_48_DZ","weapon",0.03},
			{"M249_DZ","weapon",0.04},
			{"BAF_L85A2_RIS_Holo","weapon",0.03},
			//{"G36C","weapon",0.03},
			//{"G36C_camo","weapon",0.03},
			//{"bizon_silenced","weapon",0.05},
			//{"G36_C_SD_camo","weapon",0.01},
			{"G36A_camo","weapon",0.03},
			{"G36K_camo","weapon",0.03},
			{"M9SD","weapon",0.02},
			{"KSVK_DZ","weapon",0.01},
			{"VSS_Vintorez","weapon",0.02},
			{"M14_EP1","weapon",0.02},
			{"DMR_DZ","weapon",0.02},
			{"PK_DZ","weapon",0.02},
			{"RPK_74","weapon",0.05},
		//Robert Hammer
			{"RH_deagle","weapon",0.04},//RH_7Rnd_50_AE
			{"RH_m4cmkeotech","weapon",0.08},//30Rnd_556x45_Stanag,RH_5Rnd_B_Beneli_74Slug,RH_5Rnd_B_Beneli_Pellets
			{"RH_m4ctsdaim","weapon",0.04},//30Rnd_556x45_StanagSD
			{"RH_scarHb_sd_aim","weapon",0.02},//20rnd_762x51_SB_SCAR
			{"RH_scarHb_sd_gl_eotech","weapon",0.02},//20rnd_762x51_SB_SCAR
			{"RH_scarLb_sd_eotech","weapon",0.05},//30Rnd_556x45_StanagSD
			{"RH_scarLb_sd_gl_aim","weapon",0.04},//30Rnd_556x45_StanagSD
			{"RH_rk95sdaim","weapon",0.01},//RH_30Rnd_762x39_SDmag
			{"RH_aks74usdk","weapon",0.01},//30Rnd_545x39_AKSD
			//---Snipers---
			{"RH_m21","weapon",0.01},//20Rnd_762x51_DMR
			{"SCAR_H_LNG_Sniper","weapon",0.01},
			{"RH_m40a5","weapon",0.01},//5Rnd_762x51_M24
			{"RH_svdb","weapon",0.02},//10Rnd_762x54_SVD
			{"RH_svu","weapon",0.02},//10Rnd_762x54_SVD
			{"RH_mk12mod1","weapon",0.04},//30Rnd_556x45_Stanag
			{"RH_mk12mod1sd","weapon",0.03},//30Rnd_556x45_StanagSD
			//---Machineguns---
			{"RH_mk43","weapon",0.001},//100Rnd_762x51_M240
			{"RH_Mk48mod1","weapon",0.001},//100Rnd_762x51_M240
		//special
			{"MedBox0","object",0.05},
			{"AmmoBoxSmall_556","object",0.05},
			{"WeaponHolder_ItemCamoNet","object",0.01},
		//bags
		//multiple spawns
		//multiple spawns
			{"","medical",0.25},
			{"","CaribouClothing",0.2},
			{"","military",0.25}
		};
	};
/*
	class HeliCrashEAST: Default {
		zombieChance = 1;
		maxRoaming = 8;
		zombieClass[] = {"z_soldier_pilot"};
		lootChance = 0.5;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"Binocular","weapon",0.01},
			{"ItemKnife","generic",0.03},
			{"ItemCompass","generic",0.04},
		//weapons
			{"MakarovSD","weapon",0.02},
		//special
			{"MedBox0","object",0.05},
			{"AmmoBoxSmall_762","object",0.3},
			{"WeaponHolder_PartVRotor","object",0.02},
			{"WeaponHolder_ItemCamoNet","object",0.01},
		//mags special
			{"100Rnd_762x54_PK","magazine",0.01},
		//bags
		//multiple spawns
			{"","medical",0.25},
			{"","militaryEAST",0.25}
		};
	};
*/
	class Hospital: Default {
		zombieChance = 0.4;
		minRoaming = 2;
		maxRoaming = 6;
		zombieClass[] = {"z_doctor","z_doctor","z_doctor"};
		lootChance = 0.2;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
		//weapons
		//special
			{"MedBox0","object",0.02},
			{"MedBox1","object",0.03},
			{"DZ_Medic_Pack_EP1","object",0.01},
		//mags special
		//bags
		//multiple spawns
			{"","hospital",0.60}
		};
	};

	class Police: Default {
		zombieChance = 0.3;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_policeman","z_new_worker2","z_new_worker3","z_new_worker4"};
		lootChance = 0.2;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"Binocular","weapon",0.05},
			{"ItemFlashlightRed","generic",0.06},
			{"ItemKnife","generic",0.06},
			{"ItemGPS","weapon",0.01},
			{"ItemMap","generic",0.03},
			{"ItemEtool","weapon",0.03},
		//Unused
			//{"Colt1911","weapon",0.05},
			//{"M9","weapon",0.05},
			//{"M9SD","weapon",0.01},
			//{"MakarovSD","weapon",0.03},
			//{"M4A1_Aim","weapon",0.03},
			//{"M14_EP1","weapon",0.01},
			//{"UZI_EP1","weapon",0.05},
			//{"glock17_EP1","weapon",0.08},
			//{"MP5A5","weapon",0.04},
			//{"MP5SD","weapon",0.03},
			//{"bizon","weapon",0.03},
		//Handguns
			{"RH_usp","weapon",0.03},//RH_15Rnd_9x19_usp
			{"RH_m9","weapon",0.04},//15Rnd_9x19_M9
			{"RH_g17","weapon",0.04},//RH_17Rnd_9x19_g17
			{"RH_g18","weapon",0.02},//RH_19Rnd_9x19_g18,RH_33Rnd_9x19_g18
			{"RH_tec9","weapon",0.03},//RH_30Rnd_9x19_tec
			{"RH_muzi","weapon",0.04},//RH_32Rnd_9x19_Muzi
			{"RH_p226","weapon",0.035},//RH_15Rnd_9x19_usp
		//weapons
			{"M79_DZ","weapon",0.06},
			{"Remington870_lamp","weapon",0.06},
			{"M1014","weapon",0.04},
			{"Saiga12K","weapon",0.03},
			{"RH_mac10","weapon",0.04},//RH_9mm_32RND_Mag
			{"RH_uzi","weapon",0.04},//RH_9mm_32RND_Mag
			{"RH_ump","weapon",0.04},//RH_45ACP_25RND_Mag
			{"RH_umpeot","weapon",0.03},//RH_45ACP_25RND_Mag
			{"RH_mp5a4","weapon",0.04},//30Rnd_9x19_MP5
			{"RH_mp5a4eot","weapon",0.03},//30Rnd_9x19_MP5
			{"RH_bizon","weapon",0.04},//64Rnd_9x19_Bizon
			{"RH_bizonk","weapon",0.03},//64Rnd_9x19_Bizon
			{"AK_74","weapon",0.04},
			{"AKS_74_U","weapon",0.03},
			{"AKS_74_kobra","weapon",0.03},
			{"M16A2","weapon",0.03},
			{"M16A2GL","weapon",0.03},
			{"M4A1","weapon",0.02},
			{"RH_HK53","weapon",0.02},//30Rnd_556x45_Stanag
			{"RH_HK53eot","weapon",0.01},//30Rnd_556x45_Stanag
			{"M4A3_CCO_EP1","weapon",0.01},
			{"AK_47_M","weapon",0.01},
		//Silenced
			{"RH_uzisd","weapon",0.02},//RH_9mm_32RND_SD_Mag
			{"RH_umpsd","weapon",0.02},//RH_45ACP_25RND_SD_Mag
			{"RH_umpsdeot","weapon",0.01},//RH_45ACP_25RND_SD_Mag
			{"RH_mp5sd6","weapon",0.02},//30Rnd_9x19_MP5SD
			{"RH_mp5sd6eot","weapon",0.01},//30Rnd_9x19_MP5SD
			{"RH_bizonsd","weapon",0.02},//64Rnd_9x19_SD_Bizon
			{"RH_bizonsdk","weapon",0.01},//64Rnd_9x19_SD_Bizon
		//special
		//mags special
			{"ItemSandbag","magazine",0.06},
		//bags
			{"DZ_RPG_Pack_EP1","object",0.1}, // 18
			{"DZ_British_ACU","object",0.05}, // 18
			{"DZ_CivilBackpack_EP1","object",0.03}, // 24			
		//multiple spawns
			{"","military",0.70},
			{"","generic",0.30}
		};
	};

	class Military: Default {
		zombieChance = 0.3;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_policeman","z_new_worker2","z_new_worker3","z_new_worker4"};
		lootChance = 0.2;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"Binocular","weapon",0.05},
			{"ItemFlashlightRed","generic",0.06},
			{"ItemKnife","generic",0.06},
			{"ItemGPS","weapon",0.01},
			{"ItemMap","generic",0.03},
			{"ItemEtool","weapon",0.03},
		//Unused
			//{"Colt1911","weapon",0.05},
			//{"M9","weapon",0.05},
			//{"M16A2","weapon",0.05},
			//{"M16A2GL","weapon",0.04},
			//{"M9SD","weapon",0.01},
			//{"MakarovSD","weapon",0.03},
			//{"M4A1_Aim","weapon",0.03},
			//{"AKS_74_kobra","weapon",0.06},
			//{"AKS_74_U","weapon",0.04},
			//{"AK_47_M","weapon",0.04},
			//{"M14_EP1","weapon",0.01},
			//{"UZI_EP1","weapon",0.05},
			//{"glock17_EP1","weapon",0.08},
			//{"MP5A5","weapon",0.04},
			//{"MP5SD","weapon",0.03},
			//{"bizon","weapon",0.03},
			//{"AK_74","weapon",0.06},
		//Handguns
			{"RH_usp","weapon",0.03},//RH_15Rnd_9x19_usp
			{"RH_m9","weapon",0.04},//15Rnd_9x19_M9
			{"RH_g17","weapon",0.04},//RH_17Rnd_9x19_g17
			{"RH_g18","weapon",0.02},//RH_19Rnd_9x19_g18,RH_33Rnd_9x19_g18
			{"RH_tec9","weapon",0.03},//RH_30Rnd_9x19_tec
			{"RH_muzi","weapon",0.04},//RH_32Rnd_9x19_Muzi
			{"RH_p226","weapon",0.035},//RH_15Rnd_9x19_usp
		//weapons
			{"M79_DZ","weapon",0.04},
			{"Remington870_lamp","weapon",0.06},
			{"M1014","weapon",0.05},
			{"Saiga12K","weapon",0.03},
			{"RH_aks74u","weapon",0.04},//RH_30Rnd_545x39_AKSU_mag
			{"RH_ak74m","weapon",0.03},//30Rnd_545x39_AK
			{"RH_ak74mgl","weapon",0.02},//30Rnd_545x39_AK
			{"RH_ak105","weapon",0.04},//30Rnd_545x39_AK
			{"RH_ak105gl","weapon",0.02},//30Rnd_545x39_AK
			{"RH_rpk74m","weapon",0.01},//RH_45Rnd_545x39_mag
			{"M4A1","weapon",0.03},
			{"RH_m4ct","weapon",0.02},//30Rnd_556x45_Stanag
			{"RH_m4cgl","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a1","weapon",0.03},//20Rnd_556x45_Stanag
			{"RH_m16a1gl","weapon",0.02},//20Rnd_556x45_Stanag
			{"RH_m16a2","weapon",0.02},//30Rnd_556x45_Stanag
			{"RH_m16a2gl","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4","weapon",0.02},//30Rnd_556x45_Stanag
			{"RH_m16a4gl","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a3c","weapon",0.005},//100Rnd_556x45_BetaCMag
			{"M4A3_CCO_EP1","weapon",0.005},
			{"RH_rpk47","weapon",0.001},//RH_75Rnd_762x39_mag
			{"RH_rk95","weapon",0.02},//30Rnd_762x39_AK47
			{"RH_ak47","weapon",0.02},//30Rnd_762x39_AK47
			{"RH_ak47gl","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_ak103","weapon",0.02},//30Rnd_762x39_AK47
			{"RH_ak103gl","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_m14","weapon",0.005},//20Rnd_762x51_DMR
		//mags special
			{"ItemSandbag","magazine",0.04},
		//bags
			{"DZ_RPG_Pack_EP1","object",0.1}, // 18
			{"DZ_British_ACU","object",0.05}, // 18
			{"DZ_CivilBackpack_EP1","object",0.03}, // 24			
		//multiple spawns
			{"","military",0.70},
			{"","generic",0.30}
		};
	};
	class MilitarySpecial: Default {
		zombieChance = 0.8;
		minRoaming = 2;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier_heavy","z_new_worker2","z_new_worker3","z_new_worker4"};
		lootChance = 0.1;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"Binocular","weapon",0.03},
			{"ItemFlashlightRed","generic",0.05},
			{"ItemKnife","generic",0.05},
			{"ItemGPS","weapon",0.01},
			{"ItemMap","generic",0.03},
			{"Binocular_Vector","generic",0.002},
			{"NVGoggles","weapon",0.004},
		//Unused
			//{"UZI_EP1","weapon",0.08},
			//{"M16A2","weapon",0.05},
			//{"M16A2GL","weapon",0.05},
			//{"M4A1","weapon",0.05},
			//{"M4A1_Aim","weapon",0.03},
			//{"SCAR_L_STD_HOLO","weapon",0.015},
			//{"M16A4_ACG","weapon",0.02},
			//{"Sa58P_EP1","weapon",0.02},
			//{"Sa58V_EP1","weapon",0.02},
			//{"AK_74","weapon",0.05},
			//{"AKS_74_kobra","weapon",0.05},
			//{"AKS_74_U","weapon",0.05},
			//{"AK_47_M","weapon",0.05},
			//{"M14_EP1","weapon",0.005},
			//{"KSVK_DZ","weapon",0.003},
			//{"M4A3_CCO_EP1","weapon",0.02},
			//{"M9SD","weapon",0.02},
		//pistols
			{"MakarovSD","weapon",0.07},
			{"glock17_EP1","weapon",0.06},
			{"RH_uspsd","weapon",0.04},//RH_15Rnd_9x19_uspsd
			{"RH_m9sd","weapon",0.03},//15Rnd_9x19_M9SD
			{"RH_pmsd","weapon",0.04},//8Rnd_9x18_MakarovSD
			{"RH_apssd","weapon",0.05},//RH_20Rnd_9x18_apssd
		//weapons
			{"Remington870_lamp","weapon",0.08},
			{"M1014","weapon",0.07},
			{"Saiga12K","weapon",0.04},
		//AK-Damage
			{"RH_ak74mk","weapon",0.04},//30Rnd_545x39_AK
			{"RH_ak74mkgl","weapon",0.03},//30Rnd_545x39_AK
			{"RH_ak74msp","weapon",0.04},//30Rnd_545x39_AK
			{"RH_ak74mglsp","weapon",0.03},//30Rnd_545x39_AK
			{"RH_ak105k","weapon",0.03},//30Rnd_545x39_AK
			{"RH_ak105kgl","weapon",0.02},//30Rnd_545x39_AK
			{"RH_ak105sp","weapon",0.03},//30Rnd_545x39_AK
			{"RH_ak105glsp","weapon",0.02},//30Rnd_545x39_AK
		//Stanag-Damage
			{"RH_m4caim","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m4cacog","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m4ceotech","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m4cglaim","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m4cglacog","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m4cgleotech","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4acog","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4glacog","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4aim","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4glaim","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4eotech","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_m16a4gleotech","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_scarLb_aim","weapon",0.01},//30Rnd_556x45_Stanag
			{"RH_scarLb_gl_acog","weapon",0.01},//30Rnd_556x45_Stanag
			{"MG36_DZ","weapon",0.01},
			{"MG36_camo_DZ","weapon",0.006},
			{"M249_DZ","weapon",0.01},
			{"RH_M249","weapon",0.01},//200Rnd_556x45_M249
			{"RH_M249p","weapon",0.01},//200Rnd_556x45_M249
		//AKM-Damage
			{"RH_rk95ag","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_rk95aim","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_ak103k","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_ak103kgl","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_ak103sp","weapon",0.01},//30Rnd_762x39_AK47
			{"RH_ak103glsp","weapon",0.01},//30Rnd_762x39_AK47
			{"Sa58V_RCO_EP1","weapon",0.01},
			{"Sa58V_CCO_EP1","weapon",0.02},
		//DMR-Damage
			{"RH_m14acog","weapon",0.005},//20Rnd_762x51_DMR
			{"RH_m14aim","weapon",0.01},//20Rnd_762x51_DMR
			{"RH_m14eot","weapon",0.01},//20Rnd_762x51_DMR
			{"RH_scarHb_eotech","weapon",0.01},//20rnd_762x51_B_SCAR
			{"RH_scarHb_gl_acog","weapon",0.01},//20rnd_762x51_B_SCAR
			{"M240_DZ","weapon",0.01},
			{"Mk_48_DZ","weapon",0.005},
			{"Pecheneg_DZ","weapon",0.005},
			{"DMR_DZ","weapon",0.005},
			{"M24","weapon",0.01},
			{"M40A3","weapon",0.005},
			{"SVD_CAMO","weapon",0.005},
			{"SVD","weapon",0.01},
		//Silenced
			{"M4A1_AIM_SD_camo","weapon",0.02},
			{"SCAR_L_CQC_CCO_SD","weapon",0.015},
			{"RH_aks74usd","weapon",0.01},//30Rnd_545x39_AKSD
			{"RH_m4ctsd","weapon",0.01},//30Rnd_556x45_StanagSD
			{"M4A1_HWS_GL_SD_Camo","weapon",0.02},
			{"SCAR_L_CQC","weapon",0.03},
			{"SCAR_H_CQC_CCO","weapon",0.005},

			//silenced
			{"bizon_silenced","weapon",0.04},
			//{"G36_C_SD_camo","weapon",0.02},
			{"SCAR_H_CQC_CCO_SD","weapon",0.006},
			{"SCAR_H_LNG_Sniper_SD","weapon",0.005},
			{"WeaponHolder_ItemCamoNet","object",0.03},
		//mags special
			{"PipeBomb","magazine",0.01},
			{"100Rnd_762x54_PK","magazine",0.01},
		//bags
			{"DZ_CivilBackpack_EP1","object",0.02}, // 24
			{"DZ_Backpack_EP1","object",0.03}, // 24		
		//multiple spawns
			{"","military",0.90},
			{"","CaribouClothing",0.3},
			{"","generic",0.90}
		};
	};
	class Hunting: Default {
		zombieChance = 0.6;
		minRoaming = 1;
		maxRoaming = 3;
		zombieClass[] = {"z_hunter","z_hunter","z_hunter"};
		lootChance = 0.8;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			{"ItemMap","weapon",0.06},
			{"ItemFlashlight","generic",0.06},
			{"ItemKnife","generic",0.05},
			{"ItemMatchbox","generic",0.07},
		//weapons
			{"Crossbow_DZ","weapon",0.04},
			{"Remington870_lamp","weapon",0.3},
			{"MeleeMachete","weapon",0.04},
			{"huntingrifle","weapon",0.05},
			{"MR43","weapon",0.08},
			{"Winchester1866","weapon",0.06},
			{"RH_anac","weapon",0.02},//RH_6Rnd_44_Mag
			{"RH_bull","weapon",0.02},//RH_6Rnd_44_Mag
		//special
			{"WeaponHolder_ItemTent","object",0.02},
		//mags special
			{"TrapBear","magazine",0.01},
		//bags
		//multiple spawns
			{"","hunter",0.10},
			{"","generic",0.50}
		};
	};
#include "CfgBuildingPos.hpp"

};
