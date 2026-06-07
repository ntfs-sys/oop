export module collectionsdictionary;
import collectionsapi;
import std;


export template<typename TKey, typename TValue>
class DictionaryEnumerator : public IEnumerator<std::pair<const TKey, TValue>> {
	typename std::unordered_map<TKey, TValue>::const_iterator _iter;
	typename std::unordered_map<TKey, TValue>::const_iterator _end;
	bool isfirst=true;
public:
	DictionaryEnumerator(const std::unordered_map<TKey, TValue>& map) {
		_iter = map.begin();
		_end = map.end();
	}
	bool MoveNext() {
		if (isfirst) {
			isfirst = false;
			return _iter != _end;
		}
		_iter++;
		return _iter!=_end;
	}

	const std::pair<const TKey, TValue>& Current() const {
		if (_iter == _end) {
			throw std::out_of_range("Конец множества");
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
			return _map.contains(item.first);
		}
		bool Remove(std::pair<const TKey, TValue> item) override {
			if (_map.contains(item.first)) {
				_map.erase(item.first);
				return true;
			}
			return false;
		}
		int Capacity() const {
			return _map.bucket_count();

		}
		void SetCapacity(int capacity) {
			if (capacity <= 0) {
				throw std::invalid_argument("Неверный аргумент");
			}
			_map.reserve(capacity);

		}
		TValue operator[](const TKey & key) const {
			if (!_map.contains(key)) {
				throw std::invalid_argument("Такого ключа не существует");

			}
			return _map.at(key);
		}

		TValue& operator[](const TKey & key) {
			if (!_map.contains(key)) {
				throw std::invalid_argument("Такого ключа не существует");

			}
			return _map.at(key);
		}
		std::unique_ptr<IEnumerator<std::pair<const TKey, TValue>>> GetEnumerator() const override {
			return std::make_unique <DictionaryEnumerator<TKey, TValue>>(_map);
		}
};
