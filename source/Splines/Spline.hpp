//
//  Generic.hpp
//  This file is part of the "Splines" project and released under the .
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2007, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Polyline.hpp"

#include <Numerics/Vector.hpp>
#include <Numerics/Interpolate.hpp>

#include <functional>
#include <vector>
#include <list>

namespace Splines
{
	template <typename Polyline>
	class Spline
	{
	public:
		using Time = float;
		using Point = typename Polyline::Point;
		
		Spline(const Polyline & polyline) noexcept : _polyline(polyline) {}
		virtual ~Spline() {}
		
		int starting_index(Time time) const noexcept {
			// The starting point for a given t in [0.0, 1.0]
			return (_polyline.size() - 1) * time;
		}
		
		Time fractional_component(Time time) const {
			// The fractional component (ie, in [0.0, 1.0]) of a particular segment.
			auto offset = (_polyline.size() - 1) * time;
			return offset - std::size_t(offset);
		}
		
		/// Retrieve the point at time t.
		Point operator[](Time time) const noexcept {
			auto starting_index = this->starting_index(time);
			auto fractional_component = this->fractional_component(time);
			
			return Numerics::Interpolate::linear(
				fractional_component,
				_polyline[starting_index],
				_polyline[starting_index+1]
			);
		}
		
	protected:
		const Polyline & _polyline;
	};
	
	extern template class Spline<Polyline<2>>;
	extern template class Spline<Polyline<3>>;
}
