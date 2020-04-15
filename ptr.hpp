#ifndef DCDEVELOP_PTR_CLASS
#define DCDEVELOP_PTR_CLASS

#include <stddef.h>

// #define DCDEVELOP_PTR_CLASS_CSTRING

#ifdef DCDEVELOP_PTR_CLASS_CSTRING
#include <cstring>
#endif

namespace dcdevelop {
	namespace parent {
		template <typename T>
		class ptr {
		protected:
			T* raw_pointer;

		public:
			ptr();
			ptr(T* pointer);
			explicit ptr(T& reference);

			T* addr();
			inline T* address();
			operator T*();

			T& deref();
			inline T& dereference();
			explicit operator T&();

			template <typename Result>
			Result& map(Result& (*fp)(T value));

			template <typename Result>
			Result& map_with_default(Result& (*fp)(T value), Result& default_value);

			bool is_null();
			void set_null();

			ptr<T> operator+(ptrdiff_t number);
			ptr<T> next();
			ptr<T>& operator++();
			ptr<T> operator++(int);
			template <typename IncrementType>
			void operator+=(IncrementType number);

			ptrdiff_t operator-(const ptr<T>& other_ptr);
			ptrdiff_t operator-(T* other_pointer);
			ptr<T> operator-(ptrdiff_t number);
			ptr<T> prev();
			ptr<T>& operator--();
			ptr<T> operator--(int);
			template <typename DecrementType>
			void operator-=(DecrementType number);

			template <typename EqualType>
			bool operator==(const EqualType& compareTo);
			bool operator==(const ptr<T>& compareTo);

			template <typename EqualType>
			bool operator!=(const EqualType& compareTo);

			template <typename ComparisonType>
			bool operator>(const ComparisonType& compareTo);
			bool operator>(const ptr<T>& compareTo);

			template <typename ComparisonType>
			bool operator>=(const ComparisonType& compareTo);

			template <typename ComparisonType>
			bool operator<(const ComparisonType& compareTo);

			template <typename ComparisonType>
			bool operator<=(const ComparisonType& compareTo);
		};
	}

	template <typename T>
	class ptr : public parent::ptr<T> {
		using parent::ptr<T>::ptr;
	};

	template<>
	class ptr<char> : public parent::ptr<char> {
		using parent::ptr<char>::ptr;

	public:
		inline char* cstring();
		inline bool is_empty();

		#ifdef DCDEVELOP_PTR_CLASS_CSTRING

		bool operator==(const char*& compareTo);
		bool operator==(const ptr<char>& compareTo);

		bool operator>(const char*& compareTo);

		void copy_to(char* destination);
		inline void copy_to(ptr<char>& destination);

		void replace_with(char* source);
		inline void replace_with(ptr<char>& source);

		void append(char* source);
		inline void append(const ptr<char>& source);
		inline void concat(char* source);
		inline void concat(const ptr<char>& source);

		ptr<char> find(char character);
		ptr<char> find(const char*& cstring);
		inline ptr<char> find(const ptr<char>& cstring);

		ptr<char> find_any(const char*& cstring);
		inline ptr<char> find_any(const ptr<char>& cstring);

		ptr<char> find_last(char character);
		
		size_t span_until(const char*& cstring);
		size_t span_until(const ptr<char>& cstring);
		
		size_t span_containing(const char*& cstring);
		size_t span_containing(const ptr<char>& cstring);

		size_t length();

		#endif
	};

	#ifdef DCDEVELOP_PTR_CLASS_CSTRING

	class ptr_char_raw : public parent::ptr<char> {
		using parent::ptr<char>::ptr;
	};

	#else

	typedef ptr<char> ptr_char_raw;

	#endif
}

#include "ptr.cpp"

#endif