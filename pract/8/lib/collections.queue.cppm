export module collectionsqueue;
import collectionsapi;
import std;

export template<typename T>
class QueueEnumerator : public IEnumerator<T> {
	std::queue<T> _queue;
	bool isfirst = true;
public:
	QueueEnumerator(std::queue<T> queue) {
		_queue = queue;
	}
	bool MoveNext() override {
		if (isfirst && !_queue.empty()) {
			isfirst = false;
			return true;
		}
		if (_queue.size()>1) {
			_queue.pop();
			return true;
		}
		return false;
	}
	const T& Current() const override {
		if (_queue.empty()) {
			throw std::out_of_range("got no element");
		}
		return _queue.front();
	}

};


export template<typename T>
class Queue : public IEnumerable<T> {
private:
	std::queue<T> _queue;
public:
	int Count() const
	{
		return _queue.size();
	}
	T Dequeue()
	{
		T element = _queue.front();
		_queue.pop();
		return element;
	}
	T Peek() const
	{
		return _queue.front();
	}
	void Enqueue(T item)
	{
		_queue.push(item);
	}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return make_unique<QueueEnumerator<T>>(_queue);
	}
};