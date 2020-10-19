#pragma once

#include <vector>
#include <stack>
#include <iostream>


struct Buffer {
	const size_t START_SIZE = 1048576;
	const size_t STEP_SIZE = 32768;

	size_t id;
	size_t nextIndex;
	size_t maxSize;
	int* ptr;

	Buffer(int id) : id(id), nextIndex(0) {
		ptr = (int*) malloc(START_SIZE);
		maxSize = START_SIZE;
	}
	~Buffer() {
		free(ptr);
	}
	void reset() {
		nextIndex = 0;
	}
	void put(int a) {
		if (nextIndex >= maxSize) {
			maxSize += STEP_SIZE;
			void* aux = realloc(ptr, maxSize);
			if (aux == NULL) throw("Cannot reallocate a internal buffer");
			ptr = (int*)aux;
		}
		ptr[nextIndex++] = a;
	}
	int getSize() {
		return nextIndex;
	}
};

class BufferManager {
public:
	~BufferManager() {
		for (int i = 0; i < container.size(); i++) {
			delete container[i];
		}
	}

	BufferManager() : container(START_NUM_BUFFERS) {
		for (int i = 0; i < START_NUM_BUFFERS; i++) {
			container[i] = new Buffer(i);
			freeBuffer.push(i);
		}
	}

	Buffer* get() {
		if (!freeBuffer.empty()) {
			Buffer* a = container[freeBuffer.top()];
			freeBuffer.pop();
			return a;
		}
		else {
			//creatre new container
			int id = container.size();
			container.push_back(new Buffer(id));
			return container[id];
		}
	}

	void free(Buffer* buffer) {
		buffer->reset();
		freeBuffer.push(buffer->id);
	}
private:
	const int START_NUM_BUFFERS = 3;
	std::vector<Buffer*> container;
	std::stack<int> freeBuffer;
};