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
#include <functional>
#include <cmath>
#include "enginebase.h"
//////////////////////////////////////////////////
// Fuzzy set programs
//////////////////////////////////////////////////

namespace nesjoker 
{
namespace fuzzy
{

template<typename C, typename S>
class FuzzyFunctorLittleF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorLittleF() {};

	int func(void *x,void *y) {
		return (1.3 / std::sqrt((float)*x));	
	}

};

#define make_littlef make_functor<FuzzyFunctorLittleF<void,void> >

/*template<typename F> typedef typename std::mem_fun_t<void,F> make_littlef<FuzzyFunctorLittleF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/
template<typename C, typename S>
class FuzzyFunctorSlightlyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorSlightlyF() {};

	int func(void *x,void *y) {
		return (1.7 / std::sqrt((float)*x));	
	}

};

#define make_slightlyf make_functor<FuzzyFunctorSlightlyF<void,void> >
/*std::mem_fun_t make_slightlyf<FuzzyFunctorSlightlyF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/
template<typename C, typename S>
class FuzzyFunctorVeryF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorVeryF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x);	
	}

};

#define make_veryf make_functor<FuzzyFunctorVeryF<void,void> > 
/*std::mem_fun_t make_veryf<FuzzyFunctorVeryF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/

template<typename C, typename S>
class FuzzyFunctorExtremelyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorExtremelyF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x * (float)*x);	
	}

};

#define make_extremelyf make_functor<FuzzyFunctorExtremelyF<void,void> > 
/*
std::mem_fun_t make_extrmelyf<FuzzyFunctorExtremelyF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/
template<typename C, typename S>
class FuzzyFunctorVeryVeryF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorVeryVeryF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x * (float)*x * (float)*x);	
	}

};

#define make_veryveryf make_functor<FuzzyFunctorVeryVeryF<void,void> > 

/*
std::mem_fun_t make_veryf<FuzzyFunctorVeryVeryF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/

template<typename C, typename S>
class FuzzyFunctorMoreOrLessF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorMoreOrLessF() {};

	int func(void *x,void *y) {
		return (std::sqrt((float)*x));	
	}

};

#define make_moreorlessf make_functor<FuzzyFunctorMoreOrLessF<void,void> > 

/*
std::mem_fun_t make_veryf<FuzzyFunctorMoreOrLessF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/

template<typename C, typename S>
class FuzzyFunctorSomewhatF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorSomewhatF() {};

	int func(void *x,void *y) {
		return (std::sqrt((float)*x));	
	}

};

#define make_somewhatf make_functor<FuzzyFunctorSomewhatF<void,void> > 

/*
std::mem_fun_t make_veryf<FuzzyFunctorSomewhatF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/

} //namespace fuzzy
} //namespace nesjoker
