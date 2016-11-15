/*
* Copyright (C) 2007 Leonard Fischer (Crimson-Skies@gmx.de)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef Unit_H
#define Unit_H

#include <vector>
#include <string>
#include "weapon.h"

typedef std::vector<Weapon*> WeaponVector;
typedef std::vector<Weapon*>::iterator WeaponVectorIterator;

class Unit
{
	public:
		Unit(std::string name, int hp, int ap, int cost, WeaponVector weapons):
		m_name(name),
		m_hp(hp),
		m_ap(ap),
		m_cost(cost),
		m_weapons(weapons){};

		Unit(){};

		~Unit(){ for(WeaponVectorIterator iter = m_weapons.begin();iter != m_weapons.end();iter++) delete *iter;};

		int GetHP() const {return m_hp;};
		int GetAP() const {return m_ap;};
		int GetCost() const {return m_cost;};
		std::string GetName() const {return m_name;};

		void SetHP(int x) {m_hp = x;};
		void SetAP(int x) {m_ap = x;};
		void SetCost(int x) {m_cost = x;};
		void SetName(std::string name) {m_name = name;};

		void AddWeapon(Weapon* weapon){m_weapons.push_back(weapon);};
		int GetNumberOfWeapons(){return m_weapons.size();};
		Weapon* GetWeaponByID(int id){return m_weapons.at(id); };

	protected:
		std::string m_name;
		int m_hp;
		int m_ap;
		int m_cost;
		WeaponVector m_weapons;
};

#endif
