#pragma once

template<typename T>
class VectorMediana
{
public:
	VectorMediana()
		: m_ptr{ static_cast<T*>(::operator new(SIZE * sizeof(T))) }
		, m_mediana{ static_cast<T*>(::operator new(sizeof(T))) }
		, m_index{ 0 }
		, m_medianaIndex{ 0 }
	{}

	void addElement(const T& element)
	{
		m_ptr[m_index++] = element;
		calculateMediana();
	}

	void addElement(T&& element)
	{
		m_ptr[m_index++] = std::move(element);
		calculateMediana();
	}

	T getMediana() const
	{
		return *m_mediana;
	}

private:
	void calculateMediana()
	{
		if (m_index == 1)
		{
			m_medianaIndex = 0;
			*m_mediana = m_ptr[0];
			return;
		}

		bool isIndexPair{ m_index % 2 == 0};
		if (isIndexPair)
		{
			*m_mediana = m_ptr[m_medianaIndex + 1] + m_ptr[m_medianaIndex];
		}
		else
		{
			*m_mediana = m_ptr[++m_medianaIndex];
		}
	}

	T* m_ptr;
	T* m_mediana;
	size_t m_index; 
	size_t m_medianaIndex;
	static const size_t SIZE = 100;
};