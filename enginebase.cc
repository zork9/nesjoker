/*
# Copyright (C) Johan Ceuppens 2013
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <list>
#include <algorithm>
#include <functional>

template<class T>
class Lambda
{
	Lambda() {};

	virtualvoid operator() (T const& x)
	{
		v.push_back(x.get_returncode());
	}	

	std::list<int> v;
};

template<class CPU, class LAMBDA, class R>
std::list<R> executelambda(CPU/*<LAMBDA const&>*/ const& cpu) {
	LAMBDA& lamb = cpu.get_lambda();	
	lamb(const_cast<CPU&>(cpu));
	R& returncode = const_cast<CPU&>(cpu).get_returncode();
	std::list<R> v;
	v.push_back(returncode);
	return v;
}

template<class CPU, class LAMBDA>
int execute(std::list<CPU const& > const& cpul, LAMBDA const& lambda) {
	for_each (const_cast<std::list<CPU const&> >(cpul).begin(), const_cast<CPU&>(cpul).end(), const_cast<LAMBDA&>(lambda)());
};

template<class CPU>
int add(std::list<CPU const&> const& cpul, CPU cpu) {
	const_cast<std::list<CPU const&> >(cpul).push_front(cpu);
	return const_cast<CPU&>(cpu).returncode();
};

//////////////////////////////////////////////////
// Fuzzy set programs
//////////////////////////////////////////////////

template<typename C, typename S>
class FuzzyFunctor : public Lambda<S>
{
public:
	FuzzyFunctor(void*(fun*)(void*,void*)) : func(fun) {};

	void operator() (S const& x)
	{
		super.operator(const_cast<S&>(x));
		return apply(this, const_cast<S&>(x));	
	}	
	void apply(FuzzyFunctor const& ff, S const& x)
	{
		func(x,ff);
	}
		
	int (func*)(void *,void *);//FIX use mem_fun_ptr	
};

template<typename C, typename S>
class FuzzyFunctorMem : public Lambda<S>
{
public:
	FuzzyFunctorMem() {};

	virtual void operator() (S const& x)
	{
		super.operator(const_cast<S&>(x));
		return apply(this, const_cast<S&>(x));	
	}	
	virtual void apply(FuzzyFunctor const& ff, S const& x)
	{
		func(x,ff);
	}
		
	virtual int func(void *,void *) {
		std::cerr << "Subclass responsability" << std::endl;
		//subclass responsability	
	}

};

template<class F>
mem_fun_t make_functor(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};


