#pragma once

#include <memory>
#include <string>

class Entity {
	friend class EntityManager;

	bool m_active = true;
	size_t m_id = 0;
	std::string m_tag = "default";

	// constructor and destructor
	Entity(const size_t id, const std::string& tag);

public:

	// private member access functions
	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();
};
