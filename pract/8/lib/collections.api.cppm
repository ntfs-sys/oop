export module collections.api;

import std;

export template<typename T>
class IEnumerator {
public:
    virtual bool MoveNext() = 0;
    virtual T Current() = 0;
    virtual ~IEnumerator() = default;
};

export template<typename T>
class IEnumerable {
public:
    virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() = 0;
    virtual ~IEnumerable() = default;
};

export template<typename T>
class ICollection : public IEnumerable<T> {
public:
    virtual int Count() const = 0;
    virtual void Add(const T& item) = 0;
    virtual void Clear() = 0;
    virtual bool Contains(const T& item) const = 0;
    virtual bool Remove(const T& item) = 0;
    virtual ~ICollection() = default;
};