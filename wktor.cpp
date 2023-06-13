#include <iostream>

template<typename T>
class MyVector
{
	private:
		int m_copacity = 0;
		int m_size = 0;
		T * m_vector = nullptr;
	
	public:
	void PrintArray() const
	{
		for(int i = 0 ;i < m_size; ++i)
		{
			std::cout << m_vector[i] << " ";
		}

		std::cout << "\n";
	}
	
	void reserve(int size)
	{
		if(m_vector == nullptr)
		{
			m_vector = new T[size];
			m_copacity = size;
		}
		else
		{
			T* tmp = new T[size];
			for(int i = 0; i < m_size; ++i)
			{
				tmp[i] = m_vector[i];
			}
			delete[] m_vector;
			m_vector = tmp;
			tmp = nullptr;
		}
	}

	void push_back(const T& elem)
	{

		reserve(1);
		m_vector[m_size] = elem;
		m_size++;

	}

	void insert(int pos, int elem)
	{	
		reserve(1);
	
		for(int i = m_size; i >= pos; --i)
		{
			m_vector[i] = m_vector[i - 1];
		}
		m_vector[pos] = elem;
		m_size++;	
	}

	T at(int pos)
	{
		return m_vector[pos];
	}

	int size()
	{
		return m_size;
	}

	bool empty()const
	{
		if(m_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	int capacity()
	{
		return capacity;
	}

	T operator[](int index)const
	{
		return m_vector[index];
	}

	T& operator[](int index)
	{
		return m_vector[index];
	}
	
};	
int main()
{
	MyVector<int> v;
	v.push_back(1);
	v[0];
	v.PrintArray();
	return 0;
}

