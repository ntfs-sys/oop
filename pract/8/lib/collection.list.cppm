export module collectionslist;
import collectionsapi;
import std;

export template<typename T>
class ListEnumerator : public IEnumerator<T> {
private:
	std::vector<T>& _vec;
	int _index = -1;
public:
	ListEnumerator(std::vector<T>& vec) : _vec(vec){}

    bool MoveNext() override {
		if(_index + 1 < std::static_cast<int>(_vec.size())){
			_index++;
			return 1;
		}
		return 0;
	}
    T Current() override {
		if(_index < 0 || _index >= std::static_cast<int>(_vec.size())){
			throw std::logic_error("invalid iterator position");
		}
		return _vec[_index];
	}
};


export template<typename T>
class List :public ICollection<T> {
private:
	std::vector<T> _collection;
public:
	List() {}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return std::make_unique <ListEnumerator<T>>(_collection);
	}
    int Count() const {
		return _collection.size();
	}
    void Add(const T& item){
		_collection.push_back(item);
	}
    void Clear() {
		_collection.clear();
	}
    bool Contains(const T& item){
		if(std::find(_collection.begin(), _collection.end(), item) != _collection.end()){
			return 1;
		}
		return 0;
	}
	bool Remove(const T& item) override {
    	auto it = std::find(_collection.begin(), _collection.end(), item);
    	if (it != _collection.end()) {
        	_collection.erase(it);
        	return true;
    	}
    	return false;
	}
	int Capacity(){
		return _collection.capacity();
	}
  	void SetCapacity(int capacity){
		_collection.reserve(capacity);
	}

	T& operator[](size_t index) {
    	if (index >= _collection.size()) throw std::out_of_range("Index out of range");
    	return _collection[index];
	}
	const T& operator[](size_t index) const {
    	if (index >= _collection.size()) throw std::out_of_range("Index out of range");
	    return _collection[index];
	}

	void Insert(int index, const T& item) {
    	if (index < 0 || index > static_cast<int>(_collection.size()))
        	throw std::out_of_range("Index out of range");
    	_collection.insert(_collection.begin() + index, item);
	}
	void RemoveAt(int index) override {
    	if (index < 0 || index >= static_cast<int>(_collection.size()))
        	throw std::out_of_range("Index out of range");
    	_collection.erase(_collection.begin() + index);
	}
};