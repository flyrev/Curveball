#ifndef __ARRAY_CLASS_H
#define __ARRAY_CLASS_H

#include <cstdlib>
#include <cmath>

typedef unsigned int size_t;

template <class T>
class Array
{
	T* data;
	size_t m_size, m_capacity;
public:
	Array()
		: data(0)
		, m_size(0)
		, m_capacity(0)
	{}
	Array( const Array& other)
	{
		reserve( other.capacity);
		for (int  i = 0; i < other.m_size; i++)
			data[i] = other.data[i];
		
		size = other->size;
	}

	Array( size_t size )
	{
		reserve(size);
		size = 0;
	}

	void reserve( size_t capacity )
	{
		m_capacity = capacity;
		m_size = (m_size <= m_capacity ? m_size : m_capacity);

		T* temp = data;
		data = new T[capacity];

		if ( temp )
		{
			for (int i = 0; i < m_size; i++)
				data[i] = temp[i];
			delete temp;
		}
	}

	const T* getData() const
	{
		return data;
	}

	T* getData() 
	{
		return data;
	}

	operator const T*() const
	{
		return data;
	}

	const T & operator[](size_t pos) const 
	{
		return data[pos];
	}

	T & operator[] ( size_t pos )
	{
		return data[pos];
	}

	void add( const T & obj)
	{
		if (m_size >= m_capacity)
			reserve(m_size + m_size/2 + 1);
		
		data[m_size++] = obj;
	}

	size_t size() const { return m_size; }

	void clear(void)
	{
		reserve(0);
	}

	void clear_dynamic()
	{
		for ( int i = 0; i < m_size; i++)
			if ( data[i] )
				delete data[i];
		reserve(0);
	}
};


#endif
