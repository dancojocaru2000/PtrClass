#include "ptr.hpp"

namespace dcdevelop {
	namespace parent {
		template <typename T>
		ptr<T>::ptr() {
			this->raw_pointer = nullptr;
		}

		template <typename T>
		ptr<T>::ptr(T* pointer) {
			this->raw_pointer = pointer;
		}

		template <typename T>
		ptr<T>::ptr(T& reference) {
			this->raw_pointer = &reference;
		}

		template <typename T>
		T* ptr<T>::addr() {
			return this->raw_pointer;
		}

		template <typename T>
		T* ptr<T>::address() {
			return this->addr();
		}
		
		template <typename T>
		ptr<T>::operator T *() {
			return this->raw_pointer;
		}

		template <typename T>
		T& ptr<T>::deref() {
			return *(this->raw_pointer);
		}

		template <typename T>
		T& ptr<T>::dereference() {
			return this->deref();
		}
		
		template <typename T>
		ptr<T>::operator T &() {
			return *(this->raw_pointer);
		}

		template <typename T>
		template <typename Result>
		Result& ptr<T>::map(Result& (*fp)(T value)) {
			return (*fp)(this->deref());
		}

		template <typename T>
		template <typename Result>
		Result& ptr<T>::map_with_default(Result& (*fp)(T value), Result& default_value) {
			if (this->is_null()) {
				return default_value;
			}
			else {
				return (*fp)(this->deref());
			}
		}

		template <typename T>
		bool ptr<T>::is_null() {
			return this->raw_pointer == nullptr;
		}

		template <typename T>
		void ptr<T>::set_null() {
			this->raw_pointer = nullptr;
		}

		template <typename T>
		ptr<T> ptr<T>::operator+(ptrdiff_t number) {
			return this->raw_pointer + number;
		}

		template <typename T>
		ptr<T> ptr<T>::next() {
			return *this + 1;
		}

		template <typename T>
		ptr<T>& ptr<T>::operator++() {
			this->raw_pointer + 1;
			return *this;
		}

		template <typename T>
		ptr<T> ptr<T>::operator++(int) {
			auto copy = *this;
			this->raw_pointer + 1;
			return copy;
		}

		template <typename T>
		template <typename IncrementType>
		void ptr<T>::operator+=(IncrementType number) {
			this->raw_pointer += number;
		}

		template <typename T>
		ptrdiff_t ptr<T>::operator-(const ptr<T>& other_ptr) {
			return this->raw_pointer - other_ptr.raw_pointer;
		}

		template <typename T>
		ptrdiff_t ptr<T>::operator-(T* other_pointer) {
			return this->raw_pointer - other_pointer;
		}

		template <typename T>
		ptr<T> ptr<T>::operator-(ptrdiff_t number) {
			return this->raw_pointer - number;
		}

		template <typename T>
		ptr<T> ptr<T>::prev() {
			return *this - 1;
		}

		template <typename T>
		ptr<T>& ptr<T>::operator--() {
			this->raw_pointer - 1;
			return *this;
		}

		template <typename T>
		ptr<T> ptr<T>::operator--(int) {
			auto copy = *this;
			this->raw_pointer - 1;
			return copy;
		}

		template <typename T>
		template <typename DecrementType>
		void ptr<T>::operator-=(DecrementType number) {
			this->raw_pointer -= number;
		}

		template <typename T>
		bool ptr<T>::operator==(T*& compareTo) {
			return this->raw_pointer == compareTo;
		}

		template <typename T>
		template <typename EqualType>
		bool ptr<T>::operator==(EqualType& compareTo) {
			return this->raw_pointer == (T*)compareTo;
		}

		template <typename T>
		bool ptr<T>::operator==(ptr<T>& compareTo) {
			return this->raw_pointer == compareTo.raw_pointer;
		}

		template <typename T>
		template <typename EqualType>
		bool ptr<T>::operator!=(const EqualType& compareTo) {
			return *this != compareTo;
		}

		template <typename T>
		template <typename ComparisonType>
		bool ptr<T>::operator>(const ComparisonType& compareTo) {
			return this->raw_pointer > compareTo;
		}

		template <typename T>
		bool ptr<T>::operator>(const ptr<T>& compareTo) {
			return this->raw_pointer > compareTo.raw_pointer;
		}

		template <typename T>
		template <typename ComparisonType>
		bool ptr<T>::operator>=(const ComparisonType& compareTo) {
			return *this == compareTo || *this > compareTo;
		}

		template <typename T>
		template <typename ComparisonType>
		bool ptr<T>::operator<(const ComparisonType& compareTo) {
			return !(*this >= compareTo);
		}

		template <typename T>
		template <typename ComparisonType>
		bool ptr<T>::operator<=(const ComparisonType& compareTo) {
			return !(*this > compareTo);
		}

	}

	char* ptr<char>::cstring() {
		return this->addr();
	}

	bool ptr<char>::is_empty() {
		return this->is_null();
	}

	#ifdef DCDEVELOP_PTR_CLASS_CSTRING

	bool ptr<char>::operator==(const ptr<char>& compareTo) {
		return this->operator==(compareTo.raw_pointer);
	}

	bool ptr<char>::operator==(const char*& compareTo) {
		return strcmp(this->raw_pointer, compareTo);
	}

	bool ptr<char>::operator>(const char*& compareTo) {
		return strcmp(this->raw_pointer, compareTo) > 0;
	}

	void ptr<char>::copy_to(char* destination) {
		strcpy(destination, this->raw_pointer);
	}

	void ptr<char>::copy_to(ptr<char>& destination) {
		this->copy_to(destination.raw_pointer);
	}

	void ptr<char>::replace_with(char* source) {
		strcpy(this->raw_pointer, source);
	}

	void ptr<char>::replace_with(ptr<char>& source) {
		this->replace_with(source.raw_pointer);
	}

	void ptr<char>::append(char* source) {
		strcat(this->raw_pointer, source);
	}

	void ptr<char>::append(const ptr<char>& source) {
		this->append(source.raw_pointer);
	}

	void ptr<char>::concat(char* source) {
		this->append(source);
	}

	void ptr<char>::concat(const ptr<char>& source) {
		this->append(source);
	}

	ptr<char> ptr<char>::find(char character) {
		return strchr(this->raw_pointer, character);
	}

	ptr<char> ptr<char>::find(const char*& cstring) {
		return strstr(this->raw_pointer, cstring);
	}

	ptr<char> ptr<char>::find(const ptr<char>& cstring) {
		return this->find(cstring.raw_pointer);
	}

	ptr<char> ptr<char>::find_any(const char*& cstring) {
		return strpbrk(this->raw_pointer, cstring);
	}

	ptr<char> ptr<char>::find_any(const ptr<char>& cstring) {
		return this->find_any(cstring.raw_pointer);
	}

	ptr<char> ptr<char>::find_last(char character) {
		return strrchr(this->raw_pointer, character);
	}

	size_t ptr<char>::span_containing(const char*& cstring) {
		return strspn(this->raw_pointer, cstring);
	}

	size_t ptr<char>::span_containing(const ptr<char>& cstring) {
		return this->span_containing(cstring.raw_pointer);
	}

	size_t ptr<char>::span_until(const char*& cstring) {
		return strcspn(this->raw_pointer, cstring);
	}

	size_t ptr<char>::span_until(const ptr<char>& cstring) {
		return this->span_until(cstring.raw_pointer);
	}

	size_t ptr<char>::length() {
		return strlen(this->raw_pointer);
	}

	#endif
}