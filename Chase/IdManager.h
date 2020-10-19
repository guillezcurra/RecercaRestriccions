#pragma once

#include <vector>
#include <map>

template<class T>
class IdManager {
public:
	int addObj(const T& obj) {
		int id = toId(obj);
		if (id != -1) return id;
		idToObj.push_back(obj);
		objToId[obj] = nextId;
		return nextId++;
	}

	T& toObj(int id) {
		return idToObj[id];
	}
	
	int toId(T obj) {
		auto it = objToId.find(obj);
		if (it != objToId.end()) {
			return it->second;
		}
		return -1;
	}

	int getNum() {
		return nextId;
	}
private:
	std::vector<T> idToObj;
	std::map<T, int> objToId;
	int nextId = 0;
};
