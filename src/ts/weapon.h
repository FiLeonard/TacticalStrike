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

#ifndef Weapon_H
#define Weapon_H

#include <string>

class Weapon
{
	public:
		Weapon(std::string name, int ap_cost, int dmg, int min_d, int max_d):
		m_max_dist(max_d),
		m_min_dist(min_d),
		m_dmg(dmg),
		m_ap_cost(ap_cost),
		m_name(name) {};

		Weapon(){};

		~Weapon(){};


		int GetMaxDist() const {return m_max_dist;};
		int GetMinDist() const {return m_min_dist;};
		int GetAPCost() const {return m_ap_cost;};
		int GetDamage() const {return m_dmg;};
		std::string GetName() const {return m_name;};

		void SetMaxDist(int x) {m_max_dist = x;};
		void SetMinDist(int x) {m_min_dist = x;};
		void SetAPCost(int x) {m_ap_cost = x;};
		void SetDamage(int x) {m_dmg = x;};
		void SetName(std::string name) {m_name = name;};

	private:
		int m_max_dist;
		int m_min_dist;
		int m_dmg;
		int m_ap_cost;
		std::string m_name;
};

#endif
