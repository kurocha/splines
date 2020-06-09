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
	template <std::size_t D>
	class CubicSpline : public Spline<D>
	{
	public:
		using Spline<D>::Spline;
		virtual ~CubicSpline() {}
		
		using Point = typename Spline<D>::Point;
		using Time = typename Spline<D>::Time;
		
		Point operator[](Time time) const noexcept{
			std::size_t starting_index = this->starting_index(time);
			Time fractional_component = this->fractional_component(time);
			
			return Numerics::Interpolate::cubic(
				fractional_component,
				this->_polygon[starting_index-1],
				this->_polygon[starting_index],
				this->_polygon[starting_index+1],
				this->_polygon[starting_index+2]
			);
		}
	};
	
	extern template class CubicSpline<2>;
	extern template class CubicSpline<3>;
}
