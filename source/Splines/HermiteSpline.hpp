//
//  HermiteSpline.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 10/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Spline.hpp"

namespace Splines
{
	template <typename Polyline>
	class HermiteSpline : public Spline<Polyline>
	{
	public:
		HermiteSpline(const Polyline & polyline) noexcept : Spline<Polyline>(polyline) {}
		
		using Point = typename Spline<Polyline>::Point;
		using Time = typename Spline<Polyline>::Time;
		
		Point tangent(int index) const noexcept {
			return (this->_polyline[index+1] - this->_polyline[index-1]) * 0.5;
		}
		
		Point operator[](Time time) const noexcept {
			std::size_t starting_index = this->starting_index(time);
			Time fractional_component = this->fractional_component(time);
			
			return Numerics::Interpolate::hermite(
				fractional_component,
				this->_polyline[starting_index],
				this->tangent(starting_index),
				this->_polyline[starting_index+1],
				this->tangent(starting_index+1)
			);
		}
	};
	
	extern template class HermiteSpline<Polyline<2>>;
	extern template class HermiteSpline<Polyline<3>>;
}
