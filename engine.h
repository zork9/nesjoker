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

#define make_functor<FuzzyFunctorLittleF<void,void> > make_littlef

template<typename C, typename S>
class FuzzyFunctorSlightlyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorSlightlyF() {};

	int func(void *x,void *y) {
		return (1.7 / std::sqrt((float)*x));	
	}

};

#define make_functor<FuzzyFunctorSlightlyF<void,void> > make_slightlyf

template<typename C, typename S>
class FuzzyFunctorVeryF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorVeryF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x);	
	}

};

#define make_functor<FuzzyFunctorVeryF<void,void> > make_veryf


template<typename C, typename S>
class FuzzyFunctorExtremelyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorExtremelyF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x * (float)*x);	
	}

};
#define make_functor<FuzzyFunctorExtremelyF<void,void> > make_extremelyf
/*
std::mem_fun_t make_veryf<FuzzyFunctorExtremelyF>(std::mem_fun_t f, void *b, void *c) {
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
#define make_functor<FuzzyFunctorVeryVeryF<void,void> > make_veryveryf
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

#define make_functor<FuzzyFunctorMoreOrLessF<void,void> > make_moreorlessf
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

#define make_functor<FuzzyFunctorSomewhatF<void,void> > make_somewhatf
/*
std::mem_fun_t make_veryf<FuzzyFunctorSomewhatF>(std::mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};
*/

} //namespace fuzzy
} //namespace nesjoker
