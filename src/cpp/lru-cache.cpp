/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
struct Rec{
	int key;
	int value;
};

class LRUCache{
private:
	Rec * buffer;
	int size;
	int curSize;
public:
	LRUCache(int capacity) {
		size = capacity;
		buffer = new Rec[size];
		curSize = 0;
	}
	~LRUCache(){
		if (size > 0)
			delete[] buffer;
	}
	int get(int key) {
		int index=-1;
		for (int i = 0; i < curSize; i++){
			if (buffer[i].key == key){
				index = i;
				break;
			}
		}
		if (index == -1)
			return -1;
		Rec tmp = buffer[index];
		for (int i = index - 1; i >= 0; i--)
			buffer[i + 1] = buffer[i];
		buffer[0] = tmp;
		return tmp.value;
	}
	void set(int key, int value) {
		if (size <= 0)
			return;
		int index = -1;
		for (int i = 0; i < curSize; i++){
			if (buffer[i].key == key){
				buffer[i].value = value;
				index = i;
				break;
			}
		}
		if (index == -1){
			Rec record; record.key = key; record.value = value;
			if (curSize < size){
				buffer[curSize++] = record;
			}
			else buffer[size - 1] = record;
			index = curSize - 1;
		}
		Rec tmp = buffer[index];
		for (int i = index - 1; i >= 0; i--)
			buffer[i + 1] = buffer[i];
		buffer[0] = tmp;
	}
};
