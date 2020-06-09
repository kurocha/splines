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
		
		std::vector<Time> times_for_segments(std::size_t factor = 1) const noexcept {
			Time delta = (Time)1.0 / (_spline.size() * factor);
			
			std::vector<Time> times;
			
			for (Time time = 0; time <= 1.0; time += delta)
				times.push_back(time);
				
			return times;
		}
		
		std::vector<Time> times_at_resolution(Time resolution, unsigned divisions) const {
			// We must divide at least once per point, hence the + 1.
			auto minimum_divisions = (Numerics::number(this->points().size()).square_root() + 1).truncate(true);
			
			divisions = Numerics::number(divisions).max(minimum_divisions);
			
			return divide_and_append(divisions, resolution);
		}
		
	protected:
		const Spline & _spline;
		const Time _offset;
		
		// Entry point for the function below.
		// The higher res is, the more detail will be present.
		std::vector<Time> divide_and_append(int index, Time resolution) const {
			std::vector<Time> times;
			
			divide_and_append(0.0, 1.0, index, 1.0 - (1.0 / resolution), true, times);
			
			return times;
		}
		
		void divide_and_append(Time t, Time d, int n, Time res2, bool first, std::vector<Time> &times) const {
			Time hd = d / 2.0;
			
			auto t1 = (*this)[t];
			auto t2 = (*this)[t+d];
			
			bool divide = n > 0 || (t1.dot(t2) < res2 && n > -10) /* Sanity check */;
			
			// First point of segment
			if (divide) divide_and_append(t, hd, n - 1, res2, true & first, times);
			
			if (!divide) {
				if (first) times.push_back(t);
				
				times.push_back(t+d);
			}
			
			// Last point of segment
			if (divide) divide_and_append(t + hd, hd, n - 1, res2, false, times);
		}
	};
}
