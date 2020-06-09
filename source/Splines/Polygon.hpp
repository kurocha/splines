//
//  Polygon.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

#include <algorithm>
#include "Polyline.hpp"

namespace Splines
{
	template <std::size_t D>
	class Polygon : private Polyline<D>
	{
	public:
		using typename Polyline<D>::Point;
		using typename Polyline<D>::Points;
		
		using Polyline<D>::Polyline;
		
		using Polyline<D>::points;
		
		std::size_t size() const noexcept {
			return this->_points.size() + 1;
		}
		
		Point operator[](int index) const noexcept {
			auto size = this->_points.size();
			index = index % (int)size;
			
			if (index < 0) {
				index += size;
			}
			
			return this->_points[index];
		}
	};
	
	extern template class Polygon<2>;
	extern template class Polygon<3>;
}
