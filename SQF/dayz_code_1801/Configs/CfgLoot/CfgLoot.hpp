class CfgLoot {

	#include "BuildingLoot\Supermarket.hpp"
	#include "BuildingLoot\Farm.hpp"
	#include "BuildingLoot\Industrial.hpp"
	#include "BuildingLoot\Residential.hpp"
	#include "BuildingLoot\Church.hpp"
	#include "BuildingLoot\militaryEAST.hpp"
	#include "BuildingLoot\militaryWEST.hpp"
	#include "BuildingLoot\Hospital.hpp"
	//#include "BuildingLoot\Military.hpp"
	#include "BuildingLoot\Hunter.hpp"
	#include "BuildingLoot\Caribou_Clothing.hpp"

	//Zed Loot
	policeman[] = {
	//med
		{"ItemBandage",0.10},
	//ammo
		{"7Rnd_45ACP_1911",0.03},
		{"6Rnd_45ACP",0.03},
		{"15Rnd_W1866_Slug",0.03},
		{"8Rnd_B_Beneli_74Slug",0.03},
		{"HandRoadFlare",0.05},
	//drinks
		{"ItemWaterbottleUnfilled",0.01}
	//food
	//special
	//trash
	};
	civilian[] = {
	//med
		{"ItemBandage",0.06},
		{"ItemPainkiller",0.03},
	//ammo
		{"8Rnd_9x18_Makarov",0.04},
		//{"7Rnd_45ACP_1911",0.04}, //mil/police
		{"6Rnd_45ACP",0.04},
		//{"2Rnd_shotgun_74Slug",0.04}, //pellets preferred for m43
		{"2Rnd_shotgun_74Pellets",0.08},
	//drinks
		{"ItemSodaCoke",0.02},
		{"ItemSodaPepsi",0.02},
	//food
		{"FoodCanBakedBeans",0.03},
		{"FoodCanPasta",0.03}
	//special
	//trash
	};
	viralloot[] = {
	//med
		{"ItemBandage",0.02},
	//ammo
		{"8Rnd_9x18_Makarov",0.04},
		//{"7Rnd_45ACP_1911",0.04}, //mil/police
		{"6Rnd_45ACP",0.04},
		//{"2Rnd_shotgun_74Slug",0.04}, //pellets preferred for m43
		{"2Rnd_shotgun_74Pellets",0.08},
		//{"20Rnd_762x51_FNFAL",0.02}, //really (one of the best ammo)?
	//drinks
		{"ItemSodaPepsi",0.04},
	//food
		{"FoodCanFrankBeans",0.05},
		{"FoodCanPasta",0.05},
		{"FoodCanSardines",0.05}
	//special
	//trash
	};
	food[] = {
	//med
	//ammo
	//drinks
	//food
		{"FoodCakeCremeCakeClean",0.01},
		{"ItemSodaMtngreen",0.01}
	//special
	//trash
	};
	generic[] = {
	//med
		{"ItemBandage",0.04},
		{"ItemAntibacterialWipe",0.03},
		{"ItemHeatPack",0.04},
	//ammo
		{"8Rnd_9x18_Makarov",0.09},
		//{"7Rnd_45ACP_1911",0.04}, //mil/police
		{"6Rnd_45ACP",0.04},
		//{"2Rnd_shotgun_74Slug",0.04}, //pellets preferred for m43
		{"2Rnd_shotgun_74Pellets",0.08},
		{"8Rnd_9x19_Mk",0.05},
		{"8Rnd_45cal_m1911",0.03},
		{"10Rnd_22LR_mk2",0.04},
		{"8Rnd_762_tt33",0.03},
		{"20Rnd_32cal_vz61",0.02},
		{"7Rnd_32cal_ppk",0.05},
		{"8Rnd_9x19_p38",0.02},
		{"6Rnd_357_Mag",0.04},
		{"RH_20Rnd_9x18_aps",0.01},
		{"5x_22_LR_17_HMR",0.01},
		{"10x_303",0.04},
		{"15Rnd_W1866_Slug",0.06},
		//{"20Rnd_762x51_FNFAL",0.02}, //really (one of the best ammo)?
		{"WoodenArrow",0.04},
		{"HandRoadFlare",0.07},
		{"ItemPainkiller",0.02},
		{"HandChemGreen",0.01},
		{"HandChemBlue",0.03},
		{"HandChemRed",0.03},
	//drinks
		{"ItemWaterbottleUnfilled",0.03},
		{"ItemWaterbottle",0.01},
		{"ItemSodaCoke",0.02},
		{"ItemSodaPepsi",0.02},	
	//food
		{"FoodCanBakedBeans",0.01},
		{"FoodCanSardines",0.01},
		{"FoodCanFrankBeans",0.01},
		{"FoodCanPasta",0.01},
		{"FoodCanUnlabeled",0.01},
		{"FoodCanRusUnlabeled",0.01},
		{"FoodCanRusStew",0.01},
		{"FoodCanRusPork",0.02},
		{"FoodCanRusPeas",0.01},
		{"FoodCanRusMilk",0.02},
		{"FoodCanRusCorn",0.01},
		{"FoodPistachio",0.02},
		{"FoodNutmix",0.03},
	//special
	//trash
		{"ItemSodaCokeEmpty",0.05},
		{"ItemSodaPepsiEmpty",0.03},
		{"FoodCanUnlabeledEmpty",0.05},
		{"FoodCanRusUnlabeledEmpty",0.02},
		{"FoodCanRusPorkEmpty",0.02},
		{"FoodCanRusPeasEmpty",0.03},
		{"FoodCanRusMilkEmpty",0.02},
		{"FoodCanRusCornEmpty",0.05},
		{"FoodCanRusStewEmpty",0.03},
		{"TrashTinCan",0.05},
		{"TrashJackDaniels",0.02},
		{"ItemSodaEmpty",0.03},
		{"ItemTrashToiletpaper",0.01},
		{"ItemTrashRazor",0.01},
		{"ItemCards",0.02}
	};
	medical[] = {
	//med
		{"ItemBandage",0.08},
		{"ItemPainkiller",0.05},
		{"ItemMorphine",0.05},
		{"ItemEpinephrine",0.03},
		{"ItemAntibiotic",0.01},
		{"ItemAntibacterialWipe",0.04},
		{"ItemHeatPack",0.03}
	//ammo
	//drinks
	//food
	//special
	//trash
	};
	military[] = {
	//med
		{"ItemBandage",0.04},
		{"ItemPainkiller",0.02},
		{"ItemMorphine",0.01},
		{"ItemHeatPack",0.04},
	//ammo
		{"7Rnd_45ACP_1911",0.04},
		{"30Rnd_556x45_Stanag",0.06},
		{"75Rnd_545x39_RPK",0.04},
		{"20Rnd_762x51_DMR",0.05},
		{"20Rnd_762x51_FNFAL",0.04},
		{"17Rnd_9x19_glock17",0.05},
		{"15Rnd_9x19_M9SD",0.03},
		{"8Rnd_9x18_MakarovSD",0.01},
		{"15Rnd_9x19_M9",0.03},
		{"30Rnd_762x39_AK47",0.02},
		{"30Rnd_545x39_AK",0.05},
		{"5Rnd_762x51_M24",0.01},
		{"8Rnd_B_Beneli_74Slug",0.04},
		{"1Rnd_HE_M203",0.06},
		{"FlareWhite_M203",0.02},
		{"FlareGreen_M203",0.02},
		{"1Rnd_Smoke_M203",0.01},
		{"200Rnd_556x45_M249",0.01},
		{"HandGrenade_west",0.01},
		{"HandGrenade_east",0.01},
		{"SmokeShell",0.04},
		{"SmokeShellRed",0.04},
		{"SmokeShellGreen",0.04},
		{"8Rnd_B_Beneli_Pellets",0.04},
		{"30Rnd_556x45_StanagSD",0.03},
		{"30Rnd_9x19_MP5",0.05},
		{"30Rnd_9x19_MP5SD",0.05},
		{"100Rnd_762x51_M240",0.03},
		{"HandChemGreen",0.04},
		{"HandChemBlue",0.04},
		{"HandChemRed",0.04},
	//Custom Stuff
		{"5Rnd_86x70_L115A1",0.02},
		{"5Rnd_127x108_KSVK",0.02},
		{"20Rnd_762x51_B_SCAR",0.02},
		{"20Rnd_762x51_SB_SCAR",0.02},
		{"8Rnd_B_Saiga12_74Slug",0.05},
		{"10Rnd_9x39_SP5_VSS",0.02},
		{"20Rnd_9x39_SP5_VSS",0.01},
	//RH:Handgun-Ammo
		{"8Rnd_9x19_Mk",0.02},
		{"8Rnd_45cal_m1911",0.02},
		{"10Rnd_22LR_mk2",0.02},
		{"8Rnd_762_tt33",0.02},
		{"20Rnd_32cal_vz61",0.02},
		{"7Rnd_32cal_ppk",0.02},
		{"8Rnd_9x19_p38",0.02},
		{"6Rnd_357_Mag",0.02},
		{"7Rnd_50_AE",0.02},
		{"6Rnd_44_Mag",0.02},
		{"15Rnd_9x19_usp",0.02},
		{"17Rnd_9x19_g17",0.02},
		{"19Rnd_9x19_g18",0.02},
		{"33Rnd_9x19_g18",0.02},
		{"30Rnd_9x19_tec",0.02},
		{"32Rnd_9x19_Muzi",0.02},
		{"15Rnd_9x19_uspsd",0.02},
		{"RH_20Rnd_9x18_aps",0.03},
		{"RH_20Rnd_9x18_apssd",0.02},
	//RH:Rifle-Ammo
		{"RH_45ACP_25RND_Mag",0.02},
		{"RH_45ACP_25RND_SD_Mag",0.02},
		{"RH_9mm_32RND_Mag",0.02},
		{"RH_9mm_32RND_SD_Mag",0.02},
		{"RH_30Rnd_545x39_AKSU_mag",0.02},
		{"RH_75Rnd_762x39_mag",0.02},
		{"RH_45Rnd_545x39_mag",0.02},
		{"RH_5Rnd_B_Beneli_74Slug",0.02},
		{"RH_5Rnd_B_Beneli_Pellets",0.02},
		{"RH_30Rnd_762x39_SDmag",0.02},
	//drinks
		{"ItemSodaEmpty",0.06},
		{"ItemSodaCoke",0.04},
		{"ItemSodaPepsi",0.04},
	//food
		{"FoodCanBakedBeans",0.05},
		{"FoodCanSardines",0.05},
		{"FoodCanFrankBeans",0.05},
		{"FoodCanPasta",0.05},
		{"FoodCanUnlabeled",0.04},
		{"FoodPistachio",0.03},
		{"FoodNutmix",0.04},
		{"FoodCanRusUnlabeled",0.05},
		{"FoodCanRusStew",0.05},
		{"FoodCanRusPork",0.05},
		{"FoodCanRusPeas",0.05},
		{"FoodCanRusMilk",0.04},
		{"FoodCanRusCorn",0.05},
		{"FoodMRE",0.03},
	//special
	//trash
		{"ItemSodaCokeEmpty",0.05},
		{"ItemSodaPepsiEmpty",0.03},
		{"FoodCanUnlabeledEmpty",0.05},
		{"FoodCanRusUnlabeledEmpty",0.02},
		{"FoodCanRusPorkEmpty",0.02},
		{"FoodCanRusPeasEmpty",0.03},
		{"FoodCanRusMilkEmpty",0.02},
		{"FoodCanRusCornEmpty",0.05},
		{"FoodCanRusStewEmpty",0.03},
		{"TrashTinCan",0.05},
		{"TrashJackDaniels",0.02},
		{"ItemSodaEmpty",0.03},
		{"ItemTrashToiletpaper",0.01},
		{"ItemTrashRazor",0.01},
		{"ItemCards",0.02}
	};
};

  //{"ItemSodaSmasht",0.01}, //4 this supermarket, residential, industrail
  //{"FoodCanPowell",0.01}, //4 this, indy, res, super
  //{"FoodChipsSulahoops",0.01}, //4 this, indy, super, church
  
  //{"ItemSodaClays",0.01}, //3 this, supermarket, chruch
  //{"ItemSodaDrwaste",0.01}, //3 supermarket, industrail
  //{"ItemSodaLemonade",0.01},  //3 supermarket, farm, this
  //{"ItemSodaMzly",0.01},  //3 res ,super, church
  //{"FoodCanCurgon",0.01}, //3 this, super, church
  //{"FoodCanDemon",0.01}, //3 this, res,super
  //{"FoodCanFraggleos",0.01}, //3 this, res, super.
  //{"FoodCanDerpy",0.01}, //3 this, res, super
  //{"FoodCanOrlok",0.01}, //3 this, res, super
  //{"FoodCanTylers",0.01}, //3 this, res, super
  //{"FoodCanHerpy",0.001}, //3 this, res, super.
  
  //{"ItemSodaR4z0r",0.01}, //2 this, supermarket
  //{"ItemSodaLvg",0.01}, //2 this, supermarket
  //{"ItemSodaRabbit",0.01}, //2 super, this
  //{"FoodCanBadguy",0.01}, //2 this, super
  //{"FoodCanBoneboy",0.01}, //2 this supper
  //{"FoodCanCorn",0.01}, //2 this super
  //{"FoodChipsMysticales",0.01}, //2 this, super
  //{"FoodCandyAnders",0.01}, //2 this, super
  //{"FoodCandyLegacys",0.01}, //2 this, super
  //{"FoodCandyMintception",0.01}, //2 this, super