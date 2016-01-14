
#ifndef SRC_CONTAINERS_ARRAY1DBOOL_HPP_
#define SRC_CONTAINERS_ARRAY1DBOOL_HPP_

namespace Containers{

	template <size_t _size>
	class Array1D<bool, _size>{
	public:
		class BoolProxy;
		Array1D(bool initialValues = false);
		~Array1D(){}
		BoolProxy at(size_t offset);
		bool at(size_t offset) const;
		BoolProxy operator[](size_t offset);
		bool operator[](size_t offset) const;
		size_t size(){return _size;}
	private:
		uint16_t m_rawContainer[_size/16 +1];
	};

	template <size_t _size>
	class Array1D<bool, _size>::BoolProxy{
	public:
		BoolProxy(size_t offset, uint16_t (&rawContainer)[_size/16+1]):
			m_offset(offset), m_rawContainer(rawContainer){};
		operator bool()const;
		void operator=(bool newValue);

	private:
		const size_t m_offset;
		uint16_t (&m_rawContainer)[_size/16+1];
	};

	template<size_t _size>
	Array1D<bool, _size>::Array1D(bool initialValues){
		LOG_INFO("");
		for(size_t currentIdx=0; currentIdx<(_size/16+1); ++currentIdx){
			m_rawContainer[currentIdx] = initialValues ? 0xFFFF : 0x0000;
		}
	}

	template<size_t _size>
	typename Array1D<bool, _size>::BoolProxy Array1D<bool, _size>::at(size_t offset){
		LOG_INFO("");
		return BoolProxy(offset, m_rawContainer);
	}

	template<size_t _size>
	bool Array1D<bool, _size>::at(size_t offset) const{
		LOG_INFO("");
		size_t containerOffset = offset/_size;
		size_t containerOffsetMod = offset%_size;
		return m_rawContainer[containerOffset] & (1<<containerOffsetMod);
	}

	template<size_t _size>
	typename Array1D<bool, _size>::BoolProxy Array1D<bool, _size>::operator[](size_t offset){
		LOG_INFO("");
		return BoolProxy(offset, m_rawContainer);
	}

	template<size_t _size>
	bool Array1D<bool, _size>::operator[](size_t offset) const{
		LOG_INFO("");
		size_t containerOffset = offset/_size;
		size_t containerOffsetMod = offset%_size;
		return m_rawContainer[containerOffset] & (1<<containerOffsetMod);
	}

	template<size_t _size>
	Array1D<bool, _size>::BoolProxy::operator bool() const {
		LOG_INFO("");
		size_t containerOffset = m_offset/_size;
		size_t containerOffsetMod = m_offset%_size;
		return m_rawContainer[containerOffset] & (1<<containerOffsetMod);
	}

	template <size_t _size>
	void Array1D<bool, _size>::BoolProxy::operator=(bool newValue){
		LOG_INFO("");
		size_t containerOffset = m_offset/_size;
		size_t containerOffsetMod = m_offset%_size;
		if(newValue)
			m_rawContainer[containerOffset] |= 1<<containerOffsetMod;
		else
			m_rawContainer[containerOffset] &= ~(1<<containerOffsetMod);
	}

}



#endif /* SRC_CONTAINERS_ARRAY1DBOOL_HPP_ */
