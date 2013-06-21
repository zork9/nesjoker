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

template<class T>
class Lambda
{
	Lambda();

	void operator() (T const& x)
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

 
