//
//  CubicSpline.cpp
//  This file is part of the "Splines" project and released under the MIT License.
//
//  Created by Samuel Williams on 10/6/2020.
//  Copyright, 2020, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Splines/Polyline.hpp>
#include <Splines/CubicSpline.hpp>

namespace Splines
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite CubicSplineTestSuite {
		"Splines::CubicSpline",
		
		{"it can generate cubic points on the spline",
			[](UnitTest::Examiner & examiner) {
				using Point = Polyline<2>::Point;
				
				Polyline<2> polyline({
					{0, 0}, {1, 0.5}, {2, 2}, {3, 1.5}
				});
				
				CubicSpline spline(polyline);
				
				examiner.expect(spline[0]).to(be == Point{0, 0});
				examiner.expect(spline[0.5]).to(be == Point{1.5, 1.375});
				examiner.expect(spline[1.0]).to(be == Point{3, 1.5});
			}
		},
	};
}
