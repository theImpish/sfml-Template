#include "EntityManager.h"

EntityManager::EntityManager()
{

}

void EntityManager::update()
{
	// TODO: add entities from m_entitiesToAdd the proper location(s)
	//		 - add them to the vector ao all entities
	//		 - add them to the vector inside the map, with the tag as a key
	for (std::shared_ptr<Entity> e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}

	m_entitiesToAdd.clear();

	// remove dead entities from the vector of all entities
	removeDeadEntities(m_entities);

	// remove dead entities from each vector in the entity map
	// C++17 way of iterating through [key,value] pairs in a map
	for (auto& [tag, entityVec] : m_entityMap)
	{
		removeDeadEntities(entityVec);
	}
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
	vec.erase(
		std::remove_if(vec.begin(), vec.end(), [](auto e) {return !e->isActive(); })
		, vec.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

	m_entitiesToAdd.push_back(entity);

	return entity;
}

const EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag)
{
	// TODO: this is incorrect, return the correct vector from the map

	if (m_entityMap.find(tag) != m_entityMap.end())
	{
		return m_entityMap.find(tag)->second;
	}
	else
	{
		EntityVec empty;
		return empty;
	}

}
