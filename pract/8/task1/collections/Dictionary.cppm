export module collections:Dictionary;

import std;
import interface;

export template<typename TKey, typename TValue, typename THash, typename TEqual>
class DictionaryEnumerator : public IEnumerator<std::pair<const TKey, TValue>> {
	typename std::unordered_map<TKey, TValue, THash, TEqual>::const_iterator _iter;
	typename std::unordered_map<TKey, TValue, THash, TEqual>::const_iterator _end;
	bool _is_first = true;
public:
	DictionaryEnumerator(const std::unordered_map<TKey, TValue, THash, TEqual>& dictionary) :
		_iter(dictionary.begin()), _end(dictionary.end()) {}

	bool MoveNext() override {
		if (_is_first)
		{
			_is_first = false;
			return _iter != _end;
		}

		++_iter;
		return _iter != _end;
	}

	const std::pair<const TKey, TValue>& Current() const {
		if (_iter == _end) {
			throw std::out_of_range("Выход за пределы");
		}
		return *_iter;
	}
};



export template<typename TKey,
	typename TValue,
	typename THash = std::hash<TKey>,
	typename TEqual = std::equal_to<TKey>>
	class Dictionary final : public ICollection<std::pair<const TKey, TValue>>
{
private:
	std::unordered_map<TKey, TValue, THash, TEqual> _map;
public:
	int Count() const override
	{
		return _map.size();
	}

	void Add(std::pair<const TKey, TValue> pair) override
	{
		_map.insert(pair);
	}

	void Clear() override
	{
		_map.clear();
	}

	bool Contains(std::pair<const TKey, TValue> item) const override
	{
		return _map.contains(item.first);
	}

	bool Remove(std::pair<const TKey, TValue> item) override
	{
		if (Contains(item))
		{
			_map.erase(item.first);
			return true;
		}
		return false;
	}

	int Capacity() const
	{
		return _map.bucket_count();
	}

	void SetCapacity(int capacity)
	{
		_map.reserve(capacity);
	}

	const TValue operator[] (const TKey& key) const
	{
		if (!_map.contains(key))
		{
			throw std::out_of_range("Invalid key");
		}
		return _map[key];
	}

	TValue& operator[](const TKey& key)
	{
		if (!_map.contains(key))
		{
			throw std::out_of_range("Invalid key");
		}

		return _map[key];
	}

	std::unique_ptr<IEnumerator<std::pair<const TKey, TValue>>> GetEnumerator() const override {

		return std::make_unique<DictionaryEnumerator<TKey, TValue, THash, TEqual>>(_map);
	}
};
