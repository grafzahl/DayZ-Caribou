//Carbomb
class ItemCarBomb : CA_Magazine {
	scope = public;
	count = 1;
	type = (2*256);
	displayName = "Car Bomb";
	model = "\ca\weapons\explosive.p3d";
	picture = "\dzcb_data\icons\carbomb.paa";
	descriptionShort = "Can be attached to a vehicles engine and then automaticly explode when the engine is turned on!";
};

//Fuel Barrel
class ItemFuelbarrel : CA_Magazine {
	scope = public;
	count = 1;
	type = (8*256);
	fuelQuantity = 80;
	emptycan = "ItemFuelbarrelEmpty";
	displayName = "Fuel Barrel";
	model = "\ca\misc\Barel5.p3d";
	picture = "\dzcb_data\icons\ItemFuelbarrel.paa";
	descriptionShort = "Large 80L Barrel filled with Fuel. Can be used to refuel vehicles. Another Option is to deploy a burning barrel.";
	class ItemActions {
		class Build {
			text = "Deploy Burning Barrel";
			script = "spawn player_build; r_action_count = r_action_count + 1;";
			require = "ItemToolbox";
			create = "Barrel_burning_CBDZ";
		};
	};
};

class ItemFuelbarrelEmpty : CA_Magazine {
	scope = public;
	count = 1;
	type = (8*256);
	fuelQuantity = 0;
	fullcan = "ItemFuelbarrel";
	displayName = "Fuel Barrel (Empty)";
	model = "\ca\misc\Barel5.p3d";
	picture = "\dzcb_data\icons\ItemFuelbarrelEmpty.paa";
	descriptionShort = "Empty 80L Barrel. Can be used to refuel vehicles.";
};

//Bloodbag
class ItemBloodbag: CA_Magazine {
	scope=2;
	count=1;
	type=256;
	displayName="$STR_EQUIP_NAME_16";
	model="\dayz_equip\models\bloodbag.p3d";
	picture="\dayz_equip\textures\equip_bloodbag_ca.paa";
	descriptionShort="$STR_EQUIP_DESC_16";
	class ItemActions {
		class Use
		{
			text="Self-Bloodbag";
			script="spawn player_selfBloodBag;";
		};
	};
};

class ItemBikeBox : CA_Magazine {
	scope = public;
	count = 1;
	type = (256 * 6);
	displayName = "Folding-Bike Kit";
	model = "\z\addons\dayz_communityassets\models\crate.p3d";
	picture = "\dzcb_data\icons\bikeobox.paa";
	descriptionShort = "Bike";

	class ItemActions {
		class Build {
			text = "Unpack Bike"; //this is the text that is in the box you click
			script = "spawn player_unPackBike; r_action_count = r_action_count + 1;";//here we define what the action will do
			require = "ItemToolbox";//by default you require a toolbox in order to deploy the bike
			create = "MMT_Civ";//and here is the output, the mountain bike.
		};
	};
};

class ItemGeocache : CA_Magazine {
	scope = public;
	count = 1;
	type = (256 * 3);
	displayName = "Geocache Kit";
	model = "\rhnet\caribou_models\mdl\misc\rhnet_geoc";
	picture = "\dzcb_data\icons\geocache.paa";
	descriptionShort = "A Kit for hiding a Geocache (Some stupid GPS-Game before the Zombies came here... Humans...)";

	class ItemActions {
		class Build {
			text = "Deploy Geocache";
			script = "spawn player_build; r_action_count = r_action_count + 1;";
			require = "";
			create = "GeoCache_DZ";
		};
	};
};

//Skins
class Skin_Camo2_DZ : SkinBase {
	usemodel = "Camo2_DZ";
	displayName = "Takistan Bandit Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};

class Skin_Rebel1_DZ : SkinBase {
	usemodel = "Rebel1_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Rebel2_DZ : SkinBase {
	usemodel = "Rebel2_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Rebel3_DZ : SkinBase {
	usemodel = "Rebel3_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Rebel4_DZ : SkinBase {
	usemodel = "Rebel4_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Rebel5_DZ : SkinBase {
	usemodel = "Rebel5_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Rebel6_DZ : SkinBase {
	usemodel = "Rebel6_DZ";
	displayName = "Rebel Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};



class Skin_Diver1_DZ : SkinBase {
	usemodel = "Diver1_DZ";
	displayName = "Diving-Suit";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Diver2_DZ : SkinBase {
	usemodel = "Diver2_DZ";
	displayName = "Neoprene-Suit";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};



class Skin_Merc1_DZ : SkinBase {
	usemodel = "Merc1_DZ";
	displayName = "Takistan Bandit Skin";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Merc2_DZ : SkinBase {
	usemodel = "Merc2_DZ";
	displayName = "Mercenary Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Merc3_DZ : SkinBase {
	usemodel = "Merc3_DZ";
	displayName = "Scout Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Merc4_DZ : SkinBase {
	usemodel = "Merc4_DZ";
	displayName = "Mercenary Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Merc5_DZ : SkinBase {
	usemodel = "Merc5_DZ";
	displayName = "Mercenary Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};



class Skin_BlackOps1_DZ : SkinBase {
	usemodel = "BlackOps1_DZ";
	displayName = "BlackOps Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_BlackOps2_DZ : SkinBase {
	usemodel = "BlackOps2_DZ";
	displayName = "BlackOps Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_BlackOps3_DZ : SkinBase {
	usemodel = "BlackOps3_DZ";
	displayName = "BlackOps Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_BlackOps4_DZ : SkinBase {
	usemodel = "BlackOps4_DZ";
	displayName = "BlackOps Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_BlackOps5_DZ : SkinBase {
	usemodel = "BlackOps5_DZ";
	displayName = "BlackOps Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};




class Skin_Pilot1_DZ : SkinBase {
	usemodel = "Pilot1_DZ";
	displayName = "Pilot Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Pilot2_DZ : SkinBase {
	usemodel = "Pilot2_DZ";
	displayName = "Pilot Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};

class Skin_Gang1_DZ : SkinBase {
	usemodel = "Gang1_DZ";
	displayName = "Gangster Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Gang2_DZ : SkinBase {
	usemodel = "Gang2_DZ";
	displayName = "Gangster Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};
class Skin_Gang3_DZ : SkinBase {
	usemodel = "Gang3_DZ";
	displayName = "Gangster Clothing";
	descriptionShort = "Clothing-Parcel with a used Pre-Outbreak Suit";
};