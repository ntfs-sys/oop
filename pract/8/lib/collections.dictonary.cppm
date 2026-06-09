export module collectionsdictionary;
import collectionsapi;
import std;


export template<typename TKey, typename TValue>
class DictionaryEnumerator : public IEnumerator<std::pair<const TKey, TValue>> {
private:
	typename std::unordered_map<TKey, TValue>::const_iterator _iter;
	typename std::unordered_map<TKey, TValue>::const_iterator _end;
	bool _isfirst=true;
public:
	DictionaryEnumerator(const std::unordered_map<TKey, TValue>& map) {
		_iter=map.begin();
		_end=map.end();
	}
	bool MoveNext(){
		if(_isfirst){
			_isfirst = 0;
			return _iter != _end;
		}
		_iter++;
		return _iter != _end;
	}
	const std::pair<const TKey, TValue>& Current() const {
		if(_iter == _end){
			throw std::out_of_range("end of dictonary");
		}
		return *_iter;
	}
};


export template<typename TKey, typename TValue, typename Hash = std::hash<TKey>,
	typename Equal = std::equal_to<TKey>>
	class Dictionary : public ICollection<std::pair<const TKey, TValue>> {
	private:
		std::unordered_map<TKey, TValue, Hash, Equal> _map;
	public:
		int Count() const override {
			return _map.size();
		}
		void Add(std::pair<const TKey, TValue> item) override {
			_map.insert(item);
		}
		void Clear() override {
			_map.clear();
		}
		bool Contains(std::pair<const TKey, TValue> item) const override {
			auto it = _map.find(item.first);
			return it != _map.end() && it->second == item.second;
		}
		bool Remove(std::pair<const TKey, TValue> item) override {
			if(Contains(item)){
				_map.erase(item.first);
				return 1;
			}
			else return 0;
		}
		int Capacity() const {
			return _map.bucket_count();
		}
		void SetCapacity(int capacity) {
			_map.reserve(capacity);
		}
		TValue operator[](const TKey & key) const {
			if(_map.contains(key)){
				return _map.at(key);
			}
			throw std::out_of_range("not in dictonary");
		}
		TValue& operator[](const TKey & key) {
			if(_map.contains(key)){
				return _map.at(key);
			}
			throw std::out_of_range("not in dictonary");
		}
		std::unique_ptr<IEnumerator<std::pair<const TKey, TValue>>> GetEnumerator() const override {
			return std::make_unique<DictionaryEnumerator<TKey, TValue>>(_map);
		}
};
