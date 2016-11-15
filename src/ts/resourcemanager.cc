#include "resourcemanager.h"

FactionVector ResourceManager::m_factions;
TilesetVector ResourceManager::m_tilesets;

const Faction* ResourceManager::LoadFactions(std::string file_dst)
{
	TiXmlDocument m_factionfile;
	if(!m_factionfile.LoadFile(file_dst.c_str()))
	{
		fprintf(stderr, "Error while loading the file: %s\n", m_factionfile.ErrorDesc());
		exit(1);
	}

	int tmp;

	TiXmlElement* root = m_factionfile.RootElement();

	TiXmlElement* faction_element = root->FirstChildElement("faction");

	while(faction_element)
	{
		Faction* faction = new Faction;
		faction->SetName(faction_element->Attribute("name"));

		TiXmlElement* unit_element = faction_element->FirstChildElement("unit");
		while(unit_element)
		{
			Unit* unit = new Unit;
			unit->SetName(unit_element->Attribute("name"));
			unit_element->Attribute("cost", &tmp);
			unit->SetCost(tmp);
			unit_element->FirstChildElement("attributes")->Attribute("hp", &tmp);
			unit->SetHP(tmp);
			unit_element->FirstChildElement("attributes")->Attribute("ap", &tmp);
			unit->SetAP(tmp);

			TiXmlElement* weapon_element = unit_element->FirstChildElement("attributes")->FirstChildElement("weapon");
			while(weapon_element)
			{
				Weapon* weapon = new Weapon;
				weapon->SetName(weapon_element->Attribute("name"));
				weapon_element->Attribute("dmg", &tmp);
				weapon->SetDamage(tmp);
				weapon_element->Attribute("cost", &tmp);
				weapon->SetAPCost(tmp);
				weapon_element->Attribute("distmax", &tmp);
				weapon->SetMaxDist(tmp);
				weapon_element->Attribute("distmin", &tmp);
				weapon->SetMinDist(tmp);

				unit->AddWeapon(weapon);
				weapon = 0;
				weapon_element = weapon_element->NextSiblingElement("weapon");
			};
			faction->AddUnit(unit);
			unit = 0;
			unit_element = unit_element->NextSiblingElement("unit");
		};

		m_factions.push_back(faction);
		faction = 0;
		faction_element = faction_element->NextSiblingElement("faction");
	};
};

const Tileset* ResourceManager::LoadTileset(std::string file_dst, int tile_width, int tile_height)
{

    m_tilesets.push_back(new Tileset(file_dst, tile_width, tile_height));

};
