class Blueprint_CM_Pack : Recipe {
	displayName = "CM Backpack";
	descriptionShort = "Craftable small Backpack";
	input[] = 
	{
		{"equip_rope","CfgMagazines",2},
		{"equip_rag","CfgMagazines",2},
		{"equip_string","CfgMagazines",1},
		{"WoodenArrow","CfgMagazines",1}
	};
	output[] = 
	{
		{"DZ_CM_Pack_EP1","CfgVehicles",1}
	};
	required[] = 
	{
		{"ItemToolbox","CfgWeapons",1}
	};
};

class Blueprint_CMM_Pack : Recipe {
	displayName = "CMM Backpack";
	descriptionShort = "Biggest Backpack available";
	input[] = 
	{
		{"equip_rope","CfgMagazines",2},
		{"equip_hose","CfgMagazines",2},
		{"equip_rag","CfgMagazines",4},
		{"equip_string","CfgMagazines",1},
		{"WoodenArrow","CfgMagazines",1}
	};
	output[] = 
	{
		{"DZ_CMM_Pack_EP1","CfgVehicles",1}
	};
	required[] = 
	{
		{"ItemToolbox","CfgWeapons",1}
	};
};

class Blueprint_CarBomb : Recipe {
	displayName = "Carbomb";
	descriptionShort = "Letting Vehicles Explode ;)";
	input[] = 
	{
		{"HandGrenade_West","CfgMagazines",4},
		{"equip_floppywire","CfgMagazines",2},
		{"equip_scrapelectronics","CfgMagazines",1},
		{"equip_duct_tape","CfgMagazines",1}

	};
	output[] = 
	{
		{"ItemCarBomb","CfgMagazines",1}
	};
	required[] = 
	{
		{"ItemToolbox","CfgWeapons",1}
	};
};