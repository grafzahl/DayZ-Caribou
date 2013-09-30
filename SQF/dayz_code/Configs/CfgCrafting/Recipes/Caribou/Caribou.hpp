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