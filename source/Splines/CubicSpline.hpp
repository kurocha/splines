//
//  CubicSpline.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Spline.hpp"

namespace Splines
{
	template <typename Polyline>
	class CubicSpline : public Spline<Polyline>
	{
	public:
		CubicSpline(const Polyline & polyline) noexcept : Spline<Polyline>(polyline) {}
		
		using Point = typename Spline<Polyline>::Point;
		using Time = typename Spline<Polyline>::Time;
		
		Point operator[](Time time) const noexcept{
			std::size_t starting_index = this->starting_index(time);
			Time fractional_component = this->fractional_component(time);
			
			return Numerics::Interpolate::cubic(
				fractional_component,
				this->_polyline[starting_index-1],
				this->_polyline[starting_index],
				this->_polyline[starting_index+1],
				this->_polyline[starting_index+2]
			);
		}
	};
	
	extern template class CubicSpline<Polyline<2>>;
	extern template class CubicSpline<Polyline<3>>;
}
