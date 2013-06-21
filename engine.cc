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
#include <cmath>

//////////////////////////////////////////////////
// Fuzzy set programs
//////////////////////////////////////////////////

template<typename C, typename S>
class FuzzyFunctorLittleF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorLittleF() {};

	int func(void *x,void *y) {
		return (1.3 / std::sqrt((float)*x));	
	}

};

mem_fun_t make_littlef<FuzzyFunctorLittleF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};

template<typename C, typename S>
class FuzzyFunctorSlightlyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorSlightlyF() {};

	int func(void *x,void *y) {
		return (1.7 / std::sqrt((float)*x));	
	}

};

mem_fun_t make_littlef<FuzzyFunctorSlightlyF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};

template<typename C, typename S>
class FuzzyFunctorVeryF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorVeryF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x);	
	}

};

mem_fun_t make_veryf<FuzzyFunctorVeryF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};


template<typename C, typename S>
class FuzzyFunctorExtremelyF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorExtremelyF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x * (float)*x);	
	}

};

mem_fun_t make_veryf<FuzzyFunctorExtremelyF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};


template<typename C, typename S>
class FuzzyFunctorVeryVeryF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorVeryVeryF() {};

	int func(void *x,void *y) {
		return ((float)*x * (float)*x * (float)*x * (float)*x);	
	}

};

mem_fun_t make_veryf<FuzzyFunctorVeryVeryF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};


template<typename C, typename S>
class FuzzyFunctorMoreOrLessF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorMoreOrLessF() {};

	int func(void *x,void *y) {
		return (std::sqrt((float)*x);	
	}

};

mem_fun_t make_veryf<FuzzyFunctorMoreOrLessF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};


template<typename C, typename S>
class FuzzyFunctorSomewhatF : public FuzzyFunctor<C, S> 
{
public:
	FuzzyFunctorSomewhatF() {};

	int func(void *x,void *y) {
		return (std::sqrt((float)*x);	
	}

};

mem_fun_t make_veryf<FuzzyFunctorSomewhatF>(mem_fun_t f, void *b, void *c) {
	mem_fun(&F::func)();
};



