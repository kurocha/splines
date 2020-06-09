//
//  Generic.hpp
//  This file is part of the "Splines" project and released under the .
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2007, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Polygon.hpp"

#include <Numerics/Vector.hpp>
#include <Numerics/Interpolate.hpp>

#include <functional>
#include <vector>
#include <list>

namespace Splines
{
	template <std::size_t D, typename PolygonT = Polygon<D>>
	class Spline
	{
	public:
		using Time = float;
		using Polygon = PolygonT;
		using Point = typename Polygon::Point;
		
		Spline(const Polygon & polygon) noexcept : _polygon(polygon) {}
		virtual ~Spline() {}
		
		std::size_t starting_index(Time time) const noexcept {
			// The starting point for a given t in [0.0, 1.0]
			return (_polygon.size() - 1) * time;
		}
		
		Time fractional_component(Time time) const {
			// The fractional component (ie, in [0.0, 1.0]) of a particular segment.
			auto offset = (_polygon.size() - 1) * time;
			return offset - std::size_t(offset);
		}
		
		/// Retrieve the point at time t.
		Point operator[](Time time) const noexcept {
			std::size_t starting_index = this->starting_index(time);
			Time fractional_component = this->fractional_component(time);
			
			return Numerics::Interpolate::linear(
				fractional_component,
				_polygon[starting_index],
				_polygon[starting_index+1]
			);
		}
		
	protected:
		const Polygon & _polygon;
	};
	
	extern template class Spline<2>;
	extern template class Spline<3>;
}
