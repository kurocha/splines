//
//  Polyline.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

#include <vector>
#include <algorithm>
#include <Numerics/Vector.hpp>

namespace Splines
{
	template <std::size_t D>
	class Polyline
	{
	public:
		using Point = Numerics::Vector<D>;
		using Points = std::vector<Point>;
		
		Polyline(const Points && points) noexcept : _points(points) {}
		
		const Points& points() const noexcept {
			return this->_points;
		}
		
		std::size_t size() const noexcept {
			return this->_points.size();
		}
		
		Point operator[](int index) const noexcept {
			return this->_points[
				std::clamp<int>(index, 0, this->_points.size() - 1)
			];
		}
		
	protected:
		Points _points;
	};
	
	extern template class Polyline<2>;
	extern template class Polyline<3>;
}
