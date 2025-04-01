#pragma once

template <typename T>
requires std :: floating_point <T>
class complex_number
{
	private : 
		T parte_reale, parte_immaginaria;
		
	public:
		complex_number() : parte_reale(0), parte_immaginaria(0) {}  /*Costruttore di default*/
		
		explicit complex_number(T r) : parte_reale(r), parte_immaginaria(0)
		{
			std :: cout << "Converting constructor called" << std :: endl;
		}
		
		complex_number(T r, T i) : parte_reale(r), parte_immaginaria(i) {}
		
		operator T() const {
			
        if (parte_immaginaria == 0) {
			
            return parte_reale;
			
			}
        
		}
		
		T real(void) const {
			
			return parte_reale;
			
		}
		
		T imag(void) const {
			
			return parte_immaginaria;
			
		}
		
		complex_number<T> coniugato () const
		{
			
			return complex_number<T>(parte_reale,-parte_immaginaria);

		}
			
		
		complex_number& operator += (const complex_number& other) {
	
			parte_reale += other.parte_reale;
			parte_immaginaria += other.parte_immaginaria;
	
		return *this;
	
		}


		complex_number& operator *= (const complex_number& other) {
	
			T p_r = parte_reale * other.parte_reale - parte_immaginaria* other.parte_immaginaria;
			T p_i = parte_reale * other.parte_immaginaria + parte_immaginaria * other.parte_reale;
			parte_reale = p_r;
			parte_immaginaria = p_i;
	
			return *this; 
	
		}
};

template <typename T> complex_number<T>
operator+(const complex_number<T>& c1, const complex_number<T>& c2)
{
	return complex_number<T>(c1.real() + c2.real(), c1.imag() + c2.imag());
}

template <typename T> complex_number<T>
operator*(const complex_number<T>& c1,const complex_number<T>& c2)
{
	T real_part = c1.real() * c2.real() - c1.imag() * c2.imag();
	T imag_part = c1.real() * c2.imag() + c1.imag() * c2.real();
	
	return complex_number<T>(real_part,imag_part);
}

template <typename T>
complex_number<T> operator+(const T& number, const complex_number<T>& c) 
{
	
	return complex_number<T>(number + c.real() , c.imag());
	
}

template <typename T>
complex_number<T> operator*(const T& number, const complex_number<T>& c) 
{
	
	return complex_number<T>(number * c.real(), number * c.imag());

}

template <typename T> std :: ostream&
operator << (std::ostream& os, const complex_number<T>& c){

	os << c.real() ;
	
	if (c.imag() != 0) 
	{
		
		if (c.imag() > 0)
		{
			
			os << "+" ;
			
		}
		
		if (c.imag() == 1)
		{	
	
			os <<"i";
			
		}
		
		else if (c.imag() == -1)
		{
			
			os << "-i";
			
		}
		
		else{
			
		os <<  c.imag() << "i";
	
		}
		
	}

	return os;

}