class Blueprint_CMM_Pack : Recipe {
	displayName = "CMM Packpack";
	descriptionShort = "Biggest Backpack available";
	input[] = 
	{
		{"equip_rope","CfgMagazines",4},
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
		{"equip_scrapelectronics","CfgMagazines",1}
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