#ifndef Vector_h
#define Vector_h

template<typename T>
class Vector
{
public:
	Vector()
		: m_ptr{ nullptr }
		, m_size{ 0 }
		, m_numElements{ 0 }
		, m_isEmpty{ true }
	{
		std::cout << "[Vector] Se ha creado un Vector\n";
	}

	Vector(const Vector& rhs) noexcept
		: m_ptr{ static_cast<T*>(::operator new(rhs.m_size * sizeof(T))) }
		, m_size{ rhs.m_size }
		, m_numElements{ rhs.m_numElements }
		, m_isEmpty{ rhs.m_isEmpty }
	{
		std::cout << "[Vector] Copy \n";
		std::copy(rhs.m_ptr, rhs.m_ptr + m_size, m_ptr);
	}

	Vector(Vector&& rhs) noexcept
		: m_ptr{ std::exchange(rhs.m_ptr, nullptr) }
		, m_size{ std::exchange(rhs.m_size, 0) }
		, m_numElements{ std::exchange(rhs.m_numElements, 0) }
		, m_isEmpty{ std::exchange(rhs.m_isEmpty, true) }
	{
		std::cout << "[Vector] Move \n";
	}

	Vector& operator = (const Vector& rhs) noexcept
	{
		if (this != &rhs)
		{
			std::cout << "[Vector] Copy assignment\n";
			m_ptr = static_cast<T*>(::operator new(rhs.m_size * sizeof(T)));
			m_size = rhs.m_size;
			std::copy(rhs.m_ptr, rhs.m_ptr + m_size, m_ptr);
			m_numElements = rhs.m_numElements;
			m_isEmpty = rhs.m_isEmpty;
		}

		return *this;
	}

	Vector& operator = (Vector&& rhs) noexcept
	{
		if (this != &rhs)
		{
			std::cout << "[Vector] Move assignment\n";
			m_ptr = std::exchange(rhs.m_ptr, nullptr);
			m_size = std::exchange(rhs.m_size, 0);
			m_numElements = std::exchange(rhs.m_numElements, 0);
			m_isEmpty = std::exchange(rhs.isEmpty, true);
		}

		return *this;
	}

	~Vector()
	{
		delete[] m_ptr;
	}

	const T& operator[] (size_t index) const
	{
		return m_ptr[index];
	}

	T& operator[] (size_t index)
	{
		return m_ptr[index];
	}

	void push_back(const T& element)
	{
		reallocate();
		
		m_ptr[m_numElements++] = element;

		updateEmpty();
	}

	void push_back(T&& element)
	{
		reallocate();

		m_ptr[m_numElements++] = std::move(element);

		updateEmpty();
	}

	void pop_back()
	{
		if (m_numElements > 0)
		{
			m_ptr[m_numElements--].~T();
			updateEmpty();
		}
	}

	template<typename ...Args>
	T& emplace_back(Args&&... args)
	{
		reallocate();

		new(&m_ptr[m_numElements++]) T(std::forward<Args>(args)...); //Para crear elementos in place
		//m_ptr[m_numElements++] = T(std::forward<Args>(args)...);

		updateEmpty();
		return m_ptr[m_numElements];
	}

	bool empty() const
	{
		return m_isEmpty;
	}

	size_t size() const
	{
		return m_numElements;
	}

	void print()
	{
		for (size_t i = 0; i < m_numElements ; i++)
		{
			m_ptr[i].print();
		}
	}

	void clear()
	{
		for (size_t i = 0; i < m_numElements; i++)
		{
			m_ptr[i].~T();
		}

		m_numElements = 0;
	}

private:

	void reallocate()
	{
		if (m_numElements < m_size)
		{
			return;
		}

		if (m_isEmpty)
		{
			m_size = 2;
			m_ptr = static_cast<T*>(::operator new(m_size * sizeof(T)));
			return;
		}

		m_size *= 2;
		allocateMemory();
	}

	void allocateMemory()
	{
		T* nptr = static_cast<T*>(::operator new(m_size * sizeof(T)));
		nptr = std::exchange(m_ptr, nullptr);
		m_ptr = nptr;
	}

	void updateEmpty()
	{
		m_isEmpty = m_numElements == 0;
	}

	T* m_ptr;
	size_t m_size;
	size_t m_numElements;
	bool m_isEmpty;
};

#endif
