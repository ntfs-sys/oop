import std;


class ICounter
{
public:
  virtual void increment() = 0;
  virtual void reset() = 0;
  virtual int getValue() const = 0;
  virtual bool IsLimitedReached() const = 0;
  virtual std::string getType() const = 0;
  virtual ~ICounter() = default;
};


class BoundedCounter final : public ICounter {
private:
  int value_ = 0;
  const int max_value_;
public:
  explicit BoundedCounter(int max_value) : max_value_(max_value) {}
  void increment() override {
    if (value_ < max_value_) {
      ++value_;
    }
  }
  void reset() override {
    value_ = 0;
  }
  int getValue() const override {
    return value_;
  }
  bool IsLimitedReached() const override {
    return value_ == max_value_;
  }
  std::string getType() const override {
    return "BoundedCounter(max=" + std::to_string(max_value_) + ")";
  }
};


class CycleCounter : public ICounter
{
  int value = 0;
  int max;

public :
  CycleCounter(int max) : max(max) {}

  int getValue() const override {
    return value;
  }
  void reset() override {
    value = 0;
  }
  void increment() override
  {
    if (IsLimitedReached())
      value = 0;
    else
      value++;
  }
  bool IsLimitedReached() const override {
    return value == max;
  }
  std::string getType() const override
  {
    return "CycleCounter(max=" + std::to_string(max) + ")";
  }
};

class StepCounter final : public ICounter {
private:
  int _value = 0;
  int _step, _maxValue;
public:
  explicit StepCounter(int max, int step) : _step(step), _maxValue(max) {}
    

  void increment() override {
    if (_value < _maxValue) {
      _value = std::min(_value + _step, _maxValue);
    }
  }
  void reset() override {
    _value = 0;
  }
  int getValue() const override {
    return _value;
  }
  bool IsLimitedReached() const override {
    return _value == _maxValue;
  }
  std::string getType() const override {
    return "StepCounter(max=" + std::to_string(_maxValue) + ", step=" + std::to_string(_step) + ")";
  }
};



int main() {
  return 0;
};