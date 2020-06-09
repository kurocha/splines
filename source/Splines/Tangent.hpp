//
//  Tangent.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

namespace Splines
{
	template <typename Spline>
	class Tangent
	{
	public:
		using Time = typename Spline::Time;
		using Point = typename Spline::Point;
		
		Tangent(const Spline & spline, const Time offset = 0.001) : _spline(spline), _offset(offset) {}
		virtual ~Tangent() {}
		
		Point operator[](Time time) const noexcept {
			Time a = time - _offset, b = time + _offset;
			
			return (_spline[b] - _spline[a]).normalize();
		};
		
	protected:
		const Spline & _spline;
		const Time _offset;
	};
}
