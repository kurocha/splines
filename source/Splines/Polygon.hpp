//
//  Polygon.hpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 9/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#pragma once

#include <vector>
#include <Numerics/Vector.hpp>

namespace Splines
{
	template <std::size_t D>
	class Polygon
	{
	public:
		typedef Numerics::Vector<D> Point;
		typedef std::vector<Point> Points;
		
		Polygon(const Points && points, bool closed = true) noexcept : _points(points), _closed(closed) {}
		~Polygon() noexcept {}
		
		const Points& points() const noexcept {return _points;}
		bool closed() const noexcept {return _closed;}
		
		std::size_t size() const noexcept {return _points.size() + (_closed ? 1 : 0);}
		Point operator[](std::size_t index) const noexcept {return _points[index % _points.size()];}
		
	protected:
		Points _points;
		bool _closed;
	};
	
	extern template class Polygon<2>;
	extern template class Polygon<3>;
}
