class String {
private:
    char* _data = nullptr;
    size_t _size = 0;
    
    void copy_from(const char* str){
    	_size = std::strlen(str);
    	_data = new char[_size+1];
    	std::strcpy(_data, str);
    }
    
public:
    String() = default;
    String(const char* str){
    	copy_from(str);
    };               
    String(const String& other){
    	copy_from(other._data);
    }
    String(String&& other) noexcept {
    	_data = other._data;
    	_size = other._size;
    	other._data = nullptr;
    	other._size = 0;
    }
    
    
    ~String(){
    	delete[] _data;
    	_data = nullptr;
    	_size = 0;
    }
    

    String& operator=(const String& other){
    	if (_data != other._data){
    		delete[] _data;
    		copy_from(other._data);
    	}
    	return *this;
    }
    String& operator=(String&& other) noexcept {
    	if(_data != other._data){
    		_data = other._data;
    		_size = other._size;
    		other._data = nullptr;
    		other._size = 0;
    	}
    	return *this;
    }

    const char* data(){ return _data; }

    size_t size() const { return _size; }
/*  
    char& operator[](size_t index){
    	return index < _size ? _data[index] : throw std::out_of_range();
    }
    const char& operator[](size_t index) const{
	   	return index < _size ? _data[index] : throw std::out_of_range();
    }
*/

    template<typename Self>
    auto&& operator[](this Self&& self, size_t index) {
    	return std::forward<Self>(self)._data[index];
    }
};



template<>
struct std::formatter<String> : formatter<string_view> {
	auto format(const String& s, format_context& ctx) const {
		return formatter<string_view>::format({s.data(), s.size()}, ctx);
	}
};

class StringBuilder{
private:
	std::string _buffer;
public:
	StringBuilder() = default;
	void reserve(int bytes){
		_buffer.reserve(bytes);
	}
	StringBuilder& append(const std::string& str){
		_buffer += str;
		return *this;
	}
	StringBuilder& append(int i){
		_buffer += std::to_string(i);
		return *this;
	}
	StringBuilder& append(float f){
		_buffer += std::to_string(f);
		return *this;
	}
	std::string build() &{
		return _buffer;
	}
	std::string build() &&{
		return std::move(_buffer);
	}
};

int main() {

    std::println("String");
        String empty;
    std::println("Пустая строка: '{}'", empty);

    String hello("Hello");
    std::println("hello: '{}'", hello);

    String copy = hello;
    std::println("copy: '{}'", copy);
    
    String moved = std::move(copy);
    std::println("moved: '{}'", moved);
    std::println("copy после перемещения: '{}'", copy);
    
    hello[0] = 'J';
    std::println("hello после замены [0]: '{}'", hello);
    
    std::println("Размер hello: {}", hello.size());
    
    std::println("\nStringBuilder");
    
    StringBuilder sb1;
    sb1.append("Ответ: ").append(42);
    std::string result1 = sb1.build();
    std::println("sb1.build(): '{}'", result1);
    std::println("sb1 всё ещё можно использовать: '{}'", sb1.build());
    
    StringBuilder sb2;
    sb2.append("Pi ≈ ").append(3.14159f);
    std::string result2 = std::move(sb2).build();
    std::println("std::move(sb2).build(): '{}'", result2);
    
    std::string result3 = StringBuilder()
        .append("Временный ")
        .append("объект ")
        .append(2024)
        .build();
    std::println("Временный StringBuilder: '{}'", result3);
    
    StringBuilder sb3;
    sb3.reserve(100);
    sb3.append("Зарезервировано 100 байт");
    std::println("sb3: '{}'", sb3.build());
    
    return 0;
}